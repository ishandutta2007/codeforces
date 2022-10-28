#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<long long> inv(m + 1);
    inv[1] = 1;
    for (int i = 2; i <= m; ++i) {
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }

    long long ans = 1;
    for (int i = 1; i <= m; ++i) {
        ans = ans * i % MOD;
    }
    for (int i = 1; i <= n - 1; ++i) {
        ans = ans * inv[i] % MOD;
    }
    for (int i = 1; i <= m - n + 1; ++i) {
        ans = ans * inv[i] % MOD;
    }
    for (int i = 0; i < n - 2; ++i) {
        ans = ans * 2 % MOD;
    }
    ans = ans * (n - 2) % MOD * inv[2] % MOD;
    cout << ans << '\n';
}