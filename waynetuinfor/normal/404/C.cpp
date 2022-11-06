#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int d[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dis[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; ++i) pq.push(make_pair(d[i], i));
    vector<pair<int, int>> ans;
    bool st = false;
    while (pq.size()) {
        pair<int, int> vtx = pq.top(); pq.pop();
        if (vtx.first == 0) {
            if (st) return cout << "-1" << endl, 0;
            dis[0].push(make_pair(0, vtx.second));
            st = true;
            continue;
        }
        if (!dis[vtx.first - 1].size()) return cout << "-1" << endl, 0;
        if (dis[vtx.first - 1].top().first >= k) return cout << "-1" << endl, 0;
        pair<int, int> adj = dis[vtx.first - 1].top(); dis[vtx.first - 1].pop();
        ans.push_back(make_pair(adj.second, vtx.second));
        dis[vtx.first - 1].push(make_pair(adj.first + 1, adj.second));
        dis[vtx.first].push(make_pair(1, vtx.second));
    }
    cout << ans.size() << endl;
    for (auto e : ans) cout << e.first << ' ' << e.second << endl;
    return 0;
}