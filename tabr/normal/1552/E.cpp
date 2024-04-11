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
    int n, k;
    cin >> n >> k;
    vector<int> c(n * k);
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<pair<int, int>> ans(n, make_pair(-1, -1));
    vector<int> p(n, n * k);
    vector<int> s(n * k);
    for (int i = 0; i < n * k; i++) {
        if (ans[c[i]].first == -1 && p[c[i]] < i) {
            int mx = 0;
            for (int j = p[c[i]]; j <= i; j++) {
                mx = max(mx, s[j]);
            }
            debug(mx, i, p[c[i]]);
            if (mx < (n + k - 2) / (k - 1)) {
                ans[c[i]] = make_pair(p[c[i]], i);
                for (int j = p[c[i]]; j <= i; j++) {
                    s[j]++;
                }
            }
        }
        p[c[i]] = i;
    }
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << '\n';
    }
    return 0;
}