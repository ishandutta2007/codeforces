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

ll ap(ll x)
{
    return x * (x + 1) / 2;
}

int main()
{ _
    constexpr int K = 15;

    array<ll, K + 1> f;

    f[0] = 1;
    for (int x = 1; x <= K; ++x) f[x] = x * f[x - 1];

    auto getkth = [&](int n, ll k)
    {
        vector<int> S(n), p(n);
        iota(all(S), 0);
        for (int x = 0; x < n; ++x)
        {
            ll q = k / f[n - x - 1];
            p[x] = S[q];
            S.erase(begin(S) + q);
            k %= f[n - x - 1];
        }
        return p;
    };

    int n, q; cin >> n >> q;

    debug(q);

    ll sum = 0LL;

    int N = min(n, K);
    vector<int> p(N);
    iota(all(p), n - N);

    for (int z = 0; z < q; ++z)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int l, r; cin >> l >> r; --l, --r;

            ll ans = 0LL;

            if (l < n - N) ans += ap(min(r, n - N - 1)) - ap(l - 1);

            for (int i = 0; i < N; ++i)
            {
                int idx = i + n - N;
                if (l <= idx && idx <= r) ans += p[i];
            }

            ans += r - l + 1;

            cout << ans << endl;
        }
        else
        {
            ll x; cin >> x;
            sum += x;

            p = getkth(N, sum);
            for (auto& i : p) i += n - N;
        }
    }

    exit(0);
}