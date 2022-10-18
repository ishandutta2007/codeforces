#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

// #define int long long
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

const int N = 1e6 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

struct disjoint_set_union{
    vector <vpii> par;

    pii root(pii x){
        return par[x.fi][x.se].fi < 0 ? x : par[x.fi][x.se] = root(par[x.fi][x.se]);
    }

    void merge(pii x, pii y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[y.fi][y.se] < par[x.fi][y.se]){
            swap(x, y);
        }
        par[x.fi][x.se].fi += par[y.fi][y.se].fi;
        par[x.fi][x.se].se += par[y.fi][y.se].se;
        par[y.fi][y.se] = x;
    }
} dsu;

int n, m;
vvi a;
vvi finpar;
vvi adj;
vector <bool> ck;
vi ans;
vi vans;

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    vans.pb(u);
}

void toposort(){
    For(i, 0, ck.size()){
        if (!ck[i]){
            dfs(i);
        }
    }
    reverse(bend(vans));
}

void fuckinginit(){
    ForE(i, 0, n + 1){
        a.pb(vi (m + 2, 0));
        dsu.par.pb(vpii (m + 2, {-1, -1}));
        finpar.pb(vi (m + 2, 0));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fuckinginit();
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }
    vpii vtmp;
    ForE(i, 1, n){
        vtmp.clear();
        ForE(j, 1, m){
            vtmp.pb({a[i][j], j});
        }
        sort(bend(vtmp));
        For(j, 1, m){
            if (a[i][vtmp[j - 1].se] == a[i][vtmp[j].se]){
                dsu.merge({i, vtmp[j - 1].se}, {i, vtmp[j].se});
            }
        }
    }
    ForE(j, 1, m){
        vtmp.clear();
        ForE(i, 1, n){
            vtmp.pb({a[i][j], i});
        }
        sort(bend(vtmp));
        For(i, 1, n){
            if (a[vtmp[i - 1].se][j] == a[vtmp[i].se][j]){
                dsu.merge({vtmp[i - 1].se, j}, {vtmp[i].se, j});
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (dsu.par[i][j].fi < 0){
                finpar[i][j] = adj.size();
                adj.pb({});
                ck.pb(0);
                ans.pb(1);
            }
        }
    }
    ForE(i, 1, n){
        vtmp.clear();
        ForE(j, 1, m){
            vtmp.pb({a[i][j], j});
        }
        sort(bend(vtmp));
        For(j, 1, m){
            if (a[i][vtmp[j - 1].se] < a[i][vtmp[j].se]){
                adj[finpar[dsu.root({i, vtmp[j - 1].se}).fi][dsu.root({i, vtmp[j - 1].se}).se]]
                .pb(finpar[dsu.root({i, vtmp[j].se}).fi][dsu.root({i, vtmp[j].se}).se]);
            }
        }
    }
    ForE(j, 1, m){
        vtmp.clear();
        ForE(i, 1, n){
            vtmp.pb({a[i][j], i});
        }
        sort(bend(vtmp));
        For(i, 1, n){
            if (a[vtmp[i - 1].se][j] < a[vtmp[i].se][j]){
                adj[finpar[dsu.root({vtmp[i - 1].se, j}).fi][dsu.root({vtmp[i - 1].se, j}).se]]
                .pb(finpar[dsu.root({vtmp[i].se, j}).fi][dsu.root({vtmp[i].se, j}).se]);
            }
        }
    }
    toposort();
    Fora(u, vans){
        Fora(v, adj[u]){
            ans[v] = max(ans[v], ans[u] + 1);
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            cout << ans[finpar[dsu.root({i, j}).fi][dsu.root({i, j}).se]] << ' ';
        }
        cout << endl;
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