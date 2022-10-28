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

        sort(a.begin(), a.end());

        bool answer = false;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[j] < a[i] + k) {
                ++j;
            }
            if (j < n && a[j] == a[i] + k) answer = true;
        }

        cout << (answer ? "YES" : "NO") << "\n";
    }
}