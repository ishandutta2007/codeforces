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

const int inf = (1 << 28) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N), c(N);
    vector<int> xs;
    rep(i, N) {
        cin >> a[i];
        xs.eb(a[i]);
    }
    rep(i, N) {
        cin >> b[i];
        xs.eb(b[i]);
    }
    rep(i, N) {
        cin >> c[i];
        xs.eb(c[i]);
    }
    rearrange(xs);

    rep(i, N) a[i] = lb(xs, a[i]);
    rep(i, N) b[i] = lb(xs, b[i]);
    rep(i, N) c[i] = lb(xs, c[i]);

    int M = sz(xs);

    vector<int> ta(M, inf), tb(M, inf), tc(M, inf);
    rep(i, N) chmin(ta[a[i]], i);
    rep(i, N) chmin(tb[b[i]], i);
    rep(i, N) chmin(tc[c[i]], i);

    vector<int> dp(N + 1, 0);
    rep(i, M) {
        if (ta[i] == inf && tb[i] == inf) chmax(dp[N], tc[i] + 1);
    }

    rep3(i, N - 1, 0) {
        dp[i] = dp[i + 1];
        if (tb[b[i]] == i && ta[b[i]] == inf) chmax(dp[i], tc[b[i]] + 1);
    }
    // print(dp);

    set<int> s;
    multiset<int> res;
    rep(i, N + 1) {
        s.emplace(i);
        res.emplace(i + dp[i]);
    }

    int ans = N + *res.begin();

    rep3(i, N - 1, 0) {
        if (ta[a[i]] == i) {
            auto it = s.upper_bound(tb[a[i]]);
            vector<int> tmp;
            while (it != begin(s)) {
                it--;
                if (dp[*it] >= tc[a[i]] + 1) break;
                tmp.eb(*it);
            }
            if (!tmp.empty() && tb[a[i]] != inf && !s.count(tb[a[i]] + 1)) {
                dp[tb[a[i]] + 1] = dp[tmp.front()];
                s.emplace(tb[a[i]] + 1);
                res.emplace(tb[a[i]] + 1 + dp[tb[a[i]] + 1]);
            }
            if (!tmp.empty()) {
                each(e, tmp) {
                    res.erase(res.find(e + dp[e]));
                    dp[e] = tc[a[i]] + 1;
                    s.erase(e);
                }
                s.emplace(tmp.back());
                res.emplace(tmp.back() + dp[tmp.back()]);
            }
        }
        chmin(ans, i + *res.begin());
    }

    cout << ans << '\n';
}