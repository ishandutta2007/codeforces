#include <stdio.h>

#define N   105

int min(int a, int b) { return a < b ? a : b; }

int solve(int mn, int v) {
    return v / (mn * 2 - 1) - (v % (mn * 2 - 1) == 0);
}

int main() {
    static int a[N];
    int t, n, i, ans;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int mn = 1e9;
        for (i = 0; i < n; i++)
            mn = min(mn, a[i]);
        int ans = 0;
        for (i = 0; i < n; i++) {
            ans += solve(mn, a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}