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
        string s, t;
        cin >> s >> t;
        auto AC = [&](string x) {
            string y;
            for (int i = 0; i < n; i++) {
                if (x[i] != 'b') {
                    y += x[i];
                }
            }
            return y;
        };
        if (AC(s) != AC(t)) {
            cout << "NO" << '\n';
            continue;
        }
        auto B = [&](string x) {
            vector<int> a;
            int b = 0;
            for (int i = 0; i < n; i++) {
                if (x[i] != 'b') {
                    a.emplace_back(b);
                } else {
                    b++;
                }
            }
            return a;
        };
        auto bs = B(s);
        auto bt = B(t);
        auto ac = AC(s);
        string ans = "YES";
        int sz = (int) bs.size();
        for (int i = 0; i < sz; i++) {
            if (ac[i] == 'a') {
                if (bs[i] > bt[i]) {
                    ans = "NO";
                    break;
                }
            } else {
                if (bs[i] < bt[i]) {
                    ans = "NO";
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}