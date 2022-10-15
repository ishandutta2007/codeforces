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

ll solve()
{
    int n; cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    constexpr int K = 60;
    constexpr ll mod = 1e9 + 7;

    array<ll, K> pow;

    pow[0] = 1;
    for (int k = 1; k < K; ++k) pow[k] = (2 * pow[k - 1]) % mod;

    array<ll, K> ctpow;

    fill(all(ctpow), 0LL);
    for (auto x : a) for (int j = 0; j < K; ++j) ctpow[j] += x >> j & 1;

    vector<ll> or_sum(n, 0LL);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < K; ++j)
        {
            if (a[i] >> j & 1)
            {
                (or_sum[i] += n * pow[j] % mod) %= mod;
            }
            else
            {
                (or_sum[i] += ctpow[j] * pow[j] % mod) %= mod;
            }
        }

    array<ll, K> weighted_pow;

    fill(all(weighted_pow), 0LL);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < K; ++j) if (a[i] >> j & 1)
            (weighted_pow[j] += pow[j] * or_sum[i] % mod) %= mod;

    ll ans = 0LL;

    for (auto x : a)
    {
        for (int j = 0; j < K; ++j) if (x >> j & 1)
            (ans += weighted_pow[j]) %= mod;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}