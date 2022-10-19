#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

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
// const int MOD = 1000000007;
const int MOD = 998244353;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> c(H, vector<int>(W, 0));
    rep(i, H) {
        rep(j, W) {
            cin >> c[i][j];
            c[i][j] ^= 1;
        }
    }

    vector<vector<int>> sx = c;
    vector<vector<int>> sy(W, vector<int>(H));
    rep(i, H) rep(j, W) sy[j][i] = c[i][j];

    rep(i, H) {
        rep(j, W) {
            if (j > 0) sx[i][j] += sx[i][j - 1];
        }
    }
    rep(j, W) {
        rep(i, H) {
            if (i > 0) sy[j][i] += sy[j][i - 1];
        }
    }

    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;

        if (t == 1) {
            c[x][y] ^= 1;
            rep(j, W) sx[x][j] = c[x][j];
            rep(j, W) if (j > 0) sx[x][j] += sx[x][j - 1];
            rep(i, H) sy[y][i] = c[i][y];
            rep(i, H) if (i > 0) sy[y][i] += sy[y][i - 1];
        } else {
            if (c[x][y] == 1) {
                cout << "0\n";
                continue;
            }
            int ans = 0;
            {
                int ly = 0, ry = W;
                rep2(i, x, H) {
                    if (c[i][y] == 1) break;
                    int l = lb(sx[i], sx[i][y]);
                    int r = ub(sx[i], sx[i][y]);
                    if (sx[i][y] != 0) l++;
                    chmax(ly, l), chmin(ry, r);
                    chmax(ans, (ry - ly) * (i - x + 1));
                }
            }
            {
                int ly = 0, ry = W;
                per2(i, 0, x + 1) {
                    if (c[i][y] == 1) break;
                    int l = lb(sx[i], sx[i][y]);
                    int r = ub(sx[i], sx[i][y]);
                    if (sx[i][y] != 0) l++;
                    chmax(ly, l), chmin(ry, r);
                    chmax(ans, (ry - ly) * (x - i + 1));
                }
            }
            {
                int lx = 0, rx = H;
                rep2(j, y, W) {
                    if (c[x][j] == 1) break;
                    int l = lb(sy[j], sy[j][x]);
                    int r = ub(sy[j], sy[j][x]);
                    if (sy[j][x] != 0) l++;
                    chmax(lx, l), chmin(rx, r);
                    chmax(ans, (rx - lx) * (j - y + 1));
                }
            }
            {
                int lx = 0, rx = H;
                per2(j, 0, y + 1) {
                    if (c[x][j] == 1) break;
                    int l = lb(sy[j], sy[j][x]);
                    int r = ub(sy[j], sy[j][x]);
                    if (sy[j][x] != 0) l++;
                    chmax(lx, l), chmin(rx, r);
                    chmax(ans, (rx - lx) * (y - j + 1));
                }
            }
            cout << ans << '\n';
        }
    }
}