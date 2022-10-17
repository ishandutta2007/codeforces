#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

char g[55][55];
int d[55][55];
int dir1[4] = {1,-1,0,0};
int dir2[4] = {0,0,1,-1};
int sx,sy,tx,ty,n;
int dfs()
{
    queue<pair<int,int> > q;
    d[sx][sy] = 1;
    q.push({sx,sy});
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        int x=p.first,y=p.second;
        for(int i=0;i<4;++i)
        {
            int xx=x+dir1[i],yy=y+dir2[i];
            if(xx<=0||yy<=0||xx>n||yy>n||g[xx][yy]=='1'||d[xx][yy]) continue;
            d[xx][yy]=1;
            q.push({xx,yy});
        }
    }
    if(d[tx][ty]) return 1;
    d[tx][ty] = 2;
    q.push({tx,ty});
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        int x=p.first,y=p.second;
        for(int i=0;i<4;++i)
        {
            int xx=x+dir1[i],yy=y+dir2[i];
            if(xx<=0||yy<=0||xx>n||yy>n||g[xx][yy]=='1'||d[xx][yy]) continue;
            d[xx][yy]=2;
            q.push({xx,yy});
        }
    }
    return 0;
}
int main()
{
    cin>>n;
    cin>>sx>>sy>>tx>>ty;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>g[i][j];
    if(dfs())
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1e9;
    for(int x1=1;x1<=n;++x1)
    {
        for(int y1=1;y1<=n;++y1)
        {
            if(d[x1][y1]!=1) continue;
            for(int x2=1;x2<=n;++x2)
            {
                for(int y2=1;y2<=n;++y2)
                {
                    if(d[x2][y2]!=2) continue;
                    int cost = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                    ans = min(ans, cost);
                }
            }
        }
    }
    cout << ans << endl;
}