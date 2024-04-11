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

struct Runtime_Mod_Int {
    int x;

    Runtime_Mod_Int() : x(0) {}

    Runtime_Mod_Int(long long y) {
        x = y % get_mod();
        if (x < 0) x += get_mod();
    }

    static inline int &get_mod() {
        static int mod = 0;
        return mod;
    }

    static void set_mod(int md) { get_mod() = md; }

    Runtime_Mod_Int &operator+=(const Runtime_Mod_Int &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator-=(const Runtime_Mod_Int &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator*=(const Runtime_Mod_Int &p) {
        x = (int)(1LL * x * p.x % get_mod());
        return *this;
    }

    Runtime_Mod_Int &operator/=(const Runtime_Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Runtime_Mod_Int &operator++() { return *this += Runtime_Mod_Int(1); }

    Runtime_Mod_Int operator++(int) {
        Runtime_Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Runtime_Mod_Int &operator--() { return *this -= Runtime_Mod_Int(1); }

    Runtime_Mod_Int operator--(int) {
        Runtime_Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Runtime_Mod_Int operator-() const { return Runtime_Mod_Int(-x); }

    Runtime_Mod_Int operator+(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) += p; }

    Runtime_Mod_Int operator-(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) -= p; }

    Runtime_Mod_Int operator*(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) *= p; }

    Runtime_Mod_Int operator/(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) /= p; }

    bool operator==(const Runtime_Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Runtime_Mod_Int &p) const { return x != p.x; }

    Runtime_Mod_Int inverse() const {
        assert(*this != Runtime_Mod_Int(0));
        return pow(get_mod() - 2);
    }

    Runtime_Mod_Int pow(long long k) const {
        Runtime_Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Runtime_Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Runtime_Mod_Int &p) {
        long long a;
        is >> a;
        p = Runtime_Mod_Int(a);
        return is;
    }
};

using mint = Runtime_Mod_Int;
/*
if (used[i][j][k]) return dp[i][j][k];
used[i][j][k] = true;
dp[i][j][k] = 0;
if (i == 0) {
    if (k == 0) dp[i][j][k] = 1;
    return dp[i][j][k];
}
if (j == 0) {
    if (k == 0) dp[i][j][k] = fac[i];
    return dp[i][j][k];
}
rep2(l, 0, i - 1) {
    int r = i - 1 - l;
    int nk = k - (j == 1 ? 1 : 0);
    rep2(m, 0, nk) { dp[i][j][k] += dp[l][j - 1][m] * dp[r][j - 1][nk - m] * comb[i - 1][l]; }
}
return dp[i][j][k];
*/

int main() {
    int N, M, K, P;
    cin >> N >> M >> K >> P;

    mint::set_mod(P);

    if (M + K > N + 1) {
        cout << "0\n";
        return 0;
    }

    vector<vector<mint>> comb(N + 1, vector<mint>(N + 1, 0));
    vector<mint> fac(N + 1, 1);
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(M + 1, vector<mint>(K + 1, 0)));

    comb[0][0] = 1;
    rep(i, N) {
        rep(j, i + 1) {
            comb[i + 1][j] += comb[i][j];
            comb[i + 1][j + 1] += comb[i][j];
        }
    }

    rep(i, N) fac[i + 1] = fac[i] * (i + 1);

    rep2(i, 0, N) {
        rep2(j, 0, M) {
            rep2(k, 0, min(i, K)) {
                if (i == 0) {
                    if (k == 0) dp[i][j][k] = 1;
                    continue;
                }
                if (j == 0 || i < j) {
                    if (k == 0) dp[i][j][k] = fac[i];
                    continue;
                }
                if (j + k > i + 1) continue;
                rep2(l, 0, i - 1) {
                    int r = i - 1 - l;
                    int nk = k - (j == 1 ? 1 : 0);
                    int L = max(nk - r, 0), R = min(l, nk);
                    rep2(m, L, R) {
                        // if (m > l || nk - m > r) continue;
                        dp[i][j][k] += dp[l][j - 1][m] * dp[r][j - 1][nk - m] * comb[i - 1][l];
                    }
                }
            }
        }
    }

    cout << dp[N][M][K] << '\n';
}