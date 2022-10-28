#include <bits/stdc++.h>
using namespace std;

const int A = 20000000 + 1;

int sieve[A];

int solve(int c, int d, int x) {
    if ((x + d) % c == 0) {
        int q = (x + d) / c;
        int ways = 1;
        while (q > 1) {
            int p = sieve[q];
            while (q % p == 0) {
                q /= p;
            }
            ways *= 2;
        }
        return ways;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < A; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < A; j += i) {
                sieve[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int c, d, x;
        cin >> c >> d >> x;

        int ans = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                ans += solve(c, d, x / i);
                if (i * i < x) {
                    ans += solve(c, d, i);
                }
            }
        }

        cout << ans << "\n";
    }
}