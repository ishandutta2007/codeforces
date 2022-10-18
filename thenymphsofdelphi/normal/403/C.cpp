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

const int N = 5e3 + 5;

template<class T>
struct graph{
    struct E{
        int from, to;
        T cost;
    };
    int n;
    vector<E> edge;
    vector<vector<int>> adj;
    function<bool(int)> ignore;
    graph(int n): n(n), adj(n){ }
    int link(int u, int v, T w = {}){ // insert an undirected edge
        int id = (int)edge.size();
        adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
        return id;
    }
    int orient(int u, int v, T w = {}){ // insert a directed edge
        int id = (int)edge.size();
        adj[u].push_back(id), edge.push_back({u, v, w});
        return id;
    }
    graph transposed() const{ // the transpose of the directed graph
        graph res(n);
        for(auto &e: edge) res.orient(e.to, e.from, e.cost);
        res.ignore = ignore;
        return res;
    }
    int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
        return (int)adj[u].size();
    }
    vector<vector<int>> get_adjacency_list() const{
        vector<vector<int>> res(n);
        for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
            if(ignore && ignore(id)) continue;
            auto &e = edge[id];
            int v = u ^ e.from ^ e.to;
            res[u].push_back(v);
        }
        return res;
    }
    void set_ignoration_rule(const function<bool(int)> &f){
        ignore = f;
    }
    void reset_ignoration_rule(){
        ignore = nullptr;
    }
};

// Requires graph
// O(|V| + |E|)
template<class T>
void strongly_connected_components(const graph<T> &g, auto act_comp){
    int n = g.n, it = 0, ncomps = 0, v;
    vector<int> val(n), comp(n, -1), s, cur;
    auto dfs = [&](auto self, int u)->int{
        int low = val[u] = ++ it;
        s.push_back(u);
        for(auto id: g.adj[u]){
            if(g.ignore && g.ignore(id)) continue;
            auto &e = g.edge[id];
            int v = u ^ e.from ^ e.to;
            if(comp[v] < 0) low = min(low, val[v] ?: self(self, v));
        }
        if(low == val[u]){
            do{
                v = s.back(); s.pop_back();
                comp[v] = ncomps;
                cur.push_back(v);
            }while(v != u);
            act_comp(cur); // Process the component
            cur.clear();
            ++ ncomps;
        }
        return val[u] = low;
    };
    for(auto u = 0; u < n; ++ u) if(comp[u] < 0) dfs(dfs, u);
} // accesses sccs in the reverse topological order

int cnt;
auto act_comp = [&cnt](vi cur){ cnt++; return; };

int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    graph <int> g(2 * n);
    For(i, 0, n){
        For(j, 0, n){
            int x; cin >> x;
            if (x){
                if (i == j){
                    g.link(i, i + n);
                }
                else{
                    g.orient(i, j);
                    g.orient(i + n, j + n);
                }
            }
        }
    }
    strongly_connected_components(g, act_comp);
    if (cnt == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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