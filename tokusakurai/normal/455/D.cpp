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
        deque<T> que;
        vector<int> cnt;

        Node(const vector<T> &a, int l, int r) : l(l), r(r) {
            int n = sz(a);
            cnt.assign(n, 0);
            rep(i, r - l) {
                que.emplace_back(a[i + l]);
                cnt[a[i + l]]++;
            }
        }

        void push_front(const T &x) {
            que.push_front(x);
            cnt[x]++;
        }

        void push(int a, const T &x) {
            deque<T> que2;
            a -= l;
            rep(i, a) que2.emplace_back(que[i]);
            que2.emplace_back(x);
            rep2(i, a, sz(que)) que2.emplace_back(que[i]);
            swap(que, que2);
            cnt[x]++;
        }

        T pop_back() {
            T x = que.back();
            cnt[x]--;
            que.pop_back();
            return x;
        }

        T pop(int a) {
            deque<T> que2;
            a -= l;
            rep(i, a) que2.emplace_back(que[i]);
            rep2(i, a + 1, sz(que)) que2.emplace_back(que[i]);
            T x = que[a];
            swap(que, que2);
            cnt[x]--;
            return x;
        }

        void rotate(int a, int b) {
            assert(a <= b && l <= a && b < r);
            a -= l, b -= l;
            if (a == b) return;
            deque<T> que2;
            rep(i, a) que2.emplace_back(que[i]);
            que2.emplace_back(que[b]);
            rep2(i, a, b) que2.emplace_back(que[i]);
            rep2(i, b + 1, r - l) que2.emplace_back(que[i]);
            swap(que, que2);
        }

        int count(int a, int b, const T &x) {
            a = max(a, l), b = min(b, r);
            if (a >= b) return 0;
            if (a == l && b == r) return cnt[x];
            int ret = 0;
            rep2(i, a - l, b - l) {
                if (que[i] == x) ret++;
            }
            return ret;
        }
    };

    vector<Node> nodes;
    int bucket_size;

    Sqrt_Decomposition(const vector<T> &a, int bucket_size) : bucket_size(bucket_size) {
        for (int i = 0; i < (int)a.size(); i += bucket_size) {
            int l = i, r = min(i + bucket_size, (int)a.size());
            nodes.emplace_back(a, l, r);
        }
    }

    void query1(int a, int b) {
        int s = a / bucket_size, t = b / bucket_size;
        if (s == t) {
            nodes[s].rotate(a, b);
        } else {
            {
                T x = nodes[t].pop(b);
                nodes[s].push(a, x);
            }
            rep2(i, s, t) {
                T x = nodes[i].pop_back();
                nodes[i + 1].push_front(x);
            }
        }
    }

    int query2(int a, int b, const T &x) {
        b++;
        int ret = 0;
        for (auto &e : nodes) ret += e.count(a, b, x);
        return ret;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }

    Sqrt_Decomposition<int> sq(a, 300);

    int Q;
    cin >> Q;

    int last = 0;

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;

        l = (l + last - 1) % N;
        r = (r + last - 1) % N;
        if (l > r) swap(l, r);

        if (t == 1) {
            sq.query1(l, r);
        } else {
            int k;
            cin >> k;
            k = (k + last - 1) % N;
            last = sq.query2(l, r, k);
            cout << last << '\n';
        }
    }
}