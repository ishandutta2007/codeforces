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

ll sq(ll x) { return x * x; }

ll solve()
{
    int nr, ng, nb; cin >> nr >> ng >> nb;

    vector r(nr, 0LL), g(ng, 0LL), b(nb, 0LL);

    for (auto& x : r) cin >> x;
    for (auto& x : g) cin >> x;
    for (auto& x : b) cin >> x;

    sort(all(r)), sort(all(g)), sort(all(b));

    r.erase(unique(all(r)), end(r));
    g.erase(unique(all(g)), end(g));
    b.erase(unique(all(b)), end(b));

    ll ans = LINF;

    for (int t = 0; t < 3; ++t)
    {
        for (auto x : g)
        {
            auto iterr = lower_bound(all(r), x);
            auto iterb = lower_bound(all(b), x);

            if (iterr == end(r)) --iterr;
            if (iterb == end(b)) --iterb;

            ll ry[2] = { *iterr, *iterr };
            ll bz[2] = { *iterb, *iterb };

            if (iterr != begin(r)) ry[0] = *prev(iterr);
            if (iterb != begin(b)) bz[0] = *prev(iterb);

            for (int u = 0; u < 2; ++u)
                for (auto v = 0; v < 2; ++v)
                    ans = min(ans, sq(x - ry[u]) + sq(x - bz[v]) + sq(ry[u] - bz[v]));
        }

        swap(g, b), swap(g, r);
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}