#include <bits/stdc++.h>

const int M = 60;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

int a[M][M];
int d[M], dtmp[M], deg[M], fa[M];
int n, k;
std::vector <pii> old_edge;

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

std::vector <pii> objects;

// given an independent set `set`, figure out all other indexes in `to_check`
// which can be add to `set`, and remain independent (matroid1)
std::vector <int> check1(const std::vector <int> &set, const std::vector <int> &to_check){
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for (auto [u, v] : old_edge){
        unite(u, v);
    }
    for (auto id : set){
        auto [u, v] = objects[id];
        unite(u, v);
    }
    std::vector <int> ret;
    for (auto id : to_check){
        auto [u, v] = objects[id];
        if (find(u) != find(v)){
            ret.emplace_back(id);
        }
    }
    return ret;
}

// given an independent set `set`, figure out all other indexes in `to_check`
// which can be add to `set`, and remain independent (matroid2)
std::vector <int> check2(const std::vector <int> &set, const std::vector <int> &to_check){
    for (int i = 1; i <= n; ++ i){
        deg[i] = 0;
    }
    for (auto id : set){
        auto [u, v] = objects[id];
        ++ deg[u], ++ deg[v];
    }
    std::vector <int> ret;
    for (auto id : to_check){
        auto [u, v] = objects[id];
        if (u <= k && deg[u] + 1 > d[u]){
            continue;
        }
        if (v <= k && deg[v] + 1 > d[v]){
            continue;
        }
        ret.emplace_back(id);
    }
    return ret;
}

const int N = 100010;

std::vector <int> e[N];
int value[N];
pii dis[N];

std::vector <int> matroid_intersection(){
    int n = objects.size();
    std::vector <int> set;
    while (true){
        for (int i = 0; i < n; ++ i){
            e[i].clear();
            dis[i] = {INT_MIN, INT_MIN};
        }
        std::vector <int> to_check;
        std::vector <bool> vis(n);
        for (auto u : set){
            vis[u] = true;
        }
        for (int i = 0; i < n; ++ i){
            if (!vis[i]){
                to_check.emplace_back(i);
            }
        }
        std::vector <int> x1 = check1(set, to_check);
        std::vector <int> x2 = check2(set, to_check);
        int sz = set.size();
        for (int i = 0; i < sz; ++ i){
            std::vector <int> nset;
            for (int j = 0; j < sz; ++ j){
                if (i != j){
                    nset.emplace_back(set[j]);
                }
            }
            std::vector <int> edge = check1(nset, to_check);
            for (auto u : edge){
                e[set[i]].emplace_back(u);
            }
            edge = check2(nset, to_check);
            for (auto u : edge){
                e[u].emplace_back(set[i]);
            }
        }
        std::vector <int> pre(n, -1);
        std::queue <int> queue;
        std::vector <bool> inque(n);
        for (auto u : x1){
            queue.emplace(u);
            inque[u] = true;
            dis[u] = {value[u], 0};
        }
        int found = -1;
        while (!queue.empty()){
            int u = queue.front();
            queue.pop();
            inque[u] = false;
            for (auto v : e[u]){
                auto [weight, edge] = dis[u];
                weight += vis[v] ? -value[v] : value[v];
                -- edge;
                pii ndis = {weight, edge};
                if (ndis > dis[v]){
                    dis[v] = ndis;
                    if (!inque[v]){
                        queue.emplace(v);
                        inque[v] = true;
                    }
                    pre[v] = u;
                }
            }
        }
        pii max = {INT_MIN, INT_MIN};
        for (auto u : x2){
            if (dis[u] > max){
                max = dis[u];
                found = u;
            }
        }
        if (found == -1){
            break;
        }
        while (found != -1){
            vis[found] = !vis[found];
            found = pre[found];
        }
        set.clear();
        for (int i = 0; i < n; ++ i){
            if (vis[i]){
                set.emplace_back(i);
            }
        }
    }
    return set;
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++ i){
        scanf("%d", &d[i]);
        dtmp[i] = d[i];
    }
    const int INF = 120;
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            scanf("%d", &a[i][j]);
            a[i][j] = INF - a[i][j];
            a[j][i] = a[i][j];
        }
    }
    std::vector <pii> vec;
    for (int i = 1; i <= k; ++ i){
        for (int j = i + 1; j <= k; ++ j){
            vec.emplace_back(i, j);
        }
    }
    std::vector <piii> edges;
    for (int i = k + 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            edges.emplace_back(a[i][j], i, j);
        }
    }
    std::sort(edges.begin(), edges.end(), std::greater <piii>());
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    int cnt = 0;
    for (auto [w, u, v] : edges){
        if (find(u) != find(v)){
            objects.emplace_back(u, v);
            value[cnt] = a[u][v];
            ++ cnt;
            unite(u, v);
        }
    }
    for (int i = 1; i <= k; ++ i){
        for (int j = k + 1; j <= n; ++ j){
            objects.emplace_back(i, j);
            value[cnt] = a[i][j];
            ++ cnt;
        }
    }
    int sz = vec.size();
    int ans = INT_MAX;
    for (int i = 0; i < 1 << sz; ++ i){
        old_edge.clear();
        for (int j = 1; j <= n; ++ j){
            fa[j] = j;
            deg[j] = 0;
        }
        bool flag = true;
        for (int j = 0; j < sz; ++ j){
            if (i >> j & 1){
                auto [u, v] = vec[j];
                if (find(u) == find(v)){
                    flag = false;
                    break;
                }
                unite(u, v);
                ++ deg[u], ++ deg[v];
                old_edge.emplace_back(vec[j]);
            }
        }
        if (!flag){
            continue;
        }
        for (int j = 1; j <= k; ++ j){
            if (deg[j] > dtmp[j]){
                flag = false;
                break;
            }
        }
        if (!flag){
            continue;
        }
        for (int j = 1; j <= k; ++ j){
            d[j] = dtmp[j] - deg[j];
        }
        std::vector <int> vec1 = matroid_intersection();
        int sum = 0;
        cnt = 0;
        for (int j = 1; j <= n; ++ j){
            fa[j] = j;
            deg[j] = 0;
        }
        for (int j = 0; j < sz; ++ j){
            if (i >> j & 1){
                auto [u, v] = vec[j];
                assert(find(u) != find(v));
                unite(u, v);
                ++ deg[u], ++ deg[v];
                sum += a[u][v];
                ++ cnt;
            }
        }
        for (auto id : vec1){
            auto [u, v] = objects[id];
            assert(find(u) != find(v));
            unite(u, v);
            ++ deg[u], ++ deg[v];
            sum += a[u][v];
            ++ cnt;
        }
        for (int j = 1; j <= k; ++ j){
            assert(deg[j] <= dtmp[j]);
        }
        if (cnt < n - 1){
            continue;
        }
        ans = std::min(ans, cnt * INF - sum);
    }
    printf("%d\n", ans);
    return 0;
}