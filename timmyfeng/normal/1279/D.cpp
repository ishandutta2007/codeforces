#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    vector<long long> inv(1e6 + 1);
    inv[1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> prob(1e6 + 1), ct(1e6 + 1);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            prob[a] += inv[n] * inv[k] % MOD, prob[a] %= MOD;
            ++ct[a];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= 1e6; ++i) {
        ans += ct[i] * inv[n] % MOD * prob[i] % MOD, ans %= MOD;
    }
    cout << ans << '\n';
}