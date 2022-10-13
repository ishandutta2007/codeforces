#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
vector<int> sz;
vector<int> dp;
vector<vector<int>> adj;
 
void dfs(int curr, int par) {
    sz[curr] = 1;
    dp[curr] = 1;
    for (int next : adj[curr]) {
        if (next == par) continue;
        dfs(next, curr);
        sz[curr] = max(sz[curr], 1 + sz[next]);
        dp[curr] += dp[next];
    }
}
 
struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    }
};
 
int main() {
    int n, k; cin >> n >> k;
    adj.resize(n);
    sz.resize(n);
    int leaf = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i < n; i++) {
        leaf += adj[i].size() == 1;
    }
    if (k >= leaf) {
        cout << max(leaf, min(k, n / 2)) * 1LL * (n - max(leaf, min(k, n / 2))) << "\n";
        return 0;
    }
    dp.resize(n);
    dfs(0, -1);
    set<pair<int, int>, cmp> heads;
    heads.insert({sz[0], 0});
    for (int i = 0; i < k; i++) {
        pair<int, int> follow = *heads.begin();
        while (true) {
            if (follow.first == 1) {
                heads.erase(follow);
                break;
            }
            pair<int, int> go = {0, 0};
            for (int next : adj[follow.second]) {
                if (sz[next] < follow.first) {
                    if (sz[next] > go.first) {
                        go = {sz[next], next};
                    }
                    heads.insert({sz[next], next});
                }
            }
            heads.erase(follow);
            follow = go;
        }
    }
    long long ans = k * 1LL * (n - k);
    int b = 0;
    for (auto &it : heads) {
        b += dp[it.second];
    }
    b = min(b, n / 2);
    ans -= b * 1LL * (n - b);
    cout << ans << "\n";
}