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
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; i++) {
            b[i] = a[i] - a[i - 1] - 1;
        }
        int ans = *min_element(b.begin(), b.end());
        int pos = (int) (min_element(b.begin(), b.end()) - b.begin());
        b.emplace_back(d - 1 - a[n - 1]);
        b[pos + 1] += b[pos] + 1;
        b.erase(b.begin() + pos);
        b.back()--;
        ans = max(ans, *min_element(b.begin(), b.end()));
        b.pop_back();
        pos = (int) (max_element(b.begin(), b.end()) - b.begin());
        b[pos]--;
        b[pos] /= 2;
        ans = max(ans, *min_element(b.begin(), b.end()));
        b = vector<int>(n);
        b[0] = a[0];
        for (int i = 1; i < n; i++) {
            b[i] = a[i] - a[i - 1] - 1;
        }
        pos = (int) (min_element(b.begin(), b.end()) - b.begin());
        if (pos > 0) {
            b.emplace_back(d - 1 - a[n - 1]);
            b[pos] += b[pos - 1] + 1;
            b.erase(b.begin() + pos - 1);
            b.back()--;
            debug(b);
            ans = max(ans, *min_element(b.begin(), b.end()));
            b.pop_back();
            pos = (int) (max_element(b.begin(), b.end()) - b.begin());
            b[pos]--;
            b[pos] /= 2;
            ans = max(ans, *min_element(b.begin(), b.end()));
        }
        cout << ans << '\n';
    }
    return 0;
}