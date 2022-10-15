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
    constexpr int amax = 3e6;

    vector<int> cnt(amax + 1, 0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        cnt[x] += 1;
    }

    vector<ll> cnt_area(amax + 1, 0);

    for (int x = 1; x <= amax; ++x) if (cnt[x])
    {
        for (int y = 1; x * y <= amax; ++y) if (cnt[y])
        {
            cnt_area[x * y] += 1LL * cnt[x] * (cnt[y] - (x == y));
        }
    }

    for (int x = amax - 1; x >= 0; --x) cnt_area[x] += cnt_area[x + 1];

    ll large = 1LL * n * (n - 1) - cnt_area[0];

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int p; cin >> p;

        ll ans = large + cnt_area[p];

        cout << ans << endl;
    }

    exit(0);
}