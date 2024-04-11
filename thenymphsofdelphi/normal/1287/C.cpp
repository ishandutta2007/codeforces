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

const int N = 1e5 + 5, M = 1e6 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9;
const ll infll = 1e18 + 7;

int q = 1;
int n, m, k;
int x, y, z;
int ans, tmp, cnt, sum, idx, cur, len, lst = -1;
int a[N], b[N];
vpii c[2];
vi d[2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//cin >> q;
while (q--){
    int n;
    cin >> n;
    x = (n + 1) / 2, y = n - x;
    ForE(i, 1, n){
        cin >> a[i];
        if (a[i] == 0) continue;
        if (a[i] & 1) x--;
        else y--;
    }
    ForE(i, 1, n){
        if (a[i] == 0){
            cnt++;
        }
        else{
            if (i == 1){
                lst = a[i];
                continue;
            }
            if (!cnt){
                if ((a[i] - a[i - 1]) % 2){
                    ans++;
                }
                lst = a[i];
                continue;
            }
            if (lst == -1){
                d[a[i] & 1].pb(cnt);
                cnt = 0;
                lst = a[i];
                ans++;
                continue;
            }
            if ((a[i] - lst + inf) % 2 == 0){
                c[a[i] & 1].pb({cnt, 0});
                ans += 2;
            }
            else{
                ans++;
            }
            cnt = 0;
            lst = a[i];
            //cout << i << ' ' << ans << endl;
        }
    }
    if (cnt){
        d[lst & 1].pb(cnt);
        ans++;
    }
    if (d[0].size() == 2){
        c[0].pb({d[0][0] + d[0][1], 1});
    }
    if (d[1].size() == 2){
        c[1].pb({d[1][0] + d[1][1], 1});
    }
    sort(bend(c[0]));
    sort(bend(c[1]));
    sort(bend(d[0]));
    sort(bend(d[1]));
    // Fora(v, c[0]) cout << v.fi << ' '; cout << endl;
    // Fora(v, c[1]) cout << v.fi << ' '; cout << endl;
    // PrintV(d[0]); cout << endl;
    // PrintV(d[1]); cout << endl;
    // cout << x << ' ' << y << ' ' << ans << endl;
    Fora(v, c[1]){
        if (x >= v.fi){
            x -= v.fi;
            ans -= 2;
            if (v.se == 1){
                d[1].clear();
            }
        }
        else{
            break;
        }
    }
    Fora(v, d[1]){
        if (x >= v){
            x -= v;
            ans--;
        }
        else{
            break;
        }
    }
    Fora(v, c[0]){
        if (y >= v.fi){
            y -= v.fi;
            ans -= 2;
            if (v.se == 1){
                d[0].clear();
            }
        }
        else{
            break;
        }
    }
    Fora(v, d[0]){
        if (y >= v){
            y -= v;
            ans--;
        }
        else{
            break;
        }
    }
    cout << ans;
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