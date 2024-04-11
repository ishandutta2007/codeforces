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
    string s;
    cin >> s;
    int ans = 0;
    int n = (int) s.size();
    if (s == "_") {
        cout << 1 << '\n';
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        string t = s;
        for (int j = 0; j < n; j++) {
            if (t[j] == 'X') {
                t[j] = (char) ('0' + i);
            }
        }
        if (n != 1 && t[0] == '0') {
            continue;
        }
        function<void(int, int)> f = [&](int id, int now) {
            if (id == n) {
                if (now % 25 == 0) {
                    ans++;
                }
                return;
            }
            if (t[id] == '_') {
                for (int j = (id == 0 ? 1 : 0); j < 10; j++) {
                    f(id + 1, now * 10 + j);
                }
            } else {
                f(id + 1, now * 10 + t[id] - '0');
            }
        };
        f(0, 0);
        if (s.find("X") == string::npos) {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}