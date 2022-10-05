#include <bits/stdc++.h>

const int N = 1000010;
using pii = std::pair <int, int>;

int u[N], v[N], type[N];
std::vector <int> e[N];
std::vector <pii> p[N];
bool vis[N], vis1[N];
int coor[N], inv[N];

int peer(int edge, int uu){
    return u[edge] ^ v[edge] ^ uu;
}

void solve(){
    int bit;
    scanf("%d", &bit);
    int n = 1 << bit;
    int m = bit << (bit - 1);
    for (int i = 0; i < n; ++ i){
        e[i].clear();
        p[i].clear();
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        e[u[i]].emplace_back(i);
        e[v[i]].emplace_back(i);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < bit; ++ j){
            for (int k = 0; k < bit; ++ k){
                if (j == k){
                    continue;
                }
                int node1 = peer(e[i][j], i);
                int node2 = peer(e[i][k], i);
                p[node1].emplace_back(node2, e[i][j]);
            }
        }
    }
    /*for (int i = 0; i < n; ++ i){
        for (auto pair : p[i]){
            printf("%d %d\n", pair.first, pair.second);
        }
        puts("");
    }*/
    memset(vis, 0, sizeof(vis[0]) * m);
    for (int i = 0; i < bit; ++ i){
        memset(vis1, 0, sizeof(vis1[0]) * n);
        std::queue <int> queue;
        queue.push(e[0][i]);
        vis[e[0][i]] = true;
        while (!queue.empty()){
            int edge = queue.front();
            queue.pop();
            type[edge] = i;
            vis1[u[edge]] = vis1[v[edge]] = true;
            int uu = u[edge], vv = v[edge];
            for (auto edge1 : e[uu]){
                int u1 = peer(edge1, uu);
                if (vis1[u1]){
                    continue;
                }
                for (auto pair : p[u1]){
                    if (pair.first == vv && pair.second != edge1){
                        int to_push = pair.second;
                        if (!vis[to_push]){
                            queue.push(to_push);
                            vis[to_push] = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    coor[0] = 0;
    memset(vis, 0, sizeof(vis[0]) * n);
    vis[0] = true;
    std::queue <int> queue;
    queue.push(0);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto edge : e[u]){
            int v = peer(edge, u);
            coor[v] = coor[u] ^ (1 << type[edge]);
            if (!vis[v]){
                vis[v] = true;
                queue.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        inv[coor[i]] = i;
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", inv[i], " \n"[i == n - 1]);
    }
    if (bit == 1 || bit == 2 || bit == 4 || bit == 8 || bit == 16){
        for (int i = 0; i < n; ++ i){
            int ans = 0;
            for (int j = 0; j < bit; ++ j){
                if (coor[i] >> j & 1){
                    ans ^= j;
                }
            }
            printf("%d%c", ans, " \n"[i == n - 1]);
        }
        return;
    }
    puts("-1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}