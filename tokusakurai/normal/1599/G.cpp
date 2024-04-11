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
const int MOD = 1000000007;
// const int MOD = 998244353;

vector<pll> p;

long double dist(int i, int j) {
    auto [dx, dy] = p[j] - p[i];
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int N, s;
    cin >> N >> s;
    s--;

    p.resize(N);
    rep(i, N) cin >> p[i];

    pll st = p[s];
    rearrange(p);
    N = sz(p);

    assert(N >= 3);

    rep(i, N) {
        if (st == p[i]) s = i;
    }

    rep3(i, N - 1, 0) p[i] = p[i] - p[0];

    int a = -1; // 
    map<pll, vector<int>> mp;

    rep2(i, 1, N - 1) {
        auto [x, y] = p[i];
        ll g = gcd(abs(x), abs(y));
        x /= g, y /= g;
        if (x < 0 || (x == 0 && y < 0)) x *= -1, y *= -1;
        mp[pll(x, y)].eb(i);
    }

    if (sz(mp) == N - 1) {
        a = 0;
    } else {
        each(e, mp) {
            if (sz(e.second) == 1) a = e.second[0];
        }
    }
    assert(a != -1);

    vector<int> ids; // 
    rep(i, N) {
        if (a != i) ids.eb(i);
    }
    sort(all(ids), [&](int i, int j) { return p[i] < p[j]; });
    int l = ids.front(), r = ids.back();

    long double ans = 1e18;

    if (s == a) {
        chmin(ans, dist(a, l) + dist(l, r));
        chmin(ans, dist(a, r) + dist(r, l));
    }
    if (s != a) {
        double x = dist(s, l);
        chmin(ans, dist(l, a) + dist(a, r) + dist(r, ids[1]) + x);
        chmin(ans, dist(l, r) + dist(r, a) + x);
        rep(i, N - 2) {
            chmin(ans, dist(l, ids[i]) + dist(ids[i], a) + dist(a, ids[i + 1]) + dist(ids[i + 1], r) + x);
            chmin(ans, dist(l, ids[i]) + dist(ids[i], a) + dist(a, r) + dist(r, ids[i + 1]) + x);
        }
    }
    if (s != a) {
        double x = dist(s, r);
        chmin(ans, dist(r, a) + dist(a, l) + dist(l, ids[N - 3]) + x);
        chmin(ans, dist(r, l) + dist(l, a) + x);
        rep(i, N - 2) {
            chmin(ans, dist(r, ids[i + 1]) + dist(ids[i + 1], a) + dist(a, ids[i]) + dist(ids[i], l) + x);
            chmin(ans, dist(r, ids[i + 1]) + dist(ids[i + 1], a) + dist(a, l) + dist(l, ids[i]) + x);
        }
    }
    if (s != a && s != l && s != r) {
        int id = -1;
        rep(i, N - 1) {
            if (ids[i] == s) id = i;
        }
        chmin(ans, dist(s, l) + dist(l, a) + dist(a, r) + dist(r, ids[id + 1]));
        chmin(ans, dist(s, l) + dist(l, a) + dist(a, ids[id + 1]) + dist(ids[id + 1], r));
        chmin(ans, dist(s, r) + dist(r, a) + dist(a, l) + dist(l, ids[id - 1]));
        chmin(ans, dist(s, r) + dist(r, a) + dist(a, ids[id - 1]) + dist(ids[id - 1], l));
        chmin(ans, dist(s, l) + dist(l, r) + dist(r, a));
        chmin(ans, dist(s, r) + dist(r, l) + dist(l, a));
        rep(i, N - 2) {
            if (i < id) {
                chmin(ans, dist(s, ids[i + 1]) + dist(ids[i + 1], r) + dist(r, a) + dist(a, ids[i]) + dist(ids[i], l));
            } else {
                chmin(ans, dist(s, ids[i]) + dist(ids[i], l) + dist(l, a) + dist(a, ids[i + 1]) + dist(ids[i + 1], r));
            }
        }
    }

    cout << ans << '\n';
}