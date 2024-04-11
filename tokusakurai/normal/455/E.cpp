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

template <typename T, T min_x, T max_x, bool is_min = true>
struct Li_Chao_Tree {
    struct Line {
        T a, b;

        Line(const T &a, const T &b) : a(a), b(b) {}

        T get(const T &x) const { return a * x + b; }
    };

    struct Node {
        Node *lch, *rch;
        Line l;

        Node(const Line &l) : lch(NULL), rch(NULL), l(l) {}

        Node(const T &a, const T &b) : lch(NULL), rch(NULL), l(a, b) {}
    };

    Node *root;
    const T INF_T = numeric_limits<T>::max() / 2;

    Li_Chao_Tree() : root(NULL) {}

    ~Li_Chao_Tree() { rec_delete(root); }

    void rec_delete(Node *now) {
        if (!now) return;
        rec_delete(now->lch), rec_delete(now->rch);
        delete now;
    }

    Node *add_line(const Line &k, Node *now, const T &l, const T &r) {
        if (!now) return new Node(k);
        T l1 = now->l.get(l), l2 = k.get(l);
        T r1 = now->l.get(r), r2 = k.get(r);
        if (l1 <= l2 && r1 <= r2) return now;
        if (l1 >= l2 && r1 >= r2) {
            now->l = k;
            return now;
        }
        T m = (l + r - 1) / 2;
        T m1 = now->l.get(m), m2 = k.get(m);
        if (m1 > m2) {
            if (l1 <= l2) {
                now->lch = add_line(now->l, now->lch, l, m);
            } else {
                now->rch = add_line(now->l, now->rch, m + 1, r);
            }
            now->l = k;
        } else {
            if (l1 >= l2) {
                now->lch = add_line(k, now->lch, l, m);
            } else {
                now->rch = add_line(k, now->rch, m + 1, r);
            }
        }
        return now;
    }

    //  y = ax+b 
    void add_line(const T &a, const T &b) {
        Line k(is_min ? a : -a, is_min ? b : -b);
        root = add_line(k, root, min_x, max_x);
    }

    Node *add_segment(const T &s, const T &t, const Line &k, Node *now, const T &l, const T &r) {
        if (r < s || t < l) return now;
        if (s <= l && r <= t) return add_line(k, now, l, r);
        T m = (l + r - 1) / 2;
        if (!now) now = new Node(0, INF_T);
        now->lch = add_segment(s, t, k, now->lch, l, m);
        now->rch = add_segment(s, t, k, now->rch, m + 1, r);
        return now;
    }

    // [l,r)  y = ax+b 
    void add_segment(const T &l, const T &r, const T &a, const T &b) {
        Line k(is_min ? a : -a, is_min ? b : -b);
        root = add_segment(l, r - 1, k, root, min_x, max_x);
    }

    T query(const T &x, Node *now, const T &l, const T &r) const {
        if (!now) return INF_T;
        if (l == r) return now->l.get(x);
        T m = (l + r - 1) / 2;
        if (x <= m) return min(now->l.get(x), query(x, now->lch, l, m));
        return min(now->l.get(x), query(x, now->rch, m + 1, r));
    }

    T query(const T &x) const {
        T ret = query(x, root, min_x, max_x);
        return is_min ? ret : -ret;
    }
};

int main() {
    int N;
    cin >> N;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> s = a;
    per(i, N - 1) s[i] += s[i + 1];

    vector<vector<pii>> qs(N);
    int Q;
    cin >> Q;

    rep(i, Q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        qs[y].eb(i, x);
    }
    Li_Chao_Tree<ll, 0, 100000> lct;
    vector<ll> ans(Q);

    rep(i, N) {
        lct.add_segment(0, i + 1, -a[i], s[i] + a[i] * i);
        each(e, qs[i]) {
            int id = e.first;
            int d = i - e.second;
            ans[id] = lct.query(d);
            if (i < N - 1) ans[id] -= s[i + 1];
        }
    }

    printn(ans);
}