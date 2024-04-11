#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] % m == j && a[i][j] / m < n) {
                int g = a[i][j] / m;
                int d = i - g;
                if (d < 0) d += n;
                v.push_back(d);
            }
        }
        sort(v.begin(), v.end());
        int z = n;
        for (int i = 0, k = 0; i < v.size(); i = k) {
            for (k = i; k < v.size() && v[k] == v[i]; ++k);
            z = min(z, v[i] + n - (k - i));
        }
        ans += z;
    }
    printf("%d\n", ans);
    return 0;
}