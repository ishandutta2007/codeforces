#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define per(i, n) for (int i = (n)-1; 0 <= i; i--)
#define rep2(i, l, r) for (int i = (l); i < int(r); i++)
#define per2(i, l, r) for (int i = (r)-1; int(l) <= i; i--)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty())
        cout << '\n';
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using maxheap = std::priority_queue<T>;
template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
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

// const int MOD = 1000000007;
const int MOD = 998244353;
using mint = Mod_Int<MOD>;

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
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;
    const int bs = 300, nb = (n + bs - 1) / bs;
    vector<vector<int>> cnt(nb, vector<int>(n, 0));
    vector<deque<int>> que(nb);
    rep(i, n) cnt[i / bs][a[i]]++, que[i / bs].push_back(a[i]);
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--, l += last, r += last, l %= n, r %= n;
        if (l > r)
            swap(l, r);
        int bl = l / bs, il = l % bs, br = r / bs, ir = r % bs;
        if (type == 1) {
            if (bl == br) {
                vector<int> keep;
                while (sz(que[bl]))
                    keep.eb(que[bl].front()), que[bl].pop_front();
                int tmp = keep[ir];
                per2(i, il, ir) keep[i + 1] = keep[i];
                keep[il] = tmp;
                rep(i, sz(keep)) que[bl].push_back(keep[i]);
            } else {
                vector<int> keep;
                rep(i, ir + 1) keep.eb(que[br].front()), que[br].pop_front();
                int tmp = keep.back();
                cnt[br][tmp]--;
                keep.pop_back();
                per(i, sz(keep)) que[br].push_front(keep[i]);
                que[br].push_front(que[br - 1].back());
                cnt[br][que[br].front()]++;
                per2(i, bl + 1, br) cnt[i][que[i].back()]--, que[i].pop_back(), que[i].push_front(que[i - 1].back()), cnt[i][que[i].front()]++;
                keep.clear();
                rep2(i, il, bs) keep.eb(que[bl].back()), que[bl].pop_back();
                que[bl].push_back(tmp);
                cnt[bl][tmp]++, cnt[bl][keep[0]]--;
                per2(i, 1, sz(keep)) que[bl].push_back(keep[i]);
            }
        } else {
            int k;
            cin >> k;
            k--, k += last, k %= n;
            int ans = 0;
            if (bl == br) {
                rep2(i, il, ir + 1) if (que[bl][i] == k) ans++;
            } else {
                rep2(i, il, sz(que[bl])) if (que[bl][i] == k) ans++;
                rep2(i, bl + 1, br) ans += cnt[i][k];
                rep(i, ir + 1) if (que[br][i] == k) ans++;
            }
            cout << ans << '\n';
            last = ans;
        }
    }
}