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
    int N, M;
    cin >> N >> M;

    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> s(N, M), t(N, M);
    vector<vector<pii>> ps(N);
    int D = 500;
    vector<int> ans(M, 0);
    vector<vector<int>> c(D + 1, vector<int>(D + 1, 0));

    int S = 0;

    rep(i, M) {
        int q, k;
        cin >> q >> k;
        k--;
        if (q == 1) s[k] = i, ps[k].eb(i, M);
        if (q == 2) t[k] = i, ps[k].back().second = i;
        int A = x[k] + y[k];

        if (A <= D) {
            if (q == 1) {
                S++;
                c[A][i % A]--;
                c[A][(i + x[k]) % A]++;
            } else {
                int D = (i - s[k] - 1) % A;
                if (D >= x[k]) S--;
                c[A][s[k] % A]++;
                c[A][(s[k] + x[k]) % A]--;
            }
        }

        rep2(j, 1, D) S += c[j][i % j];
        ans[i] += S;
    }

    vector<int> d(M, 0);

    rep(i, N) {
        if (x[i] + y[i] > D) {
            each(e, ps[i]) {
                auto [l, r] = e;
                for (int j = l; j < r; j += x[i] + y[i]) {
                    if (j + x[i] < r) d[j + x[i]]++;
                    if (j + x[i] + y[i] < r) d[j + x[i] + y[i]]--;
                }
                if (r < M) {
                    int D = (r - 1 - l) % (x[i] + y[i]);
                    if (D >= x[i]) d[r]--;
                }
            }
        }
    }

    // print(d);
    rep2(i, 1, M - 1) d[i] += d[i - 1];
    rep(i, M) ans[i] += d[i];
    printn(ans);
}