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
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<int> c(W, 0);
    /*
    vector<string> T(H, string(W, 'N'));
    queue<pii> que;
    rep(i, H) {
        if (S[i][0] == '.') que.emplace(i, 0);
    }
    rep(j, W) {
        if (S[0][j] == '.') que.emplace(0, j);
    }

    while (!empty(que)) {
        auto [x, y] = que.front();
        que.pop();
        if (T[x][y] == 'Y') continue;
        T[x][y] = 'Y';
        if (x < H - 1 && S[x + 1][y] == '.') { que.emplace(x + 1, y); }
        if (y < W - 1 && S[x][y + 1] == '.') { que.emplace(x, y + 1); }
    }
    */

    rep(i, H - 1) {
        rep(j, W - 1) {
            if (S[i][j + 1] == 'X' && S[i + 1][j] == 'X') c[j]++;
        }
    }

    vector<int> s(W + 1, 0);
    rep(i, W) s[i + 1] = s[i] + c[i];

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << (s[r - 1] - s[l] ? "NO\n" : "YES\n");
    }
}