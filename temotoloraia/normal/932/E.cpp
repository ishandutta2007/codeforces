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
using namespace std;
const ll MOD = 1e9 + 7;
ll POWER (ll k){
    ll ans = 1, p = 2, q = 1;
    while (q <= k){
        if (q & k)
            ans = ans * p % MOD;
        p = p * p % MOD;
        q *= 2;
    }
    return ans;
}
ll n, k;
ll dp[5005], d[5005];
ll ans;
//  dp[1] dp[2] ...
int main()
{
    cin>>n>>k;
    d[1] = n;
    dp[1] = n;
    for (int i = 2; i <= k; i++){
        for (int j = 1; j <= i; j++)
            dp[j] = (d[j] * j + d[j - 1] * (n - j + 1)) % MOD;
        for (int j = 1; j <= i; j++)
            d[j] = dp[j];
    }
    for (int i = 1; i <= k; i++)
        ans = (ans + dp[i] * POWER (n - i)) % MOD;
    cout<<ans<<endl;
    return 0;
}