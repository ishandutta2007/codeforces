#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    int x = k - 1, y = n - k;
    if (x > y) swap(x, y);
    int ans = 3 + 2 * x + y + 2 * (n - 1);
    printf("%d\n", ans);
}