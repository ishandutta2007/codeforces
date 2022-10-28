#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> entries;
        map<int, int> tally;

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            if (++tally[a] <= k) {
                entries.push_back({a, i});
            }
        }

        sort(entries.begin(), entries.end());

        vector<int> ans(n);

        while (entries.size() % k != 0) {
            entries.pop_back();
        }

        for (int i = 0; i < (int) entries.size(); ++i) {
            ans[entries[i].second] = i % k + 1;
        }

        for (auto &i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}