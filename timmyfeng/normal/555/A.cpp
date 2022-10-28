#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int ans = 2 * n - k - 1;
    vector<vector<int>> a(k);
    for (auto &i : a) {
        int m;
        cin >> m;

        i.resize(m);

        for (auto &j : i) {
            cin >> j;
        }
    }

    sort(a.begin(), a.end());

    for (int i = 1; i < (int) a[0].size(); ++i) {
        if (a[0][i] == i + 1) {
           ans -= 2;
        }
    }

    cout << ans << "\n";
}