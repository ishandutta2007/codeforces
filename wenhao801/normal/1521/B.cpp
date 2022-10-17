#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n, a[100100];

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int i, mn = 0; a[0] = 1e9 + 7;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] < a[mn]) mn = i;
        }
        printf("%d\n", n - 1);
        for (i = mn - 1; i >= 1; i--) printf("%d %d %d %d\n", i, mn, a[mn] + mn - i, a[mn]);
        for (i = mn + 1; i <= n; i++) printf("%d %d %d %d\n", mn, i, a[mn], a[mn] + i - mn);
    }
    return 0;
}