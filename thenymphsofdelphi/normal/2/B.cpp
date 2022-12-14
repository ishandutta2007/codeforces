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

const int N = 1e3 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
bool ck;
int xx, yy;
int a[N][N], b[N][N], dp1[N][N], dp2[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        ForE(j, 1, n){
            int x;
            cin >> x;
            if (x == 0){
                ck = 1;
                xx = i;
                yy = j;
                a[i][j] = 1;
                b[i][j] = 1;
            }
            else{
                while (x % 2 == 0){
                    a[i][j]++;
                    x /= 2;
                }
                while (x % 5 == 0){
                    b[i][j]++;
                    x /= 5;
                }
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (i == 1 && j == 1){
                dp1[i][j] = a[i][j];
                dp2[i][j] = b[i][j];
                continue;
            }
            if (i == 1){
                dp1[i][j] = dp1[i][j - 1] + a[i][j];
                dp2[i][j] = dp2[i][j - 1] + b[i][j];
                continue;
            }
            if (j == 1){
                dp1[i][j] = dp1[i - 1][j] + a[i][j];
                dp2[i][j] = dp2[i - 1][j] + b[i][j];
                continue;
            }
            dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
            dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + b[i][j];
        }
    }
    if (min(dp1[n][n], dp2[n][n]) >= 1 && ck){
        cout << 1 << endl;
        string s = "";
        For(i, 1, xx) s += 'D';
        For(i, 1, yy) s += 'R';
        For(i, xx, n) s += 'D';
        For(i, yy, n) s += 'R';
        cout << s;
        return 0;
    }
    cout << min(dp1[n][n], dp2[n][n]) << endl;
    if (dp1[n][n] < dp2[n][n]){
        string s = "";
        int x = n, y = n;
        while (x != 1 || y != 1){
            if (x == 1){
                s += 'R';
                y--;
                continue;
            }
            if (y == 1){
                s += 'D';
                x--;
                continue;
            }
            if (dp1[x][y - 1] < dp1[x - 1][y]){
                s += 'R';
                y--;
                continue;
            }
            else{
                s += 'D';
                x--;
                continue;
            }
        }
        reverse(bend(s));
        cout << s;
    }
    else{
        string s = "";
        int x = n, y = n;
        while (x != 1 || y != 1){
            if (x == 1){
                s += 'R';
                y--;
                continue;
            }
            if (y == 1){
                s += 'D';
                x--;
                continue;
            }
            if (dp2[x][y - 1] < dp2[x - 1][y]){
                s += 'R';
                y--;
                continue;
            }
            else{
                s += 'D';
                x--;
                continue;
            }
        }
        reverse(bend(s));
        cout << s;
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