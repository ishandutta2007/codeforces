#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int& x : p) cin >> x, x--;

    vector<int> used(n), leaf(n, true);
    for (int i = 0; i < n; ++i) {
        if (i != p[i]) leaf[p[i]] = false;
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        if (!leaf[i]) continue;

        vector<int> cur;
        int j = i;
        while (!used[j]) used[j] = true, cur.push_back(j), j = p[j];
        reverse(cur.begin(), cur.end());
        ans.push_back(cur);
    }

    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size() << '\n';
        for (int x : v) cout << x+1 << ' ';
        cout << '\n';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}