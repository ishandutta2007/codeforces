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

const int N = 2e3 + 5, M = 2e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int h, w, n;
int fac[M], invfac[M];
int dp[N];
vpii a;

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = (1ll * ans * x) % mod;
        x = (1ll * x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int cal(int x, int y){
    int ans = (invfac[x] * invfac[y - x]) % mod;
    ans = (ans * fac[y]) % mod;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fac[0] = 1;
    invfac[0] = 1;
    For(i, 1, M){
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = binpow(fac[i], mod - 2);
    }
    cin >> h >> w >> n;
    For(i, 0, n){
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }
    a.pb({h, w});
    sort(bend(a));
    ForE(i, 0, n){
        dp[i] = cal(a[i].fi - 1, a[i].fi + a[i].se - 2);
        For(j, 0, i){
            if (a[j].fi <= a[i].fi && a[j].se <= a[i].se){
                dp[i] = (dp[i] - dp[j] * cal((a[i].fi - a[j].fi) % mod, (a[i].fi + a[i].se - a[j].fi - a[j].se) % mod)) % mod;
			    if (dp[i] < 0){
			        dp[i] += mod;
			    }
            }
        }
    }
    cout << dp[n];
}

/*
==================================+
INPUT:                            |
------------------------------    |
3 4 2
2 2
2 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/