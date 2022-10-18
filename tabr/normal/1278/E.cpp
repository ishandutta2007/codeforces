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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> ans(1);
    function<void(int, int)> dfs = [&](int v, int p) {
        stack<int> st;
        st.emplace(v);
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            st.emplace(to);
        }
        while (!st.empty()) {
            ans.emplace_back(st.top());
            st.pop();
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
        }
    };
    dfs(0, -1);
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < 2 * n; i++) {
        if (l[ans[i]] == -1) {
            l[ans[i]] = i + 1;
        } else {
            r[ans[i]] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] << " " << r[i] << '\n';
    }
    return 0;
}