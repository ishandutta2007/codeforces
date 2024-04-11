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
    ll f, T, t0; cin >> f >> T >> t0;

    ll a[2], t[2], p[2];

    for (int i = 0; i < 2; ++i)
    {
        cin >> a[i] >> t[i] >> p[i];

        t[i] = min(t[i], t0);
    }

    auto check = [&](ll g, ll left, ll num)
    {
        ll take = min(g, num * a[1]);

        return take * t[1] + (g - take) * t0 <= left;
    };

    auto find = [&](ll g, ll left)
    {
        ll num = -1LL;

        // may take a lower constant ??

        for (ll z = 1e7; z > 0; z >>= 1)
            while (not check(g, left, num + z)) num += z;

        num += 1LL;

        return num;
    };

    ll ans = LINF;

    for (int i = 0; i < 2; ++i)
    {
        for (ll x = 0; x <= f; ++x)
        {
            ll take = min(f, x * a[0]);

            ll g = f - take, left = T - take * t[0];

            if (g * t[1] > left) continue;

            ll y = find(g, left);

            ans = min(ans, x * p[0] + y * p[1]);
        }

        swap(a[0], a[1]);
        swap(t[0], t[1]);
        swap(p[0], p[1]);
    }

    if (ans == LINF) ans = -1;

    cout << ans << endl;

    exit(0);
}