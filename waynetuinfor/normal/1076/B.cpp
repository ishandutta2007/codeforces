#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x; scanf("%lld", &x);
    long long ans = 0;
    if (x & 1) {
        for (long long i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                x -= i;
                ++ans;
                break;
            }
        }
        if (ans == 0) {
            x = 0;
            ++ans;
        }
    } 
    ans += x / 2;
    printf("%lld\n", ans);
    return 0;
}