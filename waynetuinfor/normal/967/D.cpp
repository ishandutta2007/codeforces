#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int c[maxn], o[maxn];

int main() {
    int n, x1, x2; scanf("%d %d %d", &n, &x1, &x2);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    iota(o, o + n, 0);
    sort(o, o + n, [&](const int &i, const int &j) { return c[i] > c[j]; });
    {
        int p = 0;
        for (; p < n && (p + 1) * 1ll * c[o[p]] < x1; ++p);
        int q = p + 1;
        for (; q < n && (q - p) * 1ll * c[o[q]] < x2; ++q);
        if (q < n) {
            puts("Yes");
            printf("%d %d\n", p + 1, q - p);
            for (int i = 0; i <= p; ++i) printf("%d ", o[i] + 1); puts("");
            for (int i = p + 1; i <= q; ++i) printf("%d ", o[i] + 1); puts("");
            return 0;
        }
    }
    {
        int p = 0;
        for (; p < n && (p + 1) * 1ll * c[o[p]] < x2; ++p);
        int q = p + 1;
        for (; q < n && (q - p) * 1ll * c[o[q]] < x1; ++q);
        if (q < n) {
            puts("Yes");
            printf("%d %d\n", q - p, p + 1);
            for (int i = p + 1; i <= q; ++i) printf("%d ", o[i] + 1); puts("");
            for (int i = 0; i <= p; ++i) printf("%d ", o[i] + 1); puts("");
            return 0;
        }
    }
    puts("No");
    return 0;
}