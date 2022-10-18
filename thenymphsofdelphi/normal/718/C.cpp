#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

//#define int long long
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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
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

// Data Structure

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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, q;
int a[N];

struct matrix{
    ll mt[3][3];
    matrix(){
        mt[1][1] = 0; mt[1][2] = 0; mt[2][1] = 0; mt[2][2] = 0;
    }
};

matrix zero;
matrix A;
matrix B;

inline matrix operator+(matrix a, matrix b){
    ForE(i, 1, 2){
        ForE(j, 1, 2){
            a.mt[i][j] += b.mt[i][j];
            if (a.mt[i][j] >= mod) a.mt[i][j] -= mod;
        }
    }
    return a;
}

inline matrix operator*(matrix a, matrix b){
    matrix c;
    ForE(i, 1, 2){
        ForE(j, 1, 2){
            ForE(k, 1, 2){
                c.mt[i][j] += (a.mt[i][k] * b.mt[k][j]) % mod;
                if (c.mt[i][j] >= mod) c.mt[i][j] -= mod;
            }
        }
    }
    return c;
}

inline matrix pow(matrix a, int b){
    matrix ans = zero;
    while (b){
        if (b & 1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

matrix seg[4 * N], lazy[4 * N];

inline void down(int id, int l, int r){
    int mid = (l + r) >> 1;
    lazy[id << 1] = lazy[id << 1] * lazy[id];
    lazy[id << 1 | 1] = lazy[id << 1 | 1] * lazy[id];
    seg[id << 1] = seg[id << 1] * lazy[id];
    seg[id << 1 | 1] = seg[id << 1 | 1] * lazy[id];
    lazy[id] = zero;
}

inline void build(int id, int l, int r){
    lazy[id] = zero;
    if (l == r){
        seg[id] = B * pow(A, a[l] - 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

inline void update(int id, int l, int r, int u, int v, matrix val){
    if (v < l || r < u){
        return;
    }
    if (u <= l && r <= v){
        seg[id] = seg[id] * val;
        lazy[id] = lazy[id] * val;
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

inline ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u){
        return 0;
    }
    if (u <= l && r <= v){
        return seg[id].mt[2][2];
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    ll ans = get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    if (ans >= mod) ans -= mod;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    zero.mt[1][1] = 1; zero.mt[1][2] = 0; zero.mt[2][1] = 0; zero.mt[2][2] = 1;
    A.mt[1][1] = 0; A.mt[1][2] = 1; A.mt[2][1] = 1; A.mt[2][2] = 1;
    B.mt[1][1] = 0; B.mt[1][2] = 0; B.mt[2][1] = 0; B.mt[2][2] = 1;
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        int que, l, r;
        cin >> que >> l >> r;
        if (que == 1){
            int val; cin >> val;
            update(1, 1, n, l, r, pow(A, val));
        }
        else{
            cout << get(1, 1, n, l, r) << endl;
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