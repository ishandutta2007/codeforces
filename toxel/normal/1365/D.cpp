#include <bits/stdc++.h>

const int N = 60;

char s[N][N];
int n, m;
bool vis[N][N];

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    bool has_good = false;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == 'G'){
                has_good = true;
            }
        }
    }
    if (!has_good){
        puts("Yes");
        return;
    }
    using pii = std::pair <int, int>;
    std::vector<pii> to_block;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == 'B'){
                s[i][j] = '#';
                for (int x = -1; x <= 1; ++ x){
                    for (int y = -1; y <= 1; ++ y){
                        if (std::abs(x) + std::abs(y) == 1){
                            if (check(i + x, j + y)){
                                if (s[i + x][j + y] == 'G' || (i + x == n - 1 && j + y == m - 1)){
                                    puts("No");
                                    return;
                                }
                                to_block.emplace_back(i + x, j + y);
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto u : to_block){
        s[u.first][u.second] = '#';
    }
    std::queue <pii> queue;
    memset(vis, 0, sizeof(vis));
    vis[n - 1][m - 1] = true;
    queue.emplace(n - 1, m - 1);
    while (!queue.empty()){
        pii p = queue.front();
        queue.pop();
        for (int x = -1; x <= 1; ++ x){
            for (int y = -1; y <= 1; ++ y){
                if (std::abs(x) + std::abs(y) == 1){
                    if (check(p.first + x, p.second + y)){
                        if (s[p.first + x][p.second + y] != '#' && !vis[p.first + x][p.second + y]){
                            vis[p.first + x][p.second + y] = true;
                            queue.emplace(p.first + x, p.second + y);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == 'G' && !vis[i][j]){
                puts("No");
                return;
            }
        }
    }
    puts("Yes");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}