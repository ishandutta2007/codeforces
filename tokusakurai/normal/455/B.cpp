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

template <int char_size, char base>
struct Trie {
    struct Node {
        array<int, char_size> next;
        vector<int> accept;
        int count; // 

        Node() : count(0) { fill(begin(next), end(next), -1); }
    };

    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(const string &s, int id) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int t = s[i] - base;
            int next = nodes[now].next[t];
            if (next == -1) {
                next = nodes.size();
                nodes[now].next[t] = next;
                nodes.emplace_back();
            }
            nodes[now].count++;
            now = next;
        }
        nodes[now].count++;
        nodes[now].accept.push_back(id);
    }

    void insert(const string &s) { insert(s, nodes[0].count); }

    int find(const string &s) const {
        int now = 0;
        for (int i = 0; i < s.size(); i++) {
            int t = s[i] - base;
            now = nodes[now].next[t];
            if (now == -1) return -1;
        }
        return now;
    }

    int count(const string &s) const {
        int p = find(s);
        return p == -1 ? 0 : nodes[p].count;
    }

    pii dfs(int now) {
        int s = 0;
        int x1 = 0, x2 = 0;
        rep(j, char_size) {
            if (nodes[now].next[j] == -1) continue;
            s++;
            auto [y1, y2] = dfs(nodes[now].next[j]);
            if (y1 == 0) x1 = 1;
            if (y2 == 0) x2 = 1;
        }
        if (s == 0) x2 = 1;
        return pii(x1, x2);
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Trie<'a', 26> trie;
    rep(i, N) trie.insert(S[i]);

    auto [x1, x2] = trie.dfs(0);

    if (x1 == 1 && x2 == 1) {
        cout << "First\n";
    } else if (x1 == 0 && x2 == 0) {
        cout << "Second\n";
    } else if (x1 == 1 && x2 == 0) {
        cout << (K & 1 ? "First\n" : "Second\n");
    } else {
        cout << "Second\n";
    }
}