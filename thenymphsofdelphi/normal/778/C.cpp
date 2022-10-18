#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 6e5 + 5, M = 26;

int n;
int nxt[N][M];

int a[N], par[N], h[N];
int sz[N], heavy[N];

void dfs1(int u){
    sz[u] = 1;
    For(i, 0, M){
        if (nxt[u][i] == 0){
            continue;
        }
        int v = nxt[u][i];
        par[v] = u; h[v] = h[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
        if (heavy[u] == 0 or sz[heavy[u]] < sz[v]){
            heavy[u] = v;
        }
    }
}

int val[N];

int timeline[N];
int cntused, ctrused;
int nxt2[N][M];

void dfs2_insert(int u, int uu, int tim){
    if (timeline[uu] != tim){
        timeline[uu] = tim;
        For(i, 0, M){
            nxt2[uu][i] = nxt[uu][i];
        }
    }
    For(i, 0, M){
        if (nxt[u][i] == 0){
            continue;
        }
        int v = nxt[u][i];
        if (nxt2[uu][a[v]] == 0){
            nxt2[uu][a[v]] = ctrused++; cntused++;
        }
        dfs2_insert(v, nxt2[uu][a[v]], tim);
    }
}

void dfs_mergeset(int u){
    For(i, 0, M){
        if (nxt[u][i] == 0){
            continue;
        }
        int v = nxt[u][i];
        dfs_mergeset(v);
    }

    cntused = 0; ctrused = N / 2;
    if (heavy[u] != 0){
        cntused += sz[heavy[u]];
    }
    For(i, 0, M){
        if (nxt[u][i] == 0){
            continue;
        }
        int v = nxt[u][i];
        if (v != heavy[u]){
            dfs2_insert(v, heavy[u], u);
        }
    }

    val[u] = (heavy[u] == 0 ? 0 : cntused - 1);
}

int ans[N];
int ans1 = N, ans2;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; char c; cin >> u >> v >> c;
        int w = c - 'a';
        nxt[u][w] = v; a[v] = w;
    }

    dfs1(1);
    dfs_mergeset(1);
    For(h, 1, N){
        ans[h] = n;
    }
    ForE(u, 1, n){
        ans[h[u]] -= sz[u]; ans[h[u] + 1] += val[u];
    }
    For(h, 1, N){
        if (ans1 > ans[h]){
            ans1 = ans[h];
            ans2 = h;
        }
    }
    cout << ans1 << endl << ans2 << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/