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

const int N = 1e5 + 5;

struct disjoint_set_union{
    int par[N];

    void reset(){
        memset(par, -1, sizeof(par));
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    bool merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return 0;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} dsu;

int n, m, k;
vpii adj[N];
bool a[N];

ll dist[N]; int near[N];
template <class T>
using minimum_heap = priority_queue <T, vector <T>, greater <T>>;
minimum_heap <pair <ll, int>> pq;

vector <tuple <ll, int, int>> b;
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    cin >> k;
    ForE(i, 1, k){
        int u; cin >> u; a[u] = 1;
    }

    memset(dist, 0x3f, sizeof(dist));
    ForE(u, 1, n){
        if (a[u]){
            dist[u] = 0; near[u] = u;
            pq.emplace(dist[u], u);
        }
    }
    while (!pq.empty()){
        ll d; int u; tie(d, u) = pq.top(); pq.pop();
        if (d != dist[u]){
            continue;
        }
        Fora(&edge, adj[u]){
            int v, w; tie(v, w) = edge;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w; near[v] = near[u];
                pq.emplace(dist[v], v);
            }
        }
    }
    ForE(u, 1, n){
        Fora(&edge, adj[u]){
            int v, w; tie(v, w) = edge;
            if (u > v){
                continue;
            }
            b.emplace_back(dist[u] + dist[v] + w, near[u], near[v]);
        }
    }
    sort(bend(b));
    dsu.reset();
    Fora(&edge, b){
        if (dsu.merge(get<1>(edge), get<2>(edge))){
            ans += get<0>(edge);
        }
    }
    if (!a[1]){
        ans += dist[1];
    }
    cout << ans << endl;
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