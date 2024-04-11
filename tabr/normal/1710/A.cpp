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
        long long h, w;
        int n;
        cin >> h >> w >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string ans = "No";
        for (int z = 0; z < 2; z++) {
            vector<long long> t;
            for (int i = 0; i < n; i++) {
                long long x = a[i] / h;
                if (x >= 2) {
                    t.emplace_back(x);
                }
            }
            if (accumulate(t.begin(), t.end(), 0LL) >= w) {
                if (t == vector<long long>(t.size(), 2LL) && w % 2 == 1) {
                } else {
                    ans = "Yes";
                }
            }
            swap(h, w);
        }
        cout << ans << '\n';
    }
    return 0;
}