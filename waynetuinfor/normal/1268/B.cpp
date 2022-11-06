#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    long long x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        if (i & 1) {
            x += a / 2;
            y += a - a / 2;
        } else {
            y += a / 2;
            x += a - a / 2;
        }
    }
    printf("%lld\n", min(x, y));
    return 0;
}