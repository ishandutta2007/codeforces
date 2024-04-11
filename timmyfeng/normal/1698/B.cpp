#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        if (k == 1) {
            cout << (n - 1) / 2 << "\n";
            continue;
        }

        int answer = 0;
        for (int i = 1; i < n - 1; ++i) {
            answer += (a[i] > a[i - 1] + a[i + 1]);
        }

        cout << answer << "\n";
    }
}