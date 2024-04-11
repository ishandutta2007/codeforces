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

const ll N = 200005, MOD = 1e9 + 7;

ll n;

ll a[N];

vector < ll > v[N];

ll B[10000];

vector < ll > g[N];

ll D[N];

ll par[N];

queue < ll > Q;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    reverse (a + 1, a + n + 1);
    if (a[1] == 0){
        cout << -1 << endl;
        return 0;
    }
    while (a[n] == 0)
        n--;
    B[0] = 1;
    for (ll i = 1; i <= 60; i++)
        B[i] = B[i - 1] + B[i - 1];
    for (ll i = 1; i <= n; i++){
        for (ll j = 0; j <= 60; j++)
            if ((a[i] & B[j]) > 0)
                v[j].pb (i);
    }
    for (ll j = 0; j <= 60; j++)
    if ((ll)v[j].size() >= 3){
        cout << 3 << endl;
        return 0;
    }
    for (ll i = 0; i <= 60; i++){
        if ((ll)v[i].size() <= 1)
            continue;
        ll U = v[i][0], V = v[i][1];
        g[U].pb (V);
        g[V].pb (U);
    }
    ll ans = n + 10;
    for (ll I = 1; I <= n; I++){
        for (ll i = 1; i <= n; i++){
            D[i] = n + 1000;
            par[i] = 0;
        }
        D[I] = 0;
        while (Q.size() > 0)
            Q.pop();
        Q.push (I);
        while (Q.size() > 0){
            ll k = Q.front();
            Q.pop();
            for (ll to : g[k]){
                if (D[to] > D[k] + 1){
                    D[to] = D[k] + 1;
                    par[to] = k;
                    Q.push (to);
                }
            }
        }
        for (ll i = 1; i <= n; i++){
            if (D[i] > n)
                continue;
            for (ll j : g[i]){
                ll U = i, V = j;
                if (par[U] == V || par[V] == U)
                    continue;
                ans = min (ans, D[U] + D[V] + 1);
            }
        }
    }
    if (ans > n)
        ans = -1;
    cout << ans << endl;
    return 0;
}