#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e6 + 7, mod = 998244353;

struct disjoint_set_union{
    int par[N], ck[N];

    disjoint_set_union(){
        reset();
    }

    void reset(){
        memset(par, -1, sizeof(par));
        memset(ck, 0, sizeof(ck));
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    void merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        ck[x] |= ck[y];
        ck[y] = 0;
    }
} dsu;

int n;
int a[N];
vi adj[N];

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    vpii b;
    ForE(i, 1, n){
        b.emplace_back(a[i], i);
    }
    sort(bend(b));
    dsu.reset();
    Fora(&elem, b){
        int val, u; tie(val, u) = elem;
        ll sum1 = 1, sum2 = 1;
        Fora(&v, adj[u]){
            if (dsu.ck[dsu.root(v)]){
                sum1 += -dsu.par[dsu.root(v)];
                sum2 += (ll)dsu.par[dsu.root(v)] * dsu.par[dsu.root(v)];
            }
        }
        ans += val * (sum1 * sum1 - sum2) / 2;
        dsu.ck[u] = 1;
        Fora(&v, adj[u]){
            if (dsu.ck[dsu.root(v)]){
                dsu.merge(u, v);
            }
        }
    }
    reverse(bend(b));
    dsu.reset();
    Fora(&elem, b){
        int val, u; tie(val, u) = elem;
        ll sum1 = 1, sum2 = 1;
        Fora(&v, adj[u]){
            if (dsu.ck[dsu.root(v)]){
                sum1 += -dsu.par[dsu.root(v)];
                sum2 += (ll)dsu.par[dsu.root(v)] * dsu.par[dsu.root(v)];
            }
        }
        ans -= val * (sum1 * sum1 - sum2) / 2;
        dsu.ck[u] = 1;
        Fora(&v, adj[u]){
            if (dsu.ck[dsu.root(v)]){
                dsu.merge(u, v);
            }
        }
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/