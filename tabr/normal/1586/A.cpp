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
    const int MAX = 100000;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int s = accumulate(a.begin(), a.end(), 0);
        if (!is_prime[s]) {
            cout << n << '\n';
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        } else {
            cout << n - 1 << '\n';
            int k = -1;
            for (int i = 0; i < n; i++) {
                if (!is_prime[s - a[i]]) {
                    if (k == -1 || a[k] > a[i]) {
                        k = i;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == k) {
                    continue;
                }
                cout << i + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}