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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = "YES";
        vector<int> a(k, -1);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                if (s[j] != '?') {
                    int b = s[j] - '0';
                    if (a[i] == -1 || a[i] == b) {
                        a[i] = b;
                    } else {
                        ans = "NO";
                    }
                }
            }
        }
        int x = 0, y = 0;
        for (int i = 0; i < k; i++) {
            if (a[i] == 0) {
                x++;
            } else if (a[i] == 1) {
                y++;
            }
        }
        if (x > k / 2 || y > k / 2) {
            ans = "NO";
        }
        cout << ans << '\n';
    }
    return 0;
}