#line 1 "main.cpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    vector<int> xs(4);
    for (auto& x : xs) cin >> x;
    sort(xs.begin(), xs.end());

    int ans = 0;
    do {
        ans = max(ans, min(xs[0], xs[1]) * min(xs[2], xs[3]));
    } while (next_permutation(xs.begin(), xs.end()));
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}