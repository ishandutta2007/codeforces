#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

struct disjoint_set_union{
    int par[N];
    
    disjoint_set_union(){
        msetn1(par);
    }
    
    int root(int x){
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
    }
    
    void merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
} dsu;

struct query{
    int t, x, y, idx;
    bool ans;
    vi ask;
};

int n, q;
query que[N];
int que2[N];
vi adj[N];
int st[N], en[N], par[N];
bool ck[N];
int t = 0;

void dfs(int u){
    ck[u] = 1;
    st[u] = ++t;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    en[u] = ++t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    int tidx = 0;
    ForE(i, 1, q){
        cin >> que[i].t;
        if (que[i].t == 1){
            cin >> que[i].x >> que[i].y;
            adj[que[i].y].pb(que[i].x);
            par[que[i].x] = que[i].y;
        }
        if (que[i].t == 2){
            cin >> que[i].x;
            que2[++tidx] = i;
        }
        if (que[i].t == 3){
            cin >> que[i].x >> que[i].y;
            que[que2[que[i].y]].ask.pb(i);
        }
    }
    ForE(i, 1, n){
        if (!ck[i] && !par[i]){
            dfs(i);
        }
    }
    // PrintA(st, 1, n); PrintA(en, 1, n);
    ForE(i, 1, q){
        if (que[i].t == 1){
            // cout << "A " << que[i].x << ' ' << que[i].y << endl;
            dsu.merge(que[i].x, que[i].y);
        }
        if (que[i].t == 2){
            Fora(v, que[i].ask){
                // cout << i << ' ' << v << ' ' << que[v].x << ' ' << que[i].x << endl;
                // cout << dsu.root(que[v].x) << ' ' << dsu.root(que[i].x) << endl;
                // cout << st[que[v].x] << ' ' << st[que[i].x] << ' ' << en[que[i].x] << ' ' << en[que[v].x] << endl;
                if (dsu.root(que[v].x) == dsu.root(que[i].x) &&
                    (st[que[v].x] <= st[que[i].x] && en[que[i].x] <= en[que[v].x])){
                    que[v].ans = 1;
                }
                else{
                    que[v].ans = 0;
                }
            }
        }
    }
    ForE(i, 1, q){
        if (que[i].t == 3) cout << (que[i].ans ? "YES" : "NO") << endl;
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