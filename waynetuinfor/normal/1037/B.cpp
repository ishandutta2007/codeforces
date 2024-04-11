#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n, s; scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] > s) ans += a[i] - s;
    }
    if (a[n / 2] != s) ans += abs(s - a[n / 2]);
    for (int i = n / 2 + 1; i < n; ++i) {
        if (a[i] < s) ans += s - a[i];
    }
    printf("%lld\n", ans);
}