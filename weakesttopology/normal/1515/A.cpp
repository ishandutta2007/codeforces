#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for (auto& y : w) cin >> y;

    if (accumulate(all(w), 0) == x) {
        cout << "NO" << endl;
        return;
    }

    sort(all(w));

    int sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        sum += w[i];
        if (sum == x) swap(w[i], w[i + 1]);
    }
    cout << "YES" << endl;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cout << w[i] << "\n "[i + 1 < n];
        sum += w[i];
        assert(sum != x);
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