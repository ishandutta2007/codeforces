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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
int a[N];
vi adj[N];
int ans = 0;
int par[N];
int h[N];
bool leaf[N];
vpii path[N];
//int decr[N];

void add(int &x, int y){
    x = (x + y) % mod;
}

void sub(int &x, int y){
    x = (x - y) % mod;
    if (x < 0) x += mod;
}

int mul(int x, int y){
    return x * y % mod;
}

void dfs1(int u, int p){
    if (adj[u].size() == 1 && u != 1){
        leaf[u] = 1;
        return;
    }
    Fora(v, adj[u]){
        if (v != p){
            par[v] = u;
            h[v] = h[u] + 1;
            dfs1(v, u);
        }
    }
    return;
}

void dfs2(int u, int p){
    //cout << u << ' ' << p << ' ' << val << endl;
    vpii tmp;
	if (p != 0){
	    tmp = path[p];
	}
	For(i, 0, tmp.size()){
	    tmp[i].se = gcd(tmp[i].se, a[u]);
	}
	path[u].pb({u, a[u]});
	FordE(i, (int)tmp.size() - 1, 0){
	    if (tmp[i].se != path[u].back().se){
	        path[u].pb(tmp[i]);
	    }
	}
	reverse(bend(path[u]));
	//decr[u] = path[u].size();
	Fora(v, adj[u]){
        if (v != p){
            dfs2(v, u);
        }
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    For(i, 1, n){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    //ForE(i, 1, n){
    //    cout << decr[i] << ' ';
    //}
    //cout << endl;
    ForE(i, 1, n){
        For(j, 0, path[i].size()){
            int x = path[i][j].fi, y = path[i][j].se;
			if (j == 0){
			    add(ans, mul(y, h[x] + 1));
			}
			else{
				int lx = path[i][j - 1].fi;
				add(ans, mul(y, h[x] - h[lx]));
			}
        }
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