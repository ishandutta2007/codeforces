#include <bits/stdc++.h>

const int N = 1010;

char s[N][N];
bool up[N][N], down[N][N], left[N][N], right[N][N];
bool vis[N][N];
bool vis1[N], vis2[N];
int n, m;

bool check(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '#';
}

void dfs(int u, int v){
    if (vis[u][v]){
        return;
    }
    vis[u][v] = true;
    for (int i = -1; i <= 1; ++ i){
        for (int j = -1; j <= 1; ++ j){
            if (std::abs(i) + std::abs(j) != 1){
                continue;
            }
            if (!check(u + i, v + j)){
                continue;
            }
            dfs(u + i, v + j);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            up[i][j] = down[i][j] = left[i][j] = right[i][j] = s[i][j] == '#';
            if (s[i][j] == '#'){
                vis1[i] = vis2[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            left[i][j] = left[i][j - 1] || left[i][j];
        }
        for (int j = m - 2; j >= 0; -- j){
            right[i][j] = right[i][j + 1] || right[i][j];
        }
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            up[i][j] = up[i - 1][j] || up[i][j];
        }
    }
    for (int i = n - 2; i >= 0; -- i){
        for (int j = 0; j < m; ++ j){
            down[i][j] = down[i + 1][j] || down[i][j];
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            bool flag = (up[i][j] && down[i][j]) || (left[i][j] && right[i][j]);
            if (s[i][j] == '.' && flag){
                puts("-1");
                return 0;
            }
        }
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++ i){
        sum1 += vis1[i];
    }
    for (int j = 0; j < m; ++ j){
        sum2 += vis2[j];
    }
    if (sum1 == n && sum2 != m){
        puts("-1");
        return 0;
    }
    if (sum1 != n && sum2 == m){
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '#' && !vis[i][j]) {
                dfs(i, j);
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}