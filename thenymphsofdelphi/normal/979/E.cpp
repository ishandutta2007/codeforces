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

const int N = 50 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, p, ans;
int a[N], pw[N], fac[N], invfac[N];
int odd[N], even[N];
int dp[N][N][N][N];

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int C(int x, int y){
    return ((fac[x] * invfac[y]) % mod * invfac[x - y]) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dp[0][0][0][0] = 1;
    pw[0] = 1;
    fac[0] = 1;
    For(i, 1, N){
        pw[i] = (pw[i - 1] * 2) % mod;
        fac[i] = (fac[i - 1] * i) % mod;
    }
    invfac[N - 1] = binpow(fac[N - 1], mod - 2);
    FordE(i, N - 2, 0){
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
    For(i, 0, N){
        ForE(j, 0, i){
            if (j & 1){
                odd[i] = (odd[i] + C(i, j)) % mod;
            }
            else{
                even[i] = (even[i] + C(i, j)) % mod;
            }
        }
    }
    cin >> n >> p;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        ForE(ob, 0, i){
            ForE(eb, 0, i - ob){
                ForE(ow, 0, i - ob - eb){
                    int ew = i - ob - eb - ow;
                    if (a[i] != 0 && ew != 0){
                        dp[ob][eb][ow][ew] = (dp[ob][eb][ow][ew] + ((dp[ob][eb][ow][ew - 1] * pw[ow + ew - 1 + eb]) % mod * odd[ob]) % mod) % mod;
                    }
                    if (a[i] != 0 && ow != 0){
                        dp[ob][eb][ow][ew] = (dp[ob][eb][ow][ew] + ((dp[ob][eb][ow - 1][ew] * pw[ow - 1 + ew + eb]) % mod * even[ob]) % mod) % mod;
                    }
                    if (a[i] != 1 && eb != 0){
                        dp[ob][eb][ow][ew] = (dp[ob][eb][ow][ew] + ((dp[ob][eb - 1][ow][ew] * pw[ob + eb - 1 + ew]) % mod * odd[ow]) % mod) % mod;
                    }
                    if (a[i] != 1 && ob != 0){
                        dp[ob][eb][ow][ew] = (dp[ob][eb][ow][ew] + ((dp[ob - 1][eb][ow][ew] * pw[ob - 1 + eb + ew]) % mod * even[ow]) % mod) % mod;
                    }
                    if (i == n && ((ob + ow) & 1) == p){
                        ans = (ans += dp[ob][eb][ow][ew]) % mod;
                    }
                }
            }
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