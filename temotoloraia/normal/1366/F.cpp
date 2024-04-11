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

const int N = 2005, INF = 1e12, MOD = 1e9 + 7;

int n, m, Q;

vector < pair < int, int > > G[N];

int A[N], B[N];
int W[N];
int ans;

void gad (){
    for (int i = 1; i <= n; i++){
        B[i] = -INF;
        for (auto it : G[i])
            B[i] = max (B[i], A[it.F] + it.S);
    }
}

int dot (int a, int b, int c, int d){
    return (b - d) / (c - a);
}

pair < int, int > P[N];

bool F[N];

int a[N], b[N], nn;

void solve (int X){
    if (X < 0)
        return;
    sort (P+1, P+n+1);
    for (int i = 1; i <= n; i++){
        a[i] = P[i].F;
        b[i] = P[i].S;
    }
    for (int i = 1; i <= n; i++){
        if (b[i] <= 0)
            continue;
        bool ok = 0;
        for (int j = i+1; j <= n; j++)
            if (b[j] >= b[i])
                ok = 1;
        if (ok)
            continue;
        int L = 0, R = X, dy, dx, x;
        for (int j = 1; j < i; j++){
            if (b[j] <= b[i])
                continue;
            dx = a[i] - a[j];
            dy = b[j] - b[i];
            x = dy / dx + 1;
            L = max (L, x);
        }
        for (int j = i+1; j <= n; j++){
            dx = a[j] - a[i];
            dy = b[i] - b[j];
            x = dy / dx;
            R = min (R, x);
        }
        if (L > R)
            continue;
        ans += (R - L + 1) * (L + R) / 2 % MOD * a[i] % MOD;
        ans += (R - L + 1) * b[i] % MOD;
        ans %= MOD;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> Q;
    for (int u, v, w, i = 0; i < m; i++){
        cin >> u >> v >> w;
        G[u].pb ({v, w});
        G[v].pb ({u, w});
        W[u] = max (W[u], w*2);
        W[v] = max (W[v], w*2);
    }
    for (int i = 2; i <= n; i++)
        A[i] = -INF;
    for (int it = 1; it <= m; it++){
        gad ();
        int mx = 0;
        for (int i = 1; i <= n; i++){
            A[i] = B[i];
            mx = max (mx, A[i]);
            B[i] = 0;
        }
        if (it < m)
            ans = (ans + mx) % MOD;
    }
    gad();
    int aa = (Q - m) / 2;
    int bb = (Q - m + 1) / 2 - 1;
    for (int i = 1; i <= n; i++)
        P[i] = {W[i], A[i]};
    solve (aa);
    for (int i = 1; i <= n; i++)
        P[i] = {W[i], B[i]};
    solve (bb);
    cout << ans << endl;
}