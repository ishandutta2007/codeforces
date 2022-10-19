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
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
        bit.resize(n + 1);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] = bit[b] + bit[b - a / 2];
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : Binary_Indexed_Tree(vector<T>(n, x)) {}

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i)) bit[i] = bit[i] + x;
    }

    void change(int i, const T &x) { add(i, x - query(i, i + 1)); }

    T sum(int i) const {
        i = min(i, n);
        T ret = pll(0, 0);
        for (; i > 0; i -= (i & -i)) ret = ret + bit[i];
        return ret;
    }

    T query(int l, int r) const {
        // if (l >= r) return 0;
        return sum(r) - sum(l);
    }

    T operator[](int i) const { return query(i, i + 1); }

    // v[0]+...+v[r] >= x  r ( n)
    int lower_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x) x = x - bit[ret += (1 << k)];
        }
        return ret;
    }

    // v[0]+...+v[r] > x  r ( n)
    int upper_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x) x = x - bit[ret += (1 << k)];
        }
        return ret;
    }
};

int main() {
    int N;
    cin >> N;

    vector<ll> a(N), b(N), d(N);
    rep(i, N) cin >> a[i] >> b[i] >> d[i];

    vector<tuple<ll, int, int, int>> q1, q2;

    int Q;
    cin >> Q;

    map<int, ll> mp;
    mp[0] = -1, mp[N] = -1;

    rep(i, Q) {
        ll t;
        int l, r;
        cin >> t >> l >> r;
        l--;
        ll memo;
        auto it = mp.upper_bound(l);
        --it;
        for (; it != end(mp) && it->first <= r;) {
            auto it2 = it;
            ++it2;
            ll s = it->second;
            // cout << i MM it->first MM it2->first << '\n';
            if (it2 != end(mp)) {
                if (s == -1) {
                    q1.eb(t, max(l, it->first), min(r, it2->first), i);
                } else {
                    q2.eb(t - s, max(l, it->first), min(r, it2->first), i);
                }
            }
            memo = s;
            if (it->first < l) {
                it++;
            } else {
                it = mp.erase(it);
            }
        }
        mp[l] = t, mp[r] = memo;
    }

    vector<ll> t1(N), t2(N);
    rep(i, N) {
        if (d[i] == 0) {
            t1[i] = INF, t2[i] = INF;
        } else {
            t1[i] = (b[i] - a[i]) / d[i] + 1;
            t2[i] = b[i] / d[i] + 1;
        }
    }
    vector<int> u1 = id_sort(t1), u2 = id_sort(t2);
    int p1 = 0, p2 = 0;

    vector<pll> v1(N), v2(N);
    rep(i, N) {
        v1[i] = pll(a[i], d[i]);
        v2[i] = pll(0, d[i]);
    }
    Binary_Indexed_Tree<pll> b1(v1), b2(v2);

    vector<ll> ans(Q);

    sort(all(q1));
    each(e, q1) {
        auto [t, l, r, id] = e;
        while (p1 < N && t1[u1[p1]] <= t) {
            int i = u1[p1];
            b1.change(i, pll(b[i], 0));
            p1++;
        }
        auto [x, y] = b1.query(l, r);
        ans[id] += x + y * t;
    }

    sort(all(q2));
    each(e, q2) {
        auto [t, l, r, id] = e;
        while (p2 < N && t2[u2[p2]] <= t) {
            int i = u2[p2];
            b2.change(i, pll(b[i], 0));
            p2++;
        }
        auto [x, y] = b2.query(l, r);
        ans[id] += x + y * t;
    }

    printn(ans);
}