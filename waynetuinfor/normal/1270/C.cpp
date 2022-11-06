#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        long long s = accumulate(a.begin(), a.end(), 0LL);
        int x = accumulate(a.begin(), a.end(), 0, [](int u, int v) { return u ^ v; });
        printf("2\n");
        printf("%lld %d\n", s + x, x);
    }
}