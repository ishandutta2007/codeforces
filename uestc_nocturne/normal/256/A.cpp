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
const int V=4100;
const int M=1000100;
int dp[V][V],a[V],nxt[V][V];
int id[M],n;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(id,-1,sizeof(id));
        memset(nxt,-1,sizeof(nxt));
        int m=1;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=n-1;i>=0;i--)
        {
            if(id[a[i]]==-1)id[a[i]]=m++;
            for(int j=n;j>=0;j--)
            nxt[i][j]=nxt[i+1][j];
            nxt[i][id[a[i]]]=i;
        }
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
            for(int j=i+1;j<n;j++)
            dp[j][id[a[i]]]=max(dp[j][id[a[i]]],2);
            for(int j=1;j<=n;j++)
            {
                ans=max(ans,dp[i][j]);
                if(id[a[i]]==j)continue;
                if(nxt[i][j]==-1)continue;
                dp[nxt[i][j]][id[a[i]]]=max(dp[nxt[i][j]][id[a[i]]]
                ,dp[i][j]+1);
            }
        }
        memset(id,0,sizeof(id));
        for(int i=0;i<n;i++)
        {
            id[a[i]]++;
            ans=max(ans,id[a[i]]);
        }
        printf("%d\n",ans);
    }
}