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
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx += a[i] * a[i];
    }
    int t = k - n;
    sort(a.rbegin(), a.rend());
    auto get = [&](long long x, int y) {
        long long z = x / y;
        long long res = (x - z * y);
        res = res * (z + 1) * (z + 1) + z * z * (-res + y);
        return res;
    };
    vector<long long> d;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (1LL * (j + 1) * i <= 1LL * t) {
                long long b = 0;
                b -= get(a[j], i);
                b += get(a[j], i + 1);
                d.emplace_back(b);
            } else {
                break;
            }
        }
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < min((int)d.size(), t); i++) {
        mx += d[i];
    }
    cout << mx << '\n';
    return 0;
}