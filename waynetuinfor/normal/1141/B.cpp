#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = 0, prv = -1;
    for (int i = 0; i < n + n; ++i) {
        if (a[i % n] == 1 && prv == -1) prv = i;
        if (a[i % n] == 1) ans = max(ans, i - prv + 1);
        else prv = -1;
    }
    printf("%d\n", ans);
}