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

const int N = 5e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, k;
int par[N];
int child[N];
int layer[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> k;
    ForE(i, 1, n){
        par[i] = i - 1;
        child[i] = 1;
        layer[i] = i - 1;
    }
    child[n] = 0;
    int mn = 0, mx = 0;
    int _layer = 1, _cnt = 1;
    ForE(i, 2, n){
        mn += _layer;
        _cnt++;
        if (_cnt > (1 << _layer)){
            _cnt = 1;
            _layer++;
        }
        mx += i - 1;
    }
    if (k < mn || k > mx){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    // cout << mx << endl;
    FordE(j, n, 1){
        int cur_mn = inf, cur_node;
        ForE(i, 1, n){
            if (child[i] < 2 && i != j){
                if (mx - layer[j] + (layer[i] + 1) < k){
                    continue;
                }
                if (mx - layer[j] + (layer[i] + 1) == k){
                    cur_mn = layer[i] + 1;
                    cur_node = i;
                    break;
                }
                if (layer[i] + 1 < cur_mn){
                    cur_mn = layer[i] + 1;
                    cur_node = i;
                }
            }
        }
        // cout << cur_mn << ' ' << cur_node << endl;
        mx = mx - layer[j] + cur_mn;
        child[par[j]]--;
        par[j] = cur_node;
        child[cur_node]++;
        layer[j] = cur_mn;
        if (mx == k){
            break;
        }
        // cout << mx << endl;
        // PrintA(par, 2, n);
    }
    PrintA(par, 2, n);
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