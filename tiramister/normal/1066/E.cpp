#include <iostream>
#include <algorithm>
#include <string>

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
    int N, M;
    string A, B;
    cin >> N >> M >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    ll bcnt[max(N, M) + 1];
    bcnt[0] = 0;
    for (int i = 0; i < M; ++i) {
        bcnt[i + 1] = bcnt[i] + B[i] - '0';
    }
    for (int i = M; i < max(N, M); ++i) {
        bcnt[i + 1] = bcnt[i];
    }

    ll ans = 0;
    for (int k = 0; k < N; ++k) {
        if (A[k] == '0') continue;
        ans += mypow(2LL, k) * (bcnt[M] - bcnt[k]);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}