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

        cout << [&]() -> string {
            int sum = accumulate(a.begin(), a.end(), 0);
            for (auto i : a) {
                if (i * n == sum) return "YES\n";
            }

            return "NO\n";
        }();
    }
}