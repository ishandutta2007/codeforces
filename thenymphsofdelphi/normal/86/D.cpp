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
#define mp make_pair
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

#define pque priority_queue
#define mts multiset
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

const int N = 2e5 + 5, M = 1e6 + 5, Q = 2e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

const int S = log2(Q) + 1;

ll gilbertOrder(int x, int y){
    ll d = 0;
    for (int s = 1 << (S - 1); s; s >>= 1){
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry){
            if (rx){
                x = (1 << S) - x;
                y = (1 << S) - y;
            }
            swap(x, y);
        }
    }
    return d;
}

struct Query {
    int l, r, idx;
    ll ord;

    void calcOrder() {
        ord = gilbertOrder(l, r);
    }
};

bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

int n, q;
ll valans;
int a[N];
int b[M];
Query que[Q];
ll ans[Q];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, q){
        cin >> que[i].l >> que[i].r;
        que[i].idx = i;
        que[i].calcOrder();
    }
    sort(que + 1, que + 1 + q);
    int l = 0, r = 0; b[0]++;
    ForE(i, 1, q){
        while (l > que[i].l){
            l--;
            valans += (2ll * b[a[l]] + 1) * a[l];
            b[a[l]]++;
        }
        while (r < que[i].r){
            r++;
            valans += (2ll * b[a[r]] + 1) * a[r];
            b[a[r]]++;
        }
        while (l < que[i].l){
            b[a[l]]--;
            valans -= (2ll * b[a[l]] + 1) * a[l];
            l++;
        }
        while (r > que[i].r){
            b[a[r]]--;
            valans -= (2ll * b[a[r]] + 1) * a[r];
            r--;
        }
        ans[que[i].idx] = valans;
    }
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