#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n / 2; ++i) {
            cout << a[i + 1] << " " << a[0] << "\n";
        }
    }
}