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

const int N = 3e3 + 5, M = log2(N) + 1, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, k, L, R, mn_mv, mx_mv;
string s;
int a[N], b[N];
vvi vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s; s = ' ' + s;
    ForE(i, 1, n){
        if (s[i] == 'R'){
            R++;
            b[R] = i;
        }
        else{
            L++;
            a[L] = i;
        }
    }
    if (R == 0 || L == 0) Ptest(-1);
    ForE(i, 1, L){
        mx_mv += a[i] - i;
    }
    string t = s;
    while (1){
        vi pos;
        ForE(i, 2, n){
            if (t[i] == 'L' && t[i - 1] == 'R'){
                pos.pb(i - 1);
            }
        }
        if (pos.size() == 0) break;
        Fora(v, pos){
            swap(t[v], t[v + 1]);
        }
        mn_mv++;
    }
    if (k < mn_mv || k > mx_mv) Ptest(-1);
    int dif = k - mn_mv;
    ForE(j, 1, mn_mv){
        vi pos, tmp;
        ForE(i, 2, n){
            if (s[i] == 'L' && s[i - 1] == 'R'){
                pos.pb(i - 1);
            }
        }
        For(i, 0, min(dif, (int)pos.size() - 1)){
            tmp.pb(pos[i]);
            vans.pb(tmp);
            tmp.clear();
        }
        For(i, min(dif, (int)pos.size() - 1), pos.size()){
            tmp.pb(pos[i]);
        }
        vans.pb(tmp);
        dif -= min(dif, (int)pos.size() - 1);
        Fora(v, pos){
            swap(s[v], s[v + 1]);
        }
    }
    For(i, 0, k){
        cout << vans[i].size() << ' ';
        PrintV(vans[i]);
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