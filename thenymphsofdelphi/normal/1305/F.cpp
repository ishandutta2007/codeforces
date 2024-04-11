#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

// #define int long long
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
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

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

const int N = 2e5 + 5, ITER = 4e6, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
ll a[N];
ll ans = infll;

void gay(){
    int idx = rando() % n + 1;
    ll val = a[idx], tval, tans;
    tval = val - 1;
    if (tval >= 1){
        for (int i = 2; (ll)i * i <= tval; i++){
            if (tval % i == 0){
                tans = 0;
                ForE(j, 1, n){
                    int md = (a[j] >= i ? a[j] % i : a[j]);
                    if (a[j] < i) tans += i - md;
                    else tans += min(md, i - md);
                }
                // cout << val << ' ' << i << ' ' << tans << endl;
                ans = min(ans, tans);
                while (tval % i == 0) tval /= i;
            }
        }
        if (tval != 1){
            tans = 0;
            ForE(j, 1, n){
                ll md = (a[j] >= tval ? a[j] % tval : a[j]);
                if (a[j] < tval) tans += tval - md;
                else tans += min(md, tval - md);
            }
            // cout << val << ' ' << tval << ' ' << tans << endl;
            ans = min(ans, tans);
        }
    }
    tval = val;
    for (int i = 2; (ll)i * i <= tval; i++){
        if (tval % i == 0){
            tans = 0;
            ForE(j, 1, n){
                int md = (a[j] >= i ? a[j] % i : a[j]);
                if (a[j] < i) tans += i - md;
                else tans += min(md, i - md);
            }
            // cout << val << ' ' << i << ' ' << tans << endl;
            ans = min(ans, tans);
            while (tval % i == 0) tval /= i;
        }
    }
    if (tval != 1){
        tans = 0;
        ForE(j, 1, n){
            ll md = (a[j] >= tval ? a[j] % tval : a[j]);
            if (a[j] < tval) tans += tval - md;
            else tans += min(md, tval - md);
        }
        // cout << val << ' ' << tval << ' ' << tans << endl;
        ans = min(ans, tans);
    }
    tval = val + 1;
    for (int i = 2; (ll)i * i <= tval; i++){
        if (tval % i == 0){
            tans = 0;
            ForE(j, 1, n){
                int md = (a[j] >= i ? a[j] % i : a[j]);
                if (a[j] < i) tans += i - md;
                else tans += min(md, i - md);
            }
            // cout << val << ' ' << i << ' ' << tans << endl;
            ans = min(ans, tans);
            while (tval % i == 0) tval /= i;
        }
    }
    if (tval != 1){
        tans = 0;
        ForE(j, 1, n){
            ll md = (a[j] >= tval ? a[j] % tval : a[j]);
            if (a[j] < tval) tans += tval - md;
            else tans += min(md, tval - md);
        }
        // cout << val << ' ' << tval << ' ' << tans << endl;
        ans = min(ans, tans);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, 20){
        gay();
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