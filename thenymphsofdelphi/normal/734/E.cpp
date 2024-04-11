#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e5 + 5;

struct DisjointSetUnion{
    int par[N];
    
    void reset(){
        memset(par, -1, sizeof(par));
    }
    
    int root(int x){
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
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
    }
} dsu;

int n;
int col[N];
vi adj[N];
vi adj2[N];
int h[N];

pii dfs(int u, int p){
    h[u] = h[p] + 1;
    pii ans = {h[u], u};
    Fora(&v, adj2[u]){
        if (v == p){
            continue;
        }
        ans = max(ans, dfs(v, u));
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("PIC.inp", "r", stdin);
    // freopen("PIC.out", "w", stdout);
    dsu.reset();
    cin >> n;
    ForE(i, 1, n){
        cin >> col[i];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (col[u] == col[v]){
            dsu.merge(u, v);
        }
    }
    ForE(i, 1, n){
        Fora(&j, adj[i]){
            if (col[i] != col[j]){
                adj2[dsu.root(i)].push_back(dsu.root(j));
            }
        }
    }
    ForE(i, 1, n){
        if (dsu.par[i] < 0){
            pii cac = dfs(i, i);
            memset(h, 0, sizeof(h));
            cac = dfs(cac.se, cac.se);
            cout << cac.fi / 2 << endl;
            return 0;
        }
    }
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