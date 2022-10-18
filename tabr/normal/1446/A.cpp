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
        cin >> n;
        long long x;
        cin >> x;
        vector<long long> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        long long s = accumulate(w.begin(), w.end(), 0LL);
        if (s < (x + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        int a = -1;
        for (int i = 0; i < n; i++) {
            if ((x + 1) / 2 <= w[i] && w[i] <= x) {
                a = i;
                break;
            }
        }
        if (a != -1) {
            cout << 1 << '\n';
            cout << a + 1 << '\n';
            continue;
        }
        vector<int> v;
        s = 0;
        for (int i = 0; i < n; i++) {
            if (s < (x + 1) / 2 && s + w[i] <= x && w[i] < (x + 1) / 2) {
                s += w[i];
                v.emplace_back(i + 1);
            }
        }
        if ((x + 1) / 2 <= s) {
            cout << v.size() << '\n';
            for (int i : v) {
                cout << i << " ";
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}