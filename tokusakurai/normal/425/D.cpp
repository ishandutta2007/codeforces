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
    int N;
    cin >> N;

    int M = 100000;
    vector<vector<int>> idx(M + 1), idy(M + 1);

    vector<int> x(N), y(N);
    rep(i, N) {
        cin >> x[i] >> y[i];
        idx[x[i]].eb(y[i]);
        idy[y[i]].eb(x[i]);
    }

    rep(i, M + 1) sort(all(idx[i]));
    rep(i, M + 1) sort(all(idy[i]));

    vector<vector<pii>> px(M + 1), py(M + 1);

    rep(i, N) {
        int tx = lb(idx[x[i]], y[i]);
        int ty = lb(idy[y[i]], x[i]);
        if (tx < ty) {
            rep(j, tx) {
                int d = y[i] - idx[x[i]][j];
                if (x[i] >= d) px[x[i] - d].eb(idx[x[i]][j], y[i]);
            }
        } else {
            rep(j, ty) {
                int d = x[i] - idy[y[i]][j];
                if (y[i] >= d) py[y[i] - d].eb(idy[y[i]][j], x[i]);
            }
        }
    }

    int ans = 0;
    vector<bool> used(M + 1, false);

    rep(i, M + 1) {
        each(e, idx[i]) used[e] = true;
        each(e, px[i]) {
            if (used[e.first] && used[e.second]) ans++;
        }
        each(e, idx[i]) used[e] = false;
    }

    rep(i, M + 1) {
        each(e, idy[i]) used[e] = true;
        each(e, py[i]) {
            if (used[e.first] && used[e.second]) ans++;
        }
        each(e, idy[i]) used[e] = false;
    }

    cout << ans << '\n';
}