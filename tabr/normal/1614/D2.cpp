#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const int m = 20000010;
int a[m];
int b[m];
int pref[m + 1];
bool is_prime[m + 1];
long long dp[m];
vector<int> d[m];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < m; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i < m; i++) {
        if (!is_prime[i]) {
            continue;
        }
        if (1LL * i * i >= m) {
            continue;
        }
        for (int j = i * i; j < m; j += i) {
            if (is_prime[j]) {
                is_prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + b[i];
    }
    for (int i = m - 1; i > 0; i--) {
        if (b[i] == 0) {
            continue;
        }
        dp[i] = 1LL * b[i] * i;
    }
    for (int i = 2; i < m; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = (m - 1) / i; j >= 1; j--) {
            b[j] += b[i * j];
        }
    }
    for (int i = 2; i < m; i++) {
        if (!is_prime[i]) {
            continue;
        }
        d[i].emplace_back(1);
        for (int j = i * 2; j < m; j += i) {
            if (b[j]) {
                d[j].emplace_back(j / i);
            }
        }
    }
    for (int i = m - 1; i > 0; i--) {
        if (!d[i].empty()) {
            debug(i, d[i]);
        }
        for (int j : d[i]) {
            dp[j] = max(dp[j], dp[i] + 1LL * j * (b[j] - b[i]));
        }
    }
    cout << dp[1] << '\n';
    return 0;
}