#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int a,b,n,m,k,x,y,v[2010][2010],d[2010][2010];
int F(int x,int y,int k)
{
    int p=max(1,x-k),q=min(x+k,n);
    for(int i=p;i<=q;i++)
    {
        int u=k-abs(i-x);
        if(y-u>0&&!v[i][y-u])
            return a=i,b=y-u,1;
        if(y+u<=m&&!v[i][y+u])
            return a=i,b=y+u,1;
    }
    return 0;
}
int main()
{
    for(scanf("%d%d%d",&n,&m,&k);k--;)
    {
        scanf("%d%d",&x,&y);
        for(int i=x-2;i<x+3;i++)
            for(int j=y-2;j<y+3;j++)
                if(i>0&&i<=n&&j>0&&j<=m)
                    d[x][y]=max(d[x][y],d[i][j]-abs(i-x)-abs(j-y));
        while(!F(x,y,d[x][y]))
            d[x][y]++;
        printf("%d %d\n",a,b);
        v[a][b]=1;
    }
}