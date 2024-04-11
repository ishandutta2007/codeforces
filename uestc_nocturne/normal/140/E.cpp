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
const int V=5010;
int dp[V][V];
LL last[2][V];
LL C[V];
int n,m,P;
int T[V][V];
int i,j,s,fl,te,l[1000100];
int main()
{
    while(~scanf("%d%d%d",&n,&m,&P))
    {
        for(i=0;i<n;i++)
        scanf("%d",&l[i]);
        memset(dp,0,sizeof(dp));
        dp[1][1]=m;
        for(i=1;i<=5000;i++)
        for(j=1;j<=i;j++)
        {
            if(dp[i][j]==0)continue;
            dp[i+1][j]+=(LL)dp[i][j]*(j-1)%P;
            dp[i+1][j]%=P;
            if(j+1<=m)
            {
                dp[i+1][j+1]+=(LL)dp[i][j]*(m-j)%P;
                dp[i+1][j+1]%=P;
            }
        }
        s=0;
        for(i=1;i<=5000;i++)
        for(j=1;j<=i;j++)
        {
            if(j==1)
            {
                if(i==1)T[i][j]=1;
                else T[i][j]=0;
            }
            else
            {
                T[i][j]=0;
                if(i>1)T[i][j]+=(LL)T[i-1][j]*(j-1)%P;
                T[i][j]%=P;
                if(j>1)T[i][j]+=(LL)T[i-1][j-1]*j%P;
                T[i][j]%=P;
            }
        }
        for(i=1;i<=min(l[0],m);i++)last[0][i]=dp[l[0]][i];
        //for(i=1;i<=min(l[0],m);i++)printf("0 %d %lld\n",i,last[0][i]);
        fl=0;
        for(i=1;i<n;i++)
        {
            te=1-fl;
            LL ts=0;
            for(j=1;j<=min(l[i-1],m);j++)
            ts+=last[fl][j];
            ts%=P;
            for(j=1;j<=min(l[i],m);j++)
            {
                last[te][j]=ts*dp[l[i]][j]%P;
                if(j<=l[i-1])last[te][j]-=(LL)T[l[i]][j]*last[fl][j]%P;
                last[te][j]=(last[te][j]%P+P)%P;
                //printf("%d %d %lld\n",i,j,last[te][j]);
            }
            fl=te;
        }
        LL ret=0;
        for(j=1;j<=min(l[n-1],m);j++)
        ret+=last[fl][j];
        ret%=P;
        cout<<ret<<endl;
    }
}