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
    const int MAX = 1000010;
    vector<int> primes;
    vector<int> spf(MAX);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (is_prime[b]) {
                a[i] = 2;
            } else if (b == 1) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }
        vector<vector<int>> c(e);
        for (int i = 0; i < n; i++) {
            c[i % e].emplace_back(a[i]);
        }
        vector<int> b;
        for (auto v : c) {
            for (int i : v) {
                b.emplace_back(i);
            }
            b.emplace_back(0);
        }
        int m = (int) b.size();
        int beg = 0;
        long long ans = 0;
        debug(b);
        while (beg < m) {
            if (b[beg] == 0) {
                beg++;
                continue;
            }
            int end = beg;
            while (end < m && b[end] != 0) {
                end++;
            }
            vector<int> d;
            for (int i = beg, j = 1; i < end; i++) {
                if (b[i] == 2) {
                    d.emplace_back(j);
                    j = 1;
                } else {
                    j++;
                }
                if (i + 1 == end) {
                    d.emplace_back(j);
                }
            }
            for (int i = 0; i < (int) d.size() - 1; i++) {
                ans += 1LL * d[i] * d[i + 1] - 1;
            }
            beg = end;
        }
        cout << ans << '\n';
    }
    return 0;
}