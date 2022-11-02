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
const int V=1010;
double dp[V][V],C[V][V];
int ct[V],va[V][V],pos[V],X[V],has[V],n,m;
int main()
{
    for(int i=0;i<1005;i++)
    {
        C[i][0]=C[i][i]=1.0;
        for(int j=1;j<i;j++)
        C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&ct[i]);
            for(int j=0;j<ct[i];j++)
            scanf("%d",&va[i][j]);
            sort(va[i],va[i]+ct[i]);
        }
        for(int i=0;i<m;i++)pos[i]=ct[i]-1;
        int now=-1,t=0;
        for(int i=0;i<n;i++)
        {
            int id=-1;
            for(int j=0;j<m;j++)
            if(pos[j]>=0&&(id==-1||va[id][pos[id]]<va[j][pos[j]]))
            id=j;
            //printf("%d\n",id);
            if(now==va[id][pos[id]])t++;
            else
            {
                now=va[id][pos[id]];t=1;
            }
            pos[id]--;
        }
        int all=0;
        memset(has,0,sizeof(has));
        for(int i=0;i<m;i++)
        {
            X[i]=0;
            for(int j=0;j<ct[i];j++)
            if(va[i][j]==now)all++,has[i]=1;
            else if(va[i][j]>now)X[i]++;
        }
        memset(dp,0,sizeof(dp));
        //printf("%d %d %d\n",t,all,now);
        if(!has[0])
        dp[0][0]=1.0/C[ct[0]][X[0]];
        else
        {
            dp[0][0]=1.0/C[ct[0]][X[0]]*(all-t)/all;
            dp[0][1]=1.0/C[ct[0]][X[0]+1]*t/all;
        }
        int re=all;
        if(has[0])re--;
        for(int i=1;i<m;i++)
        {
            if(!has[i])
            {
                for(int j=0;j<=t;j++)
                dp[i][j]=dp[i-1][j]/C[ct[i]][X[i]];
            }
            else
            {
                for(int j=0;j<=t;j++)
                {
                    dp[i][j]+=dp[i-1][j]/C[ct[i]][X[i]]*(re-t+j)/re;
                    if(re!=0&&j!=t)
                    dp[i][j+1]+=dp[i-1][j]/C[ct[i]][X[i]+1]*(t-j)/re;
                }
                re--;
            }
            //for(int j=0;j<=t;j++)printf("%d %d %.10f\n",i,j,dp[i][j]);
        }
        printf("%.10f\n",dp[m-1][t]);
    }
}