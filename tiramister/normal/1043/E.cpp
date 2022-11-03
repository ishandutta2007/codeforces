#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

ll INF = 1LL << 50;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    ll x[N + 1], y[N + 1];
    x[0] = -INF, y[0] = INF;
    for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i];

    int ord[N + 1];
    iota(ord, ord + N + 1, 0);
    sort(ord, ord + N + 1, [&](int i, int j) { return x[i] - y[i] < x[j] - y[j]; });

    ll xsum[N + 1], ysum[N + 1];
    xsum[0] = ysum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        xsum[i] = xsum[i - 1] + x[ord[i]];
        ysum[i] = ysum[i - 1] + y[ord[i]];
    }

    ll ans[N + 1];
    fill(ans, ans + N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int id = ord[i];
        ans[id] += xsum[i - 1] + y[id] * (i - 1);
        ans[id] += ysum[N] - ysum[i] + x[id] * (N - i);
    }

    for (int j = 0; j < M; ++j) {
        int u, v;
        cin >> u >> v;
        ll cost = min(x[u] + y[v], x[v] + y[u]);
        ans[u] -= cost;
        ans[v] -= cost;
    }

    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}