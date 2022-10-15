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

constexpr int D = 6;
using C = array<ll, D>;

void update(C& c)
{
    for (int i = 0; i < D; ++i)
        c[i] = min(c[i], c[(i + 1) % D] + c[(i + (D - 1)) % D]);
}

auto ternary_search(auto l, auto r, auto&& f, auto EPS=2)
{
    using T = decltype(l);
    while (r - l > EPS)
    {
        T m1 = l + (r - l) / 3;
        T m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    T c = l;
    for (T x = c + 1; x <= r; ++x) if (f(x) < f(c)) c = x;
    return pair(f(c), c);
}

ll solve()
{
    ll x, y; cin >> x >> y;

    C c;
    for (int i = 0; i < D; ++i) cin >> c[i];

    for (int i = 0; i < 100; ++i) update(c);

    auto f = [&](ll t)
    {
        int dx = (x + t) >= 0 ? 5 : 2;
        int dy = (y + t) >= 0 ? 1 : 4;
        int dt = t >= 0 ? 3 : 0;

        ll res = abs(x + t) * c[dx] + abs(y + t) * c[dy] + abs(t) * c[dt];

        return res;
    };

    const ll L = -1e9, R = 1e9;

    ll ans = ternary_search(L, R, f, 2LL).first;

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}