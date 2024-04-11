#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<array<int, 3>> op;
    for (int i = 0; i < n / 2; ++i) {
        op.push_back({1, i, n - 1 - i});
        op.push_back({2, i, n - 1 - i});
        op.push_back({1, i, n - 1 - i});
        op.push_back({1, i, n - 1 - i});
        op.push_back({2, i, n - 1 - i});
        op.push_back({1, i, n - 1 - i});
    }

    cout << size(op) << endl;
    for (auto [t, i, j] : op) {
        ++i, ++j;
        cout << t << " " << i << " " << j << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}