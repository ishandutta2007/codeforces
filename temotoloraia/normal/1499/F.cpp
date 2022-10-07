#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 5005, MOD = 998244353;

int n, K;
int S[N];
int dp[N][N], ans[N];
vector < int > g[N];

void dfs (int k, int p){
    dp[k][0] = 1;
    S[k] = 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        for (int x = S[k]-1; x >= 0; x--){
            int C = dp[k][x];
            for (int cnt, z, y = 0; y < S[to]; y++){
                z = y+1;
                if (x+z > K)
                    continue;
                cnt = C * dp[to][y];
                z = max (z, x);
                dp[k][z] = (dp[k][z] + cnt) % MOD;
            }
            dp[k][x] = (dp[k][x] + C * (ans[to]-1)) % MOD;
        }
        S[k] += S[to];
    }
    for (int i = 0; i < S[k]; i++)
        ans[k] = (ans[k] + dp[k][i]) % MOD;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> K;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    cout << ans[1] << endl;
}