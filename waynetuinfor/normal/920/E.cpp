#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
set<int> G[maxn];
bool vis[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    // cout << "fuck RE" << endl;
    set<int> cand;
    for (int i = 1; i <= n; ++i) cand.insert(i);
    vector<int> c;
    while (cand.size()) {
        int v = 0;
        queue<int> q; q.push(*cand.begin()); cand.erase(*cand.begin());
        while (q.size()) {
            int now = q.front(); q.pop();
            // cout << "now = " << now << endl;
            ++v;
            // if (cand.size() == 0) continue;
            auto it = cand.begin();
            while (cand.size() && it != cand.end()) {
                if (G[now].find(*it) == G[now].end()) {
                    q.push(*it);
                    it = cand.erase(it);
                    continue;
                }
                ++it;
            }
        }
        c.push_back(v);
    }
    sort(c.begin(), c.end());
    cout << c.size() << endl;
    for (int u : c) cout << u << ' '; cout << endl;
    return 0;
}