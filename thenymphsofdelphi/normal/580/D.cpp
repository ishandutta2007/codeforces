#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

const int N = 20, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int n, m, k, ans;
int a[N], b[N][N];
int dp[1 << N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, k){
        int x, y, c; cin >> x >> y >> c;
        b[x][y] = c;
    }
    For(i, 1, (1 << n)){
        if (__builtin_popcount(i) > m) continue;
        ForE(j, 1, n){
            if (!(i & (1ll << (j - 1)))) continue;
            int mx = 0;
            ForE(jj, 1, n){
                if (jj == j || !(i & (1ll << (jj - 1)))) continue;
                mx = max(mx, dp[i ^ (1ll << (j - 1))][jj] + b[jj][j]);
                // cout << (i ^ (1ll << (j - 1))) << ' ' << jj << ' ' << dp[i ^ (1ll << (jj - 1))][jj] + b[jj][j] << endl;
            }
            dp[i][j] = mx + a[j];
            // cout << "A " << i << ' ' << j << ' ' << dp[i][j] << endl;
            if (__builtin_popcount(i) == m) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
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