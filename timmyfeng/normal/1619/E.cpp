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

        vector<int> tally(n + 1);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            tally[a]++;
        }

        long long cost = 0;
        priority_queue<int> redundant;
        for (int i = 0; i <= n; ++i) {
            if (cost == -1) {
                cout << -1 << " ";
                continue;
            }

            cout << cost + tally[i] << " ";

            if (tally[i] == 0) {
                if (redundant.empty()) {
                    cost = -1;
                } else {
                    cost += i - redundant.top();
                    redundant.pop();
                }
            } else {
                for (int j = 0; j < tally[i] - 1; ++j) {
                    redundant.push(i);
                }
            }
        }

        cout << "\n";
    }
}