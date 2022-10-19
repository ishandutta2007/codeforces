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
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        vector<vector<int>> ids(N);

        rep(i, N) {
            cin >> a[i];
            ids[--a[i]].eb(i);
        }

        vector<int> ptr(N);
        rep(i, N) ptr[i] = lb(ids[a[i]], i);

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        rep2(i, 0, N) {
            rep2(j, 0, N - i) {
                int l = j, r = j + i;
                if (i == 0) {
                    dp[l][r] = 0;
                    continue;
                }
                chmax(dp[l][r], dp[l + 1][r]), chmax(dp[l][r], dp[l][r - 1]);
                if (i >= 2 && a[l] == a[r - 1]) chmax(dp[l][r], dp[l + 1][r - 1] + 1);
                for (int k = ptr[l] + 1; k < sz(ids[a[l]]) && ids[a[l]][k] < r; k++) {
                    int m = ids[a[l]][k];
                    chmax(dp[l][r], dp[l][m + 1] + dp[m][r]);
                }
                for (int k = ptr[r - 1] - 1; k >= 0 && ids[a[r - 1]][k] >= l; k--) {
                    int m = ids[a[r - 1]][k];
                    chmax(dp[l][r], dp[l][m + 1] + dp[m][r]);
                }
            }
        }

        cout << N - 1 - dp[0][N] << '\n';
    }
}