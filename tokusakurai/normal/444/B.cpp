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
    ll n, d, x;
    cin >> n >> d >> x;

    vector<ll> a(n + 1), b(n + 1);

    auto getNextX = [&]() {
        x = (x * 37 + 10007) % 1000000007;
        return x;
    };
    auto initAB = [&]() {
        int i;
        for (i = 0; i < n; i = i + 1) { a[i] = i + 1; }
        for (i = 0; i < n; i = i + 1) { swap(a[i], a[getNextX() % (i + 1)]); }
        for (i = 0; i < n; i = i + 1) {
            if (i < d)
                b[i] = 1;
            else
                b[i] = 0;
        }
        for (i = 0; i < n; i = i + 1) { swap(b[i], b[getNextX() % (i + 1)]); }
    };

    initAB();

    int K = 1000;
    if (d <= K) {
        vector<int> ids;
        rep(i, n) {
            if (b[i] == 1) ids.eb(i);
        }
        vector<ll> ans(n, 0);
        rep(i, n) {
            each(e, ids) {
                if (i + e < n) chmax(ans[i + e], a[i]);
            }
        }
        printn(ans);
    } else {
        vector<int> ans(n, 0);
        vector<int> p(n + 1);
        rep(i, n + 1) p[a[i]] = i;

        vector<int> pre(n), nxt(n);
        rep(i, n) pre[i] = i - 1, nxt[i] = i + 1;
        set<int> s;
        rep(i, n) s.emplace(i);
        per2(i, 1, n + 1) {
            auto it = s.lower_bound(p[i]);
            if (it == end(s)) continue;
            int x = *it;
            while (x < n) {
                if (b[x - p[i]] == 1) {
                    ans[x] = i;
                    s.erase(x);
                    int a = pre[x], b = nxt[x];
                    if (a != -1) nxt[a] = b;
                    if (b != n) pre[b] = a;
                }
                x = nxt[x];
            }
        }

        printn(ans);
    }
}