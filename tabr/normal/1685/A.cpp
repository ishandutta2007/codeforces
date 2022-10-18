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
        sort(a.begin(), a.end());
        auto Make = [&](vector<int> x, vector<int> y) {
            if (x.size() < y.size()) {
                swap(x, y);
            }
            vector<int> res;
            reverse(x.begin(), x.end());
            reverse(y.begin(), y.end());
            while (!x.empty()) {
                res.emplace_back(x.back());
                x.pop_back();
                if (!y.empty()) {
                    res.emplace_back(y.back());
                    y.pop_back();
                }
            }
            for (int i = 0; i < n; i++) {
                int b = res[(i + 1) % n];
                int c = res[(i + n - 1) % n];
                int d = res[i];
                if (d > max(b, c) || d < min(b, c)) {
                    continue;
                }
                return vector<int>();
            }
            return res;
        };
        vector<int> b = Make(vector<int>(a.begin(), a.begin() + n / 2), vector<int>(a.begin() + n / 2, a.end()));
        vector<int> c = Make(vector<int>(a.begin(), a.begin() + n / 2), vector<int>(a.begin() + n / 2, a.end()));
        if (c.empty()) {
            swap(b, c);
        }
        if (c.empty()) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << c[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}