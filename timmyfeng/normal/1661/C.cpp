#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> h(n);
        for (auto &i : h) cin >> i;
        ranges::sort(h);

        long long low = 0LL, high = 2LL * n * h[n - 1];
        while (low < high) {
            long long mid = (low + high) / 2LL;

            bool ok = false;
            for (int parity : {0, 1}) {
                vector<int> h_prime = h;
                int odds = 0;
                for (auto &i : h_prime) {
                    if (i % 2 != parity) ++i, ++odds;
                }

                long long diff = 0;
                for (int i = 0; i < n; ++i) {
                    diff += h_prime[n - 1] - h_prime[i];
                }

                ok |= ((mid + 1) / 2 >= odds &&
                    mid / 2 + ((mid + 1) / 2 - odds) / 2 >= diff / 2);
            }

            if (ok) high = mid;
            else low = mid + 1;
        }

        cout << low << "\n";
    }
}