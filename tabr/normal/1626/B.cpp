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
        int n = (int) s.size();
        string ans;
        for (int i = n - 2; i >= 0; i--) {
            int x = s[i] - '0';
            int y = s[i + 1] - '0';
            if (x + y >= 10) {
                ans = s;
                ans.erase(ans.begin() + i + 1);
                ans.erase(ans.begin() + i);
                ans.insert(ans.begin() + i, '1');
                ans.insert(ans.begin() + i + 1, (char) ('0' + x + y - 10));
                break;
            }
        }
        if (ans.empty()) {
            ans = s;
            int x = s[0] - '0';
            int y = s[1] - '0';
            ans.erase(ans.begin());
            ans.erase(ans.begin());
            ans.insert(ans.begin(), (char) (x + y + '0'));
        }
        cout << ans << '\n';
    }
    return 0;
}