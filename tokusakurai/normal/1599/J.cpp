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

    vector<int> B(N);
    rep(i, N) cin >> B[i];

    if (N == 2) {
        if (B[0] == B[1]) {
            cout << "YES\n";
            cout << 0 << ' ' << B[0] << '\n';
        } else {
            cout << "NO\n";
        }
        return 0;
    }

    vector<int> ids1, ids2;
    vector<int> A(N, -inf);
    int x = -1;

    rep(i, N) {
        if (B[i] % 2 == 1) {
            ids1.eb(i);
        } else {
            ids2.eb(i);
        }
    }

    if (sz(ids2) >= 3) {
        int i = ids2[0], j = ids2[1], k = ids2[2];
        A[i] = (-B[i] + B[j] + B[k]) / 2;
        A[j] = (B[i] - B[j] + B[k]) / 2;
        A[k] = (B[i] + B[j] - B[k]) / 2;
        x = i;
    } else if (sz(ids2) >= 1 && sz(ids1) >= 2) {
        int i = ids2[0], j = ids1[0], k = ids1[1];
        A[i] = (-B[i] + B[j] + B[k]) / 2;
        A[j] = (B[i] - B[j] + B[k]) / 2;
        A[k] = (B[i] + B[j] - B[k]) / 2;
        x = i;
    } else {
        int K = min(N, 27);
        int L = K / 2;
        int MAX = 1000000;
        vector<int> memo(L * MAX + 1, -1);
        rep(i, 1 << K) {
            if (__builtin_popcount(i) != L) continue;
            int S = 0;
            rep(j, K) {
                if (flg(i, j)) S += B[j];
            }
            if (memo[S] == -1) {
                memo[S] = i;
            } else {
                int j = memo[S];
                int k = i & j;
                i &= ~k, j &= ~k;
                vector<int> v1, v2;
                rep(t, K) {
                    if (flg(i, t)) v1.eb(t);
                    if (flg(j, t)) v2.eb(t);
                }
                vector<int> v;
                rep(t, sz(v1)) {
                    v.eb(v1[t]);
                    v.eb(v2[t]);
                }
                int M = sz(v);
                A[v[0]] = 0;
                rep2(t, 1, M - 1) A[v[t]] = B[v[t - 1]] - A[v[t - 1]];
                assert(A[v[M - 1]] + A[v[0]] == B[v[M - 1]]);
                x = v[0];
                break;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        rep(i, N) {
            if (A[i] == -inf) A[i] = B[i] - A[x];
        }
        print(A);
    }
}