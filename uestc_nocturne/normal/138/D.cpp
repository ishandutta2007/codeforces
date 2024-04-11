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
const int V=22;
char map[40][40];
int dp[40][40][40][40],n,m;
int SG(int l,int r,int u,int d,int re)
{
    if(dp[l][r][u][d]!=-1)return dp[l][r][u][d];
    if(l>r||d>u){dp[l][r][u][d]=0;return 0;}
    vector<int> a;
    a.clear();a.push_back(-1);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if((i+j)%2==re&&i+j>=l&&i+j<=r&&j-i+V>=d&&j-i+V<=u)
        {
            int te=0;
            if(map[i][j]=='R')
            {
                te^=SG(l,r,j-i+V-1,d,re);
                te^=SG(l,r,u,j-i+V+1,re);
            }
            else if(map[i][j]=='L')
            {
                te^=SG(l,i+j-1,u,d,re);
                te^=SG(i+j+1,r,u,d,re);
            }
            else
            {
                te^=SG(l,i+j-1,u,j-i+V+1,re);
                te^=SG(l,i+j-1,j-i+V-1,d,re);
                te^=SG(i+j+1,r,u,j-i+V+1,re);
                te^=SG(i+j+1,r,j-i+V-1,d,re);
            }
            a.push_back(te);
        }
    }
    sort(a.begin(),a.end());
    for(int i=1;i<(int)a.size();i++)
    {
        if(a[i]!=a[i-1]&&a[i]!=a[i-1]+1)
        {
            dp[l][r][u][d]=a[i-1]+1;
            return dp[l][r][u][d];
        }
    }
    dp[l][r][u][d]=a[(int)a.size()-1]+1;
    return dp[l][r][u][d];
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        scanf("%s",map[i]);
        memset(dp,-1,sizeof(dp));
        int ret=SG(0,n+m-2,m-1+V,1-n+V,0);
        memset(dp,-1,sizeof(dp));
        ret^=SG(0,n+m-2,m-1+V,1-n+V,1);
        if(ret)puts("WIN");
        else puts("LOSE");
    }
}