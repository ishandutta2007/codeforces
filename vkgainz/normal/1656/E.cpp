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
 
vector<vector<int>> adj;
vector<int> ans;

int dfs(int curr, int par, int target_sum, int tot_sum) {
    int sum = 0;
    for (int next : adj[curr]) { 
        if (next == par) continue;
        sum += dfs(next, curr, tot_sum - target_sum, tot_sum);
    }
    ans[curr] = target_sum - sum;
    return target_sum;
}

void solve() {
    int n; cin >> n;
    adj.clear(), ans.clear();
    adj.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int upd : adj[0]) {
        dfs(upd, 0, 1, 0);
        --ans[0];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}