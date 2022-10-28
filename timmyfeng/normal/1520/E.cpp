#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int prefix = 0;
        vector<int> where;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                where.push_back(i - prefix);
                ++prefix;
            }
        }

        int m = where.size();
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += abs(where[m / 2] - where[i]);
        }

        cout << ans << "\n";
    }
}