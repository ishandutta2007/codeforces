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

const int N = 1e5 + 5, K = sqrt(N), mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, q;
int a[N]; // power
int b[N]; // next hole in different block
int c[N]; // count of hole in block
int bl[N]; // index of block

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    bl[0] = -1;
    ForE(i, 1, n){
        cin >> a[i];
        bl[i] = i / K;
    }
    a[n + 1] = inf;
    b[n + 1] = inf;
    c[n + 1] = 1;
    bl[n + 1] = n / K + 1;
    FordE(i, n, 1){
        int x = a[i] + i;
        if (x > n + 1) x = n + 1;
        if (bl[x] != bl[i]){
            b[i] = x;
            c[i] = 1;
        }
        else{
            b[i] = b[x];
            c[i] = 1 + c[x];
        }
    }
    while (q--){
        int que, idx, val;
        cin >> que;
        if (que == 1){
            cin >> idx;
            int x = idx, y = 0, z;
            while (b[x] != n + 1){
                y += c[x];
                x = b[x];
            }
            while (x != n + 1){
                z = x;
                x += a[x];
                if (x > n + 1) x = n + 1;
                y++;
            }
            cout << z << ' ' << y << endl;
        }
        else{
            cin >> idx >> val;
            a[idx] = val;
            int i = idx;
            while (bl[i] == bl[idx]){
                int x = a[i] + i;
                if (x > n + 1) x = n + 1;
                if (bl[x] != bl[i]){
                    b[i] = x;
                    c[i] = 1;
                }
                else{
                    b[i] = b[x];
                    c[i] = 1 + c[x];
                }
                i--;
            }
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