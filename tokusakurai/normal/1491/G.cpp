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

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }

    vector<vector<int>> cs;
    vector<bool> used(N, false);

    rep(i, N) {
        if (used[i]) continue;
        int ptr = i;
        vector<int> tmp;

        while (true) {
            used[ptr] = true;
            tmp.eb(ptr);
            ptr = P[ptr];
            if (ptr == i) break;
        }

        cs.eb(tmp);
    }

    int K = sz(cs);
    vector<pii> ans;

    if (K == 1) {
        rep(i, N - 2) ans.eb(cs[0][i], cs[0][N - 1]);
        ans.eb(cs[0][0], cs[0][N - 2]);
        ans.eb(cs[0][N - 2], cs[0][N - 1]);
        ans.eb(cs[0][0], cs[0][N - 1]);
    } else {
        for (int i = 0; i < K;) {
            if (i + 3 != K) {
                ans.eb(cs[i].back(), cs[i + 1].back());
                rep(j, sz(cs[i]) - 1) ans.eb(cs[i][j], cs[i + 1].back());
                rep(j, sz(cs[i + 1])) ans.eb(cs[i].back(), cs[i + 1][j]);
                i += 2;
            } else {
                ans.eb(cs[i].back(), cs[i + 2].back());
                rep(j, sz(cs[i])) ans.eb(cs[i][j], cs[i + 2].back());
                ans.eb(cs[i + 1].back(), cs[i + 2].back());
                rep(j, sz(cs[i + 1]) - 1) ans.eb(cs[i + 1][j], cs[i + 2].back());
                rep(j, sz(cs[i + 2])) ans.eb(cs[i + 1].back(), cs[i + 2][j]);
                i += 3;
            }
        }
    }

    rep(i, N) P[i]++;

    cout << sz(ans) << '\n';

    each(e, ans) {
        auto [u, v] = e;
        cout << u + 1 << ' ' << v + 1 << '\n';
        int nu = -P[v], nv = -P[u];
        P[u] = nu, P[v] = nv;
        // print(P);
    }
}