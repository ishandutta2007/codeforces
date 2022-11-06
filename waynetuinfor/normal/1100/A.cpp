#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (j % k != i % k) sum += a[j];
        }
        ans = max(ans, abs(sum));
    }
    printf("%d\n", ans);
    return 0;
}