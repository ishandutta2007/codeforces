#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 20;
const int moder = 998244353;
using pii = std::pair <int, int>;
using piiii = std::pair <pii, pii>;

int dis[N][BIT];
pii dis1[N][2];
std::vector<int> e[N], e1[N];
int power[N];

int calc(int bit, int add){
    int ans = ((power[bit] - 1) + add) % moder;
    ans += ans < 0 ? moder : 0;
    return ans;
}

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2ll * power[i - 1] % moder;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e1[v].emplace_back(u);
    }
    memset(dis, -1, sizeof(dis));
    dis[1][0] = 0;
    std::deque<pii> queue;
    queue.emplace_back(1, 0);
    while (!queue.empty()){
        pii p = queue.front();
        queue.pop_front();
        int u = p.first;
        pii q = {u, p.second + 1};
        int value = dis[u][p.second];
        if (q.second < BIT && dis[q.first][q.second] == -1){
            dis[q.first][q.second] = value;
            queue.emplace_front(q);
        }
        auto &vec = p.second & 1 ? e1[u] : e[u];
        for (auto v : vec){
            if (dis[v][p.second] == -1){
                dis[v][p.second] = value + 1;
                queue.emplace_back(v, p.second);
            }
        }
    }
    std::priority_queue<piiii, std::vector<piiii>, std::greater<piiii>> pq;
    for (int i = 1; i <= n; ++ i){
        dis1[i][0] = dis1[i][1] = {-1, -1};
    }
    pq.push({{0, 0}, {1, 0}});
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        auto distance = p.first;
        auto pp = p.second;
        int u = pp.first;
        if (dis1[u][pp.second] != std::make_pair(-1, -1)){
            continue;
        }
        dis1[u][pp.second] = distance;
        pq.push({{distance.first + 1, distance.second}, {u, pp.second ^ 1}});
        auto &vec = pp.second ? e1[u] : e[u];
        for (auto v : vec){
            pq.push({{distance.first, distance.second + 1}, {v, pp.second}});
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < BIT; ++ i){
        if (dis[n][i] == -1){
            continue;
        }
        ans = std::min(ans, calc(i, dis[n][i]));
    }
    if (ans != INT_MAX){
        printf("%d\n", ans);
        return 0;
    }
    pii ret = std::min(dis1[n][0], dis1[n][1]);
    printf("%d\n", calc(ret.first, ret.second));
    return 0;
}