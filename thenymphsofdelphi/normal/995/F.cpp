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

#define div __div__

const int N = 3e3 + 5, mod = 1e9 + 7;

int add(int x, int y){
    x += y; if (x >= mod) x -= mod; return x;
}

int sub(int x, int y){
    x -= y; if (x < 0) x += mod; return x;
}

int mul(int x, int y){
    return 1ll * x * y % mod;
}

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int div(int x, int y){
    return mul(x, inv(y));
}

int n, d;
int p[N];
vi adj[N];

int f[N][N];

void dfs(int u){
    Fora(&v, adj[u]){
        dfs(v);
    }
    f[u][0] = 0;
    ForE(i, 1, n){
        int x = 1;
        Fora(&v, adj[u]){
            x = mul(x, f[v][i]);
        }
        f[u][i] = add(f[u][i - 1], x);
    }
}

int preinv[2][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    For(i, 1, N){
        preinv[0][i] = inv(i);
        preinv[1][i] = inv(mod - i);
    }
    cin >> n >> d;
    ForE(i, 2, n){
        cin >> p[i];
        adj[p[i]].emplace_back(i);
    }
    dfs(1);
    int ans = 0;
    ForE(i, 0, n){
        int term = f[1][i];
        ForE(j, 0, n){
            if (j == i){
                continue;
            }
            term = mul(term, sub(d, j));
            if (i > j){
                term = mul(term, preinv[0][i - j]);
            }
            else{
                term = mul(term, preinv[1][j - i]);
            }
        }
        ans = add(ans, term);
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