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

vector<vector<int>> es;
vector<vector<ll>> perm;
int N, M, K;

vector<ll> ok;
ll ans = 0;

ll vtoi(const vector<int> &col) {
    ll ret = 0;
    each(e, col) {
        ret *= 6;
        ret += e;
    }
    return ret;
}

void judge(const vector<int> &col) {
    int L = N / 2;
    vector<vector<int>> ids(L);
    rep(i, N) ids[col[i]].eb(i);

    vector<int> v(L);
    iota(all(v), 0);
    do {
        int last = v[L - 1];
        if (es[ids[last][0]][ids[last][1]] == 0) continue;
        int flag = 1;
        rep(i, L - 1) {
            int a = ids[v[i]][0], b = ids[v[i]][1];
            int c = ids[v[i + 1]][0], d = ids[v[i + 1]][1];
            if (!(es[a][c] & es[b][d]) && !(es[a][d] & es[b][c])) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ok.eb(vtoi(col));
            return;
        }
    } while (next_permutation(all(v)));
}

void dfs(vector<int> col, int cnt, int k) {
    if (cnt == N) {
        judge(col);
        return;
    }
    int s = -1;
    rep(i, N) {
        if (col[i] == -1) {
            s = i;
            break;
        }
    }
    col[s] = k;
    rep2(i, s + 1, N - 1) {
        if (col[i] == -1) {
            col[i] = k;
            dfs(col, cnt + 2, k + 1);
            col[i] = -1;
        }
    }
}

int solve(vector<int> col, int k) {
    if (k == N / 2) {
        vector<pii> ps;
        vector<int> pre(N / 2, -1);
        rep(i, N) {
            if (pre[col[i]] != -1) ps.eb(pre[col[i]], i);
            pre[col[i]] = i;
        }
        sort(all(ps));
        rep(i, N / 2) {
            auto [a, b] = ps[i];
            col[a] = i, col[b] = i;
        }
        ll x = vtoi(col);
        int t = lb(ok, x);
        return (t < sz(ok) && ok[t] == x ? 1 : 0);
    }
    vector<int> rem(N / 2, 2);
    rep(i, N) rem[col[i]]--;
    int s = -1, c = -1;
    rep(i, N) {
        if (rem[col[i]] < 0) {
            s = i;
            c = col[i];
            break;
        }
    }
    rep(i, N) {
        if (col[i] >= c) col[i]++;
    }
    col[s]--;
    rep2(i, s + 1, N - 1) {
        if (col[i] == c + 1) {
            col[i]--;
            int x = solve(col, k + 1);
            if (x == 1) return 1;
            col[i]++;
        }
    }
    return 0;
}

// 
void rec(vector<int> col, int cnt, int k) {
    if (cnt == N) {
        int x = solve(col, k);
        ans += x * perm[K][k];
    }
    vector<int> rem;
    rep(i, N) {
        if (col[i] == -1) rem.eb(i);
    }
    int K = sz(rem);
    rep(i, 1 << K) {
        if (!(i & 1)) continue;
        int c = __builtin_popcount(i);
        if (c & 1) continue;
        rep(t, K) {
            if (flg(i, t)) col[rem[t]] = k;
        }
        rec(col, cnt + c, k + 1);
        rep(t, K) col[rem[t]] = -1;
    }
}

int main() {
    cin >> N >> M >> K;

    rep(i, N) es.eb(N, 0);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es[u][v] = 1, es[v][u] = 1;
    }

    perm.assign(13, vector<ll>(13, 1));
    rep2(i, 0, 12) {
        rep2(j, 0, 12) {
            rep(k, j) {
                perm[i][j] *= i - k; //
            }
        }
    }

    vector<int> col(N, -1);
    dfs(col, 0, 0);
    sort(all(ok));

    rec(col, 0, 0);
    cout << ans << '\n';
}