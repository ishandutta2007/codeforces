#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// source: Atcoder Library https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// docs: https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html
namespace atcoder{

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S,
        S (*op)(S, S),
        S (*e)(),
        class F,
        S (*mapping)(F, S),
        F (*composition)(F, F),
        F (*id)()>
struct lazy_segtree {
public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}

int find_par(vi &parent, int u){
    if(parent[u] == u) return u;
    return parent[u] = find_par(parent, parent[u]);
}

void merge(vi &parent, int u, int v){
    int x = find_par(parent, u);
    int y = find_par(parent, v);
    parent[x] = y;
}

void lca_dfs(vvi &adj, vi &tour, vi &dis, vi &fin, int u, vi &vis, vi &depth, vi &par){
    vis[u] = 1;
    dis[u] = tour.size();
    tour.push_back(u);
    for(int v : adj[u]){
        if(vis[v]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        lca_dfs(adj, tour, dis, fin, v, vis, depth, par);
        tour.push_back(u);
    }
    fin[u] = tour.size() - 1;
}

// namespace sf{
//     using S = int;
//     S op(S a, S b) { return max(a, b); }
//     S e() { return 0; }
//     using F = int;
//     S mapping(F f, S x) { return f + x; }
//     F composition(F f, F g) { return f + g; }
//     F id() { return 0; }
// }

// using TreeMax = atcoder::lazy_segtree<sf::S, sf::op, sf::e, sf::F, sf::mapping, sf::composition, sf::id>;

namespace sg{
    using S = int;
    S op(S a, S b) { return min(a, b); }
    S e() { return 1e9; }
    using F = int;
    S mapping(F f, S x) { return f + x; }
    F composition(F f, F g) { return f + g; }
    F id() { return 0; }
}

using TreeMin = atcoder::lazy_segtree<sg::S, sg::op, sg::e, sg::F, sg::mapping, sg::composition, sg::id>;


void add_subtree(TreeMin &t, vi &dis, vi &fin, int u, int val){
    t.apply(dis[u], fin[u] + 1, val);
}

const int B = 20;

int ancestor(vvi &lift, int layers, int u){
    for(int i = B-1; i >= 0; i--){
        if(layers >= (1 << i)){
            layers -= (1 << i);
            u = lift[i][u];
        }
    }
    return u;
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    // dsu to find tree-edges
    vvi tree_adj(n);
    vpii other_edges;
    vi parent(n);
    iota(parent.begin(), parent.end(), 0);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(find_par(parent, x) == find_par(parent, y)){
            other_edges.push_back({x, y});
        }else{
            tree_adj[x].push_back(y);
            tree_adj[y].push_back(x);
            merge(parent, x, y);
        }
    }

    debug(tree_adj, other_edges);

    int root = 0; // TODO change back

    // lca and euler tour
    vi tour, dis(n), fin(n), vis(n), depth(n), par(n, root);
    lca_dfs(tree_adj, tour, dis, fin, root, vis, depth, par);
    debug(tour);
    debug(dis);
    debug(fin);

    // binary lift
    vvi lift(B, vi(n));
    for(int i = 0; i < n; i++){
        lift[0][i] = par[i];
    }
    for(int i = 1; i < B; i++){
        for(int j = 0; j < n; j++){
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    vi tour_depths;
    for(int u : tour){
        tour_depths.push_back(depth[u]);
    }
    debug(tour_depths);

    TreeMin values(tour.size());
    for(int i = 0; i < tour.size(); i++) values.set(i, 0);
    TreeMin depths(tour_depths);

    for(pii edge : other_edges){
        int u, v;
        tie(u, v) = edge;
        // for(int i = 0; i < tour.size(); i++){
        //     debug(i, depths.get(i));
        // }
        int lca_depth = depths.prod(min(dis[u], dis[v]), max(dis[u], dis[v]) + 1);
        debug(u, v, dis[u], dis[v], lca_depth);
        if(lca_depth < depth[u] && lca_depth < depth[v]){
            debug(u, v, "cross");
            // cross edge
            add_subtree(values, dis, fin, root, 1);
            add_subtree(values, dis, fin, u, -1);
            add_subtree(values, dis, fin, v, -1);
        }else{
            // forward edge
            int delta = abs(depth[u] - depth[v]);
            if(depth[u] < depth[v]){
                debug(u, v, "forward u->v", ancestor(lift, delta - 1, v));
                add_subtree(values, dis, fin, ancestor(lift, delta - 1, v), 1);
                add_subtree(values, dis, fin, v, -1);
                // values.apply(dis[u], -1);
            }else{
                debug(u, v, "forward v->u", ancestor(lift, delta - 1, u));
                add_subtree(values, dis, fin, ancestor(lift, delta - 1, u), 1);
                add_subtree(values, dis, fin, u, -1);
                // values.apply(dis[v], -1);
            }
        }
    }
    // for(int i = 0; i < tour.size(); i++){
    //     debug(i, values.get(i));
    // }

    for(int i = 0; i < n; i++){
        cout << (values.get(dis[i]) == 0 ? '1' : '0');
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}