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

const int N = 1e5 + 5, mod = 1e9 + 7;
const ld inf = 1e14 + 7;

pair <ld, ld> a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << setpre(6);
    int n, cnt = 0;
    ld l = 0.0, r = inf, mid;
    ld mn, mx;
    ld dis, ckpre = 1e-6;
    bool ck1 = 0, ck2 = 0, ck3 = 0;
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        if (a[i].se > 0) ck1 = 1;
        if (a[i].se < 0){
            ck2 = 1;
            a[i].se = -a[i].se;
        }
        if (a[i].se == 0){
            if (ck3) Ptest(-1);
            ck3 = 1;
        }
    }
    if (n == 1) Ptest(a[1].se / 2.0);
    if (ck1 && ck2) Ptest(-1);
    while (l + ckpre <= r){
        mn = -inf;
        mx = inf;
        mid = (l + r) / 2.0;
        ForE(i, 1, n){
            if (a[i].se > 2 * mid){
                l = mid + ckpre;
                break;
            }
            dis = sqrtl(a[i].se) * sqrtl(2 * mid - a[i].se);
            mn = max(mn, a[i].fi - dis);
            mx = min(mx, a[i].fi + dis);
            if (i == n){
                if (mx >= mn){
                    r = mid;
                }
                else{
                    l = mid + ckpre;
                }
            }
        }
        cnt++;
        if (cnt == 500){
            break;
        }
    }
    cout << r;
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