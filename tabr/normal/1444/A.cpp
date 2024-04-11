#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<pair<long long, int>> factor(long long n) {
    vector<pair<long long, int>> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pair<long long, int> p;
            p.first = i;
            while (n % i == 0) {
                n /= i;
                p.second++;
            }
            res.emplace_back(p);
        }
    }
    if (n != 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long p, q;
        cin >> p >> q;
        if (p % q != 0) {
            cout << p << '\n';
            continue;
        }
        auto a = factor(q);
        long long x = 0;
        debug(a, p / q);
        for (auto b : a) {
            long long k = p / q;
            while (k % b.first == 0) {
                k /= b.first;
            }
            x = max(x, q * k / b.first);
        }
        cout << x << '\n';
    }
    return 0;
}