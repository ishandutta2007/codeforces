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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (i ? c[i - 1] : 0) + (s[i] == '+' ? 1 : -1);
        }
        long long res = n;
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] == cur) {
                res += i + 1;
                cur--;
            }
        }
        cout << res << '\n';
    }
    return 0;
}