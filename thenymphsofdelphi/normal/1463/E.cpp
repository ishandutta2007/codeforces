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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 3e5 + 5;

int n, k;

vi adj[N];
int par[N];
int root;

pii a[N];
int verprev[N], vernext[N];
int ctrchain, chain[N];
int ctrposchain, poschain[N];
int startchain[N];

vi adj2[N];

void dfs1(int u){
    Fora(&v, adj[u]){
        if (chain[u] != chain[v]){
            adj2[chain[u]].emplace_back(chain[v]);
        }
        else{
            if (poschain[u] > poschain[v]){
                cout << 0 << endl;
                exit(0);
            }
        }
        dfs1(v);
    }
}

vi vtopo;
bool ck[N];
int posvtopo[N];

void dfs_topo(int u){
    ck[u] = 1;
    Fora(&v, adj2[u]){
        if (!ck[v]){
            dfs_topo(v);
        }
    }
    vtopo.emplace_back(u);
}

void find_topo(){
    vtopo.clear();
    memset(ck, 0, sizeof(ck));
    ForE(i, 1, ctrchain){
        if (!ck[i]){
            dfs_topo(i);
        }
    }
    reverse(bend(vtopo));
    For(i, 0, ctrchain){
        posvtopo[vtopo[i]] = i + 1;
    }
}

void dfs2(int u){
    Fora(&v, adj[u]){
        if (chain[u] != chain[v]){
            if (posvtopo[chain[u]] > posvtopo[chain[v]]){
                cout << 0 << endl;
                exit(0);
            }
        }
        dfs2(v);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(u, 1, n){
        cin >> par[u];
        if (!par[u]){
            root = u;
        }
        else{
            adj[par[u]].emplace_back(u);
        }
    }
    ForE(i, 1, k){
        cin >> a[i].fi >> a[i].se;
        vernext[a[i].fi] = a[i].se;
        verprev[a[i].se] = a[i].fi;
    }
    ForE(u, 1, n){
        if (!verprev[u]){
            startchain[++ctrchain] = u; ctrposchain = 0;
            int v = u;
            while (1){
                chain[v] = ctrchain; poschain[v] = ++ctrposchain;
                if (!vernext[v]){
                    break;
                }
                v = vernext[v];
            }
        }
    }
    ForE(u, 1, n){
        if (!chain[u]){
            cout << 0 << endl;
            return 0;
        }
    }
    dfs1(root);
    find_topo();
    dfs2(root);
    Fora(&i, vtopo){
        int u = startchain[i];
        while (1){
            cout << u << ' ';
            if (!vernext[u]){
                break;
            }
            u = vernext[u];
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