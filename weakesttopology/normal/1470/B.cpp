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
    vector<int> sq(N + 1, 1);

    for (int x = 2; x * x <= N; ++x)
        for (int k = 1; k * x * x <= N; ++k)
            sq[k * x * x] = x * x;

    return sq;
}

void solve()
{
    static constexpr int N = 1e6;
    static auto sq = sieve(N);

    int n; cin >> n;

    map<int, int> freq;

    int a = 0;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; x /= sq[x];
        a = max(a, freq[x] += 1);
    }

    int b = freq[1];

    for (auto [k, v] : freq)
    {
        if (k != 1 && v % 2 == 0) b += v;
    }

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        ll w; cin >> w;

        int ans = w ? max(a, b) : a;

        cout << ans << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}