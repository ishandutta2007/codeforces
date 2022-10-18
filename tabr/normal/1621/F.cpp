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
        long long a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        vector<pair<int, int>> t;
        t.emplace_back(s[0] - '0', 1);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                t.emplace_back(s[i] - '0', 1);
            } else {
                t.back().second++;
            }
        }
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < (int) t.size(); i++) {
            if (t[i].first == 0) {
                zeros += t[i].second - 1;
            } else {
                ones += t[i].second - 1;
            }
        }
        vector<int> u;
        for (int i = 1; i < (int) t.size() - 1; i++) {
            if (t[i].first == 0) {
                u.emplace_back(t[i].second);
            }
        }
        sort(u.rbegin(), u.rend());
        vector<int> v;
        if (t[0].first == 0) {
            v.emplace_back(t[0].second);
        }
        if (t.back().first == 0) {
            v.emplace_back(t.back().second);
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        // 1010..
        {
            int c1 = ones;
            long long now = 0;
            auto z = u;
            auto w = v;
            int zcnt = 0;
            int wcnt = 0;
            while (!z.empty() && z.back() == 1) {
                zcnt++;
                z.pop_back();
            }
            while (!w.empty() && w.back() == 1) {
                wcnt++;
                w.pop_back();
            }
            debug(z, w, zcnt, wcnt);
            for (int i = 0; i < n; i++) {
                if (!z.empty() || !w.empty()) {
                    ans = max(ans, now + a);
                }
                if (i % 2 == 0) {
                    if (c1 == 0) {
                        break;
                    }
                    c1--;
                    now += b;
                    ans = max(ans, now);
                } else {
                    if (c1 > 0 && !z.empty()) {
                        now += a;
                        z.back()--;
                        if (z.back() == 1) {
                            z.pop_back();
                            zcnt++;
                        }
                    } else if (c1 > 0 && !w.empty()) {
                        now += a;
                        w.back()--;
                        if (w.back() == 1) {
                            w.pop_back();
                            wcnt++;
                        }
                    } else if (zcnt > 0) {
                        now -= c;
                        zcnt--;
                        c1++;
                    } else if (wcnt > 0) {
                        now -= c;
                        wcnt--;
                    } else {
                        break;
                    }
                    ans = max(ans, now);
                }
            }
        }
        // 0101..
        {
            int c1 = ones;
            long long now = 0;
            auto z = u;
            auto w = v;
            int zcnt = 0;
            int wcnt = 0;
            while (!z.empty() && z.back() == 1) {
                zcnt++;
                z.pop_back();
            }
            while (!w.empty() && w.back() == 1) {
                wcnt++;
                w.pop_back();
            }
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    if (c1 == 0) {
                        break;
                    }
                    c1--;
                    now += b;
                    ans = max(ans, now);
                } else {
                    if (!z.empty() || !w.empty()) {
                        ans = max(ans, now + a);
                    }
                    if (c1 > 0 && !z.empty()) {
                        now += a;
                        z.back()--;
                        if (z.back() == 1) {
                            z.pop_back();
                            zcnt++;
                        }
                    } else if (c1 > 0 && !w.empty()) {
                        now += a;
                        w.back()--;
                        if (w.back() == 1) {
                            w.pop_back();
                            wcnt++;
                        }
                    } else if (zcnt > 0) {
                        now -= c;
                        zcnt--;
                        c1++;
                    } else if (wcnt > 0) {
                        now -= c;
                        wcnt--;
                    } else {
                        break;
                    }
                    ans = max(ans, now);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}