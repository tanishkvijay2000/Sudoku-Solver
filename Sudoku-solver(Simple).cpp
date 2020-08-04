#include <iostream>

using namespace std;
int grid[9][9];
bool Possible(int y,int x,int n)
{
    for(int i = 0;i<9;i++)
    {
        if(grid[y][i]==n)
        {
            return false;
        }
    }
    for(int i = 0;i<9;i++)
    {
        if(grid[i][x]==n)
        {
            return false;
        }
    }
    int xo = (x/3)*3;
    int yo = (y/3)*3;
    for(int i = 0;i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(grid[yo+i][xo+i]==n)
            {
                return false;
            }
        }
    }
    return true;
}
void PrintGrid()
{
    cout<<"After Solving"<<endl;
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void Solve()
{
    for(int y = 0;y<9;y++)
    {
        for(int x = 0;x<9;x++)
        {
            if(grid[y][x]==0)
            {
                for(int n = 1;n<10;n++)
                {
                    if(Possible(y,x,n))
                    {
                        grid[y][x] = n;
                        Solve();
                        grid[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    PrintGrid();
}
/*void PrintGrid()
{
    for(int i = 1;i<=9;i++)
    {
        for(int j = 1;j<=9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}*/
int main()
{
    cout<<"Enter a valid sudoku"<<endl;
    for(int i =0;i<9;i++)
    {
        for(int j =0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"Before solving:"<<endl;
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    Solve();
    return 0;
}

