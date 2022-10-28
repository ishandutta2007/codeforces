#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long p;
        cin >> p;

        long long ans = LLONG_MAX;
        for (int i = 0; i < 3; ++i) {
            long long a;
            cin >> a;

            long long res = a - p % a;
            if (res == a) {
                res = 0;
            }

            ans = min(ans, res);
        }

        cout << ans << "\n";
    }
}