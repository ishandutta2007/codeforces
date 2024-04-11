#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> words(5);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;

            for (int j = 0; j < 5; ++j) {
                int balance = 0;
                for (auto c : s) {
                    balance += (c == 'a' + j ? -1 : 1);
                }
                words[j].push_back(balance);
            }
        }

        int ans = 0;
        for (auto &v : words) {
            int balance = 0, tally = 0;
            sort(v.begin(), v.end());
            for (auto i : v) {
                if (balance + i < 0) {
                    balance += i;
                    ++tally;
                }
            }
            ans = max(ans, tally);
        }

        cout << ans << "\n";
    }
}