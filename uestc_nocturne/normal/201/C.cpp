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
const int V=100100;
const LL ooo=1000000000;
const LL oo=ooo*ooo;
LL dp[V][3];
int a[V],i,j,n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        dp[i][j]=-oo;
        for(i=1;i<n;i++)
        scanf("%d",&a[i]);
        dp[0][0]=0;a[0]=0;
        for(i=0;i<n-1;i++)
        {
            int use;
            use=a[i];
            if(a[i]%2==1)use--;
            dp[i][0]=max(dp[i][0],(LL)use);
            if(dp[i][0]!=-oo)
            {
                if(a[i+1]!=1)
                {
                    use=a[i+1];
                    if(use%2==1)use--;
                    dp[i+1][0]=max(dp[i+1][0],dp[i][0]+use);
                }
                use=a[i+1];if(use%2==0)use--;
                dp[i+1][1]=max(dp[i+1][1],dp[i][0]+use);
            }
            if(dp[i][1]!=-oo)
            {
                if(a[i+1]!=1)
                {
                    use=a[i+1];
                    if(use%2==1)use--;
                    dp[i+1][2]=max(dp[i+1][2],dp[i][1]+use);
                }
                use=a[i+1];if(use%2==0)use--;
                dp[i+1][1]=max(dp[i+1][1],dp[i][1]+use);
            }
            if(dp[i][2]!=-oo)
            {
                if(a[i+1]!=1)
                {
                    use=a[i+1];
                    if(use%2==1)use--;
                    dp[i+1][2]=max(dp[i+1][2],dp[i][2]+use);
                }
            }
        }
        LL ans=-oo;
        for(i=1;i<n;i++)
        for(j=0;j<3;j++)
        ans=max(ans,dp[i][j]);
        cout<<ans<<endl;
    }
}