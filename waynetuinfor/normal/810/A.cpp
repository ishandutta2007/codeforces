#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double n, k; cin >> n >> k;
    double s = 0.0, x;
    for (int i = 0; i < n; ++i) {
        cin >> x; s += x;
    }
    if (round(s / n) == k) return cout << "0\n", 0;
    // double tar = ceil((k - 0.5) * (n + 1));
    int ans = 0;
    ++n;
    while (true) {
        ++ans;
        if (round((s + k) / n) == k) return cout << ans << '\n', 0;
        s += k;
        ++n;
    }
    // return cout << tar - s << '\n', 0;
}