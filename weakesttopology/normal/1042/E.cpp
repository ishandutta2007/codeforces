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

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint
{
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(Mint rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(Mint rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(Mint rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};

template<typename T> T sq(T x){ return x * x; }

int main()
{ _
    int n, m;
    cin >> n >> m;

    constexpr int mod = 998244353;
    using mint = Mint<mod>;

    map<int, vector<array<int, 2>>> A;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            A[x].push_back({i, j});
        }

    array<int, 2> init;
    for (int t = 0; t < 2; ++t)
    {
        cin >> init[t];
        --init[t];
    }

    mint Esum = 0;
    mint sum[2], sqsum[2];
    int ct = 0;

    map<array<int, 2>, mint> memo;

    for (auto& [x, v] : A)
    {
        mint cur_sum[2], cur_sqsum[2], Ecur = 0;
        for (auto pt : v)
        {
            for (int t = 0; t < 2; ++t)
            {
                if (ct > 0) memo[pt] += sq(pt[t]) + (-2 * sum[t] * pt[t] + sqsum[t]) / ct;
                cur_sum[t] += pt[t], cur_sqsum[t] += sq(pt[t]);
            }
            if (ct > 0) memo[pt] += Esum / ct;
            Ecur += memo[pt];
        }
        for (int t = 0; t < 2; ++t) sum[t] += cur_sum[t], sqsum[t] += cur_sqsum[t];
        Esum += Ecur, ct += size(v);
    }

    mint res = memo[init];

    cout << res << endl;

    exit(0);
}