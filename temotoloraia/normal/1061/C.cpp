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
const ll N = 1e6 + 7, MOD = 1e9 + 7;
ll n;
ll a[N];
ll dp[N];
vector < ll > V[N];
int main()
{
    for (int i = 1; i <= 1000000; i++)
        for (int j = i; j <= 1000000; j += i)
            V[j].pb (i);
    dp[0] = 1;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        for (int k = (int)V[a[i]].size() - 1; k >= 0; k--){
            ll x = V[a[i]][k];
            dp[x] = (dp[x] + dp[x - 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % MOD;
    cout<<ans<<endl;
    return 0;
}