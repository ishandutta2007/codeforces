#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;
const int N = 250010;

std::vector <pii> e[N];
std::vector <int> vec[N];
std::priority_queue <int> pq1[N], pq2[N];
ll sum1[N], sum2[N];
ll dp[N][2];
int fa[N], faw[N];
int deg[N];

void getfa(int u, int fa, int faw){
    ::fa[u] = fa, ::faw[u] = faw;
    for (auto v : e[u]){
        if (v.first == fa){
            continue;
        }
        getfa(v.first, u, v.second);
    }
}

ll getdp(std::priority_queue <int> &pq, std::vector <ll> &vec, int target){
    if (target <= 0){
        int sum = 0;
        for (auto u : vec){
            sum += std::min(u, 0ll);
        }
        return sum;
    }
    std::vector <int> rollback;
    int sit = target - pq.size();
    ll ret = 0;
    for (int i = 0; i < sit; ++ i){
        ret += vec[i];
    }
    for (int i = sit; i < (int) vec.size(); ++ i){
        if (!pq.empty()){
            if (vec[i] < pq.top()){
                ret -= pq.top();
                rollback.push_back(pq.top());
                pq.pop();
                ret += vec[i];
            }
            else{
                break;
            }
        } else if (vec[i] < 0){
            ret += vec[i];
        }
    }
    for (auto u : rollback){
        pq.push(u);
    }
    return ret;
}

void dfs(int u, int top, int x){
    ll sum = 0;
    std::vector <ll> vec;
    for (auto v : e[u]){
        dfs(v.first, top, x);
        sum += dp[v.first][0];
        vec.push_back(dp[v.first][1] - dp[v.first][0] + v.second);
    }
    if (u == top && u != 1){
        vec.push_back(faw[u]);
    }
    std::sort(vec.begin(), vec.end());
    dp[u][0] = sum + sum1[u] + getdp(pq1[u], vec, deg[u] - (x + 0));
    dp[u][1] = sum + sum2[u] + getdp(pq2[u], vec, deg[u] - (x + 1));
}

int main(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0, u, v, w; i < n - 1; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        sum += w;
    }
    getfa(1, 0, 0);
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < (int) e[i].size(); ++ j){
            vec[j].push_back(i);
        }
        deg[i] = e[i].size();
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < (int) e[i].size(); ++ j){
            if (e[i][j].first == fa[i]){
                std::swap(e[i][j], e[i].back());
                e[i].pop_back();
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        ll ans = 0;
        if (i) {
            for (auto u : vec[i]) {
                if (deg[fa[u]] > i) {
                    continue;
                }
                dfs(u, u, i);
                ans += dp[u][0];
            }
        }
        else{
            ans = sum;
        }
        printf("%lld%c", ans, " \n"[i == n - 1]);
        for (auto u : vec[i]){
            if (deg[u] <= i + 1){
                continue;
            }
            for (int j = 0; j < (int) e[u].size(); ++ j){
                if (deg[e[u][j].first] <= i + 1){
                    pq1[u].push(e[u][j].second);
                    pq2[u].push(e[u][j].second);
                    sum1[u] += e[u][j].second;
                    sum2[u] += e[u][j].second;
                    std::swap(e[u][j], e[u].back());
                    e[u].pop_back();
                    -- j;
                }
            }
            int target = deg[u] - (i + 1);
            while (!pq1[u].empty() && (int) pq1[u].size() > target){
                sum1[u] -= pq1[u].top();
                pq1[u].pop();
            }
            -- target;
            while (!pq2[u].empty() && (int) pq2[u].size() > target){
                sum2[u] -= pq2[u].top();
                pq2[u].pop();
            }
        }
    }
    return 0;
}