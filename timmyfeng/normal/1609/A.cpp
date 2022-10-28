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

        long long sum = 0, max_a = 0, coeff = 1;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;

            while (a % 2 == 0) {
                coeff *= 2;
                a /= 2;
            }

            max_a = max(max_a, a);
            sum += a;
        }

        cout << sum + max_a * (coeff - 1) << "\n";
    }
}