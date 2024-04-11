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

string S;

template <bool directed = false>
struct Graph {
    const int n;

    vector<int> l, r;

    vector<int> vs; // DFS
    string ans;
    vector<bool> flag;

    Graph(int n) : n(n), l(n, -1), r(n, -1), flag(n, false) {}

    void euler_tour(int now) {
        if (l[now] != -1) euler_tour(l[now]);
        vs.push_back(now);
        if (r[now] != -1) euler_tour(r[now]);
    }

    int dfs(int now, int k) {
        int ret = 0;
        bool used = false;

        if (l[now] != -1) {
            int x = dfs(l[now], max(k - 1, 0));
            ret += x;
            k -= x;
            if (x > 0) used = true;
        }

        if (k > 0 && !used && flag[now]) used = true;
        ans += S[now];
        if (used) k--, ret++, ans += S[now];

        if (r[now] != -1) {
            int y = dfs(r[now], (used ? k : 0));
            ret += y;
            k -= y;
        }

        return ret;
    }

    void solve(int k) {
        euler_tour(0);

        // print(vs);
        for (int i = 0; i < n;) {
            int j = 0;
            while (i + j < n && S[vs[i + j]] == S[vs[i]]) j++;
            bool tmp = (i + j < n && S[vs[i]] < S[vs[i + j]]);
            rep(k, j) flag[vs[i + k]] = tmp;
            i += j;
        }

        // rep(i, n) cout << flag[i] << (i == n - 1 ? '\n' : ' ');

        dfs(0, k);
        cout << ans << '\n';
    }
};

int main() {
    int N, K;
    cin >> N >> K >> S;

    Graph<true> G(N);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l >= 0) G.l[i] = l;
        if (r >= 0) G.r[i] = r;
    }

    G.solve(K);
}