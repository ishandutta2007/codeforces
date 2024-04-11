#include <bits/stdc++.h>

using namespace std;

const int oo = (int)1e9 + 7;
const int MAXN = (int)1e5 + 5;

int n, q, k, a[MAXN], cnt[MAXN];
long long sum[MAXN];

int main() {
    scanf("%d%d%d", &n, &q, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for(int i = 2; i <= n-1; ++i)
        cnt[i] = a[i+1] - a[i-1] - 2;
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + cnt[i];

    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);

        long long ans;
        if (l == r) {
            ans = k-1;
        } else {
            ans = sum[r-1] - sum[l];
            ans += a[l+1] - 2;
            ans += k - a[r-1] - 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}