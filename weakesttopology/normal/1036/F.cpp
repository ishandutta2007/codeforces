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

using ld = long double;
using ull = unsigned long long;

bool check_safe(ull a, ull b, ull n)
{
    ull x = a * b;
    if (a != 0 && x / a != b) return false;
    return x <= n;
}

ll getroot(ll n, ll d)
{
    ll rt = max((ll)powl(n, ld(1.0) / d), 1LL);

    if (rt > 1) rt -= 1;

    while (true)
    {
        ll x = rt + 1, res = 1, p = d;
        bool good = true;
        while (p && good)
        {
            if (p & 1)
            {
                good = good && check_safe(res, x, n);
                res *= x;
            }
            p >>= 1;
            good = good && (p == 0 || check_safe(x, x, n));
            x *= x;
        }
        if (good && res <= n) rt += 1;
        else break;
    }
    return rt;
}

ll solve()
{
    ll n;
    cin >> n;

    constexpr int gmax = 59;
    ll num[gmax + 1]{};

    for (int g = 2; g <= gmax; ++g)
    {
        ll rt = getroot(n, g);
        if (rt <= 1) break;
        num[g] = rt - 1;
    }

    for (int g = gmax; g >= 2; --g)
    {
        for (int d = 2; d * g <= gmax; ++d)
        {
            num[g] -= num[d * g];
        }
    }

    return n - 1 - accumulate(all(num), 0LL);
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}