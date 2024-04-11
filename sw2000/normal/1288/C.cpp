#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll n,m,dp[1010][15];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)dp[i][1]=1;
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                dp[j][i]+=dp[k][i-1];
            }
            dp[j][i]%=mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j+i<=n+1;j++)
        {
            ans+=dp[i][m]*dp[j][m]%mod;
            ans%=mod;
        }
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}