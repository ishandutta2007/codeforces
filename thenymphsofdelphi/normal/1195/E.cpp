#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define endl '\n'
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
#define mset(a) memset(a, 0, sizeof(a));
#define m1set(a) memset(a, -1, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
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

const int N = 3e3 + 5, mod = 998244353, inf = 1e9 + 7;

int n, m, p, q, ans;
int a[N][N], dp[N][N];
ll g0, x, y, z;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> p >> q;
    cin >> g0 >> x >> y >> z;
    int xx = 1, yy = 1;
    while (xx != n || yy != m){
        a[xx][yy] = g0;
        g0 = (g0 * x + y) % z;
        yy++;
        if (yy == m + 1){
            yy = 1;
            xx++;
        }
    }
    a[xx][yy] = g0;
    int ans = 0;
    ForE(i, 1, n){
        deque <int> dq;
        ForE(j, 1, m){
            while (!dq.empty() && a[i][dq.back()] > a[i][j]){
                dq.pob();
            }
            dq.pb(j);
            if (dq.front() <= j - q){
                dq.pop_front();
            }
            dp[i][j] = dq.front();
        }
        dq.clear();
    }
    ForE(j, q, m){
        deque <int> dq;
        ForE(i, 1, n){
            while (!dq.empty() && a[dq.back()][dp[dq.back()][j]] > a[i][dp[i][j]]){
                dq.pob();
            }
            dq.pb(i);
            if (dq.front() <= i - p){
                dq.pop_front();
            }
            if (i >= p){
                ans += a[dq.front()][dp[dq.front()][j]];
            }
        }
        dq.clear();
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

------------- -----------------    |
==================================+
*/