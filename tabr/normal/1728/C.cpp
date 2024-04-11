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
        multiset<int> a, b;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            a.emplace(c);
        }
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            b.emplace(c);
        }
        auto f = [&](int x) {
            return (int) to_string(x).size();
        };
        int ans = 0;
        while (!a.empty()) {
            int x = *a.rbegin();
            int y = *b.rbegin();
            if (x == y) {
                a.erase(prev(a.end()));
                b.erase(prev(b.end()));
            } else if (x > y) {
                a.erase(prev(a.end()));
                a.emplace(f(x));
                ans++;
            } else {
                b.erase(prev(b.end()));
                b.emplace(f(y));
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}