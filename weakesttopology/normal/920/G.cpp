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

auto sieve(int N)
{
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

int main()
{ _
    constexpr int N = 1e7, M = 10;
    auto [lp, pr] = sieve(N);

    using P = array<int, (1 << M)>;

    array<int, (1 << M)> sgn;

    for (int mask = 1; mask < (1 << M); ++mask)
        sgn[mask] = (__builtin_popcount(mask) & 1 ? 1 : -1);

    auto count = [&](int x, int y, P& p, int K)
    {
        int cnt = 0;
        for (int mask = 1; mask < (1 << K); ++mask)
            cnt += (y / p[mask] - x / p[mask]) * sgn[mask];
        return cnt;
    };

    int t; cin >> t;

    while (t--)
    {
        int x, p, k; cin >> x >> p >> k;

        P f, prod;

        fill(all(f), 0), fill(all(prod), 1);

        for (int idx = 0; p > 1; ++idx)
        {
            int q = lp[p];
            while (lp[p] == q) p /= q;
            f[idx] = q;
        }

        int K = 0; while (f[K] != 0) ++K;

        for (int mask = 1; mask < (1 << K); ++mask)
            for (int j = 0; j < K; ++j)
                if (mask >> j & 1) prod[mask] *= f[j];

        int ans = x;

        for (int z = N - ans; z; z >>= 1)
            while(ans + z <= N && (ans + z - x) - count(x, ans + z, prod, K) < k)
                ans += z;

        ans += 1;

        cout << ans << endl;
    }

    exit(0);
}