#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector a(n, vector<int>(m));
        for (auto &i : a)
            for (auto &j : i)
                cin >> j;
        
        for (int z = 0; z < n; ++z) {
            vector<pair<int, long long>> answer;
            for (int i = 0; i < n; ++i) {
                long long delta = 0, prefix = 0;
                for (int j = 0; j < m; ++j) {
                    prefix += a[i][j] - a[z][j];
                    delta -= prefix;
                }
                if (delta) answer.push_back({i, delta});
            }

            if (answer.size() == 1) {
                cout << answer[0].first + 1 << " " << answer[0].second << "\n";
                break;
            }
        }
    }
}