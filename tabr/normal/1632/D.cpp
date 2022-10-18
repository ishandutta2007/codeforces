#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int binary_gcd(int x_, int y_) {
    int x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;
    if (!x or !y) {
        return x + y;
    }
    int n = __builtin_ctz(x), m = __builtin_ctz(y);
    x >>= n, y >>= m;
    while (x != y) {
        if (x > y) {
            x = (x - y) >> __builtin_ctz(x - y);
        } else {
            y = (y - x) >> __builtin_ctz(y - x);
        }
    }
    return x << (n > m ? m : n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> b;
    int t = 0;
    if (a[0] == 1) {
        b.emplace_back((int) 1e9 + 7, 0);
        t = 1;
    } else {
        b.emplace_back(a[0], 0);
    }
    cout << t << " \n"[n == 1];
    for (int i = 1; i < n; i++) {
        vector<pair<int, int>> new_b;
        for (auto p : b) {
            p.first = binary_gcd(p.first, a[i]);
            if (new_b.empty() || new_b.back().first < p.first) {
                new_b.emplace_back(p);
            }
        }
        if (new_b.back().first < a[i]) {
            new_b.emplace_back(a[i], i);
        }
        int ok = 1;
        int lst = i + 1;
        reverse(new_b.begin(), new_b.end());
        for (auto p : new_b) {
            int j = i - p.first + 1;
            if (p.second <= j && j < lst) {
                ok = 0;
                break;
            }
            lst = p.second;
        }
        reverse(new_b.begin(), new_b.end());
        if (ok) {
            swap(b, new_b);
        } else {
            t++;
            b.clear();
            b.emplace_back((int) 1e9 + 7, 0);
        }
        cout << t << " \n"[i == n - 1];
    }
    return 0;
}