#include<bits/stdc++.h>
using namespace std;

// Shortcut

#pragma optimize ("O3")
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

const int N = 17, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m, ans;
int a[N], b[N], fact[N];
int dp[N][N][N][4];
int x = 0, y = 0, z = 0, t = 0;

void print(int xx, int yy, int zz){
    cout << dp[xx][yy][zz][1] << ' ' << dp[xx][yy][zz][2] << ' ' << dp[xx][yy][zz][3] << endl;
}

void bt(int u){
    if (u == n + 1){
        if (t == m){
            ans += (dp[x][y][z][1] + dp[x][y][z][2] + dp[x][y][z][3]) % mod * fact[x] % mod * fact[y] % mod * fact[z] % mod;
            //cout << x << ' ' << y << ' ' << z << endl;
            //print(x, y, z);
            ans %= mod;
        }
        return;
    }
    bt(u + 1);
    t += a[u];
    if (b[u] == 1) x++;
    if (b[u] == 2) y++;
    if (b[u] == 3) z++;
    bt(u + 1);
    t -= a[u];
    if (b[u] == 1) x--;
    if (b[u] == 2) y--;
    if (b[u] == 3) z--;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fact[0] = 1;
    For(i, 1, N){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ForE(i, 0, 15){ // 1
        ForE(j, 0, 15){ // 2
            ForE(k, 0, 15){ // 3
                if (!i && !j && !k){
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 0;
                    dp[i][j][k][3] = 0;
                    continue;
                }
                if (k > i + j + 1 || j > i + k + 1 || i > j + k + 1){
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 0;
                    dp[i][j][k][3] = 0;
                    continue;
                }
                if (!i && !j){
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 0;
                    dp[i][j][k][3] = 1;
                    continue;
                }
                if (!j && !k){
                    dp[i][j][k][1] = 1;
                    dp[i][j][k][2] = 0;
                    dp[i][j][k][3] = 0;
                    continue;
                }
                if (!k && !i){
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 1;
                    dp[i][j][k][3] = 0;
                    continue;
                }
                if (i){
                    dp[i][j][k][1] += dp[i - 1][j][k][2] + dp[i - 1][j][k][3];
                    dp[i][j][k][1] %= mod;
                }
                if (j){
                    dp[i][j][k][2] += dp[i][j - 1][k][1] + dp[i][j - 1][k][3];
                    dp[i][j][k][2] %= mod;
                }
                if (k){
                    dp[i][j][k][3] += dp[i][j][k - 1][1] + dp[i][j][k - 1][2];
                    dp[i][j][k][3] %= mod;
                }
            }
        }
    }
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i] >> b[i];
    }
    bt(1);
    cout << ans << endl;
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