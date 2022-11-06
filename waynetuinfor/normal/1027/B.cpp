#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        if ((x + y) % 2 == 0) {
            long long p = ((x - 1) * 1ll * n + 1) / 2;
            if (x & 1) p += y / 2;
            else p += (y - 1) / 2;
            printf("%lld\n", p + 1);
        } else {
            long long p = ((x - 1) * 1ll * n) / 2;
            if (x & 1) p += (y - 1) / 2;
            else p += y / 2;
            printf("%lld\n", (n * 1ll * n + 1) / 2 + p + 1);
        }
    }
}