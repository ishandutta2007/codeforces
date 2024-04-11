#include <bits/stdc++.h>
using namespace std;

int calc(int x, int y, int a, int b) {
    return max(0, min(a, b) - max(x, y) + 1); 
}

int main() {
    int n; scanf("%d", &n);
    int x = 0, y = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        if (i + 1 < n) ans -= a == b;
        ans += calc(x, y, a, b);
        x = a, y = b;
    }
    printf("%lld\n", ans);
}