#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> pos(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        tot += min(k, (int) pos[i].size());
    }
    tot /= k;
    vector<int> ans(n);
    vector<int> fill(n);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < min(k, (int) pos[i].size()); r++) {
            if (fill[curr] == tot) break;
            ans[pos[i][r]] = curr + 1;
            ++fill[curr];
            ++curr;
            curr %= k;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}