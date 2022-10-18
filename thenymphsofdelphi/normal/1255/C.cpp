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

const int N = 3e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m, k;
int q = 1, ans, res, tmp, idx, cnt, sum;
int x, y, z;
string s, t;
int a[N];
int b[N];
map <pii, pii> mpp;
int t1, t2, tn1, tn;
int x1, x2, x3;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//cin >> q;
while (q--){
    cin >> n;
    ForE(i, 3, n){
        cin >> x >> y >> z;
        b[x]++;
        b[y]++;
        b[z]++;
        if (mpp.find({x, y}) == mpp.end()){
            mpp[{x, y}] = {z, 0};
            mpp[{y, x}] = {z, 0};
        }
        else{
            tmp = mpp[{x, y}].fi;
            mpp[{x, y}] = {tmp, z};
            mpp[{y, x}] = {tmp, z};
        }
        if (mpp.find({y, z}) == mpp.end()){
            mpp[{y, z}] = {x, 0};
            mpp[{z, y}] = {x, 0};
        }
        else{
            tmp = mpp[{y, z}].fi;
            mpp[{y, z}] = {tmp, x};
            mpp[{z, y}] = {tmp, x};
        }
        if (mpp.find({z, x}) == mpp.end()){
            mpp[{z, x}] = {y, 0};
            mpp[{x, z}] = {y, 0};
        }
        else{
            tmp = mpp[{z, x}].fi;
            mpp[{z, x}] = {tmp, y};
            mpp[{x, z}] = {tmp, y};
        }
    }
    ForE(i, 1, n){
        if (b[i] == 1){
            if (t1 == 0){
                t1 = i;
            }
            else{
                tn = i;
            }
        }
        if (b[i] == 2){
            if (t2 == 0){
                t2 = i;
            }
            else{
                tn1 = i;
            }
        }
    }
    if (mpp.find({t1, t2}) == mpp.end()){
        swap(t2, tn1);
    }
    //cout << t1 << ' ' << t2 << ' ' << tn1 << ' ' << tn << endl;
    x1 = t1;
    x2 = t2;
    x3 = mpp[{x1, x2}].fi;
    a[1] = x1;
    a[2] = x2;
    a[3] = x3;
    ForE(i, 4, n){
        pii ptmp = mpp[{x2, x3}];
        if (ptmp.fi != x1){
            x1 = x2;
            x2 = x3;
            x3 = ptmp.fi;
        }
        else{
            x1 = x2;
            x2 = x3;
            x3 = ptmp.se;
        }
        a[i] = x3;
    }
    ForE(i, 1, n){
        cout << a[i] << ' ';
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