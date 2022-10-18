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
        cin >> n >> k;
        string s;
        cin >> s;
        string ans(k, 'a');
        map<char, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (c - 'a' >= n / k) {
                break;
            }
            int i = 0;
            while (i < k && cnt[c] > 0 && ans[i] == c) {
                cnt[c]--;
                ans[i]++;
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}