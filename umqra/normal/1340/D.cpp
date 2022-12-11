#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 10;
int deg[N];
vector<int> g[N];
vector<pair<int, int>> path;

void route(int v, int parent, int return_time, int max_time) {
    path.emplace_back(v, return_time);
    int current_time = return_time;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == parent) {
            continue;
        }
        if (current_time == max_time) {
            int remainder = 0;
            for (int s = i; s < (int)g[v].size(); s++) {
                if (g[v][s] == parent) {
                    continue;
                }
                remainder++;
            }
            assert(remainder <= return_time - 1);
            current_time = (return_time - 1) - remainder;
            path.emplace_back(v, current_time);
        }
        route(to, v, current_time + 1, max_time);
        current_time++;
    }
    if (current_time != return_time - 1) {
        path.emplace_back(v, return_time - 1);
    }
    path.emplace_back(parent, return_time);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, deg[i] + 1);
    }
    path.emplace_back(0, 0);
    for (int i = 0; i < (int)g[0].size(); i++) {
        route(g[0][i], 0, i + 1, result - 1);
    }
#ifdef DEBUG
    auto pairs = set<pair<int, int>>(path.begin(), path.end());
    assert(pairs.size() == path.size());
    auto cities = set<int>();
    for (auto &&e : pairs) {
        cities.insert(e.first);
    }
    assert((int)cities.size() == n);
#endif
    printf("%d\n", (int)path.size());
    for (auto &&e : path) {
        printf("%d %d\n", e.first + 1, e.second);
    }

    return 0;
}