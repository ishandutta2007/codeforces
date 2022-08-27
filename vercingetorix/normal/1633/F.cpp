#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

int sgn(ll x) {
    if(x== 0 ) return 0;
    else if(x > 0) return 1;
    else return -1;
}

const pll PINF= mp(0,0);
typedef pll seg_t;
template<int size, int lg>
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
        return mp(a.first + b.first, a.second + b.second);
    }
    
    inline seg_t seg_lazy_apply(seg_t lazy_val, seg_t new_val) {
        return mp(new_val.first*lazy_val.first, new_val.first*lazy_val.second+new_val.second);
//        return min(lazy_val, new_val);
        //        return new_val;
        //        lazy_val = min(lazy_val, new_val);
        //        return lazy_val;
    }
    
    inline seg_t seg_lazy_func(seg_t cur_val, seg_t lazy_val, int l, int r) {
        return mp(cur_val.first*lazy_val.first+(r-l+1)*lazy_val.second, cur_val.second*lazy_val.first+sgn(lazy_val.second));
        return min(lazy_val, cur_val);
        //        cur_val = min(cur_val, lazy_val);
        //        return lazy_val;
    }
    
    const seg_t seg_sentinel = mp(0,0);
    const seg_t seg_lazy_sentinel = mp(1,0);
    const seg_t seg_init_val = mp(0,0);
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
#ifdef LOCAL
const int A = 20;
hld <A, 5> h;
#else
const int A = 200500;
hld<A, 18> h;
#endif
pi par[A];
int odd[A];
vpi g[A];

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u.first == p) continue;
        par[u.first] = mp(v, u.second);
        dfs(u.first, v);
    }
}

int mark[A];
vi res;

int dfs2(int v, int p) {
    int tot = 0;
    for(auto u : g[v]) {
        if(u.first == p) continue;
        int ret = dfs2(u.first, v);
        if(ret%2) res.pb(u.second);
        tot += ret;
    }
    tot += mark[v];
    return tot;
}

pll def[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    def[0] = mp(0, 2);
    int n;
    read(n);
    odd[0] = 1;
    int k = 1;
    int c1 = 1;
    h.init_arrays(n);
    forn(i,1,n) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(mp(v,i));
        g[v].pb(mp(u,i));
        h.add_edge(u, v);
    }
    dfs(0,0);
    h.init_tree(def);
    ll sum = 0;
    int bal = 1;
    ll full = 0;
    h.update(0, 0, mp(1,1));
    h.update(0, 0, mp(1,-3));
    auto x = h.query(0, 0);
//    x = h.query(0, 3);
    mark[0] = 1;
    while(1) {
        int tp;
        scanf("%d", &tp);
        if(tp==3) break;
        else if(tp == 1) {
            int v;
            scanf("%d", &v);
            
            v--;
            mark[v] = 1;
            full += par[v].second;
            h.update(v, v, mp(1, -par[v].second));
            bal--;
            sum -= par[v].second;
            auto x = h.query(0, v);
            bal -= 2*x.second;
            sum -= 2*x.first;
            h.update(0, v, mp(-1,0));
            if(bal != 0) printf("0\n");
            else printf("%lld\n", (sum+full)/2);
            fflush(stdout);
        }
        else if(tp == 2) {
            if(bal != 0) printf("0\n");
            else {
                dfs2(0, 0);
                srt(res);
                printf("%d", res.size());
                for(auto x : res) printf(" %d", x);
                printf("\n");
                res.clear();
            }
            fflush(stdout);
//            printf("TYPE2\n");
        }
    }
    
    
}