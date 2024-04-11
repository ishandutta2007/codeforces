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
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> dp1(H, vector<int>(W, 0)), dp2(H, vector<int>(W, 0));
    vector<vector<int>> c(H, vector<int>(W, 1));
    ll S1 = 0, S2 = 0;

    rep(i, H) {
        rep(j, W) {
            int h = H - i, w = W - j;
            dp1[i][j] = (h < w ? 2 * h : 2 * w - 1);
            dp2[i][j] = (h > w ? 2 * w : 2 * h - 1);
            S1++;
            S2 += dp1[i][j] + dp2[i][j];
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        S1 -= c[x][y];
        c[x][y] ^= 1;
        S1 += c[x][y];

        {
            int px = x, py = y;
            int cnt = c[x][y];
            if (cnt) {
                for (int i = 1;; i++) {
                    (i & 1 ? px : py)++;
                    if (px >= H || py >= W || c[px][py] == 0) break;
                    cnt++;
                }
            }
            // cout << cnt << '\n';

            S2 -= dp2[x][y];
            dp2[x][y] = cnt;
            S2 += dp2[x][y];

            px = x, py = y;
            for (int i = 1;; i++) {
                (i & 1 ? py : px)--;
                if (px < 0 || py < 0 || c[px][py] == 0) break;
                if (i & 1) {
                    S2 -= dp1[px][py];
                    dp1[px][py] = i + cnt;
                    S2 += dp1[px][py];
                } else {
                    S2 -= dp2[px][py];
                    dp2[px][py] = i + cnt;
                    S2 += dp2[px][py];
                }
            }
        }
        {
            int px = x, py = y;
            int cnt = c[x][y];
            if (cnt) {
                for (int i = 1;; i++) {
                    (i & 1 ? py : px)++;
                    if (px >= H || py >= W || c[px][py] == 0) break;
                    cnt++;
                }
            }
            // cout << cnt << '\n';

            S2 -= dp1[x][y];
            dp1[x][y] = cnt;
            S2 += dp1[x][y];

            px = x, py = y;
            for (int i = 1;; i++) {
                (i & 1 ? px : py)--;
                if (px < 0 || py < 0 || c[px][py] == 0) break;
                if (i & 1) {
                    S2 -= dp2[px][py];
                    dp2[px][py] = i + cnt;
                    S2 += dp2[px][py];
                } else {
                    S2 -= dp1[px][py];
                    dp1[px][py] = i + cnt;
                    S2 += dp1[px][py];
                }
            }
        }

        cout << S2 - S1 << '\n';
    }
}