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
static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;
    
    inline char get_char() {
        if (buf_pos >= chars_read) {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }
    
    inline void tie(int) {}
    
    inline explicit operator bool() {
        return cur != -1;
    }
    
    inline static bool is_blank(char c) {
        return c <= ' ';
    }
    
    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }
    
    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }
    
    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }
    
    template <typename T>
    inline FastInput& read_integer(T& n) {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
            int sign = +1;
            if (cur == '-') {
                sign = -1;
                get_char();
            }
            do {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
        return read_integer(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline FastInput& operator>>(__int128& n) {
        return read_integer(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

#define cin fast_input

static struct FastOutput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;
    
    inline void put_char(char c) {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }
    
    ~FastOutput() {
        fwrite(buf, 1, buf_pos, out);
    }
    
    inline FastOutput& operator<<(char c) {
        put_char(c);
        return *this;
    }
    
    inline FastOutput& operator<<(const char* s) {
        while (*s) {
            put_char(*s++);
        }
        return *this;
    }
    
    inline FastOutput& operator<<(const string& s) {
        for (int i = 0; i < (int) s.size(); i++) {
            put_char(s[i]);
        }
        return *this;
    }
    
    template <typename T>
    inline char* integer_to_string(T n) {
        // beware of TMP_SIZE
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
            *--p = '0';
        } else {
            bool is_negative = false;
            if (n < 0) {
                is_negative = true;
                n = -n;
            }
            while (n > 0) {
                *--p = (char) ('0' + n % 10);
                n /= 10;
            }
            if (is_negative) {
                *--p = '-';
            }
        }
        return p;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
        return integer_to_string(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline char* stringify(__int128 n) {
        return integer_to_string(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }
    
    template <typename T>
    inline FastOutput& operator<<(const T& n) {
        auto p = stringify(n);
        for (; *p != 0; p++) {
            put_char(*p);
        }
        return *this;
    }
} fast_output;

#define cout fast_output
const int A = 100500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

vector<pair<int, pi>> g[A];

int par[21][A];
int pen[A];
int st[21][A];
int lev[A];

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u.first == p) continue;
        par[0][u.first] = v;
        st[0][u.first] = u.second.first;
        lev[u.first] = lev[v] + 1;
        dfs(u.first, v);
        pen[u.first] = u.second.second;
    }
}

int get(int a, int b) {
    int ret = 0;
    if(lev[a] > lev[b]) {
        for(int l = 20; l >= 0; l--) {
            if(lev[a] >= lev[b] + (1<<l)) {
                ret = max(ret, st[l][a]);
                a = par[l][a];
            }
        }
    }
    if(lev[a] < lev[b]) {
        for(int l = 20; l >= 0; l--) {
            if(lev[b] >= lev[a] + (1<<l)) {
                ret = max(ret, st[l][b]);
                b = par[l][b];
            }
        }
    }
    if(a != b) {
        for(int l = 20; l >= 0; l--) {
            if(par[l][a] != par[l][b]) {
                ret = max(ret, st[l][b]);
                ret = max(ret, st[l][a]);
                a = par[l][a];
                b = par[l][b];
            }
        }
        ret = max(ret, st[0][a]);
        ret = max(ret, st[0][b]);
    }
    return ret;
}

int lca(int a, int b) {
    if(lev[a] > lev[b]) {
        for(int l = 20; l >= 0; l--) {
            if(lev[a] >= lev[b] + (1<<l)) {
                a = par[l][a];
            }
        }
    }
    if(lev[a] < lev[b]) {
        for(int l = 20; l >= 0; l--) {
            if(lev[b] >= lev[a] + (1<<l)) {
                b = par[l][b];
            }
        }
    }
    if(a == b) return a;
    for(int l = 20; l >= 0; l--) {
        if(par[l][a] != par[l][b]) {
            a = par[l][a];
            b = par[l][b];
        }
    }
    return par[0][a];
}

int getpred(int a, int pa) {
    for(int l = 20; l >= 0; l--) {
        if(lev[a] > lev[pa] + (1<<l)) {
            a = par[l][a];
        }
    }
    return a;
}

const int INF = 1000000000;

template<int size, int lg, typename seg_t = int>
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
    // t[v] = combine(t[v*2], t[v*2+1])
    inline seg_t seg_combine(seg_t a, seg_t b) {
        //        return a ^ b;
        return min(a,b);
    }
    
    // update pp[v]
    inline seg_t seg_lazy_apply(seg_t lazy_val, seg_t new_val) {
        return min(lazy_val, new_val);
        //        return new_val;
        //        lazy_val = min(lazy_val, new_val);
        //        return lazy_val;
    }
    
    // push t[v] <- pp[v]
    inline seg_t seg_lazy_func(seg_t cur_val, seg_t lazy_val, int l, int r) {
        return min(lazy_val, cur_val);
        //        cur_val = min(cur_val, lazy_val);
        //        return lazy_val;
    }
    
    // 0 for combine
    const seg_t seg_sentinel = INF;
    // 0 for pp[v]
    const seg_t seg_lazy_sentinel = INF;
    // init val 0
    const seg_t seg_init_val = INF;
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
const int MAXN = 1000500;
hld<MAXN, 21, int> h;
//set<int> add[A];
//set<int> del[A];

int nimf[MAXN];
//int ans[MAXN];
//
//void dfsans(int v, int p) {
//    for(auto u : g[v]) {
//        if(u.first != p) {
//            dfsans(u.first, p);
//        }
//    }
//}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vi a(m), b(m), e(m);
    vector<pair<int, int>> q;
    forn(i,0,m) {
        cin>>a[i]>>b[i]>>e[i];
        a[i]--;
        b[i]--;
        q.pb(mp(e[i], i));
    }
    srt(q);
    forn(i,0,n) make_set(i);
    vi skip(m, 0);
    h.init_arrays(n);
    forn(i,0,m) {
        auto x = q[i];
        if(find_set(a[x.second]) != find_set(b[x.second])) {
            union_sets(a[x.second], b[x.second]);
            g[a[x.second]].pb(mp(b[x.second], mp(e[x.second], x.second)));
            g[b[x.second]].pb(mp(a[x.second], mp(e[x.second], x.second)));
            h.add_edge(a[x.second], b[x.second]);
            skip[x.second] = 1;
        }
    }
    forn(i,0,n+10) nimf[i] = INF;
    h.init_tree(nimf, 0);
    
    dfs(0, 0);
    forn(l,1,21) {
        forn(v,0,n) {
            int v1 = par[l-1][v];
            par[l][v] = par[l-1][v1];
            st[l][v] = max(st[l-1][v], st[l-1][v1]);
        }
    }
    vi ans(m);
    forn(i,0,m) if(skip[i] == 0) {
//        ans[i] = get(a[i], b[i]);
        int c = h.lca(a[i], b[i]);
        for(auto u : {a[i], b[i]}) {
            if(u != c) {
                int pu = getpred(u, c);
//                forn(v,0,n) cout<<h.query(v, v)<<' '; cout<<'\n';
                h.update(u, pu, e[i]);
//                cout<<u<<' '<<pu <<' '<<e[i]<<'\n';
//                forn(v,0,n) cout<<h.query(v, v)<<' '; cout<<'\n';
            }
        }
    }
    forn(i,0,m) {
        if(skip[i] == 0) cout<<get(a[i], b[i])<<'\n';
        else {
            int v = a[i];
            if(lev[b[i]] > lev[a[i]]) v = b[i];
            cout<<h.query(v, v)<<'\n';
        }
    }
    
    
}