#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
//#define endl '\n'
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
#define mset(a) memset(a, 0, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int a[6] = {4, 8, 15, 16, 23, 42};

pii cal(int x){
    For(i, 1, 6){
        For(j, 0, i){
            if (a[i] * a[j] == x) return {a[i], a[j]};
        }
    }
    return {4, 16};
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int b[7];
    int x, y, z, t;
    pii xx, yy, zz, tt;
    cout << "? 1 2" << endl;
    cin >> x;
    cout << "? 2 3" << endl;
    cin >> y;
    cout << "? 4 5" << endl;
    cin >> z;
    cout << "? 5 6" << endl;
    cin >> t;
    xx = cal(x);
    yy = cal(y);
    zz = cal(z);
    tt = cal(t);
    if (xx.fi == yy.fi || xx.fi == yy.se){
        b[2] = xx.fi;
        b[1] = xx.se;
        b[3] = yy.fi * yy.se / xx.fi;
    }
    else{
        b[2] = xx.se;
        b[1] = xx.fi;
        b[3] = yy.fi * yy.se / xx.se;
    }
    if (zz.fi == tt.fi || zz.fi == tt.se){
        b[5] = zz.fi;
        b[4] = zz.se;
        b[6] = tt.fi * tt.se / zz.fi;
    }
    else{
        b[5] = zz.se;
        b[4] = zz.fi;
        b[6] = tt.fi * tt.se / zz.se;
    }
    cout << "! ";
    ForE(i, 1, 6){
        cout << b[i] << ' ';
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