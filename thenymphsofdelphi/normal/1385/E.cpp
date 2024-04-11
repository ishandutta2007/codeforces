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
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

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

const int N = 2e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int n, m;
vector <pair <int, pii> > edge;
int degin[N];

vi adj[N];
int col[N];

bool dfs(int u){
    col[u] = 1;
    Fora(v, adj[u]){
        if (col[v] == 1){
            return true;
        }
        if (col[v] == 2){
            continue;
        }
        if (dfs(v)){
            return true;
        }
    }
    col[u] = 2;
    return false;
}

bool is_cycle(){
    ForE(i, 1, n){
        if (col[i] == 0){
            if (dfs(i)){
                return true;
            }
        }
    }
    return false;
}

bool ck[N];
vi vans;
int ord[N];

void dfs2(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs2(v);
        }
    }
    vans.pb(u);
}

void toposort(){
    ForE(i, 1, n){
        if (!ck[i]){
            dfs2(i);
        }
    }
    reverse(bend(vans));
    For(i, 0, n){
        ord[vans[i]] = i;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> m;
    vans.clear();
    edge.clear();
    ForE(i, 1, n){
        adj[i].clear();
        degin[i] = 0;
        col[i] = 0; ck[i] = 0;
    }
    ForE(j, 1, m){
        int k, u, v; cin >> k >> u >> v;
        edge.pb({k, {u, v}});
        if (k == 1){
            adj[u].pb(v);
        }
    }
    if (is_cycle()){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    toposort();
    Fora(v, edge){
        if (v.fi == 1){
            cout << v.se.fi << ' ' << v.se.se << endl;
        }
        else{
            if (ord[v.se.fi] < ord[v.se.se]){
                cout << v.se.fi << ' ' << v.se.se << endl;
            }
            else{
                cout << v.se.se << ' ' << v.se.fi << endl;
            }
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