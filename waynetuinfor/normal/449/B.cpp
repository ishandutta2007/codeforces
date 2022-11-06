#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;

struct Edge {
    int to, w;
};

vector<Edge> G[maxn];
long long d[maxn];
int deg[maxn];
bool v[maxn], used[maxn << 2];

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<pair<pair<int, int>, int>> edge;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back((Edge){ b, c }); G[b].push_back((Edge){ a, c });
        edge.push_back(make_pair(make_pair(a, b), c));
    }
    vector<pair<int, int>> t;
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        G[1].push_back((Edge){ x, y }); G[x].push_back((Edge){ 1, y });
        edge.push_back(make_pair(make_pair(1, x), y));
        t.push_back(make_pair(x, y));
    }
    fill(d, d + maxn, inf);
    d[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 1));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (auto e : G[p.second]) {
            if (d[e.to] > p.first + e.w) {
                d[e.to] = p.first + e.w;
                pq.push(make_pair(d[e.to], e.to));
            }
        } 
    }
    int ans = 0;
    for (int i = 0; i < edge.size(); ++i) {
        auto e = edge[i];
        if (d[e.first.first] < d[e.first.second]) if (d[e.first.first] + e.second == d[e.first.second]) ++deg[e.first.second], used[i] = true;
        if (d[e.first.second] < d[e.first.first]) if (d[e.first.second] + e.second == d[e.first.first]) ++deg[e.first.first], used[i] = true;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (used[i + m] && deg[t[i].first] > 1) --deg[t[i].first], ++ans;
        else if (!used[i + m]) ++ans;
    }
    cout << ans << endl;
    return 0;
}