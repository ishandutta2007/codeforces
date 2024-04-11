#include <bits/stdc++.h>

using namespace std;
const int maxn=55;
bool a[maxn][maxn];
bool fix[maxn][maxn];
bool used[maxn];
int d[maxn];
int n;
bool dfs(int x,int cor)
{
    used[x]=true;
    if(d[x]<=(d[cor]-2))
    {
        d[x]++;
        d[cor]--;
        return true;
    }
    for(int v=0;v<n;++v)
    {
        if(a[x][v] && !fix[x][v] && !used[v])
        {
            bool h=dfs(v,cor);
            if(h)
            {
                a[x][v]=false;
                a[v][x]=true;
                return true;
            }
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i<j)
            {
                a[i][j]=true;
            }
            else
            {
                a[i][j]=false;
            }
        }
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x][y]=true;
        a[y][x]=false;
        fix[x][y]=true;
        fix[y][x]=false;
    }
    for(int i=0;i<n;++i)
    {
        d[i]=0;
        for(int j=0;j<n;++j)
        {
            if(a[i][j])
            {
                d[i]++;
            }
        }
    }
    for(int cyc=0;cyc<(n*n+1)/2;++cyc)
    {
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) used[j]=false;
        dfs(i,i);
    }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j])
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
    return 0;
}