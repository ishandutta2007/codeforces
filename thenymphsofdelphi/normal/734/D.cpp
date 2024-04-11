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

const int N = 1e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int n;
int x0, y0;
int dist[8];
char near[8] = {'$', '$', '$', '$', '$', '$', '$', '$'};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    msetinf(dist);
    cin >> n;
    cin >> x0 >> y0;
    while (n--){
        char c; int x, y; cin >> c >> x >> y;
        if (abs(x - x0) == abs(y - y0)){
            int t = abs(x - x0);
            For(i, 0, 8){
                if (x0 + t * dx[i] == x && y0 + t * dy[i] == y){
                    if (dist[i] > t){
                        dist[i] = t;
                        near[i] = c;
                        break;
                    }
                }
            }
        }
        else if (abs(x - x0) == 0){
            int t = abs(y - y0);
            For(i, 0, 8){
                if (dx[i] == 0 && y0 + t * dy[i] == y){
                    if (dist[i] > t){
                        dist[i] = t;
                        near[i] = c;
                        break;
                    }
                }
            }
        }
        else if (abs(y - y0) == 0){
            int t = abs(x - x0);
            For(i, 0, 8){
                if (x0 + t * dx[i] == x && dy[i] == 0){
                    if (dist[i] > t){
                        dist[i] = t;
                        near[i] = c;
                        break;
                    }
                }
            }
        }
    }
    For(i, 0, 8){
        if (near[i] != '$'){
            // cout << i << ' ' << near[i] << endl;
            if (near[i] == 'Q') Ptest("YES");
            if (dx[i] == 0 || dy[i] == 0){
                if (near[i] == 'R') Ptest("YES");
            }
            else{
                if (near[i] == 'B') Ptest("YES");
            }
        }
    }
    cout << "NO";
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