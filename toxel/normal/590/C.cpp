#include<bits/stdc++.h>

const int N = 1010;

char s[N][N];
int dis[3][N * N];
bool vis[N * N];
int n, m;

std::vector <int> e[N * N];

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int f(int x, int y){
    char ch = s[x][y];
    if (ch >= '1' && ch <= '3'){
        return n * m + ch - '1';
    }
    return x * m + y;
}

void addedge(int x1, int y1, int x2, int y2){
    if (!check(x1, y1) || !check(x2, y2)) return;
    if (s[x1][y1] == '#' || s[x2][y2] == '#') return;
    int p1 = f(x1, y1), p2 = f(x2, y2);
    if (p1 == p2) return;
    e[p1].push_back(p2);
    e[p2].push_back(p1);
}

void bfs(int *dis, int s){
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N * N; ++ i){
        dis[i] = INT_MAX;
    }
    vis[s] = true;
    dis[s] = 0;
    std::queue <int> queue;
    queue.push(s);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (vis[v]) continue;
            dis[v] = dis[u] + 1;
            queue.push(v);
            vis[v] = true;
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
            addedge(i, j, i + 1, j);
            addedge(i, j, i, j + 1);
        }
    }
    for (int i = 0; i < 3; ++ i){
        bfs(dis[i], n * m + i);
    }
    if (dis[0][n * m + 1] == INT_MAX || dis[0][n * m + 2] == INT_MAX || dis[1][n * m + 2] == INT_MAX){
        puts("-1");
        return 0;
    }
    int min = std::min(dis[0][n * m + 1] + dis[1][n * m + 2], std::min(dis[0][n * m + 2] + dis[1][n * m + 2], dis[0][n * m + 1] + dis[0][n * m + 2])) - 2;
    for (int i = 0; i < n * m; ++ i){
        if (dis[0][i] == INT_MAX || dis[1][i] == INT_MAX || dis[2][i] == INT_MAX) continue;
        min = std::min(min, dis[0][i] + dis[1][i] + dis[2][i] - 2);
    }
    printf("%d\n", min);
    return 0;
}