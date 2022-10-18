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
    // x >= 2 * y - 1
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << " " << 1 << '\n';
        return 0;
    }
    int x = -1;
    for (int y = 0; 2 * y - 1 <= n - y; y++) {
        x = n - y;
    }
    int y = n - x;
    vector<pair<int, int>> ans;
    debug(n, x, y);
    for (int i = 0; i < y; i++) {
        ans.emplace_back(y - 1 - i, i);
    }
    for (int i = 0; i < y - 1; i++) {
        ans.emplace_back(y - 2 - i + y, i + y);
    }
    for (int i = 2 * y - 1, j = x - 1; i < x; i++, j--) {
        ans.emplace_back(i, j);
    }
    cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i + 1 << " " << j + 1 << '\n';
    }
    return 0;
}