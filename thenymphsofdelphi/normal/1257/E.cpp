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

const int N = 2e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m, o, tN;
bool a[N], b[N], c[N];
int ta[N], tb[N], tc[N];
int t23[N], mnt23[N];
int dp1[N], dp2[N];
int ans = inf;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> o;
    ForE(i, 1, n){
        int x;
        cin >> x;
        a[x] = 1;
    }
    ForE(i, 1, m){
        int x;
        cin >> x;
        b[x] = 1;
    }
    ForE(i, 1, o){
        int x;
        cin >> x;
        c[x] = 1;
    }
    tN = n + m + o;
    ForE(i, 1, tN){
        ta[i] = ta[i - 1] + a[i];
        tb[i] = tb[i - 1] + b[i];
        tc[i] = tc[i - 1] + c[i];
    }
    ForE(i, 1, tN){
        t23[i] = t23[i - 1];
        if (b[i]){
            t23[i]--;
        }
        if (c[i]){
            t23[i]++;
        }
    }
    mnt23[tN + 1] = t23[tN];
    FordE(i, tN, 0){
        mnt23[i] = min(mnt23[i + 1], t23[i]);
    }
    ans = min(tN - o, tN - n);
    int sum1 = tN - o;
    ForE(i, 0, tN){
        if (a[i]){
            sum1--;
        }
        if (c[i]){
            sum1++;
        }
        //cout << sum1 << ' ' << mnt23[i] << ' ' << t23[i] << ' ' << endl;
        ans = min(ans, sum1 + mnt23[i] - t23[i]);
    }
    cout << ans;
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