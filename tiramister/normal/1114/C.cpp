#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 62;

int main() {
    ll N, B;
    cin >> N >> B;

    ll ans = INF;
    for (ll p = 2; p * p <= B; ++p) {
        if (B % p > 0) continue;
        ll e = 0;
        while (B % p == 0) {
            B /= p;
            ++e;
        }

        ll cnt = 0, M = N;
        while (M > 0) {
            cnt += M / p;
            M /= p;
        }
        ans = min(ans, cnt / e);
    }

    if (B > 1) {
        ll cnt = 0, M = N;
        while (M > 0) {
            cnt += M / B;
            M /= B;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}