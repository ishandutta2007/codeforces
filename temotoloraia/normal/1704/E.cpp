#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 300005, MOD = 998244353, INF = 1e11;

int n, m;
int a[N];
vector < int > g[N];
bool fix[N], F[N];
vector < int > V;

void dfs (int k){
    F[k] = 1;
    for (int to : g[k]){
        if (F[to] == 0)
            dfs (to);
    }
    V.pb (k);
}


void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--){
        int u, v;
        cin >> u >> v;
        fix[u] = 1;
        g[v].pb (u);
    }
    V.clear();
    for (int i = 1; i <= n; i++){
        if (fix[i] == 0){
            dfs (i);
            break;
        }
    }
    reverse (V.begin(), V.end());
    /*for (int x : V)
        cout << x << " ";
    cout << endl;*/
    int ans = 0;
    for (int cnt = 0; cnt < n; cnt++){
        bool ok = 1;
        for (int x : V){
            if (a[x]){
                a[x]--;
                ok = 0;
            }
            for (int y : g[x])
                if (a[y])
                    a[x]++;
        }
        if (ok)
            break;
        ans++;
    }
    for (int i = n-1; i >= 0; i--){
        int x = V[i];
        for (int y : g[x])
            a[x] += a[y];
        a[x] %= MOD;
    }
    cout << (ans + a[V[0]])%MOD << endl;
    for (int i = 0; i <= n; i++){
        g[i].clear();
        fix[i] = 0;
        F[i] = 0;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}