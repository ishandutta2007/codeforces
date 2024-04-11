#include<bits/stdc++.h>
using namespace std;

// Shortcut

#pragma optimize ("O3")
#define int long long
#define endl '\n'
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
#define mmset(a) memset(a, 0x3f, sizeof(a));
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

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n;
int a[N], b[N];
pii ans, mx = {-inf, 1};

pii cal(int x, int y){
    int t = b[x] - b[x - y - 1] + b[n] - b[n - y];
    return {t, 2 * y + 1};
}

bool cmp(pii x, pii y){
	return x.fi * y.se <= x.se * y.fi;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ForE(i, 1, n){
        b[i] = b[i - 1] + a[i];
    }
    ForE(i, 1, n){
        int l = 0, r = min(i - 1, n - i);
        ForE(j, 1, 100){
            int l1 = l + (r - l + 1) / 3;
            int r1 = r - (r - l + 1) / 3;
            if (!cmp(cal(i, l1), cal(i, r1))){
                r = r1;
            }
            else{
                l = l1;
            }
        }
        ForE(j, l, r){
            pii t = cal(i, j);
            t.fi -= t.se * a[i];
            if (cmp(mx, t)){
                mx = t;
                ans = {i, j};
            }
        }
    }
    cout << 2 * ans.se + 1 << endl;
    ForE(i, ans.fi - ans.se, ans.fi){
        cout << a[i] << ' ';
    }
    ForE(i, n - ans.se + 1, n){
        cout << a[i] << ' ';
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