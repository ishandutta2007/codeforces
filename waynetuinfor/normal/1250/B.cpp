#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000 + 5;
const long long kInf = 1'000'000'000'000'000'000;
int a[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    long long sum = accumulate(a, a + n, 0LL);
    if (sum == 1) {
        puts("-1");
        return 0;
    }
    long long ans = kInf;
    for (int d = 2; 1LL * d * d <= sum; ++d) {
        int cnt = 0;
        while (sum % d == 0) sum /= d, cnt++;
        if (cnt > 0) {
            long long res = 0, s = 0;
            for (int i = 0; i < n; ++i) {
                s += a[i];
                res += min(s % d, d - s % d);
            }
            ans = min(ans, res);
        }
    }
    if (sum > 1) {
        long long res = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            res += min(s % sum, sum - s % sum);
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}