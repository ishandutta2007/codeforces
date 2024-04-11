#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int j;
            cin >> j;
            j--;
            g[j].emplace_back(i);
        }
        vector<long long> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        {
            function<void(int)> Dfs = [&](int v) {
                for (int to : g[v]) {
                    s[to] += s[v];
                    Dfs(to);
                }
            };
            Dfs(0);
        }
        vector<map<int, long long>> dp(n);
        function<long long(int, int)> Dfs = [&](int v, int x) {
            if (dp[v].count(x)) {
                return dp[v][x];
            }
            debug(v, x, dp[v][x]);
            int sz = (int) g[v].size();
            if (sz == 0) {
                return dp[v][x] = s[v] * x;
            }
            dp[v][x] = 0;
            vector<long long> t;
            for (int to : g[v]) {
                dp[v][x] += Dfs(to, x / sz);
                t.emplace_back(Dfs(to, (x + sz - 1) / sz) - Dfs(to, x / sz));
            }
            sort(t.rbegin(), t.rend());
            for (int i = 0; i < x % sz; i++) {
                dp[v][x] += t[i];
            }
            return dp[v][x];
        };
        cout << Dfs(0, k) << '\n';
    }
    return 0;
}