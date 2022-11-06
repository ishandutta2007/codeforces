#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int p[maxn], t[maxn], z, x, n, m;

int query(int y) {
    printf("%d\n", y);
    fflush(stdout);
#ifdef LOCAL
    int ret = 0;
    if (x < y) ret = -1;
    if (x > y) ret = 1;
    ret *= t[z];
    if (ret == 0) {
        puts("AC");
        exit(0);
    }
    z = (z + 1) % n;
    return ret;
#else
    int q; scanf("%d", &q);
    if (q == 0) exit(0);
    return q;
#endif
}

int rand_t(int l, int r) {
    mt19937 gen(7122);
    return uniform_int_distribution<int>(l, r)(gen);
}

int main() {
    scanf("%d %d", &m, &n);
#ifdef LOCAL
    for (int i = 0; i < n; ++i) t[i] = rand_t(0, 1) ? 1 : -1;
    x = rand_t(1, m);
#endif
    for (int i = 0; i < n; ++i) p[i] = query(1);
    int ans = 0;
    for (int d = 29, i = 0; d >= 0; --d) {
        if (ans + (1 << d) > m) continue;
        int q = query(ans + (1 << d)) * p[i];
        if (q == 1) ans += (1 << d);
        i = (i + 1) % n;
    }
    assert(false);
}