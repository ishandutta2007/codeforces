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

template <typename Operator_Monoid>
struct Dual_Segment_Tree {
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<Operator_Monoid> lazy;
    const H h;
    const Operator_Monoid e2;

    Dual_Segment_Tree(int m, const H &h, const Operator_Monoid &e2) : h(h), e2(e2) {
        n = 1, height = 0;
        while (n < m) n <<= 1, height++;
        lazy.assign(2 * n, e2);
    }

    inline void eval(int i) {
        if (i < n && lazy[i] != e2) {
            lazy[2 * i] = h(lazy[2 * i], lazy[i]);
            lazy[2 * i + 1] = h(lazy[2 * i + 1], lazy[i]);
            lazy[i] = e2;
        }
    }

    inline void thrust(int i) {
        for (int j = height; j > 0; j--) eval(i >> j);
    }

    void apply(int l, int r, const Operator_Monoid &x) {
        l = max(l, 0), r = min(r, n);
        if (l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r - 1);
        while (l < r) {
            if (l & 1) lazy[l] = h(lazy[l], x), l++;
            if (r & 1) r--, lazy[r] = h(lazy[r], x);
            l >>= 1, r >>= 1;
        }
    }

    Operator_Monoid get(int i) {
        thrust(i + n);
        return lazy[i + n];
    }

    Operator_Monoid operator[](int i) { return get(i); }
};

int main() {
    int N;
    ll T;
    cin >> N >> T;

    vector<ll> g(N), c(N), d(N - 1);
    rep(i, N) cin >> g[i] >> c[i];
    rep(i, N - 1) cin >> d[i];

    vector<ll> s(N, 0);
    rep(i, N - 1) s[i + 1] = s[i] + d[i];
    rep(i, N) c[i] = (c[i] + s[i]) % T;

    map<ll, pll> mp;
    mp[0] = pll(0, 0);
    mp[T] = pll(T, T);

    auto get = [&]() {
        if (empty(mp)) return 0LL;
        auto it = begin(mp);
        if (it->second.first == 0) return it->first;
        return 0LL;
    };

    //  [l,r)  x 
    auto update = [&](ll l, ll r, ll x) {
        auto it1 = mp.lower_bound(l);
        auto it2 = mp.lower_bound(r);
        // cout << l MM r MM x MM it1->first MM it2->first << '\n';
        if (it1 == it2) {
            ll L = l, R = r;
            if (it2 != end(mp)) chmin(R, it2->second.first);
            if (L < R) mp[x] = pll(L, R);
        } else {
            it2--;
            ll L = it1->second.first;
            ll R = it2->second.second;
            if (L > 0) {
                it1--;
                if (it1->second.second < L) chmin(L, max(it1->second.second, l));
            }
            if (R < T) {
                it2++;
                if (it2->second.first > R) chmax(R, min(it2->second.first, r));
            }
            auto it = mp.lower_bound(l);
            while (it != end(mp) && it->first < r) it = mp.erase(it);
            mp[x] = pll(L, R);
        }
    };

    rep(i, N) {
        ll x = get();
        ll y = (T + g[i] - c[i]) % T;
        y += T * (x / T);
        if (y < x) y += T;
        if (y + T - g[i] <= x + T) {
            update(y, y + T - g[i] + 1, y + T - g[i]);
        } else {
            update(y, x + T + 1, y + T - g[i]);
            update(x, y - g[i] + 1, y - g[i]);
        }
        if (y == x) update(x + T, x + T + 1, y + 2 * T - g[i]);
        // cout << i << '\n';
        // each(e, mp) cout << e << '\n';
    }

    ll ans = INF;
    each(e, mp) {
        auto [l, r] = e.second;
        if (r > l) chmin(ans, e.first - (r - 1));
    }
    // mp[-INF] = pll(0, 0), mp[INF] = pll(T, T);
    auto it1 = begin(mp), it2 = it1;
    it2++;
    while (it2 != end(mp)) {
        if (it1->second.second < it2->second.first) chmin(ans, 0LL);
        it1++, it2++;
    }
    ans += s[N - 1];
    cout << ans << '\n';
}