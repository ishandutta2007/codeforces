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
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());
    long long ans = 0;
    long long cur = 0;
    debug(c);
    vector<long long> t;
    for (int i = 0; i < n; i++) {
        debug(cur, ans);
        if (c[i] >= 0) {
            ans += cur;
            cur += c[i];
        } else if (cur >= 0) {
            ans += cur;
            cur += c[i];
            if (cur < 0) {
                t.emplace_back(cur);
            }
        } else {
            t.emplace_back(c[i]);
        }
    }
    debug(t);
    if ((int)t.size() > k + 1) {
        for (int i = 0; i < k + 1; i++) {
            t.pop_back();
        }
        debug(t);
        vector<long long> b(k + 1);
        for (int i = 0; i < (int)t.size(); i++) {
            b[i % (k + 1)] += t[i];
            ans += b[i % (k + 1)];
        }
    }
    cout << ans << '\n';
    return 0;
}