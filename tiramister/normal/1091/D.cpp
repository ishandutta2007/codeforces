#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll MAX_V = 1000010;

ll fact[MAX_V + 1];

void precalc() {
    fact[0] = 1;
    for (ll i = 1; i <= MAX_V; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}

int main() {
    precalc();

    ll N;
    cin >> N;

    ll ans = fact[N];
    ll p = 1;
    for (ll i = N; i >= 1; --i) {
        p = (p * i) % MOD;
        ans += p * (fact[i - 1] - 1) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}