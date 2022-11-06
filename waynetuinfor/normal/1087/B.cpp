#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if (n / i >= k) continue;
            ans = min(ans, i * k + n / i);
        }
    }
    printf("%d\n", ans);
    return 0;
}