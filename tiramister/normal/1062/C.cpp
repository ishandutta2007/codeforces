#include <iostream>

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    int sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        sum[i] = sum[i - 1] + (c == '1');
    }

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        int one = sum[r] - sum[l - 1];
        int zero = (r - l + 1) - one;

        cout << (mypow(2LL, one) + MOD - 1) % MOD * mypow(2LL, zero) % MOD << "\n";
    }
    return 0;
}