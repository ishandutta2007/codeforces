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

vector<array<long long, 2>> dp;
vector<vector<int>> adj;
vector<bool> rem;

void dfs(int curr, int par, vector<int> &a) {
    dp[curr][1] = a[curr];
    long long m0 = 0, m1 = 0;
    for (int next : adj[curr]) {
        if (next == par) continue;
        dfs(next, curr, a);
        m0 = max(m0, dp[next][0]);
        if (dp[next][1] > 0) {
            m1 += dp[next][1];
        }
    }
    dp[curr][1] += m1;
    m0 = max(m0, dp[curr][1]);
    dp[curr][0] = m0;
}

int dfs2(int curr, int par, vector<int> &a, long long look) {
    dp[curr][1] = 0LL, dp[curr][0] = 0LL;
    dp[curr][1] = a[curr];
    long long m0 = 0, m1 = 0;
    int ans = 0;
    for (int next : adj[curr]) {
        if (next == par) continue;
        ans += dfs2(next, curr, a, look);
        if (rem[next]) continue;
        m0 = max(m0, dp[next][0]);
        if (dp[next][1] > 0) {
            m1 += dp[next][1];
        }
    }
    dp[curr][1] += m1;
    m0 = max(m0, dp[curr][1]);
    dp[curr][0] = m0;
    if (dp[curr][1] == look) {
        rem[curr] = true;
        ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp.resize(n);
    dfs(0, -1, a);
    if (dp[0][0] == 0) {
        int mx = -1e9 - 1, curr = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                mx = a[i], curr = 1;
            } else if (a[i] == mx) {
                ++curr;
            }
        }
        cout << mx * 1LL * curr << " " << curr << "\n";
    } else {
        rem.resize(n);
        long long ans = dp[0][0];
        int num = dfs2(0, -1, a, dp[0][0]);
        cout << ans * 1LL * num << " " << num << "\n";
    }
}