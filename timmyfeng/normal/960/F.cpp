#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

map<int, int> paths[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        int x = 1;
        auto it = paths[u].lower_bound(w);
        if (it != paths[u].begin()) {
            x += (--it)->second;
        }

        it = paths[v].upper_bound(w);
        if (it != paths[v].begin() && (--it)->second >= x) {
            continue;
        }

        paths[v][w] = x;

        it = paths[v].find(w);
        while (true) {
            auto nxt = it;
            if (++nxt == paths[v].end() || nxt->second > x) {
                break;
            }
            paths[v].erase(nxt);
        }

        ans = max(ans, x);
    }

    cout << ans << "\n";
}