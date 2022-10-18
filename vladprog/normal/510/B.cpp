#include<bits/stdc++.h>

using namespace std;

char a[52][52];
bool u[52][52];

void dfs(int px,int py,int x,int y)
{
    //printf("-> (%d,%d) (%d,%d)\n",px,py,x,y);
    if(u[x][y])
        printf("Yes\n"),exit(0);
    u[x][y]=true;
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++)
        {
            if(abs(dx+dy)!=1)continue;
            int nx=x+dx,ny=y+dy;
            if(nx==px&&ny==py)continue;
            if(a[nx][ny]!=a[x][y])continue;
            dfs(x,y,nx,ny);
        }
    u[x][y]=false;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int j=0;j<=m+1;j++)
        a[0][j]=' ';
    for(int i=1;i<=n;i++)
    {
        scanf("%*c");
        a[i][0]=' ';
        for(int j=1;j<=m;j++)
            scanf("%c",&a[i][j]);
        a[i][m+1]=' ';
    }
    for(int j=0;j<=m+1;j++)
        a[n+1][j]=' ';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dfs(-1,-1,i,j);
    printf("No\n");
}