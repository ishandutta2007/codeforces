#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        int ans = INT_MAX;
        for (long long i = 0; i < 60; ++i) {
            string m = to_string(1LL << i);
            int j = 0;
            for (auto c : n) {
                j += j < (int) m.size() && c == m[j];
            }
            ans = min(ans, (int) m.size() + (int) n.size() - 2 * j);
        }

        cout << ans << "\n";
    }
}