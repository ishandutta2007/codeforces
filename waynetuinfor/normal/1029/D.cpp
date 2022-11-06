#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], d[maxn], pw[11];
map<int, int> cnt[11];

int calc(int x) {
    int res = 0;
    while (x) res++, x /= 10;
    return res;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) d[i] = calc(a[i]);
    pw[0] = 1;
    for (int i = 1; i <= 10; ++i) pw[i] = pw[i - 1] * 1ll * 10 % k;
    for (int i = 0; i < n; ++i) cnt[d[i]][a[i] % k]++;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        --cnt[d[i]][a[i] % k];
        for (int j = 1; j <= 10; ++j) {
            int r = (a[i] % k) * 1ll * pw[j] % k;
            if (cnt[j].find((k - r) % k) != cnt[j].end())
                ans += cnt[j][(k - r) % k];
        }
        ++cnt[d[i]][a[i] % k];
    }
    printf("%lld\n", ans);
}