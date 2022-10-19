#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty()) cout << '\n';
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

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

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
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

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

ll dot(pll p, pll q) { return p.first * q.first + p.second * q.second; }

ll det(pll p, pll q) { return p.first * q.second - p.second * q.first; }

int sgn(ll x) { return (x > 0 ? 1 : x < 0 ? -1 : 0); }

ll norm(pll p) { return p.first * p.first + p.second * p.second; }

int ccw(pll a, pll b, pll c) {
    b = b - a, c = c - a;
    if (sgn(det(b, c)) == 1) return 1;
    if (sgn(det(b, c)) == -1) return -1;
    if (sgn(dot(b, c)) == -1) return 2;
    if (norm(c) > norm(b)) return -2;
    return 0;
}

bool intersect(pll p1, pll q1, pll p2, pll q2) {
    if (ccw(p1, q1, p2) * ccw(p1, q1, q2) > 0) return false;
    return ccw(p2, q2, p1) * ccw(p2, q2, q1) <= 0;
}

int in_polygon(const vector<pll> &p, pll q) {
    int n = p.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        pll a = p[i] - q, b = p[(i + 1) % n] - q;
        if (det(a, b) == 0 && sgn(dot(a, b)) <= 0) return 1;
        if (a.second > b.second) swap(a, b);
        if (sgn(a.second) <= 0 && sgn(b.second) == 1 && sgn(det(a, b)) == 1) ret ^= 2;
    }
    return ret;
}

bool judge(const vector<pll> &p, int i, int j) {
    int n = sz(p);
    if (j - i == 1) return true;
    if (i == 0 && j == n - 1) return true;
    rep(k, n) {
        if (i == k || j == k) continue;
        if (ccw(p[i], p[j], p[k]) == 0) return false;
    }
    rep(k, n) {
        int l = (k + 1) % n;
        if (i == k || i == l || j == k || j == l) continue;
        if (intersect(p[i], p[j], p[k], p[l])) return false;
    }
    pll q = p[i] + p[j];
    q.first /= 2, q.second /= 2;
    return in_polygon(p, q) == 0 ? false : true;
}

int main() {
    int N;
    cin >> N;

    vector<pll> ps(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        ps[i] = pll(2 * x, 2 * y);
    }

    vector<vector<mint>> dp(N, vector<mint>(N, 0));

    // rep(i, N) rep2(j, i + 1, N) cout << i << ' ' << j << ' ' << judge(ps, i, j) << '\n';

    per(i, N) rep2(j, i, N) {
        if (j <= i + 1) {
            dp[i][j] = 1;
            continue;
        }
        if (!judge(ps, i, j)) continue;
        rep2(k, i + 1, j) dp[i][j] += dp[i][k] * dp[k][j];
    }

    cout << dp[0][N - 1] << '\n';
}