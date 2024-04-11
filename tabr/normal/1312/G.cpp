#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<char> c(n);
    vector<vector<int>> trie(n + 1, vector<int>(26, -1));
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        trie[p[i]][c[i] - 'a'] = i + 1;
    }
    int k;
    cin >> k;
    vector<int> a(k), b(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    int cnt = 0;
    vector<int> x(1, 1e9), y(1, 1e9);
    function<void(int)> dfs = [&](int v) {
        if (b[v]) {
            dp[v] = min(dp[v], cnt + 1 + y.back());
        }
        x.emplace_back(dp[v] - cnt);
        y.emplace_back(min(y.back(), x.back()));
        if (b[v]) {
            cnt++;
        }
        for (int i = 0; i < 26; i++) {
            if (trie[v][i] != -1) {
                dp[trie[v][i]] = dp[v] + 1;
                dfs(trie[v][i]);
            }
        }
        x.pop_back();
        y.pop_back();
    };
    dfs(0);
    for (int i = 0; i < k; i++) {
        cout << dp[a[i]] << " ";
    }
    cout << '\n';
    return 0;
}