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

int main() {
    int T;
    cin >> T;

    vector<ll> cnt(1000001, 0);

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> xs(N), ys(M);
        rep(i, N) cin >> xs[i];
        rep(i, M) cin >> ys[i];

        vector<int> x(K), y(K);
        vector<int> v1, v2;
        rep(i, K) {
            cin >> x[i] >> y[i];
            int a = lb(xs, x[i]), b = lb(ys, y[i]);
            if (xs[a] == x[i] && ys[b] != y[i]) v1.eb(i);
            if (xs[a] != x[i] && ys[b] == y[i]) v2.eb(i);
        }

        ll ans = 0;

        {
            sort(all(v1), [&](int a, int b) { return y[a] < y[b]; });
            int L = sz(v1);
            int ptr = 0;

            rep(i, M - 1) {
                ll j = 0;
                while (ptr + j < L && ys[i] < y[v1[ptr + j]] && y[v1[ptr + j]] < ys[i + 1]) {
                    int e = v1[ptr + j];
                    ans -= cnt[x[e]];
                    cnt[x[e]]++;
                    j++;
                }
                ans += j * (j - 1) / 2;
                rep(k, j) {
                    int e = v1[ptr + k];
                    cnt[x[e]]--;
                }
                ptr += j;
            }
        }
        {
            sort(all(v2), [&](int a, int b) { return x[a] < x[b]; });
            int L = sz(v2);
            int ptr = 0;

            rep(i, N - 1) {
                ll j = 0;
                while (ptr + j < L && xs[i] < x[v2[ptr + j]] && x[v2[ptr + j]] < xs[i + 1]) {
                    int e = v2[ptr + j];
                    ans -= cnt[y[e]];
                    cnt[y[e]]++;
                    j++;
                }
                ans += j * (j - 1) / 2;
                rep(k, j) {
                    int e = v2[ptr + k];
                    cnt[y[e]]--;
                }
                ptr += j;
            }
        }

        cout << ans << '\n';
    }
}