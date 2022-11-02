#line 1 "main.cpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using ldouble = long double;

ldouble input() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<ldouble> xs, ys;
    for (int i = 0; i < n * 2; ++i) {
        auto x = input();
        if (x == 0) {
            ys.push_back(abs(input()));
        } else {
            xs.push_back(abs(x));
            input();
        }
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    ldouble ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += hypot(xs[i], ys[i]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}