#include <iostream>
#include <algorithm>
using namespace std;
int tab[55][55];
int vis[55][55];
int n, m;
void czysc()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            vis[i][j]=0;
        }
    }
    return;
}
void dfs(int i, int j)
{
    vis[i][j]=1;
    if(tab[i+1][j]==1 && vis[i+1][j]==0)
    {
        dfs(i+1, j);
    }
    if(tab[i-1][j]==1 && vis[i-1][j]==0)
    {
        dfs(i-1, j);
    }
    if(tab[i][j+1]==1 && vis[i][j+1]==0)
    {
        dfs(i, j+1);
    }
    if(tab[i][j-1]==1 && vis[i][j-1]==0)
    {
        dfs(i, j-1);
    }
    return;
}
int main()
{
    //int n, m;
    char c;
    cin>>n>>m;
    int licz=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c;
            if(c=='#')
            {
                tab[i][j]=1;
                licz++;
            }
        }
    }
    if(licz<3)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int wynik=5;
    int akt;
    int odw;
    //cout<<"no co?"<<endl;
    //system("pause");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(tab[i][j]==1)
            {
                akt=0;
                akt=tab[i+1][j]+tab[i-1][j]+tab[i][j+1]+tab[i][j-1];
                if(akt==1)
                {
                    cout<<"1"<<endl;
                    //system("pause");
                    return 0;
                }
                else
                {
                    czysc();
                    tab[i][j]=0;
                    if(tab[i+1][j]==1)
                    {
                        dfs(i+1, j);
                    }
                    else
                    {
                        if(tab[i-1][j]==1)
                        {
                            dfs(i-1, j);
                        }
                        else
                        {
                            dfs(i, j+1);
                        }
                    }
                    tab[i][j]=1;
                }
                odw=vis[i+1][j]+vis[i-1][j]+vis[i][j+1]+vis[i][j-1];
                if(odw<akt)
                {
                    cout<<"1"<<endl;
                    // system("pause");
                    return 0;
                }
                /* if(i==3 && j==3)
                {
                    cout<<akt<<" "<<odw<<endl;
                } */
            }
        }
    }
    cout<<"2"<<endl;
    // system("pause");
    return 0;
}
/*
5 5
#####
#####
..#..
#####
#####
*/