#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    long long sum = n * 1ll * (n + 1) / 2;
    int x = n + 1;
    for (int d = 30; d >= 0; --d) {
        int y = x - (1 << d);
        if (y < 1) continue;
        long long p = (1ll * y + n) * 1ll * (n - y + 1) / 2;
        if (sum - p >= p) x = y;
    }
    long long p = (1ll * x + n) * 1ll * (n - x + 1) / 2;
    long long y = (sum - p - p) / 2;
    if (y < x && y >= 1) p += y;
    printf("%lld\n", sum - p - p);
    return 0;
}