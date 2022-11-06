#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
vector<pair<int, int>> graph[maxn];
int x[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", x + i);
    while (m--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        --a; --b;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            int to, e; tie(to, e) = graph[i][j];
            ans = max(ans, 1.0 * (x[to] + x[i]) / e);
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}