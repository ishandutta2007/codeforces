#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int h[N], t[N];
std::vector<int> e[N];
ll dp[N][2];
// 0 : up, 1 : down

void dfs(int u, int fa){
    std::vector<int> equal, less, greater;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (h[v] == h[u]){
            equal.emplace_back(v);
        }
        else if (h[v] > h[u]){
            greater.emplace_back(v);
        }
        else{
            less.emplace_back(v);
        }
        dfs(v, u);
    }
    if (equal.empty() && greater.empty() && less.empty()){
        dp[u][0] = dp[u][1] = t[u];
        return;
    }
    ll sum = 0;
    for (auto v : greater){
        sum += dp[v][0];
    }
    for (auto v : less){
        sum += dp[v][1];
    }
    std::vector<ll> value;
    for (auto v : equal){
        sum += dp[v][0];
        value.emplace_back(dp[v][1] - dp[v][0]);
    }
    int g_cnt = greater.size() + equal.size();
    int l_cnt = less.size();
    std::sort(value.begin(), value.end());
    int sz = equal.size();
    dp[u][0] = dp[u][1] = LLONG_MAX;
    for (int i = 0; i <= sz; ++ i){
        ll num = std::max(l_cnt, g_cnt) + (fa > 0);
        dp[u][0] = std::min(dp[u][0], sum + num * t[u]);
        dp[u][1] = std::min(dp[u][1], sum + num * t[u]);
        if (g_cnt > 0 && fa){
            num = std::max(l_cnt, g_cnt - 1) + 1;
            dp[u][0] = std::min(dp[u][0], sum + num * t[u]);
        }
        if (l_cnt > 0 && fa){
            num = std::max(l_cnt - 1, g_cnt) + 1;
            dp[u][1] = std::min(dp[u][1], sum + num * t[u]);
        }
        if (i < sz){
            sum += value[i];
            ++ l_cnt;
            -- g_cnt;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (n == 1){
        puts("0");
        return 0;
    }
    dfs(1, 0);
    printf("%lld\n", std::min(dp[1][0], dp[1][1]));
    return 0;
}