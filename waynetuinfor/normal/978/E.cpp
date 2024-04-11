#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn];
long long s[maxn];

int main() {
    int n, w; scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    long long l = 0, r = w;
    for (int i = 1; i <= n; ++i) {
        l = max(l, -s[i]);
        r = min(r, w - s[i]);
    }
    if (r < l) puts("0");
    else printf("%d\n", r - l + 1);
}