#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int h[maxn], c[maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]), ++c[h[i]];
    int tg = *min_element(h, h + n);
    int z = *max_element(h, h + n), buf = 0, ans = 0;
    while (z > tg) {
        int p = c[z];
        if (buf + p > k) {
            ans++;
            buf = 0;
        }
        buf += p;
        c[z - 1] += c[z];
        --z;
    }
    if (buf > 0) ++ans;
    printf("%d\n", ans);
    return 0;
}