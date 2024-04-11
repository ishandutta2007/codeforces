#include<bits/stdc++.h>
using namespace std;

// Optimization
//#pragma optimize ("O3")
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

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
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
#define m1set(a) memset(a, 1, sizeof(a))
#define mn1set(a) memset(a, -1, sizeof(a))
#define mmset(a) memset(a, 0x3f, sizeof(a))
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

const int N = 2e3 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, k, x, y, z, ans, t, te, q;
int a[N][N], sa[N][N], sb[N][N], dpaa[N][N], dpbb[N][N], iaw[N], ibw[N];
bool dpa[N][N], dpb[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (k == n) Ptest(n * 2);
    ForE(i, 1, n){
        ForE(j, 1, n){
            char c;
            cin >> c;
            a[i][j] = (c == 'W' ? 1 : 0);
            sa[i][j] = sa[i][j - 1] + a[i][j];
            sb[i][j] = sb[i - 1][j] + a[i][j];
        }
    }
    ForE(i, 1, n){
        iaw[i] = iaw[i - 1] + (sa[i][n] == n);
        ibw[i] = ibw[i - 1] + (sb[n][i] == n);
    }
    ForE(i, 1, n){
        ForE(j, 1, n - k + 1){
            int l = j, r = j + k - 1;
            dpa[i][j] = (sa[i][n] - sa[i][r] == n - r) && (sa[i][l - 1] - sa[i][0] == l - 1);
            dpaa[i][j] = dpaa[i - 1][j] + dpa[i][j];
        }
    }
    ForE(i, 1, n - k + 1){
        ForE(j, 1, n){
            int l = i, r = i + k - 1;
            dpb[i][j] = (sb[n][j] - sb[r][j] == n - r) && (sb[l - 1][j] - sb[0][j] == l - 1);
            dpbb[i][j] = dpbb[i][j - 1] + dpb[i][j];
        }
    }
    int ans = 0;
    ForE(i, 1, n - k + 1){
        ForE(j, 1, n - k + 1){
            ans = max(ans, iaw[n] - iaw[i + k - 1] + iaw[i - 1] + ibw[n] - ibw[j + k - 1] + ibw[j - 1] + dpaa[i + k - 1][j] - dpaa[i - 1][j] + dpbb[i][j + k - 1] - dpbb[i][j - 1]);
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