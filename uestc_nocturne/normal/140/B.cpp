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
const int V=310;
int pf[V][V];
int n;
int i,j,k,ans[V],ma,pj[V][V],now[V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            for(j=0;j<n;j++)
            scanf("%d",&pf[i][j]);
            for(j=0;j<n;j++)
            pj[i][pf[i][j]]=j;
        }
        for(i=0;i<n;i++)
        scanf("%d",&pf[0][i]);
        for(i=1;i<=n;i++)ans[i]=n,now[i]=n+1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ma=-1;
                for(k=0;k<n;k++)
                if(pf[0][k]!=j&&pf[0][k]<=i)
                {ma=pf[0][k];break;}
                if(ma==-1)continue;
                if(pj[j][ma]<now[j])
                {
                    ans[j]=ma;
                    now[j]=pj[j][ma];
                }
            }
        }
        for(i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    }
}