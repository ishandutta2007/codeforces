#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long b[maxn], a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n / 2; ++i) scanf("%lld", &b[i]);
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        long long x = max((i ? a[i - 1] : 0ll), (i ? b[i] - a[j + 1] : 0));
        a[i] = x;
        a[j] = b[i] - a[i];
    }
    for (int i = 0; i < n; ++i) printf("%lld ", a[i]);
    puts("");
    return 0;
}