#include <bits/stdc++.h>
using namespace std;

int tally[2][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        memset(tally, 0, sizeof tally);
        for (int i = 0; i < n; ++i) {
            tally[a[i] - '0'][b[i] - '0']++;
        }

        int ans = INT_MAX;

        if (tally[0][1] == tally[1][0]) {
            ans = min(ans, 2 * tally[0][1]);
        }

        if (tally[1][1] - tally[0][0] == 1) {
            ans = min(ans, tally[0][0] + tally[1][1]);
        }

        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
}