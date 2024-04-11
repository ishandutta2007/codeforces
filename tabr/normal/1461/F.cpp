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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    if ((int)s.size() == 1) {
        for (int i = 0; i < n; i++) {
            if (i) {
                cout << s[0];
            }
            cout << a[i];
        }
        cout << '\n';
    } else if (s == "+-" || s == "-+") {
        for (int i = 0; i < n; i++) {
            if (i) {
                cout << '+';
            }
            cout << a[i];
        }
        cout << '\n';
    } else if (s == "*-" || s == "-*") {
        for (int i = 0; i < n; i++) {
            if (i) {
                if (a[i] == 0) {
                    cout << '-';
                } else {
                    cout << '*';
                }
            }
            cout << a[i];
        }
        cout << '\n';
    } else {
        int m = (int)2e5;
        auto solve = [&](vector<int> x) {
            vector<int> y(1), z(1);
            for (int i = 0; i < (int)x.size(); i++) {
                if ((int)y.size() % 2) {
                    if (x[i] == 1) {
                        y.back()++;
                    } else {
                        y.emplace_back(x[i]);
                        z.emplace_back(i);
                    }
                } else {
                    if (x[i] == 1) {
                        y.emplace_back(1);
                        z.emplace_back(i);
                    } else {
                        y.back() *= x[i];
                        y.back() = min(y.back(), m);
                    }
                }
            }
            if ((int)y.size() % 2 == 0) {
                y.emplace_back(0);
                z.emplace_back((int)x.size());
            }
            int p = 1;
            for (int i = 1; i < (int)y.size(); i += 2) {
                if (1LL * p * y[i] >= m) {
                    p = m;
                } else {
                    p *= y[i];
                }
            }
            int sz = (int)x.size();
            if (p == m || (int)y.size() <= 3) {
                string t(sz - 1, '*');
                for (int i = 0; i < y[0]; i++) {
                    t[i] = '+';
                }
                for (int i = 0; i < y.back(); i++) {
                    t[sz - 2 - i] = '+';
                }
                for (int i = 0; i < sz; i++) {
                    if (i) {
                        cout << t[i - 1];
                    }
                    cout << x[i];
                }
                return;
            }
            int mx = 0;
            int rmask = 0;
            int k = (int)y.size();
            k /= 2;
            k--;
            debug(y);
            debug(z);
            debug(k);
            for (int mask = 0; mask < (1 << k); mask++) {
                int t = 0;
                int mul = y[1];
                for (int i = 0; i < k; i++) {
                    if (mask & (1 << i)) {
                        mul *= y[2 * i + 3];
                    } else {
                        t += mul;
                        mul = y[2 * i + 3];
                        t += y[2 * i + 2];
                    }
                }
                t += mul;
                if (mx < t) {
                    mx = t;
                    rmask = mask;
                }
            }
            string t(sz - 1, '*');
            for (int i = 0; i < y[0]; i++) {
                t[i] = '+';
            }
            for (int i = 0; i < y.back(); i++) {
                t[sz - 2 - i] = '+';
            }
            for (int i = 0; i < k; i++) {
                if (!(rmask & (1 << i))) {
                    for (int j = z[2 * i + 2]; j <= z[2 * i + 3]; j++) {
                        t[j - 1] = '+';
                    }
                }
            }
            for (int i = 0; i < sz; i++) {
                if (i) {
                    cout << t[i - 1];
                }
                cout << x[i];
            }
        };
        for (int i = 0; i < n; i++) {
            if (!a[i]) {
                if (i) {
                    cout << '+';
                }
                cout << 0;
                continue;
            }
            if (i) {
                cout << '+';
            }
            vector<int> b;
            for (int j = i; j <= n; j++) {
                if (j != n && a[j]) {
                    b.emplace_back(a[j]);
                } else {
                    i = j - 1;
                    break;
                }
            }
            solve(b);
        }
        cout << '\n';
    }
    return 0;
}