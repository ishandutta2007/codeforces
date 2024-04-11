#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define REP(i, l, r) for (int i = l; i < (r); i++)
#define REP2(i, l, r) for (int i = (int)r - 1; i >= (l); i--)
#define siz(x) (ll) x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
void print(vector<T> a) {
    if (a.empty())
        cout << '\n';
    else {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
    }
}

// __int128_t gcd(__int128_t a, __int128_t b) {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     __int128_t cnt = a % b;
//     while (cnt != 0) {
//         a = b;
//         b = cnt;
//         cnt = a % b;
//     }
//     return b;
// }

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

struct UnionFind {
    vector<int> data;
    int num;

    UnionFind(int sz) {
        data.assign(sz, -1);
        num = sz;
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        num--;
        return (true);
    }

    int find(int k) {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int operator[](int k) {
        return find(k);
    }
};

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {
    }

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    static int get_mod() {
        return mod;
    }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() {
        return *this += Mod_Int(1);
    }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() {
        return *this -= Mod_Int(1);
    }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const {
        return Mod_Int(-x);
    }

    Mod_Int operator+(const Mod_Int &p) const {
        return Mod_Int(*this) += p;
    }

    Mod_Int operator-(const Mod_Int &p) const {
        return Mod_Int(*this) -= p;
    }

    Mod_Int operator*(const Mod_Int &p) const {
        return Mod_Int(*this) *= p;
    }

    Mod_Int operator/(const Mod_Int &p) const {
        return Mod_Int(*this) /= p;
    }

    bool operator==(const Mod_Int &p) const {
        return x == p.x;
    }

    bool operator!=(const Mod_Int &p) const {
        return x != p.x;
    }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1)
                ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

ll mpow2(ll x, ll n, ll mod) {
    ll ans = 1;
    x %= mod;
    while (n != 0) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    ans %= mod;
    return ans;
}

ll modinv2(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0)
        u += mod;
    return u;
}

ll divide_int(ll a, ll b) {
    return (a >= 0 ? a / b : (a - b + 1) / b);
}

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = Mod_Int<mod>;

mint mpow(mint x, ll n) {
    bool rev = n < 0;
    n = abs(n);
    mint ans = 1;
    while (n != 0) {
        if (n & 1)
            ans *= x;
        x *= x;
        n = n >> 1;
    }
    return (rev ? ans.inverse() : ans);
}

// ----- library -------
struct st {
    int t, val;
    mint mval;
    st(int t, int val, mint mval) : t(t), val(val), mval(mval) {}
    bool operator<(const st x) const {
        return t < x.t;
    }
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int u, v;
        vector<int> d(n, 0);
        vector<vector<int>> li(n);
        rep(i, m) cin >> u >> v, li[--u].pb(--v), d[v]++;
        vector<int> ord;
        queue<int> que;
        rep(i, n) if (!d[i]) que.push(i);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            ord.pb(now);
            for (auto e : li[now]) {
                if (!(--d[e]))
                    que.push(e);
            }
        }
        vector<multiset<st>> ev(n);
        rep(i, n) if (a[i]) ev[i].insert(st(0, min(n, a[i]), a[i]));
        for (auto now : ord) {
            for (auto itr = ev[now].begin(); itr != ev[now].end();) {
                int bt = itr->t, bv = itr->val;
                itr++;
                if (itr == ev[now].end())
                    break;
                assert(bt + bv < itr->t);
            }
            for (auto dst : li[now]) {
                for (auto e : ev[now]) {
                    e.t++;
                    auto itrl = ev[dst].upper_bound(e);
                    if (itrl != ev[dst].begin()) {
                        itrl--;
                        if (itrl->t + itrl->val >= e.t)
                            e.t = itrl->t, e.val = min(n, e.val + itrl->val), e.mval += itrl->mval, ev[dst].erase(itrl);
                    }
                    auto itr = ev[dst].upper_bound(e);
                    while (itr != ev[dst].end()) {
                        if (e.t + e.val < itr->t)
                            break;
                        e.val = min(n, e.val + itr->val), e.mval += itr->mval;
                        itr = ev[dst].erase(itr);
                    }
                    ev[dst].insert(e);
                }
            }
        }
        if (ev[ord[n - 1]].empty()) {
            cout << 0 << '\n';
            continue;
        }
        auto itr = ev[ord[n - 1]].rbegin();
        cout << itr->mval + itr->t << '\n';
    }
}