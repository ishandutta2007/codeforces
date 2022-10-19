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

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n) {}

    int root(int x) {
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator[](int i) { return root(i); }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        cnt--;
        return true;
    }

    int size(int x) { return -data[root(x)]; }

    int count() { return cnt; };

    bool same(int x, int y) { return root(x) == root(y); }

    void clear() {
        cnt = n;
        fill(begin(data), end(data), -1);
    }
};

template <typename T>
vector<T> divisors(const T &n) {
    vector<T> ret;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}

template <typename T>
vector<pair<T, int>> prime_factor(T n) {
    vector<pair<T, int>> ret;
    for (T i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) cnt++, n /= i;
        if (cnt > 0) ret.emplace_back(i, cnt);
    }
    if (n > 1) ret.emplace_back(n, 1);
    return ret;
}

template <typename T>
bool is_prime(const T &n) {
    if (n == 1) return false;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 1,2,...,nk
template <typename T>
T coprime(T n, T k) {
    vector<pair<T, int>> ps = prime_factor(k);
    int m = ps.size();
    T ret = 0;
    for (int i = 0; i < (1 << m); i++) {
        T prd = 1;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) prd *= ps[j].first;
        }
        ret += (__builtin_parity(i) ? -1 : 1) * (n / prd);
    }
    return ret;
}

vector<bool> Eratosthenes(const int &n) {
    vector<bool> ret(n + 1, true);
    if (n >= 0) ret[0] = false;
    if (n >= 1) ret[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!ret[i]) continue;
        for (int j = i + i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}

vector<int> Eratosthenes2(const int &n) {
    vector<int> ret(n + 1);
    iota(begin(ret), end(ret), 0);
    if (n >= 0) ret[0] = -1;
    if (n >= 1) ret[1] = -1;
    for (int i = 2; i * i <= n; i++) {
        if (ret[i] < i) continue;
        for (int j = i + i; j <= n; j += i) ret[j] = min(ret[j], i);
    }
    return ret;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    int M = 1000001;
    vector<int> id(M + 1, -1);

    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        id[a[i]] = i;
    }

    Union_Find_Tree uf(N);

    vector<int> memo(M + 1, -1);
    vector<int> p = Eratosthenes2(M);
    // rep(i, 10) cout << p[i] << ' ';
    // cout << '\n';

    rep2(i, 2, M) {
        if (p[i] != i) continue;

        vector<int> ids;
        for (int j = i; j <= M; j += i) {
            if (id[j] != -1) ids.eb(id[j]);
        }

        if (!empty(ids)) {
            memo[i] = ids.front();
            rep(j, sz(ids) - 1) uf.unite(ids[j], ids[j + 1]);
        }
    }

    vector<int> p_id(M + 1, -1);

    rep2(i, 2, M) {
        if (memo[i] != -1) {
            int r = uf[memo[i]];
            p_id[i] = r;
        }
    }
    // rep(i, 10) cout << p_id[i] << (i == 9 ? '\n' : ' ');

    vector<set<int>> es(N);

    rep(i, N) {
        int r = uf[i];
        int ptr = a[i] + 1;

        vector<int> tmp;
        int pre = -1;

        while (ptr > 1) {
            int t = p[ptr];
            if (t != pre) {
                if (p_id[t] != -1) es[r].emplace(p_id[t]);
                tmp.eb(t);
            }
            ptr /= t;
            pre = t;
        }

        int K = sz(tmp);
        rep(i, K) {
            rep(j, i) {
                if (p_id[tmp[i]] != -1 && p_id[tmp[j]] != -1) {
                    if (p_id[tmp[i]] != p_id[tmp[j]]) es[p_id[tmp[i]]].emplace(p_id[tmp[j]]);
                }
            }
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u = uf[u], v = uf[v];
        if (u == v) {
            cout << "0\n";
        } else if (p_id[2] == u || p_id[2] == v) {
            cout << "1\n";
        } else if (es[u].count(v) || es[v].count(u)) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}