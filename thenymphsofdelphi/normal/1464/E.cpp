#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

#define div __div__

const int N = 1e5 + 5, S = 320, mod = 998244353;

inline int add(int a, int b){
    return ((a += b) >= mod ? a - mod : a);
}

inline int sub(int a, int b){
    return ((a -= b) < 0 ? a + mod : a);
}

inline int mul(int a, int b){
    return (ll)a * b % mod;
}

inline int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

inline int div(int a, int b){
    return (ll)a * binpow(b, mod - 2) % mod;
}

int n, m;
vi adj[N];

bool ck[N];
vi topo;

void dfs_topo(int u){
    ck[u] = 1;
    Fora(&v, adj[u]){
        if (!ck[v]){
            dfs_topo(v);
        }
    }
    topo.push_back(u);
}

void toposort(){
    memset(ck, 0, sizeof(ck));
    topo.clear();
    ForE(i, 1, n){
        if (!ck[i]){
            dfs_topo(i);
        }
    }
    reverse(bend(topo));
}

int grundy[N];
int cnt_grundy[512];

int coef[512][513];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    toposort();
    memset(ck, 0, sizeof(ck));
    FordE(i, n - 1, 0){
        int u = topo[i];
        Fora(&v, adj[u]){
            ck[grundy[v]] = 1;
        }
        while (ck[grundy[u]]) grundy[u]++;
        cnt_grundy[grundy[u]]++;
        Fora(&v, adj[u]){
            ck[grundy[v]] = 0;
        }
    }
    For(i, 0, 512){
        For(j, 0, 512){
            if (cnt_grundy[j]){
                coef[i][i ^ j] = div(cnt_grundy[j], n + 1);
            }
        }
        if (i){
            coef[i][512] = sub(0, div(1, n + 1));
        }
        coef[i][i] = sub(coef[i][i], 1);
    }
    // For(i, 0, 512){
    //     ForE(j, 0, 512){
    //         if (coef[i][j]){
    //             cout << i << ' ' << j << ' ' << coef[i][j] << endl;
    //         }
    //     }
    // }
    // gauss-jordan
    For(i, 0, 512){
        ForE(j, i + 1, 512){
            coef[i][j] = div(coef[i][j], coef[i][i]);
        }
        coef[i][i] = 1;
        For(k, i + 1, 512){
            ForE(j, i + 1, 512){
                coef[k][j] = sub(coef[k][j], mul(coef[i][j], coef[k][i]));
            }
            coef[k][i] = 0;
        }
    }
    FordE(i, 511, 0){
        For(j, i + 1, 512){
            coef[i][512] = sub(coef[i][512], mul(coef[i][j], coef[j][512]));
        }
    }
    cout << coef[0][512];
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