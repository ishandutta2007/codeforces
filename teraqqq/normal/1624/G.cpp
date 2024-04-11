#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b, w;
};

const int N = 2e5+7;

int used[N], utmr;
vector<int> g[N];

int get_size(int v) {
    if (used[v] == utmr) return 0;

    int cnt = 1;
    used[v] = utmr;

    for (int to : g[v]) {
        cnt += get_size(to);
    }

    return cnt;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [a, b, w] : edges) {
        cin >> a >> b >> w; --a, --b;
    }

    int forbiden_bits = 0, ans = 0;
    for (int bit = 30; bit--; ) {
        forbiden_bits ^= 1 << bit;

        // cout << forbiden_bits << "!" << endl;

        for (auto [a, b, w] : edges) {
            if ((w & forbiden_bits) == 0) {
                g[a].push_back(b);
                g[b].push_back(a);
                // cout << "add edge " << a+1 << " <=> " << b+1 << endl;
            }
        }


        ++utmr;
        if (get_size(0) != n) {
            // cout << "you can win if you want!" << endl;
            forbiden_bits ^= 1 << bit;
            ans ^= 1 << bit;
        }

        for (int i = 0; i < n; ++i) g[i].clear();
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}