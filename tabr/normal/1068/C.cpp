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
    int m;
    cin >> m;
    vector<vector<int>> b(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) {
            swap(x, y);
        }
        b[x].emplace_back(y);
    }
    int cur = 0;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j : b[i]) {
            ans[i].emplace_back(cur);
            ans[j].emplace_back(cur);
            cur++;
        }
        ans[i].emplace_back(cur++);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].size() << '\n';
        for (int j : ans[i]) {
            cout << i + 1 << " " << j + 1 << '\n';
        }
    }
    return 0;
}