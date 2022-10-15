#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int m, n; cin >> m >> n;

    vector a(m, 0);
    for (auto& x : a) cin >> x;

    vector b(n, 0);
    for (auto& x : b) cin >> x;

    vector E(n + m, vector(0, pair(0, 0)));

    ll ans = 0;

    for (int j = 0; j < m; ++j)
    {
        int s; cin >> s;
        while (s--)
        {
            int x; cin >> x; --x;
            E[x].push_back(pair(n + j, a[j] + b[x]));
            E[n + j].push_back(pair(x, a[j] + b[x]));
            ans += a[j] + b[x];
        }
    }

    struct Data
    {
        int key, v;
        bool operator<(const Data& rhs) const { return key < rhs.key; }
    };

    priority_queue<Data> pq;

    vector vis(n + m, 0);
    auto prim = [&](int u)
    {
        pq.push(Data{0, u});
        while (not pq.empty())
        {
            auto [cost, v] = pq.top(); pq.pop();
            if (vis[v]++) continue;
            ans -= cost;
            for (auto [u, w] : E[v])
                if (not vis[u]) pq.push(Data{w, u});
        }
    };

    for (int u = 0; u < n + m; ++u)
        if (not vis[u]) prim(u);

    cout << ans << endl;

    exit(0);
}