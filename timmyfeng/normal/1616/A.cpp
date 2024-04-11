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

        map<int, int> frequency;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++frequency[abs(a)];
        }

        int ans = 0;
        for (auto [a, b] : frequency) {
            if (a == 0) {
                ans += min(1, b);
            } else {
                ans += min(2, b);
            }
        }

        cout << ans << "\n";
    }
}