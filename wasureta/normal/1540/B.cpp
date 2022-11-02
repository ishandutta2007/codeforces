// ./b-tree-array.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
ll fix(ll x, ll mod = MOD) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x*x%mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod-2, mod); }
ll mdiv(ll x, ll y, ll mod = MOD) { return x * fpow(y, mod-2, mod) % mod; }
// N choose R
vector<ll> fact, invf;
void init_nchooser(int MN) {
    fact.resize(MN + 1); invf.resize(MN + 1);
    fact[0] = 1LL;
    for (int i = 1; i <= MN; i++) fact[i] = fix(fact[i - 1] * i);
    invf[MN] = inv(fact[MN]);
    for (auto i = MN-1; i >= 0; i--) invf[i] = fix(invf[i + 1] * (i + 1));
}
ll choose(ll N, ll K) { return fix(fact[N] * fix(invf[K] * invf[N - K])); }
ll permute(ll N, ll K) { return fix(fact[N] * invf[N - K]); }

struct Graph {
    using Edge = int; // Edge object in adjacency list (i.e. vector<int> g[MN], Edge type would be int)
    int v(Edge &e) { return e; } // Returns the adjacent node in an edge object
};
template <class Graph> struct LCA {
    using Edge = typename Graph::Edge; Graph G;
    vector<int> dep;
    vector<Edge> *g;
    vector<vector<int>> tb;
    int N, lg;
    void dfs(int c, int p) {
        tb[0][c] = p;
        for (auto to : g[c]) {
            int v = G.v(to);
            if (v != p) {
                dep[v] = dep[c] + 1;
                dfs(v, c);
            }
        }
    }
    void init(int rt, int N0, vector<Edge> *g0) {
        N = N0; g = g0;
        lg = 31 - __builtin_clz(N) + 1;
        tb.assign(lg, vector<int>(N + 1, -1)); dep.assign(N + 1, 0);
        dfs(rt, -1);
        for (auto i = 1; i < lg; i++) {
            for (auto j = 1; j <= N; j++) {
                int pp = tb[i - 1][j];
                tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
            }
        }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        if (dep[a] > dep[b]) swap(a, b);
        int delta = dep[b] - dep[a];
        for (auto i = 0; i < lg; i++)
            if ((delta >> i) & 1)
                b = tb[i][b];
        if (a == b) return a;
        for (auto i = lg-1; i >= 0; i--) {
            if (tb[i][a] != tb[i][b]) {
                a = tb[i][a];
                b = tb[i][b];
            }
        }
        return tb[0][a];
    }
};

const int MN = 201;
int N;
vector<int> g[MN];

LCA<Graph> lca;

int ctr = 0, in[MN], out[MN], dep[MN], par[MN];
void dfs(int c, int p) {
    in[c] = ++ctr;
    par[c] = p;
    for (auto to : g[c]) {
        if (to != p) {
            dep[to] = dep[c]+1;
            dfs(to, c);
        }
    }
    out[c] = ++ctr;
}

bool ant(int j, int k) {
    return in[j] <= in[k] && out[k] <= out[j];
}

ll i2[MN], pro[MN][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_nchooser(MN);
    i2[0] = 1;
    for (auto i = 1; i < MN; i++)
        i2[i] = mdiv(i2[i-1], 2);

    cin >> N;
    for (auto i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (auto a = 1; a <= N; a++) {
        for (auto b = 1; b <= N; b++) {
            ll c = 0;
            for (auto i = a; i <= a+b-1; i++) {
                c = fix(c + fpow(2, a+b-i) * choose(i-1, a-1));
            }
            // cout<<"a="<<(a)<<", "; cout<<"b="<<(b)<<", "; cout<<"c="<<(c)<<", "; cout<<"fpow(2,a+b)="<<(fpow(2,a+b))<<", "; cout << endl; // db a,b,c,fpow(2,a+b)
            pro[a][b] = mdiv(c, fpow(2, a+b));
        }
    }

    ll ans = 0;
    for (auto i = 1; i <= N; i++) {
        ctr = 0;
        fill(dep, dep+N+1, 0);
        dfs(i, -1);
        lca.init(i, N, g);

        // int t[N], cnt = 0, icnt = 0; iota(t, t+N, 1);
        // do {
        //     bool ok = t[0] == i;
        //     vector<bool> seen(N+1);
        //     for (auto i = 0; i < N; i++) {
        //         if (par[t[i]] != -1 && !seen[par[t[i]]])
        //             ok = 0;
        //         seen[t[i]] = true;
        //     }
        //
        //     if (ok) {
        //         cnt++;
        //         int ic = 0;
        //         for (auto i = 0; i < N; i++)
        //             for (auto j = i+1; j < N; j++)
        //                 if (t[i] > t[j])
        //                     ic++;
        //         icnt += ic;
        //
        //         if (i==1) {
        //             cout<<"ic="<<(ic)<<", "; cout<<"t=["; for(int __i=0; __i<(N); __i++)cout<<(t)[__i]<<", "; cout<<"], ";cout << endl; // db ic,A:N:t
        //         }
        //     }
        // } while (next_permutation(t, t+N));
        // stot = fix(stot+mdiv(icnt,cnt));

        // j before k
        // cout<<"[rt]: "; cout<<"i="<<(i)<<", "; cout << endl; // db l:rt,i
        // ld fans = 0;
        for (auto j = 1; j <= N; j++) {
            for (auto k = 1; k <= j-1; k++) {
                if (ant(j, k)) { // 100%
                    // cout<<"[ant]: "; cout<<"j="<<(j)<<", "; cout<<"k="<<(k)<<", "; cout << endl; // db l:ant,j,k
                    ans++;
                    // fans++;
                }
                else if (!ant(k, j)) {
                    int l = lca.lca(j, k), a = dep[j]-dep[l], b = dep[k]-dep[l];
                    // cout<<"j="<<(j)<<", "; cout<<"k="<<(k)<<", "; cout<<"l="<<(l)<<", "; cout<<"a="<<(a)<<", "; cout<<"b="<<(b)<<", "; cout<<"choose(a+b,b)="<<(choose(a+b,b))<<", "; cout<<"choose(a+b-1,b-1)="<<(choose(a+b-1,b-1))<<", "; cout << endl; // db j,k,l,a,b,choose(a+b,b),choose(a+b-1,b-1)
                    ans += pro[a][b];
                }
                ans = fix(ans);
            }
        }
        // cout<<"fans="<<(fans)<<", "; cout << endl; // db fans
        // ft+=fans;
    }
    // ft/=N;
    // cout<<"ft="<<(ft)<<", "; cout << endl; // db ft
    ans = mdiv(ans, N); // 1/N for each start node

    cout << (ans) << '\n';

    return 0;
}