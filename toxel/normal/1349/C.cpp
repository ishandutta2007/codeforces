#include <bits/stdc++.h>

const int N = 1010;
using ll = long long;
using pii = std::pair <int, int>;
const int INF = 0x3f3f3f3f;

int begin[N][N];
char s[N][N];
bool vis[N][N];
int n, m, t;

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    memset(begin, 0x3f, sizeof(begin));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m - 1; ++ j){
            if (s[i][j] == s[i][j + 1]){
                begin[i][j] = begin[i][j + 1] = 0;
                vis[i][j] = vis[i][j + 1] = true;
            }
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == s[i + 1][j]){
                begin[i][j] = begin[i + 1][j] = 0;
                vis[i][j] = vis[i + 1][j] = true;
            }
        }
    }
    std::queue<pii> queue;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (begin[i][j] == 0){
                queue.emplace(i, j);
            }
        }
    }
    while (!queue.empty()){
        pii p = queue.front();
        queue.pop();
        for (int i = -1; i <= 1; ++ i){
            for (int j = -1; j <= 1; ++ j){
                if (std::abs(i) + std::abs(j) != 1){
                    continue;
                }
                if (!check(p.first + i, p.second + j)){
                    continue;
                }
                if (vis[p.first + i][p.second + j]){
                    continue;
                }
                begin[p.first + i][p.second + j] = begin[p.first][p.second] + 1;
                vis[p.first + i][p.second + j] = true;
                queue.emplace(p.first + i, p.second + j);
            }
        }
    }
    while (t --){
        int x, y;
        ll p;
        scanf("%d%d%lld", &x, &y, &p);
        -- x, -- y;
        if (begin[x][y] == INF || p <= begin[x][y]){
            putchar(s[x][y]);
        }
        else{
            putchar(begin[x][y] % 2 == p % 2 ? s[x][y] : char(1 ^ s[x][y]));
        }
        puts("");
    }
    return 0;
}

/*
5 2 2
01
10
01
10
01
1 1 3
5 1 3
 */