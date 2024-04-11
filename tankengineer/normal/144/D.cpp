#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, s, l;

const int N = 100005;

const int INF = 1000000000;
int dis[N];

vector<pair<int, int> > edge[N];

int main() {
    scanf("%d%d%d", &n, &m, &s);
    --s;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i < n; ++i) {
        dis[i] = INF;
    }
    priority_queue<pair<int, int> > heap;
    dis[s] = 0;
    heap.push(make_pair(-dis[s], s));
    while (heap.size()) {
        int d = -heap.top().first, u = heap.top().second;
        heap.pop();
        if (dis[u] != d) {
            continue;
        }
        for (int i = 0; i < (int)edge[u].size(); ++i) {
            int v = edge[u][i].first, nd = d + edge[u][i].second;
            if (dis[v] > nd) {
                dis[v] = nd;
                heap.push(make_pair(-dis[v], v));
            }
        }
    }
    scanf("%d", &l);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dis[i] == l;
        int u = i;
        for (int j = 0; j < (int)edge[u].size(); ++j) {
            int u = i, v = edge[u][j].first, d = edge[u][j].second;
            if (u < v) {
                continue;
            }
            int d1 = d + dis[v] - dis[u], d2 = 2 * d - d1;
            int k = l - dis[u];
            if (k > 0 && k * 2 < d1) {
                ++ans;
            }
            k = l - dis[v];
            if (k > 0 && k * 2 < d2) {
                ++ans;
            }
            if (d1 != 2 * d && d2 != 2 * d) {
                if (2 * (l - dis[u]) == d1) {
                    ++ans;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}