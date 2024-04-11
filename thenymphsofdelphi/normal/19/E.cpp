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

const int N = 1e4 + 5, M = 14;

int n, m;
pii edges[N]; map <pii, int> mppedges;
vi adj[N];

bool ck[N];
int h[N], col[N];
int lift[N][M], add1[N][M], add2[N][M];
int edgesame, edgedif; vpii vedgesame;

vi vans;

void dfs1(int u, int p){
    ck[u] = 1;
    lift[u][0] = p;
    For(j, 1, M){
        lift[u][j] = lift[lift[u][j - 1]][j - 1];
    }
    Fora(&v, adj[u]){
        if (!ck[v]){
            h[v] = h[u] + 1;
            col[v] = col[u] ^ 1;
            dfs1(v, u);
        }
    }
}

void update1(int u, int v){
    FordE(i, M - 1, 0){
        if (h[u] - (1 << i) >= h[v]){
            add1[u][i]++;
            u = lift[u][i];
        }
    }
    assert(u == v);
}

void update2(int u, int v){
    FordE(i, M - 1, 0){
        if (h[u] - (1 << i) >= h[v]){
            add2[u][i]++;
            u = lift[u][i];
        }
    }
    assert(u == v);
}

void down(int u, int i){
    if (i != 0){
        int v = lift[u][i - 1];
        add1[u][i - 1] += add1[u][i];
        add1[v][i - 1] += add1[u][i];
        add2[u][i - 1] += add2[u][i];
        add2[v][i - 1] += add2[u][i];
        add1[u][i] = 0; add2[u][i] = 0;
        down(u, i - 1);
        down(v, i - 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        mppedges[{u, v}] = i; mppedges[{v, u}] = i;
    }
    memset(ck, 0, sizeof(ck));
    ForE(u, 1, n){
        if (!ck[u]){
            dfs1(u, u);
        }
    }
    ForE(i, 1, m){
        int u, v; tie(u, v) = edges[i];
        if (h[u] < h[v]){
            swap(u, v);
        }
        if (v == lift[u][0]){
            continue;
        }
        if (col[u] == col[v]){
            edgesame++;
            vedgesame.emplace_back(u, v);
            update1(u, v);
        }
        else{
            edgedif++;
            update2(u, v);
        }
    }
    ForE(u, 1, n){
        if (h[u]){
            down(u, __lg(h[u]));
        }
    }
    if (edgesame == 0){
        cout << m << endl;
        ForE(i, 1, m){
            cout << i << ' ';
        } cout << endl;
        return 0;
    }
    ForE(u, 1, n){
        if (u == lift[u][0]){
            continue;
        }
        if (add1[u][0] == edgesame and add2[u][0] == 0){
           vans.emplace_back(mppedges[{u, lift[u][0]}]);
        }
    }
    if (edgesame == 1){
        vans.emplace_back(mppedges[vedgesame[0]]);
    }
    sort(bend(vans));
    cout << isz(vans) << endl;
    Fora(&elem, vans){
        cout << elem << ' ';
    } cout << endl;
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