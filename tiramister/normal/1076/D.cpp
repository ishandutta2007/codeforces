#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    map<pair<int, int>, int> id;
    vector<pair<int, ll>> path[N];

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;

        path[u].push_back(make_pair(v, w));
        path[v].push_back(make_pair(u, w));
        id[make_pair(u, v)] = i + 1;
        id[make_pair(v, u)] = i + 1;
    }

    // Dijkstra0
    vector<int> remain;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    que.push(make_tuple(0, 0, -1));

    ll d[N];
    fill(d, d + N, INF);
    while (!que.empty()) {
        int v, par;
        ll c;
        tie(c, v, par) = que.top();
        que.pop();

        if (c >= d[v]) continue;
        if (v != 0) remain.push_back(id[make_pair(v, par)]);
        d[v] = c;

        for (auto p : path[v]) {
            int sv;
            ll w;
            tie(sv, w) = p;
            que.push(make_tuple(d[v] + w, sv, v));
        }
    }

    // 0K
    cout << min(N - 1, K) << endl;
    for (int i = 0; i < min(N - 1, K); ++i) {
        cout << remain[i] << " ";
    }
    cout << endl;
    return 0;
}