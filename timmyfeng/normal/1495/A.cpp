#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(11);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> miner, mine;
        for (int i = 0; i < 2 * n; ++i) {
            long long x, y;
            cin >> x >> y;

            if (x == 0) {
                miner.push_back(abs(y));
            } else {
                mine.push_back(abs(x));
            }
        }

        sort(miner.begin(), miner.end());
        sort(mine.begin(), mine.end());

        double ans = 0.0;
        for (int i = 0; i < n; ++i) {
            ans += sqrt(miner[i] * miner[i] + mine[i] * mine[i]);
        }

        cout << ans << "\n";
    }
}