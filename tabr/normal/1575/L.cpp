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
    vector<int> a(n);
    int m = (int) 2e5 + 10;
    vector<vector<int>> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]].emplace_back(i);
    }
    vector<int> c(m + 10, (int) 1e9);
    c[0] = -1;
    for (int x = 0; x < m; x++) {
        reverse(b[x].begin(), b[x].end());
        for (int i : b[x]) {
            if (i - x < 0) {
                continue;
            }
            int j = (int) (upper_bound(c.begin(), c.end(), i - x) - c.begin());
            c[j] = i - x;
        }
        if (!b[x].empty()) {
            debug(vector<int>(c.begin(), c.begin() + 10));
        }
    }
    cout << lower_bound(c.begin(), c.end(), (int) 1e9) - c.begin() - 1 << '\n';
    return 0;
}