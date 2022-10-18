#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

pair<long long, long long> inv_gcd(long long a, long long b) {
    a = a % b;
    if (a == 0) {
        return {b, 0};
    }
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) {
        m0 += b / s;
    }
    return {s, m0};
}

pair<long long, long long> crt(vector<long long> r, vector<long long> m) {
    int n = (int) r.size();
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        long long r1 = r[i] % m[i], m1 = m[i];
        if (m0 < m1) {
            swap(r0, r1);
            swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) {
                return {0, 0};
            }
            continue;
        }
        long long g, im;
        tie(g, im) = inv_gcd(m0, m1);
        long long u1 = (m1 / g);
        if ((r1 - r0) % g) {
            return {0, 0};
        }
        long long x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) {
            r0 += m0;
        }
    }
    return {r0, m0};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<long long> p = {2, 11, 13, 17, 19, 23, 29, 31};
        vector<long long> q(p.size());
        long long c = 1;
        for (long long i : p) {
            c *= i;
        }
        for (int i = 1; i <= 30; i++) {
            cout << "? " << i << " " << c + i << endl;
            long long g = __gcd(c + i + 4LL, i + 4LL);
            cin >> g;
            for (int j = 0; j < (int) p.size(); j++) {
                if (g % p[j] == 0 && i < p[j]) {
                    q[j] = i;
                }
            }
        }
        auto a = crt(q, p);
        cout << "! " << a.second - a.first << '\n';
    }
    return 0;
}