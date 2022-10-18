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

#define int long long
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

const int N = 1e3 + 5, Q = 1e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

struct query{
    int type, cac1, cac2;
    
    query(int _type = 0, int _cac1 = 0, int _cac2 = 0): type(_type), cac1(_cac1), cac2(_cac2) {}
};

int n, m, q;

bool a[N][N];
int sum[N];
bool inv[N];

vector <pair <int, query>> adj[Q];
vi que[Q];
int ans[Q], tans;
int curpos[Q];

void dfs(int u){
    // cout << u << ' ' << tans << endl;
    // ForE(i, 1, n){
    //     ForE(j, 1, m){
    //         cout << a[i][j];
    //     } cout << endl;
    // }
    // PrintA(sum, 1, n);
    // PrintA(inv, 1, n);
    // PrintV(que[u]);
    // cout << endl;
    
    Fora(v, que[u]){
        ans[v] = tans;
    }
    Fora(v, adj[u]){
        bool cac = 0;
        if (v.se.type == 1){
            if (!(a[v.se.cac1][v.se.cac2] ^ inv[v.se.cac1])){
                cac = 1;
                a[v.se.cac1][v.se.cac2] ^= 1;
                sum[v.se.cac1]++;
                tans++;
            }
            dfs(v.fi);
            if (cac){
                a[v.se.cac1][v.se.cac2] ^= 1;
                sum[v.se.cac1]--;
                tans--;
            }
        }
        if (v.se.type == 2){
            if (a[v.se.cac1][v.se.cac2] ^ inv[v.se.cac1]){
                cac = 1;
                a[v.se.cac1][v.se.cac2] ^= 1;
                sum[v.se.cac1]--;
                tans--;
            }
            dfs(v.fi);
            if (cac){
                a[v.se.cac1][v.se.cac2] ^= 1;
                sum[v.se.cac1]++;
                tans++;
            }
        }
        if (v.se.type == 3){
            tans -= sum[v.se.cac1];
            sum[v.se.cac1] = m - sum[v.se.cac1];
            tans += sum[v.se.cac1];
            inv[v.se.cac1] ^= 1;
            dfs(v.fi);
            tans -= sum[v.se.cac1];
            sum[v.se.cac1] = m - sum[v.se.cac1];
            tans += sum[v.se.cac1];
            inv[v.se.cac1] ^= 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    int cur = 0, cnt = 0;
    ForE(i, 1, q){
        query tmp; cin >> tmp.type;
        if (tmp.type == 1){
            cin >> tmp.cac1 >> tmp.cac2;
            adj[cur].pb({cnt + 1, tmp});
            cur = ++cnt;
        }
        if (tmp.type == 2){
            cin >> tmp.cac1 >> tmp.cac2;
            adj[cur].pb({cnt + 1, tmp});
            cur = ++cnt;
        }
        if (tmp.type == 3){
            cin >> tmp.cac1;
            adj[cur].pb({cnt + 1, tmp});
            cur = ++cnt;
        }
        if (tmp.type == 4){
            cin >> tmp.cac1;
            cur = curpos[tmp.cac1];
        }
        que[cur].pb(i);
        curpos[i] = cur;
    }
    dfs(0);
    PrintAl(ans, 1, q);
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