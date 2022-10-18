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
        vector<pair<int, int>> s(k);
        vector<int> t(2 * n);
        for (int i = 0; i < k; i++) {
            cin >> s[i].first >> s[i].second;
            s[i].first--;
            s[i].second--;
            t[s[i].first] = t[s[i].second] = 1;
            if (s[i].first > s[i].second) {
                swap(s[i].first, s[i].second);
            }
        }
        vector<int> u;
        for (int i = 0; i < 2 * n; i++) {
            if (!t[i]) {
                u.emplace_back(i);
            }
        }
        for (int i = 0; i < n - k; i++) {
            s.emplace_back(u[i], u[i + n - k]);
        }
        sort(s.begin(), s.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i].second > s[j].first && s[i].second < s[j].second) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}