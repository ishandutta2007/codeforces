#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

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
// const int MOD = 1000000007;
const int MOD = 998244353;

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

template <typename T>
struct Combination {
    static vector<T> _fac, _ifac;

    Combination() {}

    static void init(int n) {
        _fac.resize(n + 1), _ifac.resize(n + 1);
        _fac[0] = 1;
        for (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;
        _ifac[n] = _fac[n].inverse();
        for (int i = n; i >= 1; i--) _ifac[i - 1] = _ifac[i] * i;
    }

    static T fac(int k) { return _fac[k]; }

    static T ifac(int k) { return _ifac[k]; }

    static T inv(int k) { return fac(k - 1) * ifac(k); }

    static T P(int n, int k) {
        if (k < 0 || n < k) return 0;
        return fac(n) * ifac(n - k);
    }

    static T C(int n, int k) {
        if (k < 0 || n < k) return 0;
        return fac(n) * ifac(n - k) * ifac(k);
    }

    static T H(int n, int k) { // k  n 
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : C(n + k - 1, k);
    }

    static T second_stirling_number(int n, int k) { // n k  1 
        T ret = 0;
        for (int i = 0; i <= k; i++) {
            T tmp = C(k, i) * T(i).pow(n);
            ret += ((k - i) & 1) ? -tmp : tmp;
        }
        return ret * ifac(k);
    }

    static T bell_number(int n, int k) { // n k 
        if (n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k + 1);
        pref[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (i & 1) {
                pref[i] = pref[i - 1] - ifac(i);
            } else {
                pref[i] = pref[i - 1] + ifac(i);
            }
        }
        T ret = 0;
        for (int i = 1; i <= k; i++) ret += T(i).pow(n) * ifac(i) * pref[k - i];
        return ret;
    }
};

template <typename T>
vector<T> Combination<T>::_fac = vector<T>();

template <typename T>
vector<T> Combination<T>::_ifac = vector<T>();

using comb = Combination<mint>;

template <typename T>
vector<T> divisors(const T &n) {
    vector<T> ret;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}

template <typename T>
vector<pair<T, int>> prime_factor(T n) {
    vector<pair<T, int>> ret;
    for (T i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) cnt++, n /= i;
        if (cnt > 0) ret.emplace_back(i, cnt);
    }
    if (n > 1) ret.emplace_back(n, 1);
    return ret;
}

template <typename T>
bool is_prime(const T &n) {
    if (n == 1) return false;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 1,2,...,n  k 
template <typename T>
T coprime(T n, T k) {
    vector<pair<T, int>> ps = prime_factor(k);
    int m = ps.size();
    T ret = 0;
    for (int i = 0; i < (1 << m); i++) {
        T prd = 1;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) prd *= ps[j].first;
        }
        ret += (__builtin_parity(i) ? -1 : 1) * (n / prd);
    }
    return ret;
}

vector<bool> Eratosthenes(const int &n) {
    vector<bool> ret(n + 1, true);
    if (n >= 0) ret[0] = false;
    if (n >= 1) ret[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!ret[i]) continue;
        for (int j = i + i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}

vector<int> Eratosthenes2(const int &n) {
    vector<int> ret(n + 1);
    iota(begin(ret), end(ret), 0);
    if (n >= 0) ret[0] = -1;
    if (n >= 1) ret[1] = -1;
    for (int i = 2; i * i <= n; i++) {
        if (ret[i] < i) continue;
        for (int j = i + i; j <= n; j += i) ret[j] = min(ret[j], i);
    }
    return ret;
}

vector<int> p;

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id, x, y;
        edge(int to, int id, int x, int y) : to(to), id(id), x(x), y(y) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> mi;

    Graph(int n) : es(n), n(n), m(0), mi(n + 1, 0) {}

    void add_edge(int from, int to, int x, int y) {
        es[from].emplace_back(to, m, x, y);
        if (!directed) es[to].emplace_back(from, m, y, x);
        m++;
    }

    void dfs(int now, int pre, vector<int> &cnt) {
        each(e, es[now]) {
            if (e.to == pre) continue;
            {
                int my = e.y;
                while (my > 1) {
                    int t = p[my];
                    my /= t;
                    cnt[t]++;
                    chmin(mi[t], cnt[t]);
                }
                int mx = e.x;
                while (mx > 1) {
                    int t = p[mx];
                    mx /= t;
                    cnt[t]--;
                    chmin(mi[t], cnt[t]);
                }
            }
            dfs(e.to, now, cnt);
            {
                int mx = e.x;
                while (mx > 1) {
                    int t = p[mx];
                    mx /= t;
                    cnt[t]++;
                    chmin(mi[t], cnt[t]);
                }
                int my = e.y;
                while (my > 1) {
                    int t = p[my];
                    my /= t;
                    cnt[t]--;
                    chmin(mi[t], cnt[t]);
                }
            }   
        }
    }

    void dfs2(int now, int pre, mint a, mint &b) {
        b += a;
        each(e, es[now]) {
            if (e.to == pre) continue;
            dfs2(e.to, now, a * comb::inv(e.x) * e.y, b);
        }
    }

    void solve() {
        vector<int> cnt(n + 1, 0);
        dfs(0, -1, cnt);
        mint tmp = 1;
        rep2(i, 1, n) {
            if (mi[i] < 0) tmp *= mint(i).pow(-mi[i]);
        }
        // print(mi);
        // cout << tmp << ' ';
        mint ret = 0;
        dfs2(0, -1, tmp, ret);
        cout << ret << '\n';
    }
};

int main() {
    p = Eratosthenes2(200000);
    comb::init(200000);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        Graph G(N);

        rep(i, N - 1) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--, v--;
            G.add_edge(u, v, x, y);
        }

        G.solve();
    }
}