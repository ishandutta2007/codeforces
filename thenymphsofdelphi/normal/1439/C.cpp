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

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")/

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
#define Fora(i, a) for (auto i: a)

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
#define isz(a) (signed)a.size()
#define mset(a) memset(a, 0, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define msetninf(a) memset(a, 0xc0, sizeof(a))
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

const int N = 2e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int a[N];

int segidx[N];

ll segsum[4 * N]; int segmn[4 * N], lazy[4 * N];

void down(int id, int l, int r){
    if (!lazy[id]){
        return;
    }
    int mid = (l + r) >> 1;
    lazy[id << 1] = lazy[id];
    lazy[id << 1 | 1] = lazy[id];
    segsum[id << 1] = (ll)lazy[id] * (mid - l + 1);
    segsum[id << 1 | 1] = (ll)lazy[id] * (r - mid);
    segmn[id << 1] = lazy[id];
    segmn[id << 1 | 1] = lazy[id];
    lazy[id] = 0;
}

void build(int id, int l, int r){
    if (l == r){
        segsum[id] = a[l];
        segmn[id] = a[l];
        segidx[l] = id;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    segmn[id] = segmn[id << 1 | 1];
}

void update(int id, int l, int r, int u, int v, int val){
    if (v < l || r < u){
        return;
    }
    if (u <= l && r <= v){
        segsum[id] = (ll)(r - l + 1) * val;
        segmn[id] = val;
        lazy[id] = val;
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    segmn[id] = segmn[id << 1 | 1];
}

ll getsum(int id, int l, int r, int u, int v){
    if (v < l || r < u){
        return 0;
    }
    if (u <= l && r <= v){
        return segsum[id];
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    return getsum(id << 1, l, mid, u, v) + getsum(id << 1 | 1, mid + 1, r, u, v);
}

int getmin(int id, int l, int r, int idx){
    if (r == idx){
        return segmn[id];
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    if (mid >= idx){
        return getmin(id << 1, l, mid, idx);
    }
    else{
        return getmin(id << 1 | 1, mid + 1, r, idx);
    }
}

 // smallest i such that a[i] < val
int binary_search(int id, int l, int r, int val){
    if (l == r){
        return l;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    if (segmn[id << 1] < val){
        return binary_search(id << 1, l, mid, val);
    }
    else{
        return binary_search(id << 1 | 1, mid + 1, r, val);
    }
}

// smallest i such that a[1 .. i] > val
int binary_search2(int id, int l, int r, ll val){
    if (l == r){
        return l;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    if (segsum[id << 1] > val){
        return binary_search2(id << 1, l, mid, val);
    }
    else{
        return binary_search2(id << 1 | 1, mid + 1, r, val - segsum[id << 1]);
    }
}

int n, q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int x, y; cin >> x >> y;
            if (y <= getmin(1, 1, n, x)){
                continue;
            }
            int idx = binary_search(1, 1, n, y);
            update(1, 1, n, idx, x, y);
        }
        else{
            int x, y; cin >> x >> y;
            if (y >= getsum(1, 1, n, x, n)){
                cout << n - x + 1 << endl;
                continue;
            }
            int ans = 0;
            int last = getmin(1, 1, n, n);
            while (y >= last){
                // cout << x << ' ' << y << endl;
                if (y < getsum(1, 1, n, x, x)){
                    x = binary_search(1, 1, n, y + 1);
                    continue;
                }
                if (y >= getsum(1, 1, n, x, n)){
                    ans += n - x + 1;
                    break;
                }
                ll sum = (x == 1 ? 0 : getsum(1, 1, n, 1, x - 1));
                int idx = binary_search2(1, 1, n, sum + y);
                // smallest l such that a[x .. l] > y, or a[1 .. l] > y + a[1 .. x - 1]
                // cout << "B " << sum << ' ' << idx << endl;
                y -= getsum(1, 1, n, x, idx - 1);
                ans += idx - x;
                x = idx;
            }
            cout << ans << endl;
        }
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