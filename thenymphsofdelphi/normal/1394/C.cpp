#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

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

const int N = 5e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e6 + 7;
ll infll = 1e18 + 7;

int n;
pii a[N];

int l, r; // left and right limit, calculated by x
int d, u; // up and down limit, calculated by y
int dl, ur; // down-left and up-right, calculated by x + y
int dr, ul; //down-right and up-left, calculated by x - y

void calmid(int mid){
    // Oxy plane
    // All are inclusive
    l = 0, r = inf; // left and right limit, calculated by x
    d = 0, u = inf; // up and down limit, calculated by y
    dl = 1, ur = inf + inf; // down-left and up-right, calculated by x + y \\
                                   1 because non-empty
    ul = -inf, dr = inf; // up-left and down-right, calculated by x - y
    ForE(i, 1, n){
        l = max(l, a[i].fi - mid);
        r = min(r, a[i].fi + mid);
        d = max(d, a[i].se - mid);
        u = min(u, a[i].se + mid);
        dl = max(dl, a[i].fi + a[i].se - 2 * mid);
        ur = min(ur, a[i].fi + a[i].se + 2 * mid);
        ul = max(ul, a[i].fi - a[i].se - mid);
        dr = min(dr, a[i].fi - a[i].se + mid);
    }
    return;
}

pii find(){
    pii ans = {-2, -2};
    if (l > r || d > u || dl > ur || ul > dr){
        return {-1, -1};
    }
    ForE(x, l, r){
        int ly = d, ry = u;
        ly = max(ly, dl - x); ry = min(ry, ur - x);
        ly = max(ly, x - dr); ry = min(ry, x - ul);
        if (ly > ry) continue;
        return {x, ly};
    }
    return {-1, -1};
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        string s; cin >> s;
        int x = 0, y = 0;
        Fora(&v, s){
            if (v == 'B') x++;
            else y++;
        }
        a[i] = {x, y};
    }
    int l = 0, r = inf;
    while (l < r){
        int mid = (l + r) >> 1;
        calmid(mid);
        pii kek = find();
        if (kek.fi == -1){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    calmid(l);
    pii ans = find();
    cout << l << endl;
    ForE(i, 1, ans.fi) cout << 'B';
    ForE(i, 1, ans.se) cout << 'N';
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