#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; scanf("%lld", &n);
    if (n == 0) {
        puts("0");
        return 0;
    }
    ++n;
    if (n % 2 == 0) printf("%lld\n", n / 2);
    else printf("%lld\n", n);
}