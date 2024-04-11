#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    long long p, q, b, g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d %I64d\n", &p, &q, &b);
        g = gcd(p, q);
        p /= g;
        q /= g;
        while (1) {
            g = gcd(q, b);
            q /= g;
            b = g;
            if (g == 1) break;
        }
        if (q == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}