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

#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, q;
int dp[N];
int a[N], b[N];
bool ck[N], ck2[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
        if (!ck2[b[i]]){
            ck2[b[i]] = 1;
            ck[i] = 1;
        }
    }
    while (q--){
        mset(dp);
        int x, y, mx1 = 0, mx2 = 0, colmx1 = 0, colmx2 = 0;
        cin >> x >> y;
        ForE(i, 1, n){
            if (ck[i]){
                dp[b[i]] = mx1 + y * a[i];
                if (dp[b[i]] >= mx1){
                    if (colmx1 != b[i]){
                        mx2 = mx1;
                        colmx2 = colmx1;
                    }
                    mx1 = dp[b[i]];
                    colmx1 = b[i];
                }
                else if (dp[b[i]] > mx2){
                    colmx2 = b[i];
                    mx2 = dp[b[i]];
                }
                continue;
            }
            dp[b[i]] = max(dp[b[i]], dp[b[i]] + x * a[i]);
            if (b[i] != colmx1){
                dp[b[i]] = max(dp[b[i]], mx1 + y * a[i]);
            }
            else{
                dp[b[i]] = max(dp[b[i]], mx2 + y * a[i]);
            }
            if (dp[b[i]] >= mx1){
                if (colmx1 != b[i]){
                    mx2 = mx1;
                    colmx2 = colmx1;
                }
                mx1 = dp[b[i]];
                colmx1 = b[i];
            }
            else if (dp[b[i]] > mx2){
                colmx2 = b[i];
                mx2 = dp[b[i]];
            }
        }
        cout << mx1 << endl;
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