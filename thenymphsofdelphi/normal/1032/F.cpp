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

const int N = 3e5 + 5, mod = 998244353;

int add(int x, int y){
    return (x += y) >= mod ? x - mod : x;
}

int sub(int x, int y){
    return (x -= y) < 0 ? x + mod : x;
}

int mul(int x, int y){
    return 1ll * x * y % mod;
}

int binpow(int x, int y){
    int ans = 1; while (y){ if (y & 1) ans = mul(ans, x); x = mul(x, x); y >>= 1; } return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int div(int x, int y){
    return mul(x, inv(y));
}

int n;
vi adj[N];
int dp[N][3]; // 0: matched, 1: single, 2: match with parent

void dfs1(int u, int p){
    For(i, 0, isz(adj[u])){
        if (adj[u][i] == p){
            adj[u].erase(adj[u].begin() + i);
            i--;
            continue;
        }
        else{
            dfs1(adj[u][i], u);
        }
    }
}

void dfs2(int u){
    bool leaf = 1;
    Fora(&v, adj[u]){
        leaf = 0;
        dfs2(v);
    }
    if (leaf){
        dp[u][0] = 0;
        dp[u][1] = 1;
        dp[u][2] = 1;
        return;
    }
    int val = 1;
    Fora(&v, adj[u]){
        val = mul(val, add(add(dp[v][0], dp[v][0]), dp[v][1]));
    }
    Fora(&v, adj[u]){
        int tval = div(val, add(add(dp[v][0], dp[v][0]), dp[v][1]));
        tval = mul(tval, dp[v][2]);
        dp[u][0] = add(dp[u][0], tval);
    }
    dp[u][1] = 1;
    Fora(&v, adj[u]){
        dp[u][1] = mul(dp[u][1], add(dp[v][0], dp[v][1]));
    }
    dp[u][2] = 1;
    Fora(&v, adj[u]){
        dp[u][2] = mul(dp[u][2], add(add(dp[v][0], dp[v][0]), dp[v][1]));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1);
    int ans = add(dp[1][0], dp[1][1]);
    cout << ans << endl;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/