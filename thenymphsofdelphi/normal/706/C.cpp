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

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
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

#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(bend(a));
#define sortA(a, n) sort(a, a + n);
#define rev(s) reverse(bend(s));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
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

const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int a[N];
int dp[N][2];
string b[N], c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ForE(i, 1, n) cin >> a[i];
    ForE(i, 1, n){
        cin >> b[i];
        c[i] = b[i];
        reverse(c[i].begin(), c[i].end());
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    dp[1][0] = 0;
    dp[1][1] = a[1];
    ForE(i, 2, n){
        if (b[i] >= b[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (b[i] >= c[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (c[i] >= b[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        if (c[i] >= c[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
    }
    if (dp[n][0] < inf || dp[n][1] < inf) cout << min(dp[n][0], dp[n][1]);
    else cout << -1;
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