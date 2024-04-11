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

const int N = 1e6 + 5, mod1 = 1e9 + 7, mod = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

ll n;
ll fac[N], invfac[N];
ll ans, ans1, ans2;

ll binpow(ll x, ll y){
    ll ans = 1;
    while (y){
        if (y & 1ll) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

ll C(int n, int k){
    return (fac[n] * ((invfac[k] * invfac[n - k]) % mod)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fac[0] = 1; invfac[0] = 1;
    ForE(i, 1, n){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    invfac[n] = binpow(fac[n], mod - 2);
    FordE(i, n - 1, 1){
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
    ForE(i, 1, n){
        ll tmp = (C(n, i) * binpow(3, n * (n - i) + i)) % mod;
        if (!(i & 1)) tmp = mod - tmp;
        ans1 = (ans1 + tmp) % mod;
    }
    ans1 = (ans1 * 2) % mod;
    //cout << ans1 << endl;
    For(i, 0, n){
        ll t = mod - binpow(3, i);
        ll tmp = (binpow(1 + t, n) + mod - binpow(t, n)) % mod;
        tmp = (tmp * C(n, n - i)) % mod;
        if (!(i & 1)) tmp = mod - tmp;
        ans2 = (ans2 + tmp) % mod;
    }
    ans2 = (ans2 * 3) % mod;
    //cout << ans2 << endl;
    ans = (ans1 + ans2) % mod;
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