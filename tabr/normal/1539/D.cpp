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
    vector<pair<long long, long long>> c(n);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i].second >> c[i].first;
        s += c[i].second;
    }
    sort(c.begin(), c.end());
    long long lo = 0, hi = s + 1;
    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;
        long long cnt = s - mid;
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (cnt < c[i].first) {
                ok = 0;
                break;
            }
            cnt += c[i].second;
            if (cnt >= s) {
                break;
            }
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << 2 * s - lo << '\n';
    return 0;
}