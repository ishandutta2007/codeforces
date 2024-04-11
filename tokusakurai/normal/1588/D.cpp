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
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> S(N);
        rep(i, N) cin >> S[i];

        vector<vector<vector<int>>> ids(52, vector<vector<int>>(N));

        rep(i, N) {
            rep(j, sz(S[i])) {
                char c = S[i][j];
                int x = (c >= 'a' && c <= 'z' ? c - 'a' : 26 + c - 'A');
                ids[x][i].eb(j);
            }
        }

        rep(i, 52) {
            rep(j, N) {
                while (sz(ids[i][j]) < 2) ids[i][j].eb(inf);
            }
        }

        vector<vector<int>> dp(52, vector<int>(1 << N, 0));
        vector<vector<pii>> pre(52, vector<pii>(1 << N, pii(-1, -1)));

        vector<pii> ps;
        rep(i, 52) rep(j, 1 << N) ps.eb(i, j);
        sort(all(ps), [&](pii p, pii q) { return ids[p.first][0][flg(p.second, 0)] < ids[q.first][0][flg(q.second, 0)]; });

        each(e, ps) {
            auto [i, j] = e;
            vector<int> p(N);
            bool flag = true;

            rep(k, N) {
                p[k] = ids[i][k][flg(j, k)];
                if (p[k] == inf) flag = false;
            }

            if (!flag) continue;
            dp[i][j] = 1;

            rep(k, 52) {
                int t = 0;
                rep(l, N) {
                    if (p[l] <= ids[k][l][0]) {
                        t = -1;
                        break;
                    }
                    if (p[l] > ids[k][l][1]) t |= (1 << l);
                }
                if (t != -1) {
                    if (chmax(dp[i][j], dp[k][t] + 1)) pre[i][j] = pii(k, t);
                }
            }
        }

        int si = -1, sj = -1;
        int mx = -inf;

        rep(i, 52) {
            rep(j, 1 << N) {
                if (chmax(mx, dp[i][j])) si = i, sj = j;
            }
        }

        cout << mx << '\n';

        string ans;
        while (dp[si][sj] > 0) {
            ans += (si < 26 ? char('a' + si) : char('A' + si - 26));
            tie(si, sj) = pre[si][sj];
            if (si == -1) break;
        }

        reverse(all(ans));
        cout << ans << '\n';
    }
}