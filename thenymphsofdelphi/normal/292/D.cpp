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
#define m1set(a) memset(a, 1, sizeof(a))
#define mn1set(a) memset(a, -1, sizeof(a))
#define mmset(a) memset(a, 0x3f, sizeof(a))
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
 
const int N = 5e2 + 5, M = 1e4 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9;
const ll inf = 1e18 + 7;
 
int n, m, idx;
int lpar[M][N], rpar[M][N], par[N];
pii edge[M];
 
int lfind(int x){
    return (lpar[idx][x] < 0 ? x : lpar[idx][x] = lfind(lpar[idx][x]));
}
 
void lmerge(int x, int y){
    if ((x = lfind(x)) == (y = lfind(y))) return;
    if (lpar[idx][x] > lpar[idx][y]) swap(x, y);
    lpar[idx][x] += lpar[idx][y];
    lpar[idx][y] = x;
}
 
int rfind(int x){
    return (rpar[idx][x] < 0 ? x : rpar[idx][x] = rfind(rpar[idx][x]));
}
 
void rmerge(int x, int y){
    if ((x = rfind(x)) == (y = rfind(y))) return;
    if (rpar[idx][x] > rpar[idx][y]) swap(x, y);
    rpar[idx][x] += rpar[idx][y];
    rpar[idx][y] = x;
}
 
int find(int x){
    return (par[x] < 0 ? x : par[x] = find(par[x]));
}
 
void merge(int x, int y){
    if ((x = find(x)) == (y = find(y))) return;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, n){
        lpar[0][i] = -1;
        rpar[m + 1][i] = -1;
    }
    ForE(i, 1, m){
        cin >> edge[i].fi >> edge[i].se;
    }
    ForE(i, 1, m){
        ForE(j, 1, n){
            lpar[i][j] = lpar[i - 1][j];
        }
        idx = i;
        lmerge(edge[i].fi, edge[i].se);
    }
    FordE(i, m, 1){
        ForE(j, 1, n){
            rpar[i][j] = rpar[i + 1][j];
        }
        idx = i;
        rmerge(edge[i].fi, edge[i].se);
    }
    int q;
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        x--;
        y++;
        mn1set(par);
        ForE(i, 1, n){
            if (lpar[x][i] > 0) merge(i, lpar[x][i]);
        }
        ForE(i, 1, n){
            if (rpar[y][i] > 0) merge(i, rpar[y][i]);
        }
        int ans = 0;
        ForE(i, 1, n){
            if (par[i] < 0) ans++;
        }
        cout << ans << endl;
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