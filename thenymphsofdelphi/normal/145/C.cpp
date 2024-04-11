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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, k, cnt, ans;
int dp[N];
int fac[N], invfac[N];
map <int, int> mpp;

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int C(int x, int y){
    if (x < y || x < 0 || y < 0){
        return 0;
    }
    return ((fac[x] * invfac[y]) % mod * invfac[x - y]) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fac[0] = 1;
    invfac[0] = 1;
    invfac[1] = 1;
    For(i, 1, N){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    For(i, 2, N){
        invfac[i] = ((mod - mod / i) * invfac[mod % i]) % mod;
    }
    For(i, 1, N){
        invfac[i] = (invfac[i - 1] * invfac[i]) % mod;
    }
    cin >> n >> k;
    ForE(i, 1, n){
        int x, y, ck = 1;
        cin >> x;
        y = x;
        while (x){
            if (x % 10 != 4 && x % 10 != 7){
                ck = 0;
                break;
            }
            x /= 10;
        }
        if (ck){
            mpp[y]++;
        }
        else{
            cnt++;
        }
    }
    dp[0] = 1;
    int idx = 0;
    for (auto it = mpp.begin(); it != mpp.end(); it++){
        int t = it -> se;
        FordE(i, idx, 0){
            if (dp[i]){
                dp[i + 1] = (dp[i + 1] + (dp[i] * t) % mod) % mod;
            }
        }
        idx++;
    }
    ForE(i, 0, n){
        ans = (ans + (dp[i] * C(cnt, k - i)) % mod) % mod;
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