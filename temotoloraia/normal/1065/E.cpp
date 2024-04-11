#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo
using namespace std;
const ll N = 200005, MOD = 998244353;
ll POWER (ll X, ll Y){
    ll ans = 1, x = X;
    while (Y){
        if ((Y & 1) == 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        Y /= 2;
    }
    return ans;
}
ll n, m, k;
ll a[N];
ll ans;
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif temo
    cin>>m>>n>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    ans = POWER (k, m - 2 * a[n]);
    for (int i = 1; i <= n; i++){
        ll x = POWER (k, a[i] - a[i - 1]);
        ans = ans * (x * (x + 1) / 2 % MOD) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}