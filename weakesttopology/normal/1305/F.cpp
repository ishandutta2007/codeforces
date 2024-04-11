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

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();

mt19937 rng(FIXED_RANDOM);

int main()
{ _
    int n; cin >> n;

    vector<ll> a(n);

    for (auto& x : a) cin >> x;

    uniform_int_distribution<int> unif(0, n - 1);

    vector<ll> f;

    ll ans = n;

    for (int t = 0; t < 50; ++t)
    {
        int j = unif(rng);
        for (auto x : { max(2LL, a[j] - 1), max(2LL, a[j]), a[j] + 1 } )
            for (ll p = 2; x > 1; ++p)
            {
                if (p * p > x)
                {
                    f.push_back(x);
                    break;
                }
                if (x % p == 0)
                {
                    f.push_back(p);
                    while (x % p == 0) x /= p;
                }
            }

        sort(all(f)), f.erase(unique(all(f)), end(f));

        for (auto p : f)
        {
            ll cur = 0LL;
            for (int i = 0; i < n; ++i)
            {
                ll r = a[i] % p;
                cur += a[i] >= p ? min(r, p - r) : p - r;
            }
            ans = min(ans, cur);
        }
        f.clear();
    }

    cout << ans << endl;

    exit(0);
}