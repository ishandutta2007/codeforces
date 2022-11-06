#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
char s[20][maxn];
long long v[1048576], pc[1048576];

void xorfwt(long long v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    xorfwt(v, l, m), xorfwt(v, m, r);
    for (int i = l, j = m; i < m; ++i, ++j) {
        long long x = v[i] + v[j];
        v[j] = v[i] - v[j], v[i] = x;
    }
}

void xorifwt(long long v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    for (int i = l, j = m; i < m; ++i, ++j) {
        long long x = (v[i] + v[j]) / 2;
        v[j] = (v[i] - v[j]) / 2, v[i] = x;
    }
    xorifwt(v, l, m), xorifwt(v, m, r);
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < m; ++i) {
        int t = 0;
        for (int j = 0; j < n; ++j) t ^= ((s[j][i] - '0') << j);
        ++v[t];
    }
    auto inv = [&](const int &k, int r = 0) { for (int i = 0; i < n; ++i) r ^= (((k >> i & 1) ^ 1) << i); return r; };
    for (int i = 0; i < (1 << n); ++i) pc[i] = min(__builtin_popcount(i), __builtin_popcount(inv(i)));
    xorfwt(v, 0, (1 << n)), xorfwt(pc, 0, (1 << n));
    for (int i = 0; i < (1 << n); ++i) v[i] *= pc[i];
    xorifwt(v, 0, (1 << n));
    int ans = maxn * 20;
    for (int i = 0; i < (1 << n); ++i) ans = min(ans, (int)v[i]);
    printf("%d\n", ans);
    return 0;
}