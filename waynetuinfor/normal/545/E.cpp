#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
const long long inf = 1e18 + 1;
vector<pair<pair<int, int>, int>> G[maxn];
long long d[maxn];
int w[maxn];
bool used[maxn], v[maxn];

typedef pair<pair<long long, int>, pair<int, int>> heap;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back(make_pair(make_pair(b, c), i));
        G[b].push_back(make_pair(make_pair(a, c), i));
        w[i] = c;
    }
    int u; cin >> u;
    fill(d, d + maxn, inf);
    priority_queue<heap, vector<heap>, greater<heap>> pq;
    d[u] = 0;
    pq.push(make_pair(make_pair(0, inf), make_pair(u, -1)));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second.first]) continue;
        v[p.second.first] = true;
        if (p.second.second != -1) used[p.second.second] = true;
        for (auto e : G[p.second.first]) {
            if (d[e.first.first] >= p.first.first + e.first.second) {
                d[e.first.first] = p.first.first + e.first.second;
                pq.push(make_pair(make_pair(d[e.first.first], e.first.second), make_pair(e.first.first, e.second)));
            }
        }
    }
    int edge = 0;
    long long ans = 0;
    for (int i = 0; i < m; ++i) if (used[i]) ++edge, ans += w[i];
    vector<int> un;
    for (int i = 0; i < m; ++i) {
        if (used[i]) continue;
        else un.push_back(i);
    }
    edge = n - 1 - edge;
    sort(un.begin(), un.end(), [](const int& a, const int& b) { return w[a] < w[b]; });
    for (int i = 0; i < edge; ++i) ans += w[un[i]];
    cout << ans << endl;
    for (int i = 0; i < m; ++i) if (used[i]) cout << i + 1 << ' ';
    for (int i = 0; i < edge; ++i) cout << un[i] + 1 << ' '; cout << endl;
    return 0;
}