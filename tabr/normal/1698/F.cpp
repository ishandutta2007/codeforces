#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
            cout << "NO" << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        auto Add = [&](int x, int y) {
            assert(a[x] == a[y]);
            ans.emplace_back(x, y);
            reverse(a.begin() + x, a.begin() + y + 1);
        };
        for (int i = 1; i < n - 1; i++) {
            assert(a[i - 1] == b[i - 1]);
            if (a[i] == b[i]) {
                continue;
            }
            bool ok = false;
            for (int j = i; j < n - 1; j++) {
                if (b[i] == a[j] && b[i - 1] == a[j + 1]) {
                    Add(i - 1, j + 1);
                    ok = true;
                    break;
                }
            }
            if (ok) {
                continue;
            }
            for (int j = i; j < n - 1; j++) {
                if (b[i] == a[j + 1] && b[i - 1] == a[j]) {
                    map<int, int> at_l, at_r;
                    for (int k = i; k < j; k++) {
                        at_l[a[k]] = k;
                    }
                    for (int k = j + 2; k < n; k++) {
                        at_r[a[k]] = k;
                    }
                    if (at_l.count(a[j + 1])) {
                        Add(at_l[a[j + 1]], j + 1);
                        ok = true;
                        break;
                    }
                    if (at_r.count(a[j])) {
                        Add(j, at_r[a[j]]);
                        ok = true;
                        break;
                    }
                    for (auto p : at_l) {
                        if (at_r.count(p.first)) {
                            Add(p.second, at_r[p.first]);
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                    for (auto p : at_r) {
                        if (at_l.count(p.first)) {
                            Add(at_l[p.first], p.second);
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
            }
            if (!ok) {
                ans.clear();
                ans.emplace_back(-1, -1);
                break;
            }
            ok = false;
            for (int j = i; j < n - 1; j++) {
                if (b[i] == a[j] && b[i - 1] == a[j + 1]) {
                    Add(i - 1, j + 1);
                    ok = true;
                    break;
                }
            }
            assert(ok);
        }
        if (a != b) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            for (auto [x, y] : ans) {
                cout << x + 1 << " " << y + 1 << '\n';
            }
        }
    }
    return 0;
}