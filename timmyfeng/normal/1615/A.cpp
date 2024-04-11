#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            sum += a;
        }

        cout << (sum % n > 0) << "\n";
    }
}