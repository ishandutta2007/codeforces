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

template <int char_size, char base>
struct Trie {
    struct Node {
        vector<int> next, accept;
        int count; // 

        Node() : next(char_size, -1), count(0) {}
    };

    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    int count() const { return nodes.front().count; }

    int size() const { return nodes.size(); }

    void insert(const string &s, int id) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int &next = nodes[now].next[s[i] - base];
            if (next == -1) { next = size(), nodes.emplace_back(); }
            nodes[now].count++, now = next;
        }
        nodes[now].count++, nodes[now].accept.push_back(id);
    }

    void insert(const string &s) { insert(s, count()); }

    bool search(const string &s, bool prefix = false) const {
        int now = 0;
        for (int i = 0; i < s.size(); i++) {
            now = nodes[now].next[s[i] - base];
            if (now == -1) return false;
        }
        return (prefix) ? true : !nodes[now].accept.empty();
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    if (K == 0) {
        cout << N << '\n';
        rep(i, N) cout << i + 1 << (i == N - 1 ? '\n' : ' ');
        return 0;
    }

    vector<string> S(N);
    Trie<2, '0'> G;

    rep(i, N) {
        rep3(j, 29, 0) {
            char x = '0' + flg(a[i], j);
            S[i] += x;
        }
        G.insert(S[i]);
    }

    // rep(i, N) cout << S[i] << '\n';

    string T;
    rep3(i, 29, 0) {
        char x = '0' + flg(K, i);
        T += x;
    }

    int t = -1;
    rep3(i, 29, 0) {
        if (flg(K, i)) {
            t = 29 - i;
            break;
        }
    }

    // cout << T << ' ' << t << '\n';

    int X = (1 << (30 - t)) - 1;
    // cout << X << '\n';
    set<int> s;
    map<int, vector<int>> mp;
    vector<int> ans;

    rep(i, N) {
        int x = a[i] & ~X;
        if (s.count(x)) continue;
        int ptr = 0;
        rep(j, t) ptr = G.nodes[ptr].next[S[i][j] - '0'];
        int tmp = -1;
        rep2(j, t, 29) {
            if (T[j] == '1') {
                int e = S[i][j] - '0';
                e ^= 1;
                int to = G.nodes[ptr].next[e];
                if (to == -1) break;
                ptr = to;
            } else {
                int e = S[i][j] - '0';
                e ^= 1;
                int to = G.nodes[ptr].next[e];
                if (to != -1) {
                    ptr = to;
                    while (G.nodes[ptr].accept.empty()) {
                        each(u, G.nodes[ptr].next) {
                            if (u != -1) {
                                ptr = u;
                                break;
                            }
                        }
                    }
                    tmp = G.nodes[ptr].accept[0];
                    break;
                } else {
                    e ^= 1;
                    ptr = G.nodes[ptr].next[e];
                }
            }
            if (j == 29) tmp = G.nodes[ptr].accept[0];
        }
        if (tmp != -1) {
            // cout << i + 1 << ' ' << tmp + 1 << ' ' << x << '\n';
            s.emplace(x);
            ans.eb(i), ans.eb(tmp);
        }
        mp[x].eb(i);
    }

    if (ans.empty() && sz(mp) == 1) {
        cout << "-1\n";
        return 0;
    }

    each(e, mp) {
        if (!s.count(e.first)) ans.eb(e.second[0]);
    }

    sort(all(ans));

    cout << sz(ans) << '\n';
    print(ans, 1);
}