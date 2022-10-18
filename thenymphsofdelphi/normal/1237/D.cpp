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

const int N = 3e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
int a[N], b[N];
int mx = -inf, mn = inf;

int lg[N];
int rmq[N][21];

int query(int l, int r){
    int k = lg[r - l + 1];
    return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

int md(int x){
    return (x - 1) % n + 1;
}

int dis(int l, int r){
    return r - l;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (mn * 2 >= mx){
        ForE(i, 1, n){
            cout << -1 << ' ';
        }
        return 0;
    }
    lg[1] = 0;
    For(i, 2, N){
        lg[i] = lg[i / 2] + 1;
    }
    ForE(i, 1, 3 * n){
        rmq[i][0] = a[md(i)];
    }
    ForE(j, 1, 20){
        ForE(i, 1, 3 * n - (1 << j)){
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    ForE(i, 1, n){
        if (mn * 2 >= a[i]){
            b[i] = inf;
            continue;
        }
        int l = 1, r = n - 1;
        while (l < r){
            int mid = (l + r) >> 1;
            if (query(i + 1, i + mid) * 2 < a[i]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        b[i] = l;
    }
    ForE(i, 1, 3 * n){
        rmq[i][0] = i + b[md(i)];
    }
    ForE(j, 1, 20){
        ForE(i, 1, 3 * n - (1 << j)){
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    ForE(i, 1, n){
        int l = 1, r = 2 * n;
        //cout << i << endl;
        while (l < r){
            int mid = (l + r) >> 1;
            //cout << l << ' ' << r << ' ' << mid << endl;
            //cout << query(i + 1, i + mid) << ' ' << i + mid << endl;
            if (query(i, i + mid) <= i + mid){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << l << ' ';
        //cout << endl;
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