#include <bits/stdc++.h>

const int N = 5010;

std::vector<int> e[N];
int color[N], ans[N], tag[N];
bool valid;
std::vector<int> vec[N][2];
bool dp[N][N], pre[N][N];

void dfs(int u, int t){
    tag[u] = t;
    for (auto v : e[u]){
        if (color[v] != -1){
            if (color[u] == color[v]){
                valid = false;
                return;
            }
            continue;
        }
        color[v] = color[u] ^ 1;
        dfs(v, t);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    valid = true;
    memset(color, -1, sizeof(color));
    int cur = 0;
    for (int i = 1; i <= n; ++ i){
        if (color[i] == -1){
            color[i] = 0;
            ++ cur;
            dfs(i, cur);
        }
    }
    if (!valid){
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        vec[tag[i]][color[i]].emplace_back(i);
    }
    dp[0][0] = true;
    for (int i = 1; i <= cur; ++ i){
        for (int j = 0; j < N; ++ j){
            if (!dp[i - 1][j]){
                continue;
            }
            int nj = j + int(vec[i][0].size());
            if (!dp[i][nj]){
                dp[i][nj] = true;
                pre[i][nj] = false;
            }
            nj = j + int(vec[i][1].size());
            if (!dp[i][nj]){
                dp[i][nj] = true;
                pre[i][nj] = true;
            }
        }
    }
    if (!dp[cur][n2]){
        puts("NO");
        return 0;
    }
    std::vector<int> two;
    int now = n2;
    for (int i = cur; i >= 1; -- i){
        two.emplace_back(int(pre[i][now]));
        now -= vec[i][pre[i][now]].size();
    }
    std::reverse(two.begin(), two.end());
    for (int i = 1; i <= n; ++ i){
        if (color[i] == two[tag[i] - 1]){
            ans[i] = 2;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!ans[i]){
            if (n1 > 0){
                ans[i] = 1;
                -- n1;
            }
            else{
                ans[i] = 3;
                -- n3;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; ++ i){
        printf("%d", ans[i]);
    }
    return 0;
}