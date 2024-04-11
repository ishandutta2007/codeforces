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

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int f, w, h;
int fac[N], invfac[N];

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

int num(int r, int b, int k){
    if(b == 0) return 1;
    int ans = 0;
    for(int u = 1; u <= r + 1 && (k == 0 || u <= (b - 1) / k); ++u){
        ans += 1LL * C(r + 1,u) * C(b - k * u - 1, u - 1) % mod;
        ans %= mod;
    }
    return ans;
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
    cin >> f >> w >> h;
    int nume = 0, deno = C(f + w, w);
    if (w == 0){
        nume = 1;
    }
    else{
        ForE(i, 1, f + 1){
            if (h != 0 && i > (w - 1) / h){
                break;
            }
            nume += (C(f + 1, i) * C(w - h * i - 1, i - 1)) % mod;
            nume %= mod;
        }
    }
    int ans = (nume * binpow(deno, mod - 2)) % mod;
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