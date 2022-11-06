#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long s, a, b, c; scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
        long long ans = (s / (a * c)) * (a + b);
        s %= (a * c);
        ans += s / c;
        printf("%lld\n", ans);
    }
}