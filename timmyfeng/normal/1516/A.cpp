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

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        for (int i = 0; i < n - 1; ++i) {
            int d = min(k, a[i]);
            a[n - 1] += d;
            a[i] -= d;
            k -= d;
        }

        for (auto i : a) {
            cout << i << " ";
        }
        cout << "\n";
    }
}