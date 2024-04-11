#include <bits/stdc++.h>
using namespace std;

vector<int> sz;
vector<vector<int>> adj;

void dfs(int curr, int par) {
    sz[curr] = 1;
    for (int next : adj[curr]) {
        if (next == par) continue;
        dfs(next, curr);
        sz[curr] += sz[next];
    }
}
vector<pair<pair<int, int>, int>> ans;
vector<int> val;

int x;
void dfs_small(int curr, int par) {
    for (int next : adj[curr]) {
        if (next == par) continue;
        ++x;
        ans.push_back({{next, curr}, x - val[curr]});
        val[next] = x;
        dfs_small(next, curr);
    }
}

int mult;
int z;
void dfs_large(int curr, int par) {
    for (int next : adj[curr]) {
        if (next == par) continue;
        ++z;
        ans.push_back({{next, curr}, mult * z - val[curr]});
        val[next] = mult * z;
        dfs_large(next, curr);
    }
}

int main() {
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sz.resize(n);
    dfs(0, -1);
    val.resize(n);
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j : adj[i])
            if (sz[j] < sz[i])
                mx = max(mx, sz[j]);
        mx = max(mx, n - sz[i]);
        int cutoff = ceil(2 * (n - 1) * 1.0 / 3);
        if (mx <= cutoff) {
            vector<pair<int, int>> r;
            for (int j : adj[i]) {
                if (sz[j] < sz[i])
                    r.push_back({sz[j], j});
                else
                    r.push_back({n - sz[i], j});
            }
            sort(r.begin(), r.end());
            vector<int> small, large;
            int s = 0;
            while (s < n - 1 - cutoff) {
                s += r.back().first;
                small.push_back(r.back().second);
                r.pop_back();
            }
            while (!r.empty()) {
                large.push_back(r.back().second);
                r.pop_back();
            }
            val[i] = 0;
            for (int a : small) {
                ++x;
                ans.push_back({{a, i}, x - val[i]});
                val[a] = x;
                dfs_small(a, i);
            }
            mult = s + 1;
            for (int a : large) {
                ++z;
                ans.push_back({{a, i}, mult * z - val[i]});
                val[a] = mult * z;
                dfs_large(a, i);
            }
            for (auto &it : ans) {
                cout << it.first.first + 1 << " " << it.first.second + 1 << " " << it.second << "\n";
            }
            return 0;
        }
    }
}