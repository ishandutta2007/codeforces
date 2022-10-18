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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<long long> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = b[i] - b[(i + n - 1) % n];
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (abs(c[i] - c[(i + 1) % n]) % n != 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << '\n';
            continue;
        }
        vector<long long> d(n);
        for (int i = 1; i < n; i++) {
            d[i] = d[i - 1] + (c[i - 1] - c[i]) / n;
        }
        if (d[n - 1] + (c[n - 1] - c[0]) / n != 0) {
            cout << "NO" << '\n';
            continue;
        }
        long long mn = *min_element(d.begin(), d.end());
        for (int i = 0; i < n; i++) {
            d[i] -= mn;
            d[i]++;
        }
        long long e = d[0];
        for (int i = 1; i < n; i++) {
            e += d[i] * (n - i + 1);
        }
        long long f = b[0] - e;
        long long m = 1LL * n * (n + 1) / 2;
        if (f < 0 || f % m != 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            d[i] += f / m;
            cout << d[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}