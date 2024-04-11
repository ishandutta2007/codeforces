#line 1 "main.cpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> xs(n), bs(n);
    for (auto& x : xs) cin >> x;
    for (auto& b : bs) cin >> b;

    vector<int> ys;
    for (int i = 0; i < n; ++i) {
        if (!bs[i]) ys.push_back(xs[i]);
    }
    sort(ys.begin(), ys.end());
    for (int i = 0; i < n; ++i) {
        if (!bs[i]) {
            xs[i] = ys.back();
            ys.pop_back();
        }
    }

    for (auto x : xs) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}