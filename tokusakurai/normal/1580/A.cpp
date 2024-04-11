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

template <typename T>
struct Cumulative_Sum_2D {
    vector<vector<T>> v;
    const int n, m;

    Cumulative_Sum_2D(const vector<vector<T>> &v) : v(v), n((int)v.size()), m((int)v[0].size()) {}

    Cumulative_Sum_2D(int n, int m) : v(n, vector<T>(m, 0)), n(n), m(m) {}

    void build() { // 
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) v[i][j] += v[i][j - 1];
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) v[i][j] += v[i - 1][j];
        }
    }

    void add(int lx, int ly, int rx, int ry, T x) { // [lx,rx)[ly,ry)imos
        lx = max(lx, 0), ly = max(ly, 0), rx = min(rx, n), ry = min(ry, m);
        if (rx <= lx || ry <= ly) return;
        v[lx][ly] += x;
        if (rx < n) v[rx][ly] -= x;
        if (ry < m) v[lx][ry] -= x;
        if (rx < n && ry < m) v[rx][ry] += x;
    }

    T fold(int a, int b) { return (a <= 0 || b <= 0 ? 0 : v[min(a, n) - 1][min(b, m) - 1]); }

    T sum(int lx, int ly, int rx, int ry) { // [lx,rx)[ly,ry)
        lx = max(lx, 0), ly = max(ly, 0), rx = min(rx, n), ry = min(ry, m);
        if (rx <= lx || ry <= ly) return 0;
        return fold(lx, ly) - fold(rx, ly) - fold(lx, ry) + fold(rx, ry);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<string> S(N);
        rep(i, N) cin >> S[i];

        vector<vector<int>> A(N, vector<int>(M));
        rep(i, N) { rep(j, M) A[i][j] = S[i][j] - '0'; }

        Cumulative_Sum_2D<int> s(A);
        s.build();
        int ans = inf;

        rep2(j, 0, N - 1) {
            rep2(i, 0, j - 4) {
                vector<int> cl(M, 0), cr(M, 0);
                rep(l, M) {
                    cl[l] += j - i - 1 - s.sum(i + 1, l, j, l + 1);
                    cl[l] -= l + 1 - s.sum(i, 0, i + 1, l + 1);
                    cl[l] -= l + 1 - s.sum(j, 0, j + 1, l + 1);
                    cl[l] -= s.sum(i + 1, 0, j, l + 1);
                }
                rep(r, M) {
                    cr[r] += j - i - 1 - s.sum(i + 1, r, j, r + 1);
                    cr[r] += r - s.sum(i, 0, i + 1, r);
                    cr[r] += r - s.sum(j, 0, j + 1, r);
                    cr[r] += s.sum(i + 1, 0, j, r);
                }

                // print(cl), print(cr);

                rep2(l, 1, M - 1) chmin(cl[l], cl[l - 1]);
                rep2(r, 3, M - 1) chmin(ans, cr[r] + cl[r - 3]);
            }
        }

        cout << ans << '\n';
    }
}