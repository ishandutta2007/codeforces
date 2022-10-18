#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
    int n;
    vector<vector<T>> data;
    Compare cmp;
    T T_id;
    range_minmax_query_solver(){ }
    // O(n log n)
    range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
        for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
            data.emplace_back(n - (p << 1) + 1);
            for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
        }
    }
    // O(1)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        if(l == r) return T_id;
        int d = __lg(r - l);
        return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
    }
};

// Requires graph and range_minmax_query_solver
struct lca_solver{
    int n;
    vector<int> pv, pe, pos, end, depth, order, pos_order;
    range_minmax_query_solver<int> rmq;
    // O(|V| log |V|)
    template<class T>
    lca_solver(const graph<T> &g, const vector<int> &roots): n(g.n), pv(n, -1), pe(n, -1), depth(n), pos(n, -1), end(n, -1){
        int it = 0;
        auto dfs = [&](auto self, int u)->void{
            pos[u] = (int)order.size();
            order.push_back(u), pos_order.push_back(pos[u]);
            for(auto id: g.adj[u]){
                if(id == pe[u] || g.ignore && g.ignore(id)) continue;
                auto &e = g.edge[id];
                int v = u ^ e.from ^ e.to;
                pv[v] = u;
                pe[v] = id;
                depth[v] = depth[u] + 1;
                self(self, v);
                order.push_back(u), pos_order.push_back(pos[u]);
            }
            end[u] = (int)order.size();
        };
        for(auto root: roots) if(!~pos[root]) dfs(dfs, root);
        rmq = {pos_order};
    }
    // assumes u and v are on the same component
    // O(1)
    int lca(int u, int v) const{
        if(u == v) return u;
        tie(u, v) = minmax(pos[u], pos[v]);
        return order[rmq.query(u, v)];
    }
    // assumes u and v are on the same component
    // O(1)
    int steps(int u, int v, int w = -1) const{
        return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
    }
    // O(1)
    bool ancestor_of(int u, int v) const{
        return pos[u] <= pos[v] && end[v] <= end[u];
    }
};

// Requires graph, range_minmax_query_solver, and lca_solver
vector<array<int, 2>> compressed_tree(const lca_solver &ls, const vector<int> &subset){ // build the minimal tree containing all the nodes in O(|subset| log |subset|)
    auto order = subset;
    const auto &p = ls.pos;
    auto cmp = [&](int u, int v){ return p[u] < p[v]; };
    sort(order.begin(), order.end(), cmp);
    for(auto i = 1, sz = (int)order.size(); i < sz; ++ i) order.push_back(ls.lca(order[i - 1], order[i]));
    sort(order.begin(), order.end(), cmp), order.erase(unique(order.begin(), order.end()), order.end());
    vector<array<int, 2>> edge;
    for(auto i = 1; i < (int)order.size(); ++ i) edge.push_back({ls.lca(order[i - 1], order[i]), order[i]});
    return edge;
}

int n, k;
graph <int> g(1);
lca_solver lca(g, {0});

struct cmp_t{
    bool operator()(int u, int v) const{
        return lca.pos[u] < lca.pos[v];
    }
};

multiset <int, cmp_t> mts;
set <int, cmp_t> stt;

int insert_mts(int u){
    // cout << "INSERT_MTS " << u << endl;
    int ans = 0;
    auto itr = mts.lower_bound(u);
    if (itr != mts.begin()){
        ans += lca.steps(lca.lca(*prev(itr), u), u);
    }
    if (itr != mts.end()){
        ans += lca.steps(lca.lca(u, *itr), *itr);
    }
    if (itr != mts.begin() and itr != mts.end()){
        ans -= lca.steps(lca.lca(*prev(itr), *itr), *itr);
    }
    mts.insert(u);
    // cout << "INSERT_MTS " << u << ' ' << ans << endl;
    return ans;
}

int erase_mts(int u){
    // cout << "ERASE_MTS " << u << endl;
    int ans = 0;
    auto itr = mts.find(u);
    if (itr != mts.begin()){
        ans -= lca.steps(lca.lca(*prev(itr), u), u);
    }
    if (next(itr) != mts.end()){
        ans -= lca.steps(lca.lca(u, *next(itr)), *next(itr));
    }
    if (itr != mts.begin() and next(itr) != mts.end()){
        ans += lca.steps(lca.lca(*prev(itr), *next(itr)), *next(itr));
    }
    mts.erase(itr);
    // cout << "ERASE_MTS " << u << ' ' << ans << endl;
    return ans;
}

int insert_stt(int u){
    int ans = 0;
    auto itr = stt.lower_bound(u);
    if (itr != stt.begin()){
        ans += insert_mts(lca.lca(*prev(itr), u));
    }
    if (itr != stt.end()){
        ans += insert_mts(lca.lca(u, *itr));
    }
    if (itr != stt.begin() and itr != stt.end()){
        ans += erase_mts(lca.lca(*prev(itr), *itr));
    }
    ans += insert_mts(u);
    stt.insert(u);
    return ans;
}

int erase_stt(int u){
    int ans = 0;
    auto itr = stt.find(u);
    if (itr != stt.begin()){
        ans += erase_mts(lca.lca(*prev(itr), u));
    }
    if (next(itr) != stt.end()){
        ans += erase_mts(lca.lca(u, *next(itr)));
    }
    if (itr != stt.begin() and next(itr) != stt.end()){
        ans += insert_mts(lca.lca(*prev(itr), *next(itr)));
    }
    ans += erase_mts(u);
    stt.erase(itr);
    return ans;
}

int ans, sum;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    g = graph <int>(n);
    For(i, 1, n){
        int u, v; cin >> u >> v; u--; v--;
        g.link(u, v);
    }

    lca = lca_solver(g, {0});
    int l = 0;
    For(r, 0, n){
        sum += insert_stt(r);
        // cout << "SUM " << l << ' ' << r << ' ' << sum << endl;
        // Fora(u, mts){
        //     cout << u << ' ';
        // } cout << endl;
        // Fora(u, stt){
        //     cout << u << ' ';
        // } cout << endl;
        while (sum + 1 > k){
            sum += erase_stt(l);
            l++;
            // cout << "SUM " << l << ' ' << r << ' ' << sum << endl;
            // Fora(u, mts){
            //     cout << u << ' ';
            // } cout << endl;
            // Fora(u, stt){
            //     cout << u << ' ';
            // } cout << endl;
        }
        ans = max(ans, r - l + 1);
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