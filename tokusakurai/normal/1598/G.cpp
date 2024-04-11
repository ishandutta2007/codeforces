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

// 1,2,...,nk
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

template <typename T>
vector<int> z_algorithm(const T &s) {
    int n = s.size();
    vector<int> ret(n);
    ret[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) j++;
        ret[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + ret[k] < j) ret[i + k] = ret[k], k++;
        i += k, j -= k;
    }
    return ret;
}

int main() {
    string S, T;
    cin >> S >> T;
    int N = sz(S), M = sz(T);

    vector<ll> mods;
    int L = 20;
    rep(i, L) {
        while (true) {
            ll x = rng(100000000, 1000000000);
            if (is_prime(x)) {
                mods.eb(x);
                break;
            }
        }
    }

    vector<vector<ll>> s(L, vector<ll>(N + 1, 0));
    vector<vector<ll>> pw(L, vector<ll>(N + 1, 1));
    vector<ll> ans(L, 0);

    rep(i, L) {
        rep(j, N) {
            s[i][j + 1] = s[i][j] * 10 + (S[j] - '0');
            s[i][j + 1] %= mods[i];
            pw[i][j + 1] = pw[i][j] * 10;
            pw[i][j + 1] %= mods[i];
        }
        rep(j, M) {
            ans[i] = ans[i] * 10 + (T[j] - '0');
            ans[i] %= mods[i];
        }
    }

    auto judge = [&](int l, int m, int r) {
        rep(i, L) {
            ll a = s[i][m] + (mods[i] - s[i][l]) * pw[i][m - l];
            ll b = s[i][r] + (mods[i] - s[i][m]) * pw[i][r - m];
            ll c = (a + b) % mods[i];
            if (c != ans[i]) return false;
        }
        return true;
    };

    //  M-1 
    rep(i, N + 1) {
        if (i + 2 * (M - 1) > N) break;
        if (judge(i, i + M - 1, i + 2 * (M - 1))) {
            cout << i + 1 << ' ' << i + M - 1 << '\n';
            cout << i + M << ' ' << i + 2 * (M - 1) << '\n';
            return 0;
        }
    }

    vector<int> v = z_algorithm(T + S);

    //  M
    rep(i, N + 1) {
        int x = v[M + i];
        if (x >= M) continue;
        rep2(j, M - x - 1, M - x) {
            if (i + M + j > N) break;
            if (judge(i, i + M, i + M + j)) {
                cout << i + 1 << ' ' << i + M << '\n';
                cout << i + M + 1 << ' ' << i + M + j << '\n';
                return 0;
            }
        }
    }

    //  M
    rep(i, N + 1) {
        int x = v[M + i];
        if (x >= M) continue;
        rep2(j, M - x - 1, M - x) {
            if (i + M > N || i - j < 0) break;
            if (judge(i - j, i, i + M)) {
                cout << i - j + 1 << ' ' << i << '\n';
                cout << i + 1 << ' ' << i + M << '\n';
                return 0;
            }
        }
    }
}