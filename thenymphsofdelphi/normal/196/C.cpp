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

const int N = 1e3 + 5e2 + 5;

int n;
vi adj[N];
pii a[N];

int sz[N];

void dfs_sz(int u, int p){
    sz[u] = 1;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

vi subtree[N];
int ans[N];

void dfs(int u, int p){
    int idx = *max_element(bend(subtree[u]), [&](int i, int j){
        return a[i] < a[j];
    });
    ans[idx] = u;
    subtree[u].erase(find(bend(subtree[u]), idx));
    sort(bend(subtree[u]), [&](int i, int j){
        return (ll)(a[i].se - a[idx].se) * (a[j].fi - a[idx].fi) < (ll)(a[i].fi - a[idx].fi) * (a[j].se - a[idx].se);
    });
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        ForE(i, 1, sz[v]){
            subtree[v].emplace_back(subtree[u].back()); subtree[u].pop_back();
        }
        dfs(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }

    dfs_sz(1, 1);
    subtree[1] = vi(n); iota(bend(subtree[1]), 1);
    dfs(1, 1);
    ForE(i, 1, n){
        cout << ans[i] << ' ';
    } cout << endl;
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