#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    reverse(a, a + n);
    int ans = 0;
    bool inf = false;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 1 && a[i - 1] == 2)
            ans += 3 - (i - 2 >= 0 && a[i - 2] == 3);
        if (a[i] == 1 && a[i - 1] == 3)
            ans += 4;
        if (a[i] == 2 && a[i - 1] == 1)
            ans += 3;
        if (a[i] == 2 && a[i - 1] == 3)
            inf = true;
        if (a[i] == 3 && a[i - 1] == 1)
            ans += 4 - (i - 2 >= 0 && a[i - 2] == 2);
        if (a[i] == 3 && a[i - 1] == 2)
            inf = true;
    }

    if (inf) {
        printf("Infinite\n");
    } else {
        printf("Finite\n");
        printf("%d\n", ans);
    }
}