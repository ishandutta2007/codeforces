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

const int N = 1e6 + 5, M = 20;

int n = 4;
int h[N], lift[N][M];
int q;

int dia, u1, u2;

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(j, M - 1, 0){
        if (h[u] - (1 << j) >= h[v]){
            u = lift[u][j];
        }
    }
    if (u == v){
        return u;
    }
    FordE(j, M - 1, 0){
        if (lift[u][j] != lift[v][j]){
            u = lift[u][j]; v = lift[v][j];
        }
    }
    return lift[u][0];
}

int dis(int u, int v){
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
{
    h[1] = 0;
    h[2] = 1;
    h[3] = 1;
    h[4] = 1;
    For(j, 0, M){
        ForE(u, 1, 4){
            lift[u][j] = 1;
        }
    }
    dia = 2;
    u1 = 2; u2 = 3;
}
cin >> q;
while (q--){
    int u; cin >> u;
    ForE(i, 1, 2){
        n++; h[n] = h[u] + 1;
        lift[n][0] = u;
        For(j, 1, M){
            lift[n][j] = lift[lift[n][j - 1]][j - 1];
        }
    }
    int tdia;
    if ((tdia = dis(u1, n - 1)) > dia){
        dia = tdia; u2 = n - 1;
    }
    if ((tdia = dis(u1, n)) > dia){
        dia = tdia; u2 = n;
    }
    if ((tdia = dis(n - 1, u2)) > dia){
        dia = tdia; u1 = n - 1;
    }
    if ((tdia = dis(n, u2)) > dia){
        dia = tdia; u1 = n;
    }
    cout << dia << endl;
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