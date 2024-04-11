#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

struct fenwick_tree{
    int bit[N];
    int n;

    fenwick_tree(int n = 0){
        this->n = n + 1;
        memset(bit, 0, sizeof(bit));
    }

    int sum(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta){
        for (; idx <= n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
};

int n, m = 100000, q;
int a[N];
vi adj[N];
vpii vquery[N];
int ans[N];

int ctrtin, tin[N], tout[N], invtin[N];
int sz[N];

void dfs1(int u, int p){
    tin[u] = ++ctrtin; invtin[ctrtin] = u;
    sz[u] = 1;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
    }
    tout[u] = ctrtin;
}

int cnt[N];
fenwick_tree bit(m + 1);

inline void add(int u, int val){
    bit.add(cnt[a[u]], -1);
    cnt[a[u]] += val;
    bit.add(cnt[a[u]], 1);
}

void dfs2(int u, int p, bool keep){
    int heavy = -1;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        if (heavy == -1 or sz[v] > sz[heavy]){
            heavy = v;
        }
    }
    Fora(&v, adj[u]){
        if (v == p or v == heavy){
            continue;
        }
        dfs2(v, u, 0);
    }
    if (heavy != -1){
        dfs2(heavy, u, 1);
    }
    Fora(&v, adj[u]){
        if (v == p or v == heavy){
            continue;
        }
        ForE(i, tin[v], tout[v]){
            add(invtin[i], 1);
        }
    }
    add(u, 1);
    Fora(&query, vquery[u]){
        ans[query.se] = bit.sum(query.fi, m);
    }
    if (!keep){
        ForE(i, tin[u], tout[u]){
            int v = invtin[i];
            add(v, -1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(u, 1, n){
        cin >> a[u];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    ForE(i, 1, q){
        int u, k; cin >> u >> k; k++;
        vquery[u].emplace_back(k, i);
    }
    dfs1(1, 1);
    ForE(i, 1, m){
        cnt[i] = 1;
        bit.add(cnt[i], 1);
    }
    dfs2(1, 1, 1);
    ForE(i, 1, q){
        cout << ans[i] << endl;
    }
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