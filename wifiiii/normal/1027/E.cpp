#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 998244353;
ll dp[505][505][2];
ll n,k;
ll f[505],g[505];
int main()
{
    cin>>n>>k;
    --k;
    for(int i=1;i<=n;++i)
    {
        if(i > k) break;
        memset(dp,0,sizeof(dp));
        dp[1][1][1] = dp[1][1][0] = 1;
        for(int j=1;j<n;++j)
        {
            for(int p=1;p<=i;++p) dp[j][p][0]%=mod,dp[j][p][1]%=mod;
            for(int p=1;p<i;++p)
            {
                dp[j+1][1][1] += dp[j][p][0];
                dp[j+1][p+1][1] += dp[j][p][1];
                dp[j+1][1][0] += dp[j][p][1];
                dp[j+1][p+1][0] += dp[j][p][0];
            }
            dp[j+1][1][1] += dp[j][i][0];
            dp[j+1][1][0] += dp[j][i][1];
        }
        ll sum = 0;
        for(int j=1;j<=i;++j) sum+=dp[n][j][0]+dp[n][j][1];
        sum %= mod;
        f[i] = sum;
    }
    ll ans = 0;
    ii g[i]=f[i]-f[i-1];
    for(int i=1;i<=n;++i)
    {
        if(i > k) break;
        ans += g[i] * f[min(k/i,n)] % mod;
    }
    ans %= mod;
    ans = ans * ((mod+1)/2) % mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}