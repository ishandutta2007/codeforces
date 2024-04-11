//#define BITSET64BIT 1
#ifdef BITSET64BIT
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker,"/stack:200000000")
*/
#define endl '\n'

// Shortcut

// #define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(h13, a) cout << h13 << ' '; cout << endl;
#define PrintVl(a) Fora(h13, a) cout << h13 << endl;
#define PrintA(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << endl;
#define Ptest(x) return cout << x, 0;
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){                                                                     \\
    string _sDEB = #args;                                                                   \\
    replace(_sDEB.begin(), _sDEB.end(), ',', ' ');                                          \\
    stringstream _ssDEB(_sDEB);                                                             \\
    istream_iterator<string> _itDEB(_ssDEB);                                                \\
    DEB(_itDEB, args);                                                                      \\
}
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

// Data Structure

// Policy based data structures                                                             \\
   Support find_by_order(int k): return an iterator to the k-th smallest element,           \\
                                 counting from 0                                            \\
           order_of_key(int k): return the number of items strictly smaller than k          \\
   For ordered_multiset and ordered_multimap, lower_bound() and upper_bound() are swapped

template <typename T> using ordered_set =
tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_map =
tree <Key, T, less <Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =
tree <T, null_type, less_equal <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_multimap =
tree <Key, T, less_equal <Key>, rb_tree_tag, tree_order_statistics_node_update>;

#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 2e5 + 5, M = log2(N) + 1;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

#define segment_tree_left id << 1, l, mid
#define segment_tree_right id << 1 | 1, mid + 1, r

struct lazy_segment_tree{
    pii seg[4 * N]; int lazy[4 * N];
    
    void down(int id, int l, int r){
        if (!lazy[id]) return;
        seg[id << 1].fi += lazy[id];
        seg[id << 1 | 1].fi += lazy[id];
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = {0, 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(segment_tree_left);
        build(segment_tree_right);
        if (seg[id << 1].fi < seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1];
        }
        else if (seg[id << 1].fi > seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1 | 1];
        }
        else{
            seg[id] = {seg[id << 1].fi, seg[id << 1].se + seg[id << 1 | 1].se};
        }
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id].fi += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(segment_tree_left, u, v, val);
        update(segment_tree_right, u, v, val);
        if (seg[id << 1].fi < seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1];
        }
        else if (seg[id << 1].fi > seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1 | 1];
        }
        else{
            seg[id] = {seg[id << 1].fi, seg[id << 1].se + seg[id << 1 | 1].se};
        }
    }
    
    pii get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return {inf, 1};
        }
        if (u <= l || r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        pii ansl = get(segment_tree_left, u, v), ansr = get(segment_tree_right, u, v);
        if (ansl.fi < ansr.fi){
            return ansl;
        }
        else if (ansl.fi > ansr.fi){
            return ansr;
        }
        else{
            return {ansl.fi, ansl.se + ansr.se};
        }
    }
} it;

vi adj[N];
int memo[N][M + 1], h[N];

int tim, tour[N], lef[N], rig[N];

void dfs(int u, int p){
    memo[u][0] = p;
    ForE(i, 1, M){
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    h[u] = h[p] + 1;
    tour[++tim] = u;
    lef[u] = tim;
    Fora(&v, adj[u]){
        if (v == p) continue;
        dfs(v, u);
    }
    rig[u] = tim;
}

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(i, M, 0){
        if (h[u] - (1 << i) >= h[v]){
            u = memo[u][i];
        }
    }
    if (u == v){
        return u;
    }
    FordE(i, M, 0){
        if (memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}

int nearlca(int u, int v){ // Assuming that u is in subtree of v and u != v
    FordE(i, M, 0){
        if (h[u] - (1 << i) > h[v]){
            u = memo[u][i];
        }
    }
    return u;
}

int n, q;

set <pii> added;

void add(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    it.update(1, 1, n, lef[u], rig[u], -1);
    if (lca(u, v) != v){
        it.update(1, 1, n, lef[v], rig[v], -1);
        it.update(1, 1, n, 1, n, 1);
    }
    else{
        int w = nearlca(u, v);
        it.update(1, 1, n, lef[w], rig[w], 1);
    }
}

void del(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    it.update(1, 1, n, lef[u], rig[u], 1);
    if (lca(u, v) != v){
        it.update(1, 1, n, lef[v], rig[v], 1);
        it.update(1, 1, n, 1, n, -1);
    }
    else{
        int w = nearlca(u, v);
        it.update(1, 1, n, lef[w], rig[w], -1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    it.build(1, 1, n);
    while (q--){
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        if (added.find({u, v}) == added.end()){
            add(u, v);
            added.insert({u, v});
        }
        else{
            del(u, v);
            added.erase({u, v});
        }
        if (it.seg[1].fi == 0){
            cout << it.seg[1].se << endl;
        }
        else{
            cout << 0 << endl;
        }
        // ForE(i, 1, n){
        //     cout << it.get(1, 1, n, i, i).fi << ' ';
        // } cout << endl;
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/