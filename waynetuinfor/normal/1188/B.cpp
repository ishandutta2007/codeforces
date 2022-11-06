#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, k; scanf("%d%d%d", &n, &p, &k);

    map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        int y = (1ll * x * x % p * x % p * x % p + p - 1ll * k * x % p) % p;
        ans += cnt[y]++;
    }

    printf("%lld\n", ans);
    return 0;
}