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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> t(n);
    vector<vector<int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
        s[t[i]].emplace_back(i);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(ans.end(), s[i].begin(), s[i].end());
        for (int v : s[i]) {
            set<int> st;
            for (int to : g[v]) {
                st.emplace(t[to]);
            }
            for (int j = 0; j < i; j++) {
                if (st.count(j) == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
            if (st.count(i)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << '\n';
    return 0;
}