#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], s[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int sz = 0, dy = 0;
    for (int i = 0; i < n; ++i) {
        while (sz && s[sz - 1] < a[i] && s[sz - 1] >= a[i] - k) ++dy, --sz;
        s[sz++] = a[i];
    }
    printf("%d\n", n - dy);
    return 0;
}