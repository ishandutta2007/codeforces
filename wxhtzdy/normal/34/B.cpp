#include <bits/stdc++.h>

using namespace std;

#define N       1005

int a[N];

int main() {
        int n, m, i;

        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        long long ans = 0;
        for (i = 0; i < n; i++) {
                if (a[i] < 0 && i < m) {
                        ans -= a[i];
                }
        }
        printf("%lld", ans);
        return 0;
}