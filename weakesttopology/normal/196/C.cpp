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

const double PI = acos(-1);
const double EPS = 1e-9;

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector pt(n, pair(0, 0));

    for (auto& [x, y] : pt) cin >> x >> y;

    vector angle(n, vector(n, 0.0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (i != j)
            angle[i][j] = atan2(pt[j].second - pt[i].second, pt[j].first - pt[i].first);

    vector associated(n, -1), subtree(n, 0);

    function<void(int)> compute = [&](int u)
    {
        subtree[u] = 1;
        for (auto v : E[u]) if (subtree[v] == 0)
        {
            compute(v);
            subtree[u] += subtree[v];
        }
    };
    compute(0);

    function<void(int, vector<int>)> paint = [&](int u, vector<int> idx)
    {
        for (auto& i : idx) if (pt[i] < pt[idx.back()]) swap(i, idx.back());

        int k = idx.back(); idx.pop_back();

        associated[k] = u;

        auto cmpang = [&](int i, int j) { return angle[k][i] < angle[k][j]; };

        sort(all(idx), cmpang);

        auto iter = begin(idx);

        for (auto v : E[u]) if (subtree[v] < subtree[u])
        {
            auto nxt = iter + subtree[v];
            paint(v, vector<int>(iter, nxt));
            iter = nxt;
        }
    };

    vector idx(n, 0); iota(all(idx), 0);

    paint(0, idx);

    for (auto i : associated) cout << i + 1 << " ";
    cout << endl;

    exit(0);
}