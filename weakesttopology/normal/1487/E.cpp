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
    constexpr int K = 4;

    int n[K];
    for (int j = 0; j < K; ++j) cin >> n[j];

    vector<ll> a[K];
    for (int j = 0; j < K; ++j)
    {
        a[j].resize(n[j]);
        for (auto& x : a[j]) cin >> x;
    }

    vector<vector<int>> E[K - 1];

    for (int j = 0; j < K - 1; ++j)
    {
        E[j].resize(n[j]);

        int m;
        cin >> m;

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[j][u].push_back(v);
        }
    }

    auto dp = a[K - 1];

    for (int j = K - 2; j >= 0; --j)
    {
        vector<ll> dpnxt(n[j], LINF), V(n[j + 1]);
        iota(all(V), 0);
        sort(all(V), [&dp](int u, int v){ return dp[u] < dp[v]; });

        vector<int> pos(n[j + 1]);
        for (int i = 0; i < n[j + 1]; ++i) pos[V[i]] = i;

        for (int u = 0; u < n[j]; ++u)
        {
            sort(all(E[j][u]), [&pos](int x, int y){ return pos[x] < pos[y]; });
            int mex = 0;
            while (mex < size(E[j][u]) && pos[E[j][u][mex]] == mex) ++mex;

            if (mex < n[j + 1] && dp[V[mex]] < LINF) dpnxt[u] = a[j][u] + dp[V[mex]];
        }

        swap(dp, dpnxt);
    }

    ll res = *min_element(all(dp));

    if (res >= LINF) res = -1;

    cout << res << endl;

    exit(0);
}