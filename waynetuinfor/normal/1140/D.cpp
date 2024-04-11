#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    long long ans = 0;
    for (int i = 2; i < n; ++i) ans += i * (i + 1);
    printf("%lld\n", ans);
}