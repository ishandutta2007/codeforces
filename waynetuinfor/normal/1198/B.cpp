#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], latest[maxn], last[maxn], z[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int q; scanf("%d", &q);

    memset(last, -1, sizeof(last));

    for (int i = 0; i < q; ++i) {
        int t, p, x; scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &p, &x);
            latest[p - 1] = x;
            last[p - 1] = i;
        } else {
            scanf("%d", &x);
            z[i] = x;
        }
    }

    for (int i = q - 1; i >= 0; --i) z[i] = max(z[i], z[i + 1]);

    for (int i = 0; i < n; ++i) {
        int t = 0;
        if (last[i] != -1) {
            a[i] = latest[i];
            t = last[i];
        }
        a[i] = max(a[i], z[t]);
        printf("%d ", a[i]);
    }
}