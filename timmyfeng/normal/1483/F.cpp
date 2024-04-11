#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000001, ALPHA_SIZE = 26;

int in[MAX_N], out[MAX_N], path[MAX_N], t;
vector<int> adj[MAX_N];

int to[MAX_N][ALPHA_SIZE], depth[MAX_N], link[MAX_N], prv[MAX_N];
string ninja[MAX_N];

void dfs(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        dfs(c);
    }
    out[u] = t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> ninja[i];

        int u = 0;
        for (auto j : ninja[i]) {
            int c = j - 'a';
            if (to[u][c] == 0) {
                depth[m] = depth[u] + 1;
                to[u][c] = m++;
            }
            u = to[u][c];
        }
        prv[u] = u;
    }

    queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        int p = link[u];
        prv[u] = prv[prv[u] > 0 ? u : p];
        if (u > 0) {
            adj[p].push_back(u);
        }

        for (int c = 0; c < ALPHA_SIZE; ++c) {
            if (to[u][c] == 0) {
                to[u][c] = to[p][c];
            } else {
                link[to[u][c]] = u > 0 ? to[p][c] : 0;
                queue.push(to[u][c]);
            }
        }
    }

    dfs(0);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int size = ninja[i].size();

        for (int j = 0, u = 0; j < size; ++j) {
            u = to[u][ninja[i][j] - 'a'];
            path[j] = prv[u];
        }
        path[size - 1] = prv[link[path[size - 1]]];

        int k = size;
        vector<int> sub, skip;
        for (int j = size - 1; j >= 0; --j) {
            if (path[j] > 0) {
                sub.push_back(path[j]);
                if (j - depth[path[j]] < k) {
                    k = j - depth[path[j]];
                } else {
                    skip.push_back(path[j]);
                }
            }
        }

        sort(skip.begin(), skip.end());
        sort(sub.begin(), sub.end(), [&](int a, int b) {
            return in[a] > in[b];
        });

        int prev = m + 1;
        for (auto j : sub) {
            if (prev > out[j]) {
                ans += !binary_search(skip.begin(), skip.end(), j);
                prev = in[j];
            }
        }
    }

    cout << ans << "\n";
}