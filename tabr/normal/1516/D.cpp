#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int MAX = 100010;
    vector<int> primes;
    vector<int> spf(MAX);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
            spf[i] = i;
            if (1LL * i * i >= MAX) {
                continue;
            }
            for (int j = i * i; j < MAX; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> to(n + 1, vector<int>(20, n));
    vector<int> x(MAX, n);
    for (int i = n - 1; i >= 0; i--) {
        to[i][0] = to[i + 1][0];
        while (a[i] != 1) {
            int p = spf[a[i]];
            to[i][0] = min(to[i][0], x[p]);
            x[p] = i;
            while (a[i] % p == 0) {
                a[i] /= p;
            }
        }
    }
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < n; i++) {
            to[i][j + 1] = to[to[i][j]][j];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 1;
        for (int i = 19; i >= 0; i--) {
            if (to[l][i] <= r) {
                ans += 1 << i;
                l = to[l][i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}