#include <bits/stdc++.h>
using namespace std;

const int kN = 300'000 + 5;
int fc[kN], iv[kN];

int fpow(int a, int n, int p) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % p;
        a = 1LL * a * a % p;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    fc[0] = iv[0] = 1;
    for (int i = 1; i < kN; ++i) {
        fc[i] = 1LL * fc[i - 1] * i % m;
        iv[i] = fpow(fc[i], m - 2, m);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int g = 1LL * (n - i + 1) * fc[i] % m;
        g = 1LL * g * (n - i + 1) % m;
        g = 1LL * g * fc[n - i] % m;
        (ans += g) %= m;
    }
    printf("%d\n", ans);
    return 0;
}