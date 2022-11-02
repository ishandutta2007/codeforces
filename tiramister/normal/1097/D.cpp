#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

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

vector<pair<ll, ll>> factor(ll N) {
    vector<pair<ll, ll>> ret;

    ll M = N;
    for (ll i = 2; i * i <= M; ++i) {
        if (N % i > 0) continue;
        ll cnt = 0;
        while (N % i == 0) {
            ++cnt;
            N /= i;
        }

        ret.push_back(make_pair(i, cnt));
    }

    if (N > 1) ret.push_back(make_pair(N, 1));

    return ret;
}

int main() {
    ll inv[100];
    for (ll i = 0; i < 100; ++i) {
        inv[i] = mypow(i, MOD - 2);
    }

    ll N;
    int K;
    cin >> N >> K;

    vector<pair<ll, ll>> facts = factor(N);

    ll ans = 1;
    for (auto q : facts) {
        ll p, a;
        tie(p, a) = q;

        ll dp[K + 1][a + 1];
        fill(dp[0], dp[K + 1], 0);
        dp[0][a] = 1;

        for (ll k = 1; k <= K; ++k) {
            for (ll i = 0; i <= a; ++i) {
                for (ll j = 0; j <= i; ++j) {
                    dp[k][j] += dp[k - 1][i] * inv[i + 1] % MOD;
                    dp[k][j] %= MOD;
                }
            }
        }

        ll part = 0;
        for (ll i = 0; i <= a; ++i) {
            part += dp[K][i] * mypow(p, i);
            part %= MOD;
        }

        ans *= part;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}