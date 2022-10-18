#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mn = 0;
    for (int i = 0; i < n; i++) {
        mn = max(mn, a[i] - i);
    }
    auto eval = [&](int x) {
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j < n - 1 && a[j + 1] <= x + i) {
                j++;
            }
            int b = j + 1 - i;
            if (b >= p) {
                return false;
            }
        }
        return true;
    };
    if (!eval(mn)) {
        cout << 0 << '\n';
        return 0;
    }
    int lo = mn, hi = mn + 100100;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (eval(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo - mn + 1 << '\n';
    for (int i = mn; i < hi; i++) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}