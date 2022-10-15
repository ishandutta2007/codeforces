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
    constexpr int N = 1e5, K = 10;
    auto [lp, pr] = sieve(N);

    int n, k; cin >> n >> k;

    ll ans = 0;

    map<pair<array<int, K>, array<int, K>>, int> freq;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;

        array<int, K> f{}, e{}, complement{};

        for (int ptr = 0; x > 1;)
        {
            int p = lp[x], exp = 0;
            while (lp[x] == p) x /= p, exp += 1;
            exp %= k;

            if (exp)
            {
                f[ptr] = p, e[ptr] = exp, complement[ptr] = k - exp;
                ++ptr;
            }
        }

        ans += freq[pair(f, complement)];
        freq[pair(f, e)] += 1;
    }

    cout << ans << endl;

    exit(0);
}