#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
inline T sq(T a) { return a * a; }

int main() {
    ll N, M;
    cin >> N >> M;

    ll sum[M + 1][M + 1];
    fill(sum[0], sum[1], 0);
    for (ll i = 1; i <= M; ++i) {
        sum[i][0] = 0;
        for (ll j = 1; j <= M; ++j) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + ((sq(i) + sq(j)) % M == 0);
        }
    }

    ll ans = sum[M][M] * sq(N / M);
    ans += sum[M][N % M] * (N / M) * 2;
    ans += sum[N % M][N % M];
    cout << ans << endl;
    return 0;
}