#include <bits/stdc++.h>

const int N = 500010;
typedef std::pair <int, int> pii;
typedef long long ll;

std::vector <pii> e[N];
ll dp[N][2];
int k;

void dfs(int u, int fa){
    ll tot = 0;
    for (auto p : e[u]){
        int v = p.first;
        if (v == fa){
            continue;
        }
        dfs(v, u);
        tot += dp[v][1];
    }
    std::vector <ll> vec;
    for (auto p : e[u]){
        int v = p.first;
        if (v == fa){
            continue;
        }
        ll value = dp[v][0] + p.second - dp[v][1];
        if (value > 0){
            vec.push_back(value);
        }
    }
    std::sort(vec.begin(), vec.end(), std::greater <ll>());
    if ((int) vec.size() <= k - 1){
        for (auto v : vec){
            tot += v;
        }
        dp[u][0] = dp[u][1] = tot;
        return;
    }
    for (int i = 0; i < k - 1; ++ i){
        tot += vec[i];
    }
    dp[u][0] = tot;
    dp[u][1] = dp[u][0] + vec[k - 1];
}

void solve(){
    int n;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    printf("%lld\n", std::max(dp[1][0], dp[1][1]));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}