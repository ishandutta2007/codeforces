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


const ll N = 2e5 + 5, MOD = 1e9 + 7;

int n;
ll PO[N];
ll a[N];
ll ans;
vector < int > g[N];
ll D[N];

ll P[N][20], G[N][20];

void dfs (int k, int p){
    P[k][0] = p;
    G[k][0] = a[k];
    D[k] = D[p] + 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    PO[0] = 1;
    for (int i = 1; i < 40; i++)
        PO[i] = PO[i - 1] + PO[i - 1];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    for (int I = 1; I <= 19; I++)
        for (int i = 1; i <= n; i++){
            P[i][I] = P[P[i][I - 1]][I - 1];
            G[i][I] = __gcd (G[i][I - 1], G[P[i][I - 1]][I - 1]);
        }
    for (int k = 1; k <= n; k++){
        int p = k;
        ll x = a[k];
        while (p){
            ll de = D[p];
            for (int i = 19; i >= 0; i--){
                if (PO[i] > D[p])
                    continue;
                if (x == 0){
                    if (G[p][i] == 0)
                    p = P[p][i];
                    continue;
                }
                if (G[p][i] % x == 0)
                    p = P[p][i];
            }
            ans += (de - D[p]) * x % MOD;
            ans %= MOD;
            x = __gcd (x, G[p][0]);
            //p = P[k][0];
        }
    }
    cout << ans << endl;
    return 0;
}