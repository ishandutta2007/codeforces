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
const LL P=1000000007;
LL dp[1200][1200],s1[1200],s2[1200],ans;
int i,ma,n,m,K;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&K))
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=1000;i++)
        dp[i][0]=1;
        for(ma=1;ma<=max(n,m);ma++)
        {
            s1[0]=0;
            for(i=1;i<=1000;i++)
            {
                s1[i]=(s1[i-1]+dp[i][ma-1])%P;
                s2[i]=(s2[i-1]+i*dp[i][ma-1])%P;
            }
            for(i=2;i<=1000;i++)
            {
                dp[i][ma]=(s1[i-2]*(i-1)-s2[i-2])%P;
                dp[i][ma]=(dp[i][ma]+P)%P;
            }
        }
        ans=dp[n][K]*dp[m][K]%P;
        cout<<ans<<endl;
    }
}