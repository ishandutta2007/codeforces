#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

const int N = 2e4 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int a, b, c;
vi divi[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
ForE(i, 1, 20000){
    for (int j = 1; j * j <= i; j++){
        if (i % j == 0){
            divi[i].pb(j);
            divi[i].pb(i / j);
            if (j * j == i) divi[i].pob();
        }
    }
    sort(bend(divi[i]));
}
int q = 1;
cin >> q;
while (q--){
    int ans = inf, ansa, ansb, ansc;
    cin >> a >> b >> c;
    ForE(i, 1, 2 * c){
        int tmp = abs(b - i), ta, tc;
        if (a >= i){
            tmp += abs(a - i);
            ta = i;
        }
        else{
            int idx = lwb(bend(divi[i]), a) - divi[i].begin();
            if (divi[i][idx] != a){
                tmp += min(abs(divi[i][idx - 1] - a), abs(divi[i][idx] - a));
                ta = (abs(divi[i][idx - 1] - a) < abs(divi[i][idx] - a) ? divi[i][idx - 1] : divi[i][idx]);
            }
            else{
                ta = divi[i][idx];
            }
        }
        if (c % i){
            tmp += min(abs(c / i * i - c), abs(c / i * i + i - c));
            tc = (abs(c / i * i - c) < abs(c / i * i + i - c) ? c / i * i : c / i * i + i);
        }
        else{
            tc = c;
        }
        if (ans > tmp){
            ans = tmp;
            ansa = ta; ansb = i; ansc = tc;
        }
    }
    cout << ans << endl << ansa << ' ' << ansb << ' ' << ansc << endl;
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