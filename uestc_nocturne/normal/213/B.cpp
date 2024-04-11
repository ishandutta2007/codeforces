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
const int V=120;
const int P=1000000007;
int C[V][V],dp[20][V],a[V],n;
int main()
{
    for(int i=0;i<110;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
    }
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=9;i>=0;i--)
        scanf("%d",&a[i]);
        for(int i=0;i<9;i++)
        for(int j=0;j<=n;j++)
        if(dp[i][j]!=0)
        {
    //      printf("%d %d %d\n",i,j,dp[i][j]);
            for(int k=a[i];k+j<=n;k++)
            {
                dp[i+1][k+j]+=(LL)C[k+j][j]*dp[i][j]%P;
                dp[i+1][k+j]%=P;
            }
        }
        for(int i=0;i<=n;i++)
        if(dp[9][i]!=0)
        {
         //   printf("%d %d %d\n",9,i,dp[9][i]);
            for(int k=a[9];k+i<=n;k++)
            {
                if(i+k==0)continue;
                dp[10][k+i]+=(LL)C[k+i-1][k]*dp[9][i]%P;
                dp[10][k+i]%=P;
            }
        }
        int ret=0;
        for(int i=0;i<=n;i++)ret=(ret+dp[10][i])%P;
        printf("%d\n",ret);
    }
}