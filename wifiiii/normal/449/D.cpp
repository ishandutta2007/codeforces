#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 1e9+7;
const int maxn = 1<<20;
int a[maxn], dp[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        dp[a[i]]++;
    }
    for(int i=0;i<20;++i)
        for(int j=0;j<1<<20;++j)
        {
            if(j&(1<<i)) continue;
            dp[j] += dp[j^(1<<i)];
        }
    ll ans = 0;
    for(int i=0;i<1<<20;++i) {
        int f = 1;
        if(__builtin_popcount(i) & 1) f = -1;
        ans += f * (fpow(2, dp[i]) - 1);
        ans %= mod;
        if(ans < 0) ans += mod;
    }
    printf("%lld\n", ans);
}