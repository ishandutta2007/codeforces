#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn], s[maxn], cnt[2];

int main() {
    int n; scanf("%d", &n);
    cnt[0]++;
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        long long x; scanf("%lld", &x);
        a[i] = __builtin_popcountll(x);
        s[i] = s[i - 1] + a[i];
        cnt[s[i] & 1]++;
    } 
    long long ans = cnt[0] * 1ll * (cnt[0] - 1) / 2 + cnt[1] * 1ll * (cnt[1] - 1) / 2;
    for (int i = 1; i <= n; ++i) {
        int bit = 0;
        for (int j = 0; j < 130; ++j) {
            if (i - j < 1) break;
            bit = max(bit, a[i - j]);
            int sum = s[i] - s[i - j - 1];
            if (sum % 2 == 0 && sum < 2 * bit) --ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}