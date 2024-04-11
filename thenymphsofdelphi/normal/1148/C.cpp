#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
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

const int N = 3e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n;
int a[N], pos[N];

void swapp(int x, int y){
    swap(a[x], a[y]);
    swap(pos[a[x]], pos[a[y]]);
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        pos[a[i]] = i;
    }
    vpii ans;
    ForE(i, 1, n){
        if (pos[i] != i){
            int j = pos[i];
            if (i <= n / 2 && j <= n / 2){
                ans.pb({j, n});
                ans.pb({i, n});
                ans.pb({j, n});
                swapp(j, n);
                swapp(i, n);
                swapp(j, n);
            }
            else if (i > n / 2 && j > n / 2){
                ans.pb({j, 1});
                ans.pb({i, 1});
                ans.pb({j, 1});
                swapp(j, 1);
                swapp(i, 1);
                swapp(j, 1);
            }
            else if (i <= n / 2 && j > n / 2){
                ans.pb({j, 1});
                ans.pb({n, 1});
                ans.pb({n, i});
                ans.pb({n, 1});
                ans.pb({j, 1});
                swapp(j, 1);
                swapp(n, 1);
                swapp(n, i);
                swapp(n, 1);
                swapp(j, 1);
            }
            else{
                ans.pb({j, n});
                ans.pb({n, 1});
                ans.pb({1, i});
                ans.pb({n, 1});
                ans.pb({j, n});
                swapp(j, n);
                swapp(n, 1);
                swapp(1, i);
                swapp(n, 1);
                swapp(j, n);
            }
        }
    }
    //ForE(i, 1, n) cout << a[i] << ' ';
    //cout << endl;
    cout << ans.size() << endl;
    Fora(v, ans) cout << v.fi << ' ' << v.se << endl;
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