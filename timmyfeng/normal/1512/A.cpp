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

        vector<int> b = a;
        sort(a.begin(), a.end());

        cout << find(b.begin(), b.end(), a[0] != a[1] ? a[0] : a[n - 1]) - b.begin() + 1 << "\n";
    }
}