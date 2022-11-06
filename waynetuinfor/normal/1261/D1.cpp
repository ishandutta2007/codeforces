#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const int kMod = 998244353;
int a[kN], fc[kN], iv[kN];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % kMod;
        a = 1LL * a * a % kMod;
        n >>= 1;
    }
    return res;
}

int Choose(int n, int k) {
    return 1LL * fc[n] * iv[k] % kMod * iv[n - k] % kMod;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int s = 0;
    fc[0] = iv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fc[i] = 1LL * fc[i - 1] * i % kMod;
        iv[i] = fpow(fc[i], kMod - 2);
    }
    for (int i = 0; i < n; ++i) s += a[i] != a[(i + 1) % n];
    int ans = 0;
    for (int x = 0; x <= s; ++x) {
        for (int y = 0; y + x <= s; ++y) {
            if (x > y) {
                int add = 1LL * Choose(s, x) * Choose(s - x, y) % kMod;
                add = 1LL * add * fpow(k, n - s) % kMod;
                add = 1LL * add * fpow(k - 2, s - x - y) % kMod;
                (ans += add) %= kMod;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}