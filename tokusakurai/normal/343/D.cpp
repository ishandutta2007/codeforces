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

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<int> vs; //DFS
    vector<int> ls, rs; //i[ls[i],rs[i])vs[ls[i]] = i
    vector<int> par;
    const int n;
    int m;

    Graph(int n) : es(n), ls(n), rs(n), par(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void euler_tour(int now, int pre = -1){
        ls[now] = vs.size(), vs.push_back(now);
        par[now] = pre;
        for(auto &e: es[now]){
            if(e.to != pre) euler_tour(e.to, now);
        }
        rs[now] = vs.size();
    }
};

template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = v.size();
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(begin(v), end(v), begin(seg)+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i >>= 1){
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }

    Monoid query(int l, int r) const{
        Monoid L = e1, R = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) L = f(L, seg[l++]);
            if(r&1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
 
    Monoid operator [] (int i) const {return seg[n+i];}
 
    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const{
        while(i < n){
            Monoid nxt = type? f(seg[2*i+type], M) : f(M, seg[2*i+type]);
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x) const{
        Monoid L = e1;
        int a = l+n, b = n+n;
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, seg[a]);
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x) const{
        Monoid R = e1;
        int a = n, b = r+n;
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

template<typename T, typename Operator_Monoid>
struct Dual_Segment_Tree{
    using G = function<T(T, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<T> seg;
    vector<Operator_Monoid> lazy;
    const G g;
    const H h;
    const Operator_Monoid e2;

    Dual_Segment_Tree(const vector<T> &v, const G &g, const H &h, const Operator_Monoid &e2) : g(g), h(h), e2(e2){
        int m = v.size();
        n = 1, height = 0;
        while(n < m) n <<= 1, height++;
        lazy.assign(2*n, e2);
        seg = v;
    }

    inline void eval(int i){
        if(i < n && lazy[i] != e2){
            lazy[2*i] = h(lazy[2*i], lazy[i]);
            lazy[2*i+1] = h(lazy[2*i+1], lazy[i]);
            lazy[i] = e2;
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
        while(l < r){
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) r--, lazy[r] = h(lazy[r], x);
            l >>= 1, r >>= 1;
        }
    }

    T get(int i){
        thrust(i+n);
        return g(seg[i], lazy[i+n]);
    }

    T operator [] (int i) {return get(i);}
};

int main(){
    int N; cin >> N;

    Graph G(N);
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }
    G.euler_tour(0);

    auto f = [](int a, int b) {return max(a, b);};
    auto g = [](int a, int b) {return (b == -1? a : b);};
    auto h = [](int a, int b) {return (b == -1? a : b);};
    auto c = [](int a, int b) {return a >= b;};

    Segment_Tree<int> seg1(vector<int>(N, 0), f, -inf);
    Dual_Segment_Tree<int, int> seg2(vector<int>(N, 0), g, h, -1);

    int Q; cin >> Q;

    while(Q--){
        int q, v; cin >> q >> v; v--;
        int l = G.ls[v], r = G.rs[v], p = G.par[v];

        if(q == 1){
            seg2.apply(l, r, 1);
            if(p != -1 && seg1.query(l, r) == 1) seg1.change(G.ls[p], 1);

            while(true){
                int i = seg1.find_first(l, c, 1);
                if(i >= r) break;
                seg1.change(i, 0);
            }
        }
        else if(q == 2){
            seg1.change(l, 1);
        }
        else{
            if(seg1.query(l, r) == 1) cout << "0\n";
            else cout << seg2[l] << '\n';
        }
    }
}