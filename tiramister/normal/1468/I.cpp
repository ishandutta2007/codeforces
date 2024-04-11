#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>

using namespace std;
using lint = long long;

void fail() {
    cout << "NO\n";
    exit(0);
}

void solve() {
    lint n;
    cin >> n;

    vector<lint> dxs(2), dys(2);
    for (int i = 0; i < 2; ++i) {
        cin >> dxs[i] >> dys[i];
        if (dxs[i] < 0) {
            dxs[i] = -dxs[i];
            dys[i] = -dys[i];
        }
    }

    if (dxs[0] * dys[1] == dxs[1] * dys[0]) fail();

    auto w = gcd(dxs[0], dxs[1]);
    auto a = dxs[1] / w, b = -dxs[0] / w;
    lint h = abs(a * dys[0] + b * dys[1]);

    assert(h != 0);
    if (h > n || h * w != n) fail();

    cout << "YES\n";
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            cout << x << " " << y << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}