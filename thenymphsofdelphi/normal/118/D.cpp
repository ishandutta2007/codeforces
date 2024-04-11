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

const int N = 1e2 + 5, M = 10 + 5, mod = 1e8, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n1, n2, k1, k2;
int dp[N][N][2][M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n1 >> n2 >> k1 >> k2;
    k1 = min(k1, n1);
    k2 = min(k2, n2);
    ForE(i, 1, k1){
        dp[i][0][0][i] = 1;
    }
    ForE(i, 1, k2){
        dp[0][i][1][i] = 1;
    }
    ForE(i, 1, n1){
        ForE(j, 1, n2){
            ForE(l, 1, k2){
                dp[i][j][0][1] = (dp[i][j][0][1] + dp[i - 1][j][1][l]) % mod;
            }
            ForE(k, 2, k1){
                dp[i][j][0][k] = (dp[i][j][0][k] + dp[i - 1][j][0][k - 1]) % mod;
            }
            ForE(k, 1, k1){
                dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j - 1][0][k]) % mod;
            }
            ForE(l, 2, k2){
                dp[i][j][1][l] = (dp[i][j][1][l] + dp[i][j - 1][1][l - 1]) % mod;
            }
        }
    }
    // ForE(i, 0, n1){
    //     ForE(j, 0, n2){
    //         ForE(k, 0, k1){
    //             cout << i << ' ' << j << ' ' << 0 << ' ' << k << ' ' << dp[i][j][0][k] << endl;
    //         }
    //         ForE(l, 0, k2){
    //             cout << i << ' ' << j << ' ' << 1 << ' ' << l << ' ' << dp[i][j][1][l] << endl;
    //         }
    //     }
    // }
    int ans = 0;
    ForE(k, 0, k1) ans = (ans + dp[n1][n2][0][k]) % mod;
    ForE(l, 0, k2) ans = (ans + dp[n1][n2][1][l]) % mod;
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