/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1200;
int d[2][V],as[2][V][V],n,m,x,y;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(d,0,sizeof(d));
        memset(as,0,sizeof(as));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            d[0][y]++;
            as[0][x][y]++;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            d[1][y]++;
            as[1][x][y]++;
        }
        int ans=0,ret=0;
        for(int i=0;i<=1001;i++)
        ans+=min(d[0][i],d[1][i]);
        for(int i=0;i<=1001;i++)
        for(int j=0;j<=1001;j++)
        ret+=min(as[0][i][j],as[1][i][j]);
        printf("%d %d\n",ans,ret);
    }
}