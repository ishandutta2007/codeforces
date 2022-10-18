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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; i++) {
            b[i] = a[i + 1] - a[i];
        }
        sort(b.begin(), b.end());
        if (n == 2) {
            cout << b[0] << '\n';
            continue;
        }
        vector<int> c(n - 2);
        for (int i = 0; i < n - 2; i++) {
            c[i] = b[i + 1] - b[i];
        }
        sort(c.begin(), c.end());
        if (n == 3) {
            cout << c[0] << '\n';
            continue;
        }
        if (c.back() == 0) {
            cout << 0 << '\n';
            continue;
        }
        reverse(c.begin(), c.end());
        int zeros = 0;
        while (c.back() == 0) {
            c.pop_back();
            zeros++;
        }
        reverse(c.begin(), c.end());
        while (c.size() > 1) {
            if (zeros > 0) {
                zeros--;
                c.insert(c.begin(), 0);
            }
            int sz = (int) c.size();
            vector<int> d;
            for (int i = 0; i < sz - 1; i++) {
                d.emplace_back(c[i + 1] - c[i]);
            }
            sort(d.begin(), d.end());
            if (d.back() == 0) {
                c = vector<int>(1, 0);
                break;
            }
            while (d.back() == 0) {
                d.pop_back();
                zeros++;
            }
            swap(c, d);
        }
        cout << c[0] << '\n';
    }
    return 0;
}