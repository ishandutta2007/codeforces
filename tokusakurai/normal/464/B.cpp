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

template <typename T>
vector<T> operator+(const vector<T> &a, const vector<T> &b) {
    int n = sz(a);
    vector<T> c(n);
    rep(i, n) c[i] = a[i] + b[i];
    return c;
}

template <typename T>
vector<T> operator-(const vector<T> &a, const vector<T> &b) {
    int n = sz(a);
    vector<T> c(n);
    rep(i, n) c[i] = a[i] - b[i];
    return c;
}

ll dot(const vector<ll> &a, const vector<ll> &b) {
    ll ret = 0;
    rep(i, 3) ret += a[i] * b[i];
    return ret;
}

bool solve(const vector<vector<ll>> &a) {
    set<vector<ll>> s;
    rep(i, 8) s.emplace(a[i]);
    rep2(i, 1, 8) rep2(j, i + 1, 8) rep2(k, j + 1, 8) {
        vector<vector<ll>> d(3);
        d[0] = a[i] - a[0];
        d[1] = a[j] - a[0];
        d[2] = a[k] - a[0];
        bool flag = true;
        rep(I, 3) rep(J, I) {
            if (dot(d[I], d[J]) != 0) {
                flag = false;
                break;
            }
        }
        ll tmp = dot(d[0], d[0]);
        if (tmp == 0) continue;
        if (dot(d[1], d[1]) != tmp) flag = false;
        if (dot(d[2], d[2]) != tmp) flag = false;
        if (!flag) continue;
        if (!s.count(a[0] + d[0] + d[1])) flag = false;
        if (!s.count(a[0] + d[1] + d[2])) flag = false;
        if (!s.count(a[0] + d[2] + d[0])) flag = false;
        if (!s.count(a[0] + d[0] + d[1] + d[2])) flag = false;
        if (flag) return true;
    }
    return false;
}

int main() {
    vector<vector<ll>> a(8, vector<ll>(3));
    rep(i, 8) rep(j, 3) cin >> a[i][j];
    rep(i, 8) sort(all(a[i]));

    vector<int> v(3);
    iota(all(v), 0);
    vector<vector<int>> ss;
    do { ss.eb(v); } while (next_permutation(all(v)));
    // each(e, ss) print(e);

    vector<int> pw(8, 1);
    rep(i, 7) pw[i + 1] = pw[i] * 6;

    rep2(ii, 1, 8) rep2(jj, ii + 1, 8) rep2(kk, jj + 1, 8) {
        map<vector<ll>, int> s;
        rep2(i, 1, 8) {
            if (i != ii && i != jj && i != kk) s[a[i]]++;
        }
        vector<int> u = {ii, jj, kk};
        vector<vector<ll>> d(3, vector<ll>(3));
        rep(t, pw[3]) {
            int x = t;
            rep(i, 3) {
                int y = x % 6;
                x /= 6;
                rep(j, 3) d[i][j] = a[u[i]][ss[y][j]];
                d[i] = d[i] - a[0];
            }
            bool flag = true;
            rep(i, 3) rep(j, i) {
                if (dot(d[i], d[j]) != 0) {
                    flag = false;
                    break;
                }
            }
            ll tmp = dot(d[0], d[0]);
            if (tmp == 0) continue;
            if (dot(d[1], d[1]) != tmp) flag = false;
            if (dot(d[2], d[2]) != tmp) flag = false;
            if (!flag) continue;
            vector<vector<ll>> c(4);
            c[0] = a[0] + d[0] + d[1];
            c[1] = a[0] + d[1] + d[2];
            c[2] = a[0] + d[2] + d[0];
            c[3] = a[0] + d[0] + d[1] + d[2];
            map<vector<ll>, int> mp;
            rep(i, 4) {
                auto tmp = c[i];
                sort(all(tmp));
                mp[tmp]++;
            }
            each(e, mp) {
                if (!s.count(e.first) || s[e.first] != e.second) flag = false;
            }
            if (flag) {
                cout << "YES\n";
                vector<vector<ll>> ans;
                ans.eb(a[0]);
                rep(i, 3) ans.eb(a[0] + d[i]);
                rep(i, 4) ans.eb(c[i]);
                vector<bool> used(8, false);
                rep(i, 8) {
                    rep(j, 8) {
                        if (used[j]) continue;
                        auto tmp = ans[j];
                        sort(all(tmp));
                        if (tmp == a[i]) {
                            print(ans[j]);
                            used[j] = true;
                            break;
                        }
                    }
                }
                return 0;
            }
        }
    }

    cout << "NO\n";
}