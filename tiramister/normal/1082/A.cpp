#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;

        ll ans = INF;
        if (abs(y - x) % d == 0) {
            ans = min(ans, abs(y - x) / d);
        }

        if ((y - 1) % d == 0) {
            ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
        }

        if ((n - y) % d == 0) {
            ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
        }

        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}