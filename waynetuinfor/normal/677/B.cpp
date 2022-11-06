#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int main() {
    int n, h, k; scanf("%d %d %d", &n, &h, &k);
    int now = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        if (now + a > h) {
            int to = h - a;
            int diff = now - to;
            int req = ceil(1.0 * diff / k);
            ans += req;
            now -= k * req;
            now = max(now, 0);
        }
        now += a;
    }
    ans += ceil(1.0 * now / k);
    printf("%lld\n", ans);
}