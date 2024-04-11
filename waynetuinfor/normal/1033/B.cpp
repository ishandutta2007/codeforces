#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long a, b; scanf("%lld%lld", &a, &b);
        if (a - b != 1) {
            puts("NO");
            continue;
        }
        bool ans = true;
        for (long long i = 2; i * i <= a + b; ++i) {
            if ((a + b) % i != 0) continue;
            if (i == a + b) continue;
            ans = false;
        }
        ans ? puts("YES") : puts("NO");
    }
}