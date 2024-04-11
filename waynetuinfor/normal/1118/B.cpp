#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<vector<int>> b(2, vector<int>(n, 0));
    vector<vector<int>> c(2, vector<int>(n, 0));
    b[0][0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[0][i] = b[0][i - 1];
        b[1][i] = b[1][i - 1];
        b[i & 1][i] += a[i];
    }
    c[n & 1 ^ 1][n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        c[0][i] = c[0][i + 1];
        c[1][i] = c[1][i + 1];
        c[i & 1][i] += a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = i ? b[0][i - 1] : 0;
        int y = i + 1 < n ? c[1][i + 1] : 0;
        if (x + y + x + y == sum - a[i]) ++ans;
    }
    printf("%d\n", ans);
}