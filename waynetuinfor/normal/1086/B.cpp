#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int deg[maxn];

int main() {
    int n, s; scanf("%d%d", &n, &s);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        ++deg[x - 1];
        ++deg[y - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += deg[i] == 1;
    printf("%.20lf\n", (double)s * 2.0 / ans);
    return 0;
}