#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
int a[kN], b[kN], p[kN];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i]--;
            p[a[i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
            b[i]--;
        }
        long long ans = 0;
        int z = -1;
        for (int i = 0; i < m; ++i) {
            if (p[b[i]] <= z) {
                ans += 1;
            } else {
                ans += 2 * (p[b[i]] - i) + 1;
                z = p[b[i]];
            }
        }
        printf("%lld\n", ans);
    }
}