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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m;
set <int> adj[N];
int par[N];
int col[N];
bool ck[N];
vi col1, col2, col3;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    msetn1(par);
    cin >> n >> m;
    ForE(i, 1, m){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for (auto v = adj[1].begin(); v != adj[1].end(); v++){
        ck[*v] = 1;
    }
    col[1] = 1;
    col1.pb(1);
    ForE(i, 1, n){
        if (!ck[i]){
            col[i] = 1;
            col1.pb(i);
        }
    }
    int idx = 0;
    ForE(i, 1, n){
        if (col[i] == 0){
            idx = i;
            break;
        }
    }
    mset(ck);
    for (auto v = adj[idx].begin(); v != adj[idx].end(); v++){
        if (col[*v] == 0){
            ck[*v] = 1;
        }
    }
    col[idx] = 2;
    col2.pb(idx);
    ForE(i, 1, n){
        if (!ck[i] && col[i] == 0){
            col[i] = 2;
            col2.pb(i);
        }
    }
    ForE(i, 1, n){
        if (col[i] == 0){
            col[i] = 3;
            col3.pb(i);
        }
    }
    if (col3.size() == 0) Ptest(-1);
    ForE(i, 1, n){
        for (auto v = adj[i].begin(); v != adj[i].end(); v++){
            if (col[i] == col[*v]) Ptest(-1);
        }
    }
    Fora(u, col1){
        Fora(v, col2){
            if (adj[u].find(v) == adj[u].end()) Ptest(-1);
            if (adj[v].find(u) == adj[v].end()) Ptest(-1);
        }
    }
    Fora(u, col2){
        Fora(v, col3){
            if (adj[u].find(v) == adj[u].end()) Ptest(-1);
            if (adj[v].find(u) == adj[v].end()) Ptest(-1);
        }
    }
    Fora(u, col3){
        Fora(v, col1){
            if (adj[u].find(v) == adj[u].end()) Ptest(-1);
            if (adj[v].find(u) == adj[v].end()) Ptest(-1);
        }
    }
    ForE(i, 1, n){
        cout << col[i] << ' ';
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