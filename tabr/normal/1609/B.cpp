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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            ans++;
        }
    }
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        int beg = max(0, p - 2);
        int end = min(p, n - 3);
        for (int i = beg; i <= end; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ans--;
            }
        }
        s[p] = c;
        for (int i = beg; i <= end; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}