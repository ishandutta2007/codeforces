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
struct Sqrt_Decomposition {
    struct Node {
        const int l, r;
        vector<T> v;
        bool is_same;
        T same, all_score, tmp;
        vector<T> score;

        Node(const vector<T> &a, int l, int r) : l(l), r(r), is_same(false), same(-1), all_score(0), tmp(0), score(r - l, 0) {
            v.resize(r - l);
            copy(begin(a) + l, begin(a) + r, begin(v));
        }

        void eval_all() {
            if (same != -1) {
                rep(i, r - l) {
                    score[i] += tmp;
                    v[i] = same;
                }
                is_same = true;
                tmp = 0;
            }
        }

        void query1(int a, int b, const T &x) {
            a = max(a, l), b = min(b, r);
            if (a >= b) return;
            if (a == l && b == r) {
                query1_all(x);
                return;
            }
            eval_all();
            rep2(i, a - l, b - l) {
                score[i] += abs(v[i] - x);
                all_score += abs(v[i] - x);
                v[i] = x;
            }
            same = -1;
            is_same = false;
        }

        void query1_all(const T &x) {
            if (!is_same) {
                rep(i, r - l) {
                    score[i] += abs(v[i] - x);
                    all_score += abs(v[i] - x);
                    v[i] = x;
                }
                same = x;
                is_same = true;
            } else {
                tmp += abs(same - x);
                all_score += abs(same - x) * (r - l);
                same = x;
                is_same = true;
            }
        }

        T query2(int a, int b) {
            a = max(a, l), b = min(b, r);
            if (a >= b) return 0;
            if (a == l && b == r) return query2_all();
            eval_all();
            T ret = 0;
            rep2(i, a - l, b - l) ret += score[i];
            return ret;
            return 0;
        }

        T query2_all() { return all_score; }
    };

    vector<Node> nodes;

    Sqrt_Decomposition(const vector<T> &a, int bucket_size) {
        for (int i = 0; i < (int)a.size(); i += bucket_size) {
            int l = i, r = min(i + bucket_size, (int)a.size());
            nodes.emplace_back(a, l, r);
        }
    }

    void query1(int a, int b, const T &x) {
        for (auto &e : nodes) e.query1(a, b, x);
    }

    T query2(int a, int b) {
        T ret = 0;
        for (auto &e : nodes) ret += e.query2(a, b);
        return ret;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    int D = 300;

    vector<ll> a(N);
    rep(i, N) a[i] = i + 1;
    Sqrt_Decomposition<ll> sq(a, D);

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;

        // cout << t << ' ' << l << ' ' << r << '\n';

        if (t == 1) {
            ll x;
            cin >> x;
            sq.query1(l, r, x);
        } else {
            cout << sq.query2(l, r) << '\n';
        }
    }
}