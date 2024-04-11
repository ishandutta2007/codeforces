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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 0) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " \n"[i == n - 1];
        }
        return 0;
    }
    map<int, vector<int>> mp;
    int sh = 31 - __builtin_clz(k);
    for (int i = 0; i < n; i++) {
        mp[a[i] >> sh].emplace_back(i);
        mp[(a[i] >> sh) ^ 1];
    }
    vector<int> ans;
    debug(mp);
    for (auto [key, v1] : mp) {
        if (key % 2 == 1) {
            continue;
        }
        auto v2 = mp[key ^ 1];
        if (v1.empty()) {
            for (int i : v2) {
                ans.emplace_back(i);
                break;
            }
            continue;
        }
        if (v2.empty()) {
            for (int i : v1) {
                ans.emplace_back(i);
                break;
            }
            continue;
        }
        int c1 = -1;
        int c2 = -1;
        vector<int> a1;
        for (int i : v1) {
            a1.emplace_back(a[i] % (1 << sh));
        }
        sort(a1.begin(), a1.end());
        a1.resize(unique(a1.begin(), a1.end()) - a1.begin());
        vector<int> a2;
        for (int i : v2) {
            a2.emplace_back(a[i] % (1 << sh));
        }
        sort(a2.begin(), a2.end());
        a2.resize(unique(a2.begin(), a2.end()) - a2.begin());
        debug(a1, a2);
        int z = k % (1 << sh);
        for (int x : a1) {
            if (binary_search(a2.begin(), a2.end(), x ^ z)) {
                c1 = x;
                c2 = x ^ z;
                break;
            }
            int t = 0;
            for (int i = sh - 1; i >= 0; i--) {
                int u = t | (1 << i);
                auto it1 = lower_bound(a2.begin(), a2.end(), u);
                auto it2 = upper_bound(a2.begin(), a2.end(), u + (1 << i) - 1);
                auto it3 = lower_bound(a2.begin(), a2.end(), t);
                auto it4 = upper_bound(a2.begin(), a2.end(), t + (1 << i) - 1);
                if (x & (1 << i)) {
                    if (z & (1 << i)) {
                        if (it3 == it4) {
                            break;
                        }
                    } else {
                        if (it3 != it4) {
                            c1 = x;
                            c2 = *it3;
                            break;
                        }
                        t |= (1 << i);
                    }
                } else {
                    if (z & (1 << i)) {
                        if (it1 == it2) {
                            break;
                        }
                        t |= (1 << i);
                    } else {
                        if (it1 != it2) {
                            c1 = x;
                            c2 = *it1;
                            break;
                        }
                    }
                }
            }
            if (c1 != -1) {
                break;
            }
        }
        debug(c1, c2, (1 << sh) ^ c1 ^ c2, k);
        if (c1 == -1) {
            for (int i : v2) {
                ans.emplace_back(i);
                break;
            }
        } else {
            for (int i : v1) {
                if (a[i] % (1 << sh) == c1) {
                    ans.emplace_back(i);
                    break;
                }
            }
            for (int i : v2) {
                if (a[i] % (1 << sh) == c2) {
                    ans.emplace_back(i);
                    break;
                }
            }
        }
    }
    if (ans.size() == 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i + 1 << " \n"[i == ans.back()];
    }
    return 0;
}