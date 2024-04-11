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
#define int long long

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/
using namespace std;

const int N = 200005, MOD = 998244353;

ll POWER (ll a, ll b){
    ll ans = 1;
    while (b){
        if ((b & 1))
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

ll C (ll n, ll m){
    ll k = n - m;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * i % MOD;
    for (int i = 1; i <= m; i++)
        ans = ans * POWER (i, MOD - 2) % MOD;
    for (int i = 1; i <= k; i++)
        ans = ans * POWER (i, MOD - 2) % MOD;
    return ans;
}

int n, m;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    if (n == 2){
        cout << 0 << endl;
        return 0;
    }
    cout << C (m, n - 1) * (n - 2) % MOD * POWER (2, n - 3) % MOD << endl;
}