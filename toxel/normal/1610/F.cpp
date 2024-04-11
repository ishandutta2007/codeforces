#include <bits/stdc++.h>

const int N = 1000010;
using pii = std::pair <int, int>;

std::vector <int> e[N], e1[N];
std::set <int> edge[2][N];
int u[N], v[N], w[N];
int orient[N];
bool vis[N], valid[N];
int ans[N];

int other(int ed, int uu){
    return u[ed] ^ v[ed] ^ uu;
}

void getans(int ed){
    for (auto ed1 : e[ed]){
        int type = u[ed1] == u[ed] || v[ed1] == u[ed] ? 0 : 1;
        if (type == 0){
            orient[ed1] = orient[ed] ^ (u[ed1] != u[ed]);
        }
        else{
            orient[ed1] = orient[ed] ^ (v[ed1] != v[ed]);
        }
        getans(ed1);
    }
}

void dfs(int uu){
    vis[uu] = true;
    for (auto ed : e1[uu]){
        if (orient[ed] != -1){
            continue;
        }
        if (uu == u[ed]){
            orient[ed] = 1;
        }
        else{
            orient[ed] = 0;
        }
        int vv = other(ed, uu);
        if (!vis[vv]){
            dfs(vv);
        }
    }
}

int main(){
    memset(orient, -1, sizeof(orient));
    int n, m;
    scanf("%d%d", &n, &m);
    int ecnt = m;
    for (int i = 0; i < m; ++ i){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        edge[w[i] - 1][u[i]].emplace(i);
        edge[w[i] - 1][v[i]].emplace(i);
        valid[i] = true;
    }
    std::set <pii> pq;
    for (int i = 1; i <= n; ++ i){
        pq.emplace(edge[0][i].size() + edge[1][i].size(), i);
    }
    while (true){
        auto [cnt, uu] = *(std::prev(pq.end()));
        pq.erase(std::prev(pq.end()));
        if (cnt <= 2){
            break;
        }
        int id;
        if (edge[0][uu].size() >= 2){
            id = 0;
        }
        else{
            id = 1;
        }
        auto it = edge[id][uu].begin();
        int x = *it;
        it = edge[id][uu].erase(it);
        int y = *it;
        edge[id][uu].erase(it);
        int node_x = other(x, uu);
        int node_y = other(y, uu);
        if (node_x != node_y){
            u[ecnt] = node_x;
            v[ecnt] = node_y;
            e[ecnt].emplace_back(x);
            e[ecnt].emplace_back(y);
            edge[id][node_x].erase(x);
            edge[id][node_x].insert(ecnt);
            edge[id][node_y].erase(y);
            edge[id][node_y].insert(ecnt);
            valid[x] = valid[y] = false;
            valid[ecnt] = true;
            pq.emplace(edge[0][uu].size() + edge[1][uu].size(), uu);
            ++ ecnt;
        }
        else{
            pq.erase({edge[0][node_x].size() + edge[1][node_x].size(), node_x});
            edge[id][uu].erase(x);
            edge[id][uu].erase(y);
            edge[id][node_x].erase(x);
            edge[id][node_x].erase(y);
            valid[x] = valid[y] = false;
            orient[x] = 0;
            if (u[x] == u[y]){
                orient[y] = 1;
            }
            else{
                orient[y] = 0;
            }
            pq.emplace(edge[0][uu].size() + edge[1][uu].size(), uu);
            pq.emplace(edge[0][node_x].size() + edge[1][node_x].size(), node_x);
        }
    }
    for (int i = 0; i < ecnt; ++ i){
        if (valid[i]){
            e1[u[i]].emplace_back(i);
            e1[v[i]].emplace_back(i);
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            if (e1[i].size() == 1){
                dfs(i);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            dfs(i);
        }
    }
    for (int i = ecnt - 1; i >= 0; -- i){
        getans(i);
    }
    for (int i = 0; i < m; ++ i){
        if (orient[i] == 1){
            ans[u[i]] -= w[i];
            ans[v[i]] += w[i];
        }
        else{
            ans[u[i]] += w[i];
            ans[v[i]] -= w[i];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        if (std::abs(ans[i]) == 1){
            ++ cnt;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < m; ++ i){
        putchar('1' + orient[i]);
    }
    for (int i = 1; i <= n; ++ i){
        assert(std::abs(ans[i]) <= 2);
    }
    puts("");
    return 0;
}