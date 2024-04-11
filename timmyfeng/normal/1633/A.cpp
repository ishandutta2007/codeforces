#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        int n_new = n - n % 7;
        if (n_new / 10 != n / 10) {
            n_new += 7;
        }

        cout << n_new << "\n";
    }
}