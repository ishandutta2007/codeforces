#include <bits/stdc++.h>

const int N = 405;
const int moder = 998244353;
using pii = std::pair <int, int>;

std::vector <int> e[N];
int dis[N][N];
bool vis[N];
int mat[N][N];
int p[N];
pii vec[N][N];
int cnt[N];
std::bitset <N> edge[N], set[N];
int vec1[N][N], cnt1[N];

void solve(int s){
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    std::queue <int> queue;
    queue.push(s);
    dis[s][s] = 0;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (!vis[v]){
                vis[v] = true;
                dis[s][v] = dis[s][u] + 1;
                queue.push(v);
            }
        }
    }
}

int calc(pii *p, int n){
    for (int i = 0; i < n; ++ i){
        set[p[i].second][p[i].first] = true;
        vec1[p[i].second][cnt1[p[i].second] ++] = p[i].first;
    }
    int ret = 1;
    int now = 1;
    for (int i = 1; now < n; ++ i){
        for (int j = 0; j < cnt1[i]; ++ j){
            ret = 1ll * ret * (edge[vec1[i][j]] & set[i - 1]).count() % moder;
            if (ret == 0){
                break;
            }
        }
        now += cnt1[i];
        if (ret == 0){
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        set[p[i].second][p[i].first] = false;
        cnt1[p[i].second] = 0;
    }
    return ret;
}

int calc(int s, int t, int n){
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; ++ i){
        if (dis[s][i] + dis[t][i] == dis[s][t]){
            int &u = p[dis[s][i]];
            if (u != 0){
                return 0;
            }
            u = i;
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++ i){
        int dep = dis[s][i] + dis[t][i] - dis[s][t];
        if (dep % 2 == 1){
            return 0;
        }
        dep /= 2;
        int type = dis[s][i] - dep;
        vec[type][cnt[type] ++] = {i, dep};
    }
    int ret = 1;
    for (int i = 0; i <= dis[s][t]; ++ i){
        ret = 1ll * ret * calc(vec[i], cnt[i]) % moder;
        if (ret == 0){
            return ret;
        }
    }
    return ret;
}

int calc(int s, int n){
    cnt[0] = 0;
    for (int i = 1; i <= n; ++ i){
        vec[0][cnt[0] ++] = {i, dis[s][i]};
    }
    return calc(vec[0], cnt[0]);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        edge[u][v] = edge[v][u] = true;
    }
    for (int i = 1; i <= n; ++ i){
        solve(i);
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            mat[i][j] = mat[j][i] = calc(i, j, n);
        }
        mat[i][i] = calc(i, n);
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            printf("%d%c", mat[i][j], " \n"[j == n]);
        }
    }
    return 0;
}