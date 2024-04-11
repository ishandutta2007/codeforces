#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        s += a;
        printf("%lld ", s / m);
        s %= m;
    }
}