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

ll sq(ll x) { return x * x; }

int main()
{ _
    ll a, b; cin >> a >> b;

    ll ans = a > 0 ? sq(a) - sq(b / 2) - sq((b + 1) / 2) : -sq(b), opt = 0;

    for (ll x = 1; x <= min(a - 1, b - 2); ++x)
    {
        ll q = b / (x + 2), r = b % (x + 2);

        ll cur = x + sq(a - x) - ((x + 2 - r) * sq(q) + r * sq(q + 1));

        if (ans < cur) ans = cur, opt = x;
    }

    string s;

    ll q = b / (opt + 2), r = b % (opt + 2);

    for (int i = 0; i < opt; ++i)
    {
        if (r > 0)
        {
            s += string(q + 1, 'x');
            --r;
        }
        else
        {
            s += string(q, 'x');
        }
        s += 'o';
    }

    ll left[2] = { q + (r > 0), q + (r > 1) };

    s += string(left[0], 'x');

    s += string(a - opt, 'o');

    s += string(left[1], 'x');

    cout << ans << endl;

    cout << s << endl;

    exit(0);
}