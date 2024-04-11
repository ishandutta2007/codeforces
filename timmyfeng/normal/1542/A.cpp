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

        int balance = 0;
        for (int i = 0; i < 2 * n; ++i) {
            int a;
            cin >> a;
            balance += (a % 2 == 0 ? 1 : -1);
        }

        cout << (balance == 0 ? "Yes" : "No") << "\n";
    }
}