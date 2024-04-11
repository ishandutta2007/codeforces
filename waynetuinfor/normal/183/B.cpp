#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int ans[maxn];
int x[maxn], y[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d %d", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i) ans[i] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int dx = x[j] - x[i], dy = y[j] - y[i];
            if (dy == 0) continue;
            int c = 2;
            for (int k = 0; k < m; ++k) {
                if (k == i || k == j) continue;
                int tx = x[k] - x[i], ty = y[k] - y[i];
                if (dx * 1ll * ty == dy * 1ll * tx) ++c;
            }
            int g = __gcd(abs(dx), abs(dy));
            dx /= g, dy /= g;
            if (y[i] % abs(dy) == 0) {
                long long f = x[i] + -dx * 1ll * (y[i] / dy);
                if (f >= 1 && f <= n) ans[f] = max(ans[f], c);
            }
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; ++i) fin += ans[i];
    printf("%d\n", fin);
}