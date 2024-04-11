#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (auto &i : a) cin >> i;

        vector subarray_mex(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            set<long long> numbers;
            long long mex = 0;
            for (int j = i; j < n; ++j) {
                numbers.insert(a[j]);
                while (numbers.contains(mex)) ++mex;
                subarray_mex[i][j] = mex;
            }
        }

        long long ans = 0;
        vector max_cost(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                max_cost[i][j] = 1 + subarray_mex[i][j];
                for (int k = i; k < j; ++k) {
                    max_cost[i][j] = max(max_cost[i][j], 1 + subarray_mex[k + 1][j] + max_cost[i][k]);
                }
                ans += max_cost[i][j];
            }
        }

        cout << ans << "\n";
    }
}