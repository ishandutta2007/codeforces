#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        int answer = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                ++answer, ++i;
            }
        }

        cout << answer << "\n";
    }
}