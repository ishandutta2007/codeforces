#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
//#define int __int128
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

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 200005, MOD = 998244353;

int n;
vector < int > g[N];
int a[N];
int x[N];
int ans;

void dfs (int k, int p){
    int A = 0, B = 0;
    if (x[k] >= 0)
        A += x[k];
    else
        B += -x[k];
    for (int to : g[k]){
        if (to == p)
            continue;
        a[to] = min (a[to], a[k]);
        dfs (to, k);
        if (x[to] >= 0)
            A += x[to];
        else
            B -= x[to];
    }
    x[k] = A - B;
    ans += min (A, B) * a[k] * 2;
}

void solve () {
    cin >> n;
    for (int p, q, i = 1; i <= n; i++){
        x[i] = 0;
        cin >> a[i];
        cin >> p >> q;
        x[i] = q - p;
        ans += x[i];
    }
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    if (ans){
        cout << -1 << endl;
        return;
    }
    dfs (1, 0);
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}