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
    ll n, m, a, d; cin >> n >> m >> a >> d;

    vector t(m, 0LL);

    for (auto& x : t) cin >> x;

    auto get = [&](ll i)
    {
        if (i > n) return LINF;
        return i * a;
    };

    ll i = 1LL, j = 0LL, ans = 0LL;

    ll q = d / a + 1;

    while (j < m)
    {
        ll cur = min(get(i), t[j]);

        if (cur < t[j] - d)
        {
            ll k = max(i, min(n, (t[j] - d - 1) / a));

            ll r = (k - i + 1 + q - 1) / q;

            ans += r;

            i += r * q;

            continue;
        }

        ans += 1;

        auto iter = upper_bound(j + all(t), cur + d);

        j = (ll)distance(begin(t), iter);

        if (i <= n) i = (cur + d) / a + 1;
    }

    if (i <= n) ans += (n - i + 1 + q - 1) / q;

    cout << ans << endl;

    exit(0);
}