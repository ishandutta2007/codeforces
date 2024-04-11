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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += i;
    }
    set<pair<int, int>> st;
    vector<vector<int>> d(n + 1);
    for (int i = 0; i <= n; i++) {
        st.emplace(i, b[i]);
        d[b[i]].emplace_back(i);
    }
    int inf = (int) 1e9;
    vector<int> dp(n + 1, inf);
    vector<int> pre(n + 1, -1);
    vector<int> e(n + 1, -1);
    dp[n] = 0;
    e[n] = n;
    queue<int> que;
    que.emplace(n);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        auto it = st.lower_bound(make_pair(a[v], -1));
        vector<int> del;
        while (it != st.end() && it->first < v) {
            debug(v, *it);
            auto to = it->second;
            del.emplace_back(to);
            if (dp[to] > dp[v] + 1) {
                e[to] = it->first;
                dp[to] = dp[v] + 1;
                pre[e[to]] = e[v];
                que.emplace(to);
            }
            it++;
        }
        sort(del.begin(), del.end());
        del.resize(unique(del.begin(), del.end()) - del.begin());
        for (int i : del) {
            for (int j : d[i]) {
                st.erase(make_pair(j, i));
            }
        }
    }
    if (dp[0] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dp[0] << '\n';
        vector<int> c;
        int i = 0;
        while (i != n) {
            c.emplace_back(i);
            i = pre[i];
        }
        reverse(c.begin(), c.end());
        for (int j : c) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}