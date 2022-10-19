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

struct Random_Number_Generator {
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator()(int64_t l, int64_t r) {
        uniform_int_distribution<int64_t> dist(l, r - 1);
        return dist(mt);
    }

    int64_t operator()(int64_t r) { return (*this)(0, r); }
} rng;

template <typename T>
T kth_root_integer(T a, int k) {
    if (k == 1) return a;
    auto check = [&](T x) {
        T mul = 1;
        for (int j = 0; j < k; j++) {
            if (__builtin_mul_overflow(mul, x, &mul)) return false;
        }
        return mul <= a;
    };
    int n = 4 * sizeof(T);
    T ret = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (check(ret | (T(1) << i))) ret |= T(1) << i;
    }
    return ret;
}

ll fs(ll x) {
    return floor(sqrt(x) + 1e-9); //
}

int main() {
    int N;
    cin >> N;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    rearrange(a);
    N = sz(a);

    ll M = 2000000;
    vector<int> c(M + 1, 0);
    rep2(i, 1, N - 1) c[a[i]]++;
    vector<int> s(M + 2, 0);
    rep(i, M + 1) s[i + 1] = s[i] + c[i];

    vector<int> ma(M + 2, -inf), mi(M + 2, inf);
    rep(i, M + 1) {
        ma[i + 1] = ma[i];
        if (c[i]) chmax(ma[i + 1], i);
    }
    rep3(i, M, 0) {
        mi[i] = mi[i + 1];
        if (c[i]) chmin(mi[i], i);
    }

    ll x = fs(a[0]);

    for (ll i = x;; i++) {
        ll L = i * i, R = i * (i + 1);
        if (R < a[0]) continue;
        chmax(L, a[0]);
        L -= a[0], R -= a[0];

        ll MI = R, MA = L;
        int cnt = 0;

        for (ll j = i; j * j <= M + R; j++) {
            {
                ll l = j * j - R, r = j * j - L;
                assert(r >= 0);
                chmax(l, 0LL);
                chmin(r, M);
                int t = s[r + 1] - s[l];
                if (t > 0) {
                    cnt += t;
                    chmax(MA, j * j - mi[l]);
                }
            }
            if (j * (j + 1) <= M + R) {
                ll l = j * (j + 1) - R, r = j * (j + 1) - L;
                assert(r >= 0);
                chmax(l, 0LL);
                chmin(r, M);
                int t = s[r + 1] - s[l];
                if (t > 0) {
                    cnt += t;
                    chmin(MI, j * (j + 1) - ma[r + 1]);
                }
            }

            {
                ll l = j * j - L + 1, r = j * (j + 1) - R;
                if (r > l) {
                    chmax(l, 0LL), chmax(r, 0LL);
                    chmin(l, M + 1), chmin(r, M + 1);
                    cnt += s[r] - s[l];
                }
            }
        }

        // cout << i << ' ' << cnt << ' ' << MI << ' ' << MA << '\n';

        if (cnt == N - 1 && MA <= MI) {
            cout << MA << '\n';
            break;
        }
    }
}