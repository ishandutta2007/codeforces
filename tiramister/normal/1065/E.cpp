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

int main() {
    ll N, A;
    int M;
    cin >> N >> M >> A;

    ll ans = 1;

    ll b[M + 1];
    for (int i = 1; i <= M; ++i) cin >> b[i];
    b[0] = 0;

    for (int i = 0; i < M; ++i) {
        ll L = (b[i + 1] - b[i]) * 2;
        ll pal = mypow(A, L / 2);
        ll notpal = (mypow(A, L) - pal + MOD) % MOD;
        ans *= (notpal * mypow(2LL, MOD - 2) % MOD + pal) % MOD;
        ans %= MOD;
    }

    {
        ll L = N - b[M] * 2;
        ans *= mypow(A, L);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}