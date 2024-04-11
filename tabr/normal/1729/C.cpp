#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        vector <vector<int>> a(26);
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            a[s[i] - 'a'].emplace_back(i);
        }
        vector<int> ans;
        if (s[0] <= s[n - 1]) {
            for (char c = s[0]; c <= s[n - 1]; c++) {
                for (int i: a[c - 'a']) {
                    ans.emplace_back(i);
                }
            }
        } else {
            for (char c = s[0]; c >= s[n - 1]; c--) {
                for (int i: a[c - 'a']) {
                    ans.emplace_back(i);
                }
            }
        }
        cout << abs(s[0] - s[n - 1]) << " " << ans.size() << "\n";
        for (int i: ans) {
            cout << i + 1 << " \n"[i == ans.back()];
        }
    }
    return 0;
}