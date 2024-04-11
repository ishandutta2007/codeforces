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

int mex(vector<int> v) {
    int n = sz(v);
    vector<int> cnt(n, 0);
    each(e, v) {
        if (e < n) cnt[e]++;
    }
    rep(i, n) {
        if (cnt[i] == 0) return i;
    }
    return n;
}

void experiment() {
    int N;
    cin >> N;
    vector<int> dp(N + 1), dp2(N + 1, 0);
    dp[0] = 0, dp[1] = 0;
    dp2[0] = 0, dp2[1] = 0;
    rep2(i, 2, N) {
        vector<int> v, v2;
        rep2(j, 0, i - 2) v.eb(dp[j] ^ dp[i - 2 - j]);
        rep2(j, 0, min(i - 2, 100)) v2.eb(dp2[j] ^ dp2[i - 2 - j]);
        dp[i] = mex(v);
        dp2[i] = mex(v);
    }
    // print(dp);
    // print(dp2);
    rep(i, N + 1) {
        if (dp[i] != dp2[i]) cout << i << '\n';
    }
    // cout << *max_element(all(dp)) << '\n';
}

int main() {
    // experiment();
    int T;
    cin >> T;

    int K = 500000;
    vector<int> dp(K + 1, 0);
    rep2(i, 2, K) {
        vector<int> v;
        rep2(j, 0, min(i - 2, 100)) v.eb(dp[j] ^ dp[i - 2 - j]);
        dp[i] = mex(v);
    }

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int X = 0, Y = 0;
        rep(i, N) {
            if (S[i] == 'R') X++;
            if (S[i] == 'B') Y++;
        }

        if (X > Y) {
            cout << "Alice\n";
            continue;
        }
        if (X < Y) {
            cout << "Bob\n";
            continue;
        }

        int g = 0;
        for (int i = 0; i < N;) {
            int j = 1;
            while (i + j < N && S[i + j] != S[i + j - 1]) j++;
            g ^= dp[j];
            i += j;
        }

        cout << (g == 0 ? "Bob\n" : "Alice\n");
    }
}