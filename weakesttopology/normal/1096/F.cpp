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
    x %= mod, (p %= mod - 1) < 0 ? p += mod - 1 : 0LL;
    ll res = 1LL;
    while (p > 0)
    {
        if (p & 1) res = res * x % mod;
        (x *= x) %= mod, p >>= 1;
    }
    return res;
}

template<int mod>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= mod) < 0 ? x + mod : x)) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % mod); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= Mint(modpow(rhs.x, mod - 2, mod)); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend Mint operator+(ll lhs, const Mint& rhs) { return Mint(lhs) + rhs; }
    friend Mint operator-(ll lhs, const Mint& rhs) { return Mint(lhs) - rhs; }
    friend Mint operator*(ll lhs, const Mint& rhs) { return Mint(lhs) * rhs; }
    friend Mint operator/(ll lhs, const Mint& rhs) { return Mint(lhs) / rhs; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

template<typename T>
ll merge_sort(vector<T>& v, vector<T>& aux, int l, int r)
{
    if (r <= l) return 0LL;
    int m = l + (r - l) / 2;
    ll res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m + 1, r);
    int x = l, y = m + 1, z = l;
    while (x <= m && y <= r)
    {
        if (v[x] <= v[y])
            aux[z++] = v[x++];
        else
            aux[z++] = v[y++], res += m - x + 1;
    }
    while (x <= m) aux[z++] = v[x++];
    while (y <= r) aux[z++] = v[y++];
    while (l <= r) v[--z] = aux[r--];
    return res;
}

template<typename T>
ll inversions(vector<T> v)
{
    static vector<T> aux;
    aux.resize(max(size(aux), size(v)));
    return merge_sort(v, aux, 0, size(v) - 1);
}

int main()
{ _
    int n; cin >> n;

    vector<int> p(n), missing(n, 1), a;

    for (auto& x : p)
    {
        cin >> x;
        if (x != -1)
        {
            --x;
            missing[x] = 0;
            a.push_back(x);
        }
    }

    for (int i = 1; i < n; ++i) missing[i] += missing[i - 1];

    auto query = [&](int l, int r) { return missing[r] - (l > 0 ? missing[l - 1] : 0); };

    constexpr int mod = 998244353;
    using mint = Mint<mod>;

    const int k = query(0, n - 1);

    debug(k);

    mint ans = mint(1LL * k * (k - 1)) / 4 + inversions(a);
    mint left = k;

    for (auto x : p)
    {
        if (x != -1)
        {
            ans += (left * query(0, x)) / k;
            ans += ((k - left) * query(x, n - 1)) / k;
        }
        else left -= 1;
    }

    cout << ans << endl;

    exit(0);
}