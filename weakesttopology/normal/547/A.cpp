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

auto composition(auto f, auto g, ll mod)
{
    auto [a, b] = f;
    auto [c, d] = g;
    return pair(a * c % mod, (a * d + b) % mod);
}

auto get(auto f, ll x, ll mod)
{
    auto [a, b] = f;
    return (a * x + b) % mod;
}

void answer(ll x)
{
    cout << x << endl;
    exit(0);
}

int main()
{ _
    ll mod; cin >> mod;

    ll h[2], a[2];

    pair<ll, ll> f[2];

    for (int t = 0; t < 2; ++t)
    {
        cin >> h[t] >> a[t] >> f[t].first >> f[t].second;
    }

    pair<ll, ll> g[2] = { pair(1LL, 0LL), pair(1LL, 0LL) };
    ll ans = 0;

    for (int i = 0; i < mod && get(g[0], h[0], mod) != a[0]; ++i, ++ans)
        for (int t = 0; t < 2; ++t)
            g[t] = composition(g[t], f[t], mod);

    if (get(g[0], h[0], mod) != a[0]) answer(-1);

    if (get(g[1], h[1], mod) == a[1]) answer(ans);

    pair<ll, ll> c[2] = { f[0], f[1] };
    ll cycle = 1;

    for (int i = 0; i < mod && get(c[0], a[0], mod) != a[0]; ++i, ++cycle)
        for (int t = 0; t < 2; ++t)
            c[t] = composition(c[t], f[t], mod);

    if (get(c[0], a[0], mod) != a[0]) answer(-1);

    pair<ll, ll> G = { 1LL, 0LL };

    for (int i = 0; i < mod && get(G, get(g[1], h[1], mod), mod) != a[1]; ++i)
        G = composition(G, c[1], mod), ans += cycle;

    if (get(G, get(g[1], h[1], mod), mod) != a[1]) answer(-1);

    answer(ans);

    exit(0);
}