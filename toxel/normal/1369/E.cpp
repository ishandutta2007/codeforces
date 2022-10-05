#include <bits/stdc++.h>

const int N = 200010;

int w[N], cnt[N];
int x[N], y[N];
std::vector<int> vec[N];
bool vis[N], vis1[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &x[i], &y[i]);
        ++ cnt[x[i]], ++ cnt[y[i]];
        vec[x[i]].emplace_back(i);
        vec[y[i]].emplace_back(i);
    }
    std::vector<int> ans;
    std::queue <int> queue;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] <= w[i]){
            queue.emplace(i);
            vis1[i] = true;
        }
    }
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : vec[u]){
            if (vis[v]){
                continue;
            }
            ans.emplace_back(v);
            vis[v] = true;
            int other = x[v] ^ y[v] ^ u;
            -- cnt[other];
            if (cnt[other] <= w[other] && !vis1[other]){
                queue.emplace(other);
                vis1[other] = true;
            }
        }
    }
    std::reverse(ans.begin(), ans.end());
    if (int(ans.size()) < m){
        puts("DEAD");
        return 0;
    }
    puts("ALIVE");
    for (int i = 0; i < m; ++ i){
        printf("%d%c", ans[i] + 1, " \n"[i == m - 1]);
    }
}