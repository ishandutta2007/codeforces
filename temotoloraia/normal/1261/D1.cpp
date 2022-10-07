#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const ll N = 200005, MOD = 998244353;

ll POWER (ll x, ll y){
    ll ans = 1;
    while (y){
        if ((y & 1))
            ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}
ll PAS = 1;
ll n, K;
ll nn;
ll P[N];
int a[N];
ll F[N], inv[N];
ll ans;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> K;
    P[0] = 1;
    F[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= n; i++){
        F[i] = F[i - 1] * i % MOD;
        P[i] = P[i - 1] * (K - 2) % MOD;
        inv[i] = POWER (F[i], MOD - 2);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        if (a[i] == a[i % n + 1]){
            PAS = PAS * K % MOD;
        }
        else {
            nn++;
        }
    }
    ans = 1;
    for (int i = 1; i <= nn; i++)
        ans = ans * K % MOD;
    for (ll m = 0; m * 2 <= nn; m++){
        ll x = P[nn - m * 2] * F[nn] % MOD * inv[m] % MOD * inv[m] % MOD * inv[nn - m * 2] % MOD;
        ans = (ans - x + MOD) % MOD;
    }
    if (ans % 2 == 1)
        ans += MOD;
    ans /= 2;
    ans = ans * PAS % MOD;
    cout << ans << endl;
    return 0;
}