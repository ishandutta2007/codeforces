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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, w, h;
pii ans[N];
map <int, vector <pair <pii, int>>> mpp;

bool cmp(pair <pii, int> x, pair <pii, int> y){
    if (x.fi.fi != y.fi.fi) return x.fi.fi > y.fi.fi;
    if (x.fi.fi == 2){
        return x.fi.se > y.fi.se;
    }
    else{
        return x.fi.se < y.fi.se;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> w >> h;
    ForE(i, 1, n){
        int g, p, t; cin >> g >> p >> t;
        if (mpp.find(p - t) == mpp.end()){
            mpp[p - t] = {{{g, p}, i}};
        }
        else{
            mpp[p - t].pb({{g, p}, i});
        }
    }
    Fora(v, mpp){
        // cout << v.fi << endl;
        vector <pair <pii, int>> v1, v2, vall;
        vall = v.se;
        sort(bend(vall), cmp);
        Fora(u, vall){
            if (u.fi.fi == 1) v1.pb(u);
            else v2.pb(u);
            // cout << u.fi.fi << ' ' << u.fi.se << ' ' << u.se << endl;
        }
        int idx = 0;
        For(i, 0, vall.size()){
            if (i < v1.size()){
                ans[vall[i].se] = {v1[idx].fi.se, h};
                idx++;
            }
            else{
                ans[vall[i].se] = {w, v2[idx].fi.se};
                idx++;
            }
            if (i == v1.size() - 1) idx = 0;
        }
    }
    ForE(i, 1, n){
        cout << ans[i].fi << ' ' << ans[i].se << endl;
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