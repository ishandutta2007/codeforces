#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        priority_queue<array<int, 2>> mini;
        for (int i = 1; i <= m; ++i) {
            mini.push({0, i});
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            auto [s, j] = mini.top();
            mini.pop();

            cout << j << " ";
            mini.push({s - a, j});
        }
        cout << "\n";
    }
}