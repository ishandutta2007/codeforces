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
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = abs(a[i] - b[i]);
    }
    long long s = accumulate(c.begin(), c.end(), 0LL);
    vector<pair<long long, long long>> x, y;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            x.emplace_back(b[i], a[i]);
        } else if (a[i] < b[i]) {
            y.emplace_back(a[i], b[i]);
        }
    }
    long long mx = 0;
    sort(x.rbegin(), x.rend(), [&](auto i, auto j) { return i.second < j.second; });
    sort(y.rbegin(), y.rend(), [&](auto i, auto j) { return i.second < j.second; });
    for (int zz = 0; zz < 2; zz++) {
        long long lb = (long long)1e10;
        int id = -1;
        for (auto p : x) {
            while (id + 1 < (int)y.size() && y[id + 1].second >= p.second) {
                id++;
                lb = min(lb, y[id].first);
            }
            if (lb >= p.second) {
                continue;
            }
            mx = max(mx, p.second - max(p.first, lb));
        }
        swap(x, y);
    }
    s -= mx * 2;
    cout << s << '\n';
    return 0;
}