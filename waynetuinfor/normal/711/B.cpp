#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
long long a[maxn][maxn];
int n;

bool check(long long z) {
    for (int i = 1; i <= n; ++i) {
        long long s = 0;
        for (int j = 1; j <= n; ++j) s += a[i][j];
        if (s != z) return false;
    }
    for (int j = 1; j <= n; ++j) {
        long long s = 0;
        for (int i = 1; i <= n; ++i) s += a[i][j];
        if (s != z) return false;
    }
    long long s = 0;
    for (int i = 1; i <= n; ++i) s += a[i][i];
    if (s != z) return false;
    s = 0;
    for (int i = 1; i <= n; ++i) s += a[i][n - i + 1];
    if (s != z) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    }
    if (n == 1) return 0 * puts("1");
    int r = -1, c = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (a[i][j] == 0) r = i, c = j;
    }
    int s = (r == 1 ? 2 : r - 1);
    long long k = 0;
    for (int j = 1; j <= n; ++j) k += a[s][j];
    long long z = 0;
    for (int j = 1; j <= n; ++j) z += a[r][j];
    long long ans = k - z;
    if (ans <= 0) return 0 * puts("-1");
    a[r][c] = ans;
    if (check(k)) printf("%" PRId64 "\n", ans);
    else puts("-1");
    return 0;
}