#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}


const ll MAX_V = 5000;
ll fact[MAX_V + 1], invfact[MAX_V + 1];

void precalc() {
    invfact[0] = fact[0] = 1;
    for (ll i = 1; i <= MAX_V; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX_V] = mypow(fact[MAX_V], MOD - 2);
    for (ll i = MAX_V - 1; i >= 0; --i) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}

ll comb(ll a, ll b) {
    if (a < b) return 0;
    if (a == 0) return 1;  // a = b = 0

    return fact[a] * invfact[a - b] % MOD * invfact[b] % MOD;
}


int main() {
    precalc();

    ll N, M, K;
    cin >> N >> M >> K;

    cout << comb(N - 1, K) * M % MOD * mypow(M - 1, K) % MOD << endl;
    return 0;
}