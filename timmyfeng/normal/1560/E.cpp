#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        string order;
        for (int i = n - 1; i >= 0; --i) {
            if (count(order.begin(), order.end(), s[i]) == 0) {
                order = s[i] + order;
            }
        }

        int m = order.size(), k = 0;
        for (int i = 0; i < m; ++i) {
            k += count(s.begin(), s.end(), order[i]) / (i + 1);
        }

        string t = s.substr(0, k), expected;
        for (int i = 0; i < m; ++i) {
            string t_new;
            expected += t;
            for (auto c : t) {
                if (c != order[i]) {
                    t_new += c;
                }
            }
            t = t_new;
        }

        if (expected == s) {
            cout << s.substr(0, k) << " " << order << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}