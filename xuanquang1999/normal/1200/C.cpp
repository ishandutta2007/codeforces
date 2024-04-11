#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a%b);
}

long long n, m, d, p1, p2;
int q;

long long getSection(long long x, long long y) {
    return (x == 1) ? (y/p1) : (y/p2);
}

int main() {
    cin >> n >> m >> q;

    d = gcd(n, m);
    p1 = n / d;
    p2 = m / d;

    for(int i = 0; i < q; ++i) {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        --sy; --ey;

        long long s1 = getSection(sx, sy);
        long long s2 = getSection(ex, ey);
        puts((s1 == s2) ? "YES" : "NO");
    }

    return 0;
}