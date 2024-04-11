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
        int n, k;
        long long x;
        cin >> n >> k >> x;
        x--;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        string ans;
        for (int beg = 0; beg < n;) {
            if (s[beg] == 'a') {
                ans += "a";
                beg++;
                continue;
            }
            int end = beg;
            while (end < n && s[end] == '*') {
                end++;
            }
            int y = k * (end - beg) + 1;
            if (x > 0) {
                ans += string((int) (x % y), 'b');
                x /= y;
            }
            beg = end;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}