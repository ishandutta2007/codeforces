#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
#include <math.h>
#include <numeric>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> in(n), out(n);
    vector<int> tmp(n);
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u;
        --u, --v;
        adj[v].push_back(u);
        ++in[u], ++out[v];
        ++tmp[u];
    }
    vector<int> dp(n);
    vector<int> topSort;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        topSort.push_back(it);
        for (int next : adj[it]) {
            --in[next];
            if (in[next] == 0) {
                q.push(next);
            }
        }
    }
    in = tmp;
    reverse(topSort.begin(), topSort.end());
    for (int x : topSort) {
        for (int y : adj[x]) {
            if (in[y] > 1 && out[x] > 1) {
                dp[x] = max(dp[x], dp[y] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) + 1;
}