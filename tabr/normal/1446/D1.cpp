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
    vector<int> b(100);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]]++;
    }
    int c = *max_element(b.begin(), b.end());
    int x = -1;
    for (int i = 0; i < 100; i++) {
        if (c == b[i]) {
            if (x != -1) {
                cout << n << '\n';
                return 0;
            }
            x = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        if (i == x) {
            continue;
        }
        vector<int> p(n + 1);
        vector<int> q(n + 1);
        for (int j = 0; j < n; j++) {
            p[j + 1] = p[j];
            q[j + 1] = q[j];
            if (i == a[j]) {
                p[j + 1]++;
                q[j + 1]++;
            } else if (x == a[j]) {
                p[j + 1]--;
                q[j + 1]++;
            }
        }
        vector<pair<int, int>> z(2 * n + 1, make_pair(-1, -1));
        for (int j = 0; j <= n; j++) {
            if (z[p[j] + n].second == -1) {
                z[p[j] + n] = {j, q[j]};
            }
        }
        for (int j = n; j >= 0; j--) {
            if (q[j] != z[p[j] + n].second) {
                ans = max(ans, j - z[p[j] + n].first);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}