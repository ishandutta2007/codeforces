#include <bits/stdc++.h>
using namespace std;

int ans[21] = { 0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390, 439, 488, 537, 586, 635, 684, 733 };

int main() {
    int n; scanf("%d", &n);
    if (n <= 20) {
        printf("%d\n", ans[n]);
        return 0;
    }
    n -= 20;
    printf("%lld\n", ans[20] + 49 * 1ll * n);
}