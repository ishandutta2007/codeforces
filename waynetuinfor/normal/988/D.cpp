#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = -1, p = -1, z = -1;
    for (int i = 0; i < n; ++i) {
        for (long long d = 1; d <= 2e9; d <<= 1) {
            int x = a[i] - d, y = a[i] + d;
            int c = 0;
            if (binary_search(a, a + n, x)) ++c;
            if (binary_search(a, a + n, y)) ++c;
            if (c > ans) ans = c, p = a[i], z = d;
        }
    }
    if (ans == 0) {
        printf("1\n%d\n", a[0]);
        return 0;
    }
    if (ans == 1) {
        puts("2");
        printf("%d ", p);
        if (binary_search(a, a + n, p + z)) printf("%d\n", p + z);
        else printf("%d\n", p - z);
        return 0;
    }
    puts("3");
    printf("%d %d %d\n", p - z, p, p + z);
    return 0;
}