#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, m; cin >> n >> m;

    vector x(m, 0), y(m, 0);

    for (int j = 0; j < m; ++j) cin >> x[j] >> y[j];

    auto rows = x; rows.insert(end(rows), { 0, n + 1 });

    auto cols = y; cols.insert(end(cols), { 1, n, n + 1 });
    for (auto z : y) cols.push_back(z + 1);

    sort(all(rows)), rows.erase(unique(all(rows)), end(rows));
    sort(all(cols)), cols.erase(unique(all(cols)), end(cols));

    int k = size(rows), l = size(cols);

    vector rowsweep(k, vector(0, pair(0, 0)));

    rowsweep[0] = { {1, 1}, {2, -1} };
    rowsweep[k - 1] = { {n, 1}, {n + 1, -1} };

    for (int j = 0; j < m; ++j)
    {
        int idx = (int)distance(begin(rows), lower_bound(all(rows), x[j]));
        rowsweep[idx].emplace_back(y[j], -1), rowsweep[idx].emplace_back(y[j] + 1, +1);
    }

    vector net(l, 0), low(l, 0);

    stack<int> stk;

    for (int j = 1; j < k - 1; ++j)
    {
        rowsweep[j].emplace_back(1, +1), rowsweep[j].emplace_back(n + 1, -1);
        sort(all(rowsweep[j]));
    }

    auto merge = [&](auto& prv, auto& nxt, bool spaced)
    {
        if (spaced && not empty(prv))
        {
            int s = prv[0].first;
            prv = { {s, 1}, {n + 1, -1} };
        }

        for (auto& [y, add] : prv)
            y = (int)distance(begin(cols), lower_bound(all(cols), y));

        for (auto& [y, add] : nxt)
        {
            y = (int)distance(begin(cols), lower_bound(all(cols), y));
            if (add < 0) low[y] = 1;
        }

        nxt.insert(end(nxt), all(prv));
        sort(all(nxt));

        static vector<pair<int, int>> aux;

        int sum = 0, active = 0;

        for (auto& [idy, add] : nxt)
        {
            sum += add;

            if (sum == 2 && not active)
            {
                aux.emplace_back(cols[idy], +1);
                active = 1;
            }

            if (sum < 2 && add < 0 && low[idy] && active)
            {
                aux.emplace_back(cols[idy], -1);
                active = 0;
            }

            low[idy] = 0;
        }

        swap(nxt, aux), aux.clear();
    };

    for (int j = 1; j < k; ++j)
        merge(rowsweep[j - 1], rowsweep[j], rows[j - 1] + 1 < rows[j]);

    const auto& bottom = rowsweep.back();

    if (not empty(bottom))
        cout << 2 * (n - 1) << endl;
    else
        cout << -1 << endl;

    exit(0);
}