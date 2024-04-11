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
        vector<int> s(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> t(n + 5);
        for (int i = 0; i < n; i++) {
            ans += max(0, s[i] - t[i] - 1);
            t[i + 1] += max(t[i] - s[i] + 1, 0);
            t[i + 2] -= max(t[i] - s[i] + 1, 0);
            t[i + 2]++;
            t[min(n, i + s[i] + 1)]--;
            t[i + 1] += t[i];
        }
        cout << ans << '\n';
    }
    return 0;
}