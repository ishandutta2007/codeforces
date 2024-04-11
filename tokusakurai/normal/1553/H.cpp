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
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp1(K + 1, vector<int>(1 << K, inf));
    vector<vector<int>> dp2(K + 1, vector<int>(1 << K, -inf));
    vector<vector<int>> dp3(K + 1, vector<int>(1 << K, inf));

    rep(i, N) {
        int x;
        cin >> x;
        dp1[0][x] = 0;
        dp2[0][x] = 0;
    }

    rep(i, K) {
        rep(j, 1 << K) {
            int l = j, r = j ^ (1 << i);
            dp1[i + 1][j] = min(dp1[i][l], dp1[i][r] + (1 << i));
            dp2[i + 1][j] = max(dp2[i][l], dp2[i][r] + (1 << i));
            dp3[i + 1][j] = min(dp3[i][l], dp3[i][r]);
            if (dp2[i][l] != -inf && dp1[i][r] != inf) {
                int x = dp1[i][r] - dp2[i][l] + (1 << i);
                chmin(dp3[i + 1][j], x);
            }
        }
    }

    print(dp3[K]);
}