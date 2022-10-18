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
    vector<int> spf(MAX);  // smallest prime factor
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
    vector<int> a(1001);
    for (int i = 3; i <= 1000; i++) {
        for (int j = 0; j <= i / 2; j++) {
            if (is_prime[i + j]) {
                a[i] = i + j;
                break;
            }
        }
        assert(is_prime[a[i]]);
    }
    int n;
    cin >> n;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        x.emplace_back(i);
        y.emplace_back((i + 1) % n);
    }
    for (int i = 0; i < a[n] - n; i++) {
        x.emplace_back(i);
        y.emplace_back(i + n / 2);
    }
    cout << a[n] << '\n';
    for (int i = 0; i < a[n]; i++) {
        cout << x[i] + 1 << " " << y[i] + 1 << '\n';
    }
    return 0;
}