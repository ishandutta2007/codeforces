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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5, M = 2e6 + 5;

int lpf[M];
vi prime;

void sieve(){
    For(i, 2, M){
        if (!lpf[i]){
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < isz(prime) && prime[j] <= i && prime[j] * i < M; j++){
            lpf[prime[j] * i] = prime[j];
        }
    }
}

struct Query{
    int u, idx;
    
    Query(int u = 0, int idx = 0): u(u), idx(idx){
        
    }
};

int n, q;
int a[N];
vi adj[N];
int h[N];

int ans[N];
vector <Query> queries;
vi queries2[N];
int b[M];

void dfs1(int u, int p){
    h[u] = h[p] + 1;
    int x = a[u], tans = -1;
    vi oldb;
    while (x != 1){
        int y = lpf[x];
        while (lpf[x] == y){
            x /= y;
        }
        oldb.push_back(b[y]);
        if (b[y]){
            if (tans == -1){
                tans = b[y];
            }
            else{
                if (h[tans] < h[b[y]]){
                    tans = b[y];
                }
            }
        }
        b[y] = u;
    }
    reverse(bend(oldb));
    Fora(&query, queries2[u]){
        ans[query] = tans;
    }
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs1(v, u);
    }
    x = a[u];
    while (x != 1){
        int y = lpf[x];
        while (lpf[x] == y){
            x /= y;
        }
        b[y] = oldb.back(); oldb.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    sieve();
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ForE(i, 1, q){
        int type; cin >> type;
        if (type == 1){
            int u; cin >> u;
            queries.emplace_back(u, i);
            queries2[u].emplace_back(i);
        }
        else{
            int u, w; cin >> u >> w;
            dfs1(1, 1);
            a[u] = w;
            Fora(&query, queries){
                queries2[query.u].clear();
            }
            queries.clear();
        }
    }
    dfs1(1, 1);
    ForE(i, 1, q){
        if (ans[i]){
            cout << ans[i] << endl;
        }
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