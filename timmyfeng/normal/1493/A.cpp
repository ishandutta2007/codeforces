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

        vector<int> ans;

        for (int i = (k + 1) / 2; i < k; ++i) {
            ans.push_back(i);
        }

        for (int i = k + 1; i <= n; ++i) {
            ans.push_back(i);
        }

        cout << ans.size() << "\n";
        for (auto &i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}