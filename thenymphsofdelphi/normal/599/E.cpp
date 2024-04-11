#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 13;

int n, m, q;
int adj[N];
vpii vlca[N];

ll dp[1 << N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> q;
    ForE(i, 1, m){
        int u, v; cin >> u >> v; u--; v--;
        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }
    ForE(i, 1, q){
        int u, v, w; cin >> u >> v >> w; u--; v--; w--;
        vlca[w].emplace_back(u, v);
    }
    For(msk, 1, (1 << n)){
        For(u, 0, n){
            if (!(msk & (1 << u))){
                continue;
            }
            if (msk == (1 << u)){
                dp[msk][u] = 1;
                continue;
            }
            int tv = -1;
            For(v, 0, n){
                if (!(msk & (1 << v)) or v == u){
                    continue;
                }
                tv = v;
                break;
            }
            for (int smsk = msk ^ (1 << u); smsk != 0; smsk = (smsk - 1) & (msk ^ (1 << u))){
                if (!(smsk & (1 << tv))){
                    continue;
                }
                int cnt = __builtin_popcount(smsk & adj[u]);
                if (cnt >= 2){
                    continue;
                }
                if (cnt == 1){
                    int v = __lg(smsk & adj[u]);
                    bool ck = 1;
                    ck &= __builtin_popcount(((smsk | (1 << u)) & adj[v]) == adj[v]);
                    Fora(p, vlca[u]){
                        if ((smsk & (1 << p.fi)) and (smsk & (1 << p.se))){
                            ck = 0;
                            break;
                        }
                    }
                    Fora(p, vlca[v]){
                        if (!(smsk & (1 << p.fi)) or !(smsk & (1 << p.se))){
                            ck = 0;
                            break;
                        }
                    }
                    if (ck){
                        dp[msk][u] += dp[smsk][v] * dp[msk ^ smsk][u];
                    }
                    continue;
                }
                For(v, 0, n){
                    if (!(smsk & (1 << v))){
                        continue;
                    }
                    bool ck = 1;
                    ck &= __builtin_popcount(((smsk | (1 << u)) & adj[v]) == adj[v]);
                    Fora(p, vlca[u]){
                        if ((smsk & (1 << p.fi)) and (smsk & (1 << p.se))){
                            ck = 0;
                            break;
                        }
                    }
                    Fora(p, vlca[v]){
                        if (!(smsk & (1 << p.fi)) or !(smsk & (1 << p.se))){
                            ck = 0;
                            break;
                        }
                    }
                    if (ck){
                        dp[msk][u] += dp[smsk][v] * dp[msk ^ smsk][u];
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0] << endl;
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