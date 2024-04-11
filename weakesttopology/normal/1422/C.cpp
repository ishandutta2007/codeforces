#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<ll MOD>
struct Mint
{
    ll x;
    Mint(ll x = 0) : x(x % MOD) {};
    // Mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
    Mint& operator+=(const Mint& rhs) { x = (x + rhs.x) % MOD; return *this; }
    Mint& operator-=(const Mint& rhs) { x = (x + MOD - rhs.x) % MOD; return *this; }
    Mint& operator*=(const Mint& rhs) { x = (x * rhs.x) % MOD; return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
};

int main()
{ _
    string s; cin >> s;
    int n = sz(s);

    constexpr ll MOD = 1e9 + 7;
    using M = Mint<MOD>;

    vector power(n + 1, M(1));
    for (int i = 1; i <= n; ++i)
        power[i] = M(10) * power[i - 1];

    vector suffix(n, M(0)); suffix[n - 1] = M(s[n - 1] - '0');

    for (int i = n - 2; i >= 0; --i)
        suffix[i] = M(s[i] - '0') * power[n - 1 - i] + suffix[i + 1];
    suffix.push_back(M(0));

    vector prefixsum(n, M(0)); prefixsum[0] = M(s[0] - '0');

    for (int i = 1; i < n; ++i)
        prefixsum[i] = M(10) * prefixsum[i - 1] + M(s[i] - '0');
    for (int i = 1; i < n; ++i)
        prefixsum[i] += prefixsum[i - 1];

    M ans = suffix[1];

    for (int i = 1; i < n; ++i)
        ans += prefixsum[i - 1] * power[n - 1 - i] + M(i + 1) * suffix[i + 1];

    cout << ans.x << endl;

    exit(0);
}