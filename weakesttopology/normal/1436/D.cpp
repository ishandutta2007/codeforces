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
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int u = 1; u < n; ++u)
    {
        int p; cin >> p; --p;
        E[p].push_back(u);
    }

    vector a(n, 0LL);

    for (int u = 0; u < n; ++u) cin >> a[u];

    function<map<ll, ll>(int)> dfs = [&](int u)
    {
        map<ll, ll> G;

        if (size(E[u]) == 0)
        {
            G[a[u]] = 1;
            return G;
        }

        for (auto v : E[u])
        {
            auto H = dfs(v);

            if (size(H) > size(G)) swap(G, H);

            for (auto [b, k] : H) G[b] += k;
        }

        ll b = 0, ct = 0;

        set<ll> S;

        for (auto [bnxt, ctnxt] : G)
        {
            ll take = (bnxt - b) * ct;
            if (take > a[u]) break;

            S.insert(bnxt);
            a[u] -= take;
            ct += ctnxt;
            b = bnxt;
        }

        for (auto bnxt : S) G.erase(bnxt);

        G[b + (a[u] / ct)] += ct - (a[u] % ct);

        if (a[u] % ct) G[b + (a[u] / ct) + 1] += a[u] % ct;

        return G;
    };

    auto leaves = dfs(0);

    ll ans = rbegin(leaves)->first;

    cout << ans << endl;

    exit(0);
}