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

const int N = 1e3 + 5, mod = 1e9 + 9, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m;
ll ans;
char a[N][N];
ll dp[N][N][26];
int lst[N][N];

bool ck(int x1, int y1, int x2, int y2, int k){
    return dp[x2][y2][k] - dp[x2][y1 - 1][k] - dp[x1 - 1][y2][k] + dp[x1 - 1][y1 - 1][k] == (ll)(x2 - x1 + 1) * (ll)(y2 - y1 + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
            For(k, 0, 26){
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
            }
            dp[i][j][a[i][j] - 'a']++;
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (!lst[i][j]){
                int x = i, y = j;
                while (a[x][y] == a[i][j]){
                    lst[x][y] = x - i + 1;
                    x++;
                }
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (i < lst[i][j] * 3) continue;
            int x1 = i - lst[i][j], x2 = i - lst[i][j] * 2;
            if (a[x1][j] == a[i][j] || a[x2][j] == a[x1][j]) continue;
            if (lst[x1][j] != lst[i][j] || lst[x2][j] < lst[i][j]) continue;
            int l = 1, r = j;
            while (l < r){
                int mid = (l + r + 1) >> 1;
                if (!ck(i - lst[i][j] + 1, j - mid + 1, i, j, a[i][j] - 'a')
                 || !ck(x1 - lst[i][j] + 1, j - mid + 1, x1, j, a[x1][j] - 'a')
                 || !ck(x2 - lst[i][j] + 1, j - mid + 1, x2, j, a[x2][j] - 'a')){
                    r = mid - 1;
                }
                else{
                    l = mid;
                }
            }
            ans += l;
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