#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=P?P:0);
}
inline void sub(int &a,int b)
{
    a=a-b+(a-b<0?P:0);
}
const int max_n=1e5+5;
const int max_a=200+5;
int a[max_n],dp[2][max_a][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    for(int i=1;i<=200;++i)
        dp[1][i][0]=1;
    for(int i=1;i<n;++i)
    {
        int x=i&1,y=x^1;
        if(a[i]!=-1)
        {
            for(int j=1;j<=200;++j)
            {
                if(a[i]!=j)
                    dp[x][j][0]=dp[x][j][1]=0;
            }
        }
        for(int j=1;j<=200;++j)
            dp[y][j][0]=dp[y][j][1]=0;
        for(int j=1;j<=200;++j)
        {
            add(dp[y][j+1][0],dp[x][j][0]);
            add(dp[y][j][1],dp[x][j][0]);
            sub(dp[y][j-1][1],dp[x][j][0]);
            add(dp[y][j+1][0],dp[x][j][1]);
            add(dp[y][j][1],dp[x][j][1]); 
        }
        for(int j=1;j<=200;++j)
            add(dp[y][j][0],dp[y][j-1][0]);
        for(int j=200;j>=1;--j)
            add(dp[y][j][1],dp[y][j+1][1]);
    }
    int x=n&1,ans=0;
    for(int i=1;i<=200;++i)
    {
        if(a[n]==-1||a[n]==i)
            add(ans,dp[x][i][1]);
    }
    printf("%d\n",ans);
    return 0;
}