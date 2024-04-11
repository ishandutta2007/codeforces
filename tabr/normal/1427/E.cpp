#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x;
    cin >> x;
    vector<long long> a, b;
    vector<int> c;
    auto ch = [&](long long z) {
        long long r = 1;
        for (int i = 0; i < 60; i++) {
            if (r == z) {
                return false;
            }
            r *= 2;
            r++;
        }
        return true;
    };
    while (ch(x)) {
        long long y = x;
        long long t = x;
        for (int i = 40; i >= 0; i--) {
            if (x & (1LL << i)) {
                y += x * (1LL << i);
                for (int j = 0; j < i; j++) {
                    a.emplace_back(t);
                    b.emplace_back(t);
                    c.emplace_back(0);
                    t *= 2;
                }
                break;
            }
        }
        assert(t + x == y);
        a.emplace_back(t);
        b.emplace_back(x);
        c.emplace_back(0);
        for (int j = 40; j >= 0; j--) {
            if ((y ^ (x << j)) < y) {
                a.emplace_back(y);
                b.emplace_back(x << j);
                c.emplace_back(1);
                y ^= x << j;
            }
        }
        if (y % 2 == 1) {
            x = y;
            continue;
        }
        bool d = false;
        for (int j = 40; j >= 0; j--) {
            if ((x ^ (y << j)) < x) {
                if (!d) {
                    d = true;
                    t = y;
                    for (int k = 0; k < j; k++) {
                        a.emplace_back(t);
                        b.emplace_back(t);
                        c.emplace_back(0);
                        t *= 2;
                    }
                }
                a.emplace_back(x);
                b.emplace_back(y << j);
                c.emplace_back(1);
                x ^= y << j;
            }
        }
        assert(x % 2 == 1);
    }
    if (x != 1) {
        a.emplace_back(x);
        b.emplace_back(x);
        c.emplace_back(0);
        a.emplace_back(x);
        b.emplace_back(2 * x);
        c.emplace_back(0);
        a.emplace_back(x);
        b.emplace_back(2 * x);
        c.emplace_back(1);
        a.emplace_back(3 * x);
        b.emplace_back(x ^ (2 * x));
        c.emplace_back(0);
        a.emplace_back(2 * x);
        b.emplace_back(2 * x);
        c.emplace_back(0);
        a.emplace_back(4 * x + 2);
        b.emplace_back(4 * x);
        c.emplace_back(1);
        long long t = 2;
        while (t < x) {
            a.emplace_back(x);
            b.emplace_back(t);
            c.emplace_back(1);
            x ^= t;
            a.emplace_back(t);
            b.emplace_back(t);
            c.emplace_back(0);
            t *= 2;
        }
    }
    cout << a.size() << '\n';
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " " << (c[i] == 1 ? "^" : "+") << " " << b[i] << '\n';
    }
    return 0;
}