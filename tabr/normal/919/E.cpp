#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1, _m = m;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return (u % _m + _m) % _m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, p, n;
    cin >> a >> b >> p >> n;
    long long ans = 0;
    long long inv_a = inverse(a, p);
    long long inv_p1 = inverse(p - 1, p);
    long long d = 1;
    for (long long i = 0; i < min(n + 1, p - 1); i++) {
        long long c = (b * d - i + p) % p;
        c *= inv_p1;
        c %= p;
        d *= inv_a;
        d %= p;
        long long k = (n - i) / (p - 1);
        debug(i, k, c);
        if (k < c) {
            continue;
        }
        ans += (k - c) / p + 1;
    }
    cout << ans << '\n';
    return 0;
}