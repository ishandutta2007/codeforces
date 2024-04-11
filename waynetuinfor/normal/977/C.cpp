#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    if (k == 0) {
        if (a[1] == 1) return 0 * puts("-1");
        printf("1\n");
        return 0;
    }
    int tar = a[k];
    for (int i = k + 1; i <= n; ++i) if (a[i] == tar) return 0 * puts("-1");
    printf("%d\n", tar);
}