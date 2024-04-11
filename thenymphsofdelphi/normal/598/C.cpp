#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
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
typedef pair <ld, ld> pdd;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

const ld pi = 3.14159265358979323;
int n;
pdd a;
vector <pdd > b;
ld mn = inf;

ld cnv(ld x){
    return (1.0 * x * 180.0 / pi);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 2) Ptest("1 2");
    ForE(i, 1, n){
        cin >> a.fi >> a.se;
        if (a.fi == 0){
            if (a.se > 0){
                b.pb({0, i});
            }
            else{
                b.pb({180, i});
                b.pb({-180, i});
            }
            continue;
        }
        if (a.se == 0){
            if (a.fi < 0){
                b.pb({-90, i});
            }
            else{
                b.pb({90, i});
            }
        }
        if (a.fi > 0 && a.se > 0){
            b.pb({cnv(asin(a.fi / sqrt(a.fi * a.fi + a.se * a.se))), i});
        }
        if (a.fi > 0 && a.se < 0){
            b.pb({90 + cnv(asin(-a.se / sqrt(a.fi * a.fi + a.se * a.se))), i});
        }
        if (a.fi < 0 && a.se > 0){
            b.pb({cnv(asin(a.se / sqrt(a.fi * a.fi + a.se * a.se))) - 90, i});
        }
        if (a.fi < 0 && a.se < 0){
            b.pb({cnv(asin(-a.fi / sqrt(a.fi * a.fi + a.se * a.se))) - 180, i});
        }
    }
    sort(bend(b));
    if (b[0].fi != -180){
        b.pb({b[0].fi + 360, b[0].se});
    }
    For(i, 1, b.size()){
        mn = min(mn, min(b[i].fi - b[i - 1].fi, 360 - b[i].fi + b[i - 1].fi));
    }
    For(i, 1, b.size()){
        if (min(b[i].fi - b[i - 1].fi, 360 - b[i].fi + b[i - 1].fi) == mn){
            cout << b[i - 1].se << ' ' << b[i].se;
            return 0;
        }
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