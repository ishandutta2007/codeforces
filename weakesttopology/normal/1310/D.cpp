#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ull = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

template<int N>
bitset<N> sample()
{
    static uniform_int_distribution<ull> unif(0, -1);
    bitset<N> res;
    for (int i = 0; i < (N + 63) / 64; ++i)
    {
        res <<= 64;
        res |= unif(rng);
    }
    return res;
}

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

int main()
{ _
    int n, k; cin >> n >> k;

    vector<vector<pair<int, ll>>> E(n);

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            ll w; cin >> w;
            if (u == v) continue;
            E[u].emplace_back(v, w);
        }
    }

    constexpr int nmax = 80, maxiter = 5e3;
    bitset<nmax> color;

    ll ans = LINF;

    vector<ll> dp(n), dpnxt(n);

    for (int iter = 0; iter < maxiter; ++iter)
    {
        color = sample<nmax>();

        fill(all(dp), LINF), fill(all(dpnxt), LINF);

        dp[0] = 0;

        for (int j = 0; j < k; ++j)
        {
            for (int u = 0; u < n; ++u)
            {
                for (auto [v, w] : E[u]) if (color[u] ^ color[v])
                    chmin(dpnxt[v], dp[u] + w);
            }

            swap(dp, dpnxt), fill(all(dpnxt), LINF);
        }

        chmin(ans, dp[0]);
    }

    cout << ans << endl;

    exit(0);
}