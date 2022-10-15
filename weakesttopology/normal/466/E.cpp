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
    int n, q; cin >> n >> q;

    vector<vector<pair<int, int>>> E(n), queries(n);
    vector<vector<int>> packets(n);

    vector<int> sendtime, root(n, 1);

    for (int z = 0; z < q; ++z)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int x, y; cin >> x >> y; --x, --y;
            E[y].emplace_back(x, z);
            root[x] = 0;
        }
        else if (type == 2)
        {
            int x; cin >> x; --x;
            packets[x].push_back(z);
            sendtime.push_back(z);
        }
        else
        {
            int x, i; cin >> x >> i; --x, --i;
            queries[x].emplace_back(z, sendtime[i]);
        }
    }

    vector<pair<int, int>> ans;

    function<set<int>(int)> dfs = [&](int u)
    {
        set<int> R(all(packets[u]));

        for (auto [v, t] : E[u])
        {
            set<int> S = dfs(v);

            auto iter = S.lower_bound(t);
            S.erase(begin(S), iter);

            if (size(S) > size(R)) swap(S, R);

            R.insert(all(S));
        }

        for (auto [z, t] : queries[u]) ans.emplace_back(z, R.count(t));

        return R;
    };

    for (int u = 0; u < n; ++u) if (root[u]) dfs(u);

    sort(all(ans));

    for (auto [z, x] : ans)
    {
        cout << (x ? "YES" : "NO") << endl;
    }

    exit(0);
}