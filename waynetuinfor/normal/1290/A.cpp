#include <bits/stdc++.h>
using namespace std;

const int kInf = 2'000'000'000;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        k = min(k, m - 1);
        for (int i = 0; i <= k; ++i) {
            int g = kInf;
            for (int j = 0; j <= m - 1 - k; ++j) g = min(g, max(a[i + j], a[n - 1 - (k - i) - (m - 1 - k - j)]));
            ans = max(ans, g);
        }
        printf("%d\n", ans);
    }
    return 0;
}