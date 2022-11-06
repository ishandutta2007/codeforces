#include <bits/stdc++.h>
using namespace std;

const int kMod = 998244353;
const int kN = 200'000 + 5;
int p[kN], pd[kN], sum[kN];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % kMod;
        a = 1LL * a * a % kMod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    pd[0] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        p[i] = 100LL * fpow(p[i], kMod - 2) % kMod;
        sum[i + 1] = 1LL * (sum[i] + 1) * p[i] % kMod;
        pd[i + 1] = 1LL * pd[i] * p[i] % kMod;
    }

    auto Query = [&](int l, int r) {
        int pr = 1LL * pd[r] * fpow(pd[l], kMod - 2) % kMod;
        return (sum[r] + kMod - 1LL * sum[l] * pr % kMod) % kMod;
    };

    set<int> s;
    s.insert(0), s.insert(n);
    int ans = Query(0, n);
    while (q--) {
        int u; scanf("%d", &u); --u;
        if (s.count(u)) {
            auto it = s.find(u);
            (ans += kMod - Query(*prev(it), u)) %= kMod;
            (ans += kMod - Query(u, *next(it))) %= kMod;
            (ans += Query(*prev(it), *next(it))) %= kMod;
            s.erase(u);
        } else {
            auto it = s.lower_bound(u);
            (ans += kMod - Query(*prev(it), *it)) %= kMod;
            (ans += Query(*prev(it), u)) %= kMod;
            (ans += Query(u, *it)) %= kMod;
            s.insert(u);
        }
        printf("%d\n", ans);
    }
    return 0;
}