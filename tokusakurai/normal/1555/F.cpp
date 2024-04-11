#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

struct Union_Find_Tree{
    vector<int> data;
    const int n;
    
    Union_Find_Tree(int n) : data(n, -1), n(n) {}
    
    int root(int x){
        if(data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator [] (int i) {return root(i);}
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        return true;
    }
    
    int size(int x) {return -data[root(x)];}
    
    bool same(int x, int y) {return root(x) == root(y);}
    
    void clear() {fill(begin(data), end(data), -1);}
};

template<typename Monoid, typename Operator_Monoid>
struct Lazy_Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<Monoid> seg;
    vector<Operator_Monoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e1;
    const Operator_Monoid e2;
    
    Lazy_Segment_Tree(const vector<Monoid> &v, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2)
        : f(f), g(g), h(h), e1(e1), e2(e2){
        int m = v.size();
        n = 1, height = 0;
        while(n < m) n <<= 1, height++;
        seg.assign(2*n, e1), lazy.assign(2*n, e2);
        copy(begin(v), end(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    Lazy_Segment_Tree(int m, const Monoid &x, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2)
        : f(f), g(g), h(h), e1(e1), e2(e2){
        n = 1, height = 0;
        while(n < m) n <<= 1, height++;
        seg.assign(2*n, e1), lazy.assign(2*n, e2);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    inline Monoid reflect(int i) const{
        return (lazy[i] == e2? seg[i] : g(seg[i], lazy[i]));
    }

    inline void recalc(int i){
        while(i >>= 1) seg[i] = f(reflect(2*i), reflect(2*i+1));
    }

    inline void eval(int i){
        if(i < n && lazy[i] != e2){
            lazy[2*i] = h(lazy[2*i] ,lazy[i]);
            lazy[2*i+1] = h(lazy[2*i+1], lazy[i]);
            seg[i] = reflect(i), lazy[i] = e2;
        }
    }

    inline void thrust(int i){
        for(int j = height; j > 0; j--) eval(i>>j);
    }
    
    void apply(int l, int r, const Operator_Monoid &x){
        l = max(l, 0), r = min(r, n);
        if(l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r-1);
        int a = l, b = r;
        while(l < r){
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) r--, lazy[r] = h(lazy[r], x); 
            l >>= 1, r >>= 1;
        }
        recalc(a), recalc(b-1);
    }
    
    Monoid query(int l, int r){
        l = max(l, 0), r = min(r, n);
        if(l >= r) return e1;
        l += n, r += n;
        thrust(l), thrust(r-1);
        Monoid L = e1, R = e1;
        while(l < r){
            if(l&1) L = f(L, reflect(l++));
            if(r&1) R = f(reflect(--r), R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator [] (int i) {return query(i, i+1);}

    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type){
        while(i < n){
            eval(i);
            Monoid nxt = type? f(reflect(2*i+type), M) : f(M, reflect(2*i+type));
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x){
        Monoid L = e1;
        int a = l+n, b = n+n;
        thrust(a);
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, reflect(a));
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x){
        Monoid R = e1;
        int a = n, b = r+n;
        thrust(b-1);
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(reflect(--b), R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

auto f = [](int a, int b) {return max(a, b);};
auto g = [](int a, int b) {return max(a, b);};
auto h = [](int a, int b) {return max(a, b);};

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> par, si, depth;
    vector<int> root, comp; //
    vector<vector<int>> ids;
    vector<int> ls;
    Lazy_Segment_Tree<int, int> seg;

    Graph(int n) : es(n), n(n), m(0), par(n), si(n), depth(n), root(n, -1), comp(n), ids(n), ls(n, 0), seg(n, 0, f, g, h, 0, 0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    int dfs1(int now, int pre = -1){
        par[now] = pre;
        if(pre == -1) depth[now] = 0;
        si[now] = 1;
        for(auto &e: es[now]){
            if(e.to != pre){
                depth[e.to] = depth[now]+1;
                si[now] += dfs1(e.to, now);
            }
        }
        return si[now];
    }

    void dfs2(int now, bool st, int pre = -1){
        if(st) root[now] = now, comp[now] = 0;
        else root[now] = root[pre], comp[now] = comp[pre]+1;
        ids[root[now]].push_back(now);
        int c = -1, M = 0;
        for(auto &e: es[now]){
            if(e.to == pre) continue;
            if(M < si[e.to]) M = si[e.to], c = e.to;
        }
        for(auto &e: es[now]){
            if(e.to != pre) dfs2(e.to, c != e.to, now);
        }
    }

    void decompose(){
        rep(i, n){
            if(root[i] == -1){
                dfs1(i), dfs2(i, true);
            }
        }
        rep2(i, 1, n-1) ls[i] = ls[i-1]+sz(ids[i-1]);
    }

    vector<tuple<int, int, int>> find_path(int u, int v){ //()
        vector<tuple<int, int, int>> ret;
        while(root[u] != root[v]){
            if(depth[root[u]] > depth[root[v]]) swap(u, v);
            ret.emplace_back(root[v], 0, comp[v]+1);
            v = par[root[v]];
        }
        if(depth[u] > depth[v]) swap(u, v);
        ret.emplace_back(root[u], comp[u]+1, comp[v]+1);
        return ret;
    }

    int path_query(int u, int v){
        int ret = 0;
        each(e, find_path(u, v)){
            auto [i, l, r] = e;
            chmax(ret, seg.query(ls[i]+l, ls[i]+r));
        }
        return ret;
    }

    void path_update(int u, int v){
        each(e, find_path(u, v)){
            auto [i, l, r] = e;
            seg.apply(ls[i]+l, ls[i]+r, 1);
        }
    }
};

int main(){
    int N, M; cin >> N >> M;

    vector<int> u(M), v(M), w(M);
    vector<bool> used(M, false);
    Union_Find_Tree uf(2*N);
    Graph G(N);

    rep(i, M){
        cin >> u[i] >> v[i] >> w[i]; u[i]--, v[i]--;
        if(uf.same(u[i], v[i]) || uf.same(u[i], N+v[i])) continue;

        used[i] = true;
        if(w[i]){
            uf.unite(u[i], N+v[i]), uf.unite(N+u[i], v[i]);
        }
        else{
            uf.unite(u[i], v[i]), uf.unite(N+u[i], N+v[i]);
        }

        G.add_edge(u[i], v[i]);
    }

    G.decompose();
    
    rep(i, M){
        if(used[i]){
            cout << "YES\n";
            continue;
        }

        if(uf.same(u[i], N*w[i]+v[i]) || G.path_query(u[i], v[i])){
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        G.path_update(u[i], v[i]);
    }
}