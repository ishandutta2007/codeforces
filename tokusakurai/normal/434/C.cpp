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
const int MOD = 1000000007;
// const int MOD = 998244353;

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template <int char_size, char base>
struct Trie {
    struct Node {
        vector<int> next, accept;
        int count; // 
        int pena;

        Node() : next(char_size, -1), count(0), pena(0) {}
    };

    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    int count() const { return nodes.front().count; }

    int size() const { return nodes.size(); }

    void insert(const string &s, int pena, int id) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int &next = nodes[now].next[s[i] - base];
            if (next == -1) { next = size(), nodes.emplace_back(); }
            nodes[now].count++, now = next;
        }
        nodes[now].count++, nodes[now].accept.push_back(id);
        nodes[now].pena += pena;
    }

    void insert(const string &s, int pena) { insert(s, pena, count()); }

    bool search(const string &s, bool prefix = false) const {
        int now = 0;
        for (int i = 0; i < s.size(); i++) {
            now = nodes[now].next[s[i] - base];
            if (now == -1) return false;
        }
        return (prefix) ? true : !nodes[now].accept.empty();
    }
};

template <int char_size, char base>
struct Aho_Corasick : Trie<char_size + 1, base> {
    const int FAIL = char_size;
    vector<int> correct; //  O(|S_i|)

    void build(bool heavy = true) { // heavy := 
        correct.resize(this->size());
        for (int i = 0; i < (int)this->size(); i++) { correct[i] = (this->nodes[i].accept).size(); }
        queue<int> que;
        for (int i = 0; i <= char_size; i++) {
            if (this->nodes[0].next[i] != -1) {
                this->nodes[this->nodes[0].next[i]].next[FAIL] = 0;
                que.push(this->nodes[0].next[i]);
            } else {
                this->nodes[0].next[i] = 0;
            }
        }
        while (!que.empty()) {
            auto &now = this->nodes[que.front()];
            int fail = now.next[FAIL];
            correct[que.front()] += correct[fail]; //  correct  O(|S_i|)
            que.pop();
            for (int i = 0; i < char_size; i++) {
                if (now.next[i] != -1) {
                    this->nodes[now.next[i]].next[FAIL] = this->nodes[fail].next[i];
                    if (heavy) {
                        auto &u = this->nodes[now.next[i]].accept;
                        auto &v = this->nodes[this->nodes[fail].next[i]].accept;
                        vector<int> accept;
                        set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
                        u = accept;
                        this->nodes[now.next[i]].pena += this->nodes[this->nodes[fail].next[i]].pena;
                    }
                    que.push(now.next[i]);
                } else {
                    now.next[i] = this->nodes[fail].next[i];
                }
            }
        }
    }

    map<int, int> match(int now, const string &s) const { // now  s  id 
        map<int, int> ret;
        for (auto &c : s) {
            now = this->nodes[now].next[c - base];
            for (auto &u : this->nodes[now].accept) ret[u]++;
        }
        return ret;
    }

    map<int, int> match(const string &s) const { return match(0, s); }

    pair<long long, int> move(int now, const char &c) const { // now  c 
        now = this->nodes[now].next[c - base];
        return make_pair(correct[now], now);
    }

    pair<long long, int> move(const char &c) const { return move(0, c); }

    pair<long long, int> move(int now, const string &s) const {
        long long sum = 0;
        for (auto &c : s) {
            pair<long long, int> p = move(now, c);
            sum += p.first, now = p.second;
        }
        return make_pair(sum, now);
    }

    pair<long long, int> move(const string &s) const { return move(0, s); }
};

string scan() {
    int N;
    cin >> N;
    string S;
    rep(i, N) {
        int x;
        cin >> x;
        S += char('a' + x);
    }
    return S;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    string L = scan(), R = scan();
    int D = sz(R), X = sz(R) - sz(L);
    L = string(X, 'a') + L;

    Aho_Corasick<20, 'a'> trie;
    rep(i, N) {
        string S = scan();
        int pena;
        cin >> pena;
        trie.insert(S, pena);
    }
    trie.build();
    int A = trie.nodes.size();

    vector<vector<pii>> next(A, vector<pii>(M));
    rep(i, A) {
        rep(j, M) {
            int ni = trie.nodes[i].next[j];
            next[i][j] = pii(ni, trie.nodes[ni].pena);
            // cout << next[i][j] << '\n';
        }
    }

    vector<vector<vector<mint>>> dp(A, vector<vector<mint>>(K + 1, vector<mint>(4, 0)));
    vector<vector<vector<mint>>> ndp(A, vector<vector<mint>>(K + 1, vector<mint>(4, 0)));

    rep(t, D) {
        rep(i, A) rep(j, K + 1) rep(k, 4) ndp[i][j][k] = 0;
        if (t <= X) {
            rep2(c, 1, M) {
                int nk = 0;
                if (c < L[t] - 'a') continue;
                if (t == 0 && c > R[t] - 'a') continue;
                if (c > L[t] - 'a') nk |= 1;
                if (t > 0 || c < R[t] - 'a') nk |= 2;
                auto [ni, nj] = next[0][c];
                if (nj <= K) ndp[ni][nj][nk]++;
            }
        }
        rep(i, A) rep(j, K + 1) rep(k, 4) {
            if (dp[i][j][k] == 0) continue;
            rep(c, M) {
                auto [ni, nj] = next[i][c];
                nj += j;
                int nk = k;
                if (!flg(k, 0) && c < L[t] - 'a') continue;
                if (!flg(k, 1) && c > R[t] - 'a') continue;
                if (c > L[t] - 'a') nk |= 1;
                if (c < R[t] - 'a') nk |= 2;
                if (nj <= K) ndp[ni][nj][nk] += dp[i][j][k];
            }
        }
        swap(dp, ndp);
    }

    mint ans = 0;
    rep(i, A) rep(j, K + 1) rep(k, 4) ans += dp[i][j][k];
    cout << ans << '\n';
}