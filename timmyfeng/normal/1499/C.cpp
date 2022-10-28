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

        vector<long long> cost(n);
        for (auto &i : cost) {
            cin >> i;
        }

        long long ans = LLONG_MAX, sum = cost[0];
        array<long long, 2> mini = {cost[0], LLONG_MAX};

        for (int i = 1; i < n; ++i) {
            mini[i % 2] = min(mini[i % 2], cost[i]);
            sum += cost[i];

            ans = min(ans, sum + (n - (i - 1) / 2 - 1) * mini[1] + (n - i / 2 - 1) * mini[0]);
        }

        cout << ans << "\n";
    }
}