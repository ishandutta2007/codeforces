#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, m; cin >> n >> m;

    vector l(n, 0), r(n, 0), x(m, 0), y(m, 0);

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    for (int j = 0; j < m; ++j) cin >> x[j] >> y[j];

    constexpr int N = 5e5 + 1;
    vector start(N + 1, -1);

    vector I(n, 0); iota(all(I), 0);
    sort(all(I), [&r](int i, int j){ return r[i] > r[j]; });

    for (auto i : I) if (start[l[i]] == -1) start[l[i]] = i;

    auto cmp = [&](int i, int j, int x)
    {
        if (i == -1) return j;
        if (j == -1) return i;
        int k = r[i] >= r[j] ? i : j;
        return r[k] >= x ? k : -1;
    };

    for (int x = 1; x <= N; ++x) start[x] = cmp(start[x], start[x - 1], x);

    vector nxt(n, 0), cost(n, 1);

    for (int i = 0; i < n; ++i)
        if (int v = start[r[i]]; v != -1)
            nxt[i] = r[v] > r[i] ? v : -1;

    function<pair<int, int>(int, int)> get = [&](int i, int x)
    {
        if (r[i] >= x || nxt[i] == -1) return pair(r[i], nxt[i]);

        auto [mx, j] = get(nxt[i], x);

        cost[i] += cost[nxt[i]], nxt[i] = j, r[i] = mx;

        return pair(mx, j);
    };

    vector J(m, 0); iota(all(J), 0);
    sort(all(J), [&y](int i, int j){ return y[i] < y[j]; });

    vector ans(m, -1);

    for (auto j : J)
    {
        int i = start[x[j]];

        if (i != -1)
        {
            auto [z, k] = get(i, y[j]);
            if (z >= y[j]) ans[j] = cost[i];
        }
    }

    for (auto z : ans) cout << z << endl;

    exit(0);
}