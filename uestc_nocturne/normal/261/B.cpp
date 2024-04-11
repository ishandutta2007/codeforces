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
const int V=60;
int a[V],L,n;
double dp[2][V][V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        int S=0;
        for(int i=0;i<n;i++)S+=a[i];
        scanf("%d",&L);
        double ret=0.0;
        for(int i=0;i<n;i++)
        {
            memset(dp,0,sizeof(dp));
            int fl=0,te=1;
            dp[0][0][0]=1.0;
            int all=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                te=1-fl;
                for(int ii=0;ii<n;ii++)
                for(int jj=0;jj<=L;jj++)
                dp[te][ii][jj]=0;
                for(int ii=0;ii<=all;ii++)
                for(int jj=0;jj<=L;jj++)
                {
                    if(dp[fl][ii][jj]==0.0)continue;
                    dp[te][ii][jj]+=dp[fl][ii][jj]*(all-ii+1)/(all+2);
                    dp[te][ii+1][min(L,jj+a[j])]+=
                        dp[fl][ii][jj]*(ii+1)/(all+2);
                }
                all++;
                fl=te;
            }
            for(int ii=0;ii<n;ii++)
            for(int j=0;j<=S;j++)
            if(j+a[i]<=L)ret+=dp[fl][ii][j];
        //  printf("%.8f\n",ret);
        }
        printf("%.8f\n",ret);
    }
}