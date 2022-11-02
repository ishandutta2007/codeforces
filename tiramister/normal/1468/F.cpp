#line 1 "main.cpp"
#include <iostream>
#include <numeric>
#include <vector>
#include <map>

using namespace std;
using lint = long long;

void solve() {
    int n;
    cin >> n;

    map<pair<int, int>, lint> cnt;
    while (n--) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        auto dx = gx - sx, dy = gy - sy;

        auto g = gcd(abs(dx), abs(dy));
        dx /= g, dy /= g;

        pair<int, int> p{dx, dy};
        if (!cnt.count(p)) cnt[p] = 0;
        ++cnt[p];
    }

    lint ans = 0;
    for (auto [p, c] : cnt) {
        auto [dx, dy] = p;
        pair<int, int> q{-dx, -dy};
        if (cnt.count(q)) ans += c * cnt[q];
    }

    cout << ans / 2 << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}