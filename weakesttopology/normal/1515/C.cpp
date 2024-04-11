#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    priority_queue<pair<int, int>> pq;
    for (int j = 0; j < m; ++j) pq.emplace(0, j);

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        auto [y, j] = pq.top();
        pq.pop();
        pq.emplace(y - h, j);
        t[i] = j;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << t[i] + 1 << "\n "[i + 1 < n];
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