#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main() {
    int n, l, a; scanf("%d%d%d", &n, &l, &a);
    int last = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        ans += (x - last) / a;
        last = x + y;
    }
    ans += (l - last) / a;
    printf("%d\n", ans);
    return 0;
}