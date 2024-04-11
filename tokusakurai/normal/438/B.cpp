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

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;
    ll sum = 0;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n) {}

    int root(int x) {
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator[](int i) { return root(i); }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        sum += 1LL * (-data[x]) * (-data[y]);
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

int main() {
    int N, M;
    cin >> N >> M;

    int MAX = 100000;
    vector<vector<int>> ids(MAX + 1);
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        ids[a[i]].eb(i);
    }
    Union_Find_Tree uf(N);

    vector<vector<int>> es(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (a[u] > a[v]) swap(u, v);
        es[u].eb(v);
    }

    using ld = long double;
    ld ans = 0;

    per2(i, 1, MAX + 1) {
        each(u, ids[i]) {
            each(e, es[u]) uf.unite(u, e); //
        }
        ans += uf.sum;
    }
    ans *= 2.0;

    ans /= ld(1LL * N * (N - 1));
    cout << ans << '\n';
}