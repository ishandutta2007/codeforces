#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n, m, x, y, z, d[N], minw[N];
vector<ar2> g[N];

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        scanf("%d%d%d", &x, &y, &z);
        g[x].PB({y, z}), g[y].PB({x, z});
    }

    rep(i, 1, n) d[i] = minw[i] = INF;
    priority_queue<ar2, vector<ar2>, std::greater<ar2>> heap;
    heap.push({0, 1}), d[1] = 0;
    while (!heap.empty()) {
        ar2 ele = heap.top();
        heap.pop();
        int x = ele[1], dist = ele[0];
        if (dist > d[x])
            continue;
        for (auto ele1 : g[x]) {
            int u = ele1[0], w1 = ele1[1];
            if (w1 >= minw[u])
                continue;
            else
                minw[u] = w1;
            for (auto ele2 : g[u]) {
                int v = ele2[0], w2 = ele2[1];
                int w = (w1 + w2) * (w1 + w2);
                if (v != x && d[x] + w < d[v]) {
                    d[v] = d[x] + w;
                    heap.push({d[v], v});
                }
            }
        }
    }
    rep(i, 1, n) printf("%d ", d[i] == INF ? -1 : d[i]);
    return 0;
}