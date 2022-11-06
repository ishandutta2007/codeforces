#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n, greater<int>());
        int x = a[0], y = a[1];
        int ans = min(n - 2, y - 1);
        printf("%d\n", ans);
    }
}