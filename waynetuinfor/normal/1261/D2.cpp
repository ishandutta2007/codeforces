#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const int kMod = 998244353;
int a[kN], fc[kN], iv[kN], pf[kN];

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
    if (k == 1) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int s = 0;
    fc[0] = iv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fc[i] = 1LL * fc[i - 1] * i % kMod;
        iv[i] = fpow(fc[i], kMod - 2);
    }
    for (int i = 0; i < n; ++i) s += a[i] != a[(i + 1) % n];
    int ans = 0;
    if (k > 2) {
        for (int x = 0; x <= s; ++x) {
            int add = 1LL * Choose(s, x) * fpow(k - 2, s - x) % kMod * fpow(1 + fpow(k - 2, kMod - 2), s - x) % kMod;
            (ans += add) %= kMod;
        }
        ans = 1LL * ans * fpow(k, n - s) % kMod;
        for (int x = 0; x + x <= s; ++x) {
            int y = x;
            int add = 1LL * Choose(s, x) * Choose(s - x, y) % kMod;
            add = 1LL * add * fpow(k, n - s) % kMod;
            add = 1LL * add * fpow(k - 2, s - x - y) % kMod;
            // (ans += add) %= kMod;
            (ans += kMod - add) %= kMod;
        }
        ans = 1LL * ans * fpow(2, kMod - 2) % kMod;
    } else {
        for (int x = 0; x <= s; ++x) {
            int y = s - x;
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