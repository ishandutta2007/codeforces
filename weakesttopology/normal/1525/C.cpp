#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (auto& x : x) cin >> x;

    string s(n, '*');
    for (auto& ch : s) cin >> ch;

    vector<int> I(n);
    iota(all(I), 0), sort(all(I), [&](int i, int j){ return x[i] < x[j]; });

    priority_queue<array<int, 2>> pq[2];

    vector<int> ans(n, -1);
    for (auto i : I) {
        int b = x[i] % 2;
        if (s[i] == 'L') {
            if (not empty(pq[b])) {
                auto [y, j] = pq[b].top();
                pq[b].pop();
                ans[i] = ans[j] = (x[i] - y) / 2;
            }
            else {
                pq[b].push({-x[i], i});
            }
        }
        else if (s[i] == 'R') {
            pq[b].push({x[i], i});
        }
    }

    for (auto b : {0, 1}) {
        while (size(pq[b]) > 1) {
            auto [x, i] = pq[b].top();
            pq[b].pop();
            auto [y, j] = pq[b].top();
            pq[b].pop();
            ans[i] = ans[j] = (m - x) + (x - y) / 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n "[i + 1 < n];
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