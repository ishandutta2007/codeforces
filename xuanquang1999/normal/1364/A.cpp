#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, x, a[MAXN], d[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &x);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            d[i] = (d[i-1] + a[i]) % x;
        }

        int l = 0, r = n;
        while (l < n && d[l] == d[l+1])
            ++l;
        while (r > 0 && d[r] == d[r-1])
            --r;

        // for(int i = 0; i <= n; ++i)
        //     printf("%d ", d[i]);
        // puts("");

        int ans;
        if (l >= r)
            ans = -1;
        else if (d[0] != d[n])
            ans = n;
        else
            ans = max(n - l - 1, r - 1);

        printf("%d\n", ans);
    }

    return 0;
}