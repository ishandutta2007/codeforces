#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
long long a[maxn], b[maxn];
int cnt[60], d[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) a[m++] = b[i];
    }
    n = m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j)
            cnt[j] += (a[i] >> j & 1LL);
    }

    for (int i = 0; i < 60; ++i) {
        if (cnt[i] >= 3) {
            printf("3\n");
            return 0;
        }
    }

    assert(n <= 120);

    auto solve = [&](int r) {
        for (int i = 0; i < n; ++i) d[i] = -1;
        d[r] = 0;
        queue<int> q; q.push(r);
        int res = n + 1;

        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < n; ++i) {
                if ((a[i] & a[x]) == 0) continue;
                if (d[i] == -1) {
                    d[i] = d[x] + 1;
                    q.push(i);
                } else if (d[i] != -1 && i != x && d[i] >= d[x] ) {
                    res = min(res, d[i] + d[x] + 1);
                }
            }
        }
        return res;
    };

    int ans = 1e9;
    for (int i = 0; i < n; ++i) ans = min(ans, solve(i));

    if (ans > n) ans = -1;
    printf("%d\n", ans);
    return 0;
}