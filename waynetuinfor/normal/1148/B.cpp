#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, m, ta, tb, k; scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    if (n <= k || m <= k) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        int c = k - i;
        int j = lower_bound(b, b + m, a[i] + ta) - b;
        int nxt = j + c;
        if (nxt >= m) {
            puts("-1");
            return 0;
        }
        ans = max(ans, b[nxt] + tb);
    }
    printf("%d\n", ans);
}