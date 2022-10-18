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

const int N = 1e5 + 5, M = 1e5;

struct line_type{
    long long d, k;
    line_type(long long d = 0, long long k = numeric_limits<long long>::min() / 2): d(d), k(k){ }
    long long eval(long long x){ return d * x + k; }
    bool majorize(line_type X, long long L, long long R){ return eval(L) >= X.eval(L) && eval(R) >= X.eval(R); }
};
template<bool GET_MAX = false>
struct lichao{
    lichao *l = 0, *r = 0;
    line_type S;
    lichao(): S(line_type()){ }
    ~lichao(){
        delete l;
        delete r;
    }
    void mc(int i){
        if(i){ if(!r) r = new lichao(); }
        else{ if(!l) l = new lichao(); }
    }
    long long pq(long long X, long long L, long long R){
        long long ans = S.eval(X), M = (L + R) / 2;
        if(X < M) return max(ans, l ? l->pq(X, L, M) : -(long long)9e18);
        else return max(ans, r ? r->pq(X, M, R) : -(long long)9e18);
    }
    long long query(long long X, long long L, long long R){
        return pq(X, L, R) * (GET_MAX ? 1 : -1);
    }
    void pp(line_type X, long long L, long long R){
        if(X.majorize(S, L, R)) swap(X, S);
        if(S.majorize(X, L, R)) return;
        if(S.eval(L) < X.eval(L)) swap(X, S);
        long long M = (L + R) / 2;
        if(X.eval(M) > S.eval(M)) swap(X, S), mc(0), l->pp(X, L, M);
        else mc(1), r->pp(X, M, R);
    }
    void push(line_type X, long long L, long long R){
        if(!GET_MAX) X.d = -X.d, X.k = -X.k;
        pp(X, L, R);
    }
};

lichao<0>* cac = new lichao<0>;

int n;
int a[N], b[N];
vi adj[N];
ll dp[N];

int sz[N];
int ctrtour, tour[N], tin[N], tout[N];

void dfs_tour(int u, int p){
    sz[u] = 1;
    tour[++ctrtour] = u;
    tin[u] = ctrtour;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_tour(v, u);
        sz[u] += sz[v];
    }
    tout[u] = ctrtour;
}

void dfs_merge(int u, int p, bool keep = 0){
    int heavy = 0;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        if (!heavy or sz[v] > sz[heavy]){
            heavy = v;
        }
    }
    Fora(&v, adj[u]){
        if (v == p or v == heavy){
            continue;
        }
        dfs_merge(v, u);
    }
    if (heavy){
        dfs_merge(heavy, u, 1);
    }
    Fora(&v, adj[u]){
        if (v == p or v == heavy){
            continue;
        }
        ForE(i, tin[v], tout[v]){
            int w = tour[i];
            cac->push(line_type(b[w], dp[w]), -M, M);
        }
    }
    dp[u] = (sz[u] == 1 ? 0 : cac->query(a[u], -M, M));
    cac->push(line_type(b[u], dp[u]), -M, M);
    if (!keep){
        delete cac;
        cac = new lichao<0>;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    dfs_tour(1, 1);
    dfs_merge(1, 1);
    ForE(i, 1, n){
        cout << dp[i] << ' ';
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