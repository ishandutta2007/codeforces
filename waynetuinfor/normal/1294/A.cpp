#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
        int g = a + b + c + n;
        if (g % 3 != 0 || g / 3 < a || g / 3 < b || g / 3 < c) puts("NO");
        else puts("YES");
    }
}