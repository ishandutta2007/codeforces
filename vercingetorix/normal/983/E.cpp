#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
#ifdef LOCAL
const int MAXN = 100;
#else
const int MAXN = 200500;
#endif
int lev[MAXN];
pi veri[MAXN];
int n;
int tin[MAXN];
int tout[MAXN];
int timer;
//int l;
//vector<int> tin, tout;
//int timer;
//vector < vector<int> > up;
vvi g;
//
void dfs1 (int v, int p = 0) {
    tin[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tout[v] = timer-1;
}
//
//bool upper (int a, int b) {
//    return tin[a] <= tin[b] && tout[a] >= tout[b];
//}
//
//int lca (int a, int b) {
//    if (upper (a, b))  return a;
//    if (upper (b, a))  return b;
//    for (int i=l; i>=0; --i)
//        if (! upper (up[a][i], b))
//            a = up[a][i];
//    return up[a][0];
//}
const int INF = 1e9;
const pi PINF = mp(INF, 0);

template<int size, int lg, typename seg_t = pi>
struct hld {
    vector<int> edges[size];
    int bigchild[size];
    int sz[size];
    int depth[size];
    int chain[size];
    int label[size], label_time;
    int par[size];
    
    int lca_lift[size][lg];
    
    seg_t seg_tree[4 * size];
    seg_t seg_lazy[4 * size];
    
    int N;
    
    /* ----------- segment tree ----------- */
    
    /* CHANGE THIS SECTION BY PROBLEM */
    inline seg_t seg_combine(seg_t a, seg_t b) {
//        return a ^ b;
        return min(a,b);
    }
    
    inline seg_t seg_lazy_apply(seg_t lazy_val, seg_t new_val) {
        return min(lazy_val, new_val);
//        return new_val;
//        lazy_val = min(lazy_val, new_val);
//        return lazy_val;
    }
    
    inline seg_t seg_lazy_func(seg_t cur_val, seg_t lazy_val, int l, int r) {
        return min(lazy_val, cur_val);
//        cur_val = min(cur_val, lazy_val);
//        return lazy_val;
    }
    
    const seg_t seg_sentinel = PINF;
    const seg_t seg_lazy_sentinel = PINF;
    const seg_t seg_init_val = PINF;
    /* END SECTION */
    
    seg_t seg_query_header(int l, int r) {
        return seg_query_rec(0, 0, N - 1, l, r);
    }
    
    seg_t seg_query_rec(int i, int tl, int tr, int ql, int qr) {
        seg_eval_lazy(i, tl, tr);
        
        if (ql <= tl && tr <= qr) return seg_tree[i];
        if (tl > tr || tr < ql || qr < tl) return seg_sentinel;
        
        int mid = (tl + tr) / 2;
        seg_t a = seg_query_rec(2 * i + 1, tl, mid, ql, qr);
        seg_t b = seg_query_rec(2 * i + 2, mid + 1, tr, ql, qr);
        return seg_combine(a, b);
    }
    
    void seg_update_header(int l, int r, seg_t v) {
        seg_update_rec(0, 0, N - 1, l, r, v);
    }
    
    seg_t seg_update_rec(int i, int tl, int tr, int ql, int qr, seg_t v) {
        seg_eval_lazy(i, tl, tr);
        
        if (tl > tr || tr < ql || qr < tl) return seg_tree[i];
        if (ql <= tl && tr <= qr) {
            seg_lazy[i] = seg_lazy_apply(seg_lazy[i], v);
            seg_eval_lazy(i, tl, tr);
            return seg_tree[i];
        }
        if (tl == tr) return seg_tree[i];
        
        int mid = (tl + tr) / 2;
        seg_t a = seg_update_rec(2 * i + 1, tl, mid, ql, qr, v);
        seg_t b = seg_update_rec(2 * i + 2, mid + 1, tr, ql, qr, v);
        return seg_tree[i] = seg_combine(a, b);
    }
    
    void seg_eval_lazy(int i, int l, int r) {
        if (seg_lazy[i] == seg_lazy_sentinel) return;
        
        seg_tree[i] = seg_lazy_func(seg_tree[i], seg_lazy[i], l, r);
        
        if (l != r) {
            seg_lazy[i * 2 + 1] = seg_lazy_apply(seg_lazy[i * 2 + 1], seg_lazy[i]);
            seg_lazy[i * 2 + 2] = seg_lazy_apply(seg_lazy[i * 2 + 2], seg_lazy[i]);
        }
        
        seg_lazy[i] = seg_lazy_sentinel;
    }
    
    /* ----------- init phase 1 ----------- */
    /* initialize segtree, clear edges, etc. */
    
    void init_arrays(int n) {
        // everything not initialized doesn't need to be
        N = n;
        for (int i = 0; i < N; i++) {
            edges[i].clear();
            chain[i] = i;
        }
        
        for (int i = 0; i < 4 * N; i++) {
            seg_tree[i] = seg_init_val;
            seg_lazy[i] = seg_lazy_sentinel;
        }
    }
    
    /* ----------- init phase 2 ----------- */
    /* put edges in */
    
    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    /* ----------- init phase 3 ----------- */
    /* build the lca and hld stuff */
    
    void init_tree(seg_t* arr, int root = 0) {
        // lca
        lca_dfs(root, -1);
        
        // size, compute biggest children
        dfs_size(root, -1, 0);
        
        // compute chains
        dfs_chains(root, -1);
        
        // label nodes
        label_time = 0;
        dfs_labels(arr, root, -1);
    }
    
    void lca_dfs(int v, int par) {
        lca_lift[v][0] = par;
        
        for (int i = 1; i < lg; i++) {
            if (lca_lift[v][i - 1] == -1) lca_lift[v][i] = -1;
            else lca_lift[v][i] = lca_lift[lca_lift[v][i - 1]][i - 1];
        }
        
        for (int x: edges[v]) {
            if (x != par) {
                lca_dfs(x, v);
            }
        }
    }
    
    void dfs_size(int v, int p, int d) {
        sz[v] = 1;
        depth[v] = d;
        par[v] = p;
        int bigc = -1, bigv = -1;
        
        for (int x: edges[v]) {
            if (x != p) {
                dfs_size(x, v, d + 1);
                sz[v] += sz[x];
                if (sz[x] > bigv) {
                    bigc = x;
                    bigv = sz[x];
                }
            }
        }
        
        bigchild[v] = bigc;
    }
    
    void dfs_chains(int v, int p) {
        if (bigchild[v] != -1) {
            chain[bigchild[v]] = chain[v];
        }
        
        for (int x: edges[v]) {
            if (x != p) {
                dfs_chains(x, v);
            }
        }
    }
    
    void dfs_labels(seg_t* arr, int v, int p) {
        label[v] = label_time++;
        seg_update_header(label[v], label[v], arr[v]);
        
        if (bigchild[v] != -1) {
            dfs_labels(arr, bigchild[v], v);
        }
        
        for (int x: edges[v]) {
            if (x != p && x != bigchild[v]) {
                dfs_labels(arr, x, v);
            }
        }
    }
    
    /* ----------- init phase 4 ----------- */
    /* usage */
    
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int d = depth[a] - depth[b];
        int v = get_kth_ancestor(a, d);
        if (v == b) {
            return v;
        } else {
            for (int i = lg - 1; i >= 0; i--) {
                if (lca_lift[v][i] != lca_lift[b][i]) {
                    v = lca_lift[v][i];
                    b = lca_lift[b][i];
                }
            }
            return lca_lift[b][0];
        }
    }
    
    int get_kth_ancestor(int v, int k) {
        for (int i = lg - 1; i >= 0; i--) {
            if (v == -1) return v;
            if ((1 << i) <= k) {
                v = lca_lift[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }
    
    /* excludes p */
    seg_t query_chain(int v, int p) {
        seg_t val = seg_sentinel;
        while (depth[p] < depth[v]) {
            int top = chain[v];
            if (depth[top] <= depth[p]) {
                int diff = depth[v] - depth[p];
                top = get_kth_ancestor(v, diff - 1);
            }
            val = seg_combine(val, seg_query_header(label[top], label[v]));
            v = par[top];
        }
        return val;
    }
    
    seg_t query(int u, int v) {
        int lc = lca(u, v);
        seg_t val = seg_combine(query_chain(u, lc), query_chain(v, lc));
        return seg_combine(val, seg_query_header(label[lc], label[lc]));
    }
    
    /* excludes p */
    void update_chain(int v, int p, seg_t val) {
        while (depth[p] < depth[v]) {
            int top = chain[v];
            if (depth[top] <= depth[p]) {
                int diff = depth[v] - depth[p];
                top = get_kth_ancestor(v, diff - 1);
            }
            seg_update_header(label[top], label[v], val);
            v = par[top];
        }
    }
    
    void update(int u, int v, seg_t val) {
        int lc = lca(u, v);
        update_chain(u, lc, val);
        update_chain(v, lc, val);
        seg_update_header(label[lc], label[lc], val);
    }
};
hld<MAXN, 20, pi> h;
int sup[20][MAXN];

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

vi qind[MAXN];
vpi bus[MAXN];
int numpts[MAXN];


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    h.init_arrays(n);
    g.resize(n);
    forn(i,1,n) {
        int v;
        scanf("%d", &v);
        v--;
        g[i].pb(v);
        g[v].pb(i);
        lev[i] = lev[v] + 1;
        h.add_edge(i, v);
    }
    vpi arr;
    forn(i,0,n) veri[i] = (mp(lev[i], i));
    h.init_tree(veri);
    int m;
    read(m);
    dfs1(0);
    while(m--) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int c = h.lca(u, v);
        h.update(u, v, mp(lev[c], c));
        bus[c].pb(mp(u,v));
    }
    forn(i,0,n) {
        pi x = h.query(i, i);
        sup[0][i] = x.second;
        if(x.second == i) sup[0][i] = -1;
    }
    forn(l,1,20) {
        forn(i,0,n) if(sup[l-1][i] != -1) sup[l][i] = sup[l-1][sup[l-1][i]];
        else sup[l][i] = -1;
    }
    vpi q;
    int qn;
    read(qn);
    vi ans(qn, 0);
    forn(it,0,qn) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int c = h.lca(u, v);
        for(int l = 19; l>=0; l--) {
            int uc = sup[l][u];
            if(uc!=-1 && lev[uc] > lev[c]) {
                ans[it] += 1<<l;
                u = uc;
            }
            int vc = sup[l][v];
            if(vc!=-1 && lev[vc] > lev[c]) {
                ans[it] += 1<<l;
                v = vc;
            }
        }
        q.pb(mp(u,v));
        if(u!=c && sup[0][u] == -1) {
            ans[it] = -1;
        }
        else if(v!=c && sup[0][v] == -1) {
            ans[it] = -1;
        }
        else if(u == c || v == c) {
            ans[it] += 1;
        }
        else qind[c].pb(it);
    }
    fenwick<int> fen(n);
    forn(i,0,n) {
        if(qind[i].empty()) continue;
        vector<pair<pi, int>> ev;
        vpi addbus;
        for(auto x : bus[i]) {
            addbus.pb(mp(tin[x.first], tin[x.second]));
            addbus.pb(mp(tin[x.second], tin[x.first]));
        }
        for(auto ind : qind[i]) {
            int u = q[ind].first;
            int v = q[ind].second;
            int xl = tin[u];
            int xr = tout[u];
            int yl = tin[v];
            int yr = tout[v];
            ev.pb(mp(mp(xr,yr), ind+1));
            if(xl > 0) ev.pb(mp(mp(xl-1,yr), -ind-1));
            if(yl > 0) ev.pb(mp(mp(xr,yl-1), -ind-1));
            if(xl > 0 && xr > 0) ev.pb(mp(mp(xl-1,yl-1), ind+1));
        }
        srt(addbus);
        srt(ev);
        int pt = 0;
        for(auto x : ev) {
            while(pt<addbus.size() && addbus[pt].first <= x.first.first) {
                fen.modify(addbus[pt++].second, 1);
            }
            if(x.second > 0) numpts[x.second - 1] += fen.get(x.first.second);
            else numpts[-x.second - 1] -= fen.get(x.first.second);
        }
        forn(i,0,pt) fen.modify(addbus[i].second, -1);
        for(auto ind : qind[i]) {
            if(numpts[ind] > 0) ans[ind] ++;
            else ans[ind] += 2;
        }
    }
    forn(i,0,qn) printf("%d\n", ans[i]);
    
    
    
    
}