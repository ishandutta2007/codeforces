#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.length(), cnt = 0;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt) {
                    a.push_back(cnt);
                }
                cnt = 0;
            }
        }
        if (cnt) a.push_back(cnt);
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < (int) a.size(); i += 2) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}