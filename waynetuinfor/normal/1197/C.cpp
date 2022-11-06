#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = a[n - 1] - a[0];
    for (int i = 1; i < n; ++i) b[i - 1] = a[i] - a[i - 1];
    sort(b, b + n - 1, greater<int>());
    for (int i = 0; i < k - 1; ++i) ans -= b[i];
    printf("%d\n", ans);
    return 0;
}