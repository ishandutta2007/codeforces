#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

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

const int N = 1e6 + 5;

int n, m;
vi adj[N];
int s, t;

vi radj[N];
int deg[N];

bool vis[N];
int dp[N];
deque <int> dq;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
    }
    cin >> s >> t;

    ForE(u, 1, n){
        Fora(v, adj[u]){
            radj[v].emplace_back(u);
        }
        deg[u] = isz(adj[u]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[t] = 0;
    dq.emplace_front(t);
    while (!dq.empty()){
        int u = dq.front(); dq.pop_front();
        if (vis[u]){
            continue;
        }
        vis[u] = 1;
        Fora(v, radj[u]){
            deg[v]--;
            if (deg[v] == 0){
                if (dp[v] > dp[u]){
                    dp[v] = dp[u];
                    dq.emplace_front(v);
                }
            }
            else{
                if (dp[v] > dp[u] + 1){
                    dp[v] = dp[u] + 1;
                    dq.emplace_back(v);
                }
            }
        }
    }
    if (dp[s] == dp[0]){
        cout << -1 << endl;
    }
    else{
        cout << dp[s] << endl;
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