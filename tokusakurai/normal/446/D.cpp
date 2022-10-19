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
struct Matrix {
    vector<vector<T>> A;

    Matrix(int m, int n) : A(m, vector<T>(n, 0)) {}

    int height() const { return A.size(); }

    int width() const { return A.front().size(); }

    inline const vector<T> &operator[](int k) const { return A[k]; }

    inline vector<T> &operator[](int k) { return A[k]; }

    static Matrix I(int l) {
        Matrix ret(l, l);
        for (int i = 0; i < l; i++) ret[i][i] = 1;
        return ret;
    }

    Matrix &operator*=(const Matrix &B) {
        int m = height(), n = width(), p = B.width();
        assert(n == B.height());
        Matrix ret(m, p);
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < p; j++) ret[i][j] += A[i][k] * B[k][j];
            }
        }
        swap(A, ret.A);
        return *this;
    }

    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }

    Matrix pow(long long k) const {
        int m = height(), n = width();
        assert(m == n);
        Matrix now = *this, ret = I(n);
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    bool eq(const T &a, const T &b) const {
        return a == b;
        // return abs(a-b) <= EPS;
    }

    // (rank, det) 
    pair<int, T> row_reduction(vector<T> &b) {
        int m = height(), n = width(), check = 0, rank = 0;
        T det = 1;
        assert(b.size() == m);
        for (int j = 0; j < n; j++) {
            int pivot = check;
            for (int i = check; i < m; i++) {
                // if (A[i][j] != 0) pivot = i;
                if (abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
            }
            if (check != pivot) det *= T(-1);
            swap(A[check], A[pivot]), swap(b[check], b[pivot]);
            if (eq(A[check][j], T(0))) {
                det = T(0);
                continue;
            }
            rank++;
            det *= A[check][j];
            T r = T(1) / A[check][j];
            for (int k = j + 1; k < n; k++) A[check][k] *= r;
            b[check] *= r;
            A[check][j] = T(1);
            for (int i = 0; i < m; i++) {
                if (i == check) continue;
                if (!eq(A[i][j], 0)) {
                    for (int k = j + 1; k < n; k++) A[i][k] -= A[i][j] * A[check][k];
                    b[i] -= A[i][j] * b[check];
                }
                A[i][j] = T(0);
            }
            if (++check == m) break;
        }
        return make_pair(rank, det);
    }

    pair<int, T> row_reduction() {
        vector<T> b(height(), T(0));
        return row_reduction(b);
    }

    // 
    Matrix inverse() {
        if (height() != width()) return Matrix(0, 0);
        int n = height();
        Matrix ret = I(n);
        for (int j = 0; j < n; j++) {
            int pivot = j;
            for (int i = j; i < n; i++) {
                // if (A[i][j] != 0) pivot = i;
                if (abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
            }
            swap(A[j], A[pivot]), swap(ret[j], ret[pivot]);
            if (eq(A[j][j], T(0))) return Matrix(0, 0);
            T r = T(1) / A[j][j];
            for (int k = j + 1; k < n; k++) A[j][k] *= r;
            for (int k = 0; k < n; k++) ret[j][k] *= r;
            A[j][j] = T(1);
            for (int i = 0; i < n; i++) {
                if (i == j) continue;
                if (!eq(A[i][j], T(0))) {
                    for (int k = j + 1; k < n; k++) A[i][k] -= A[i][j] * A[j][k];
                    for (int k = 0; k < n; k++) ret[i][k] -= A[i][j] * ret[j][k];
                }
                A[i][j] = T(0);
            }
        }
        return ret;
    }

    // Ax = b  1 
    vector<vector<T>> Gausiann_elimination(vector<T> b) {
        int m = height(), n = width();
        row_reduction(b);
        vector<vector<T>> ret;
        vector<int> p(m, n);
        vector<bool> is_zero(n, true);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!eq(A[i][j], T(0))) {
                    p[i] = j;
                    break;
                }
            }
            if (p[i] < n)
                is_zero[p[i]] = false;
            else if (!eq(b[i], T(0)))
                return {};
        }
        vector<T> x(n, T(0));
        for (int i = 0; i < m; i++) {
            if (p[i] < n) x[p[i]] = b[i];
        }
        ret.push_back(x);
        for (int j = 0; j < n; j++) {
            if (!is_zero[j]) continue;
            x[j] = T(1);
            for (int i = 0; i < m; i++) {
                if (p[i] < n) x[p[i]] = -A[i][j];
            }
            ret.push_back(x), x[j] = T(0);
        }
        return ret;
    }
};

using ld = long double;
using mat = Matrix<ld>;

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<int> id0, id1;
    vector<int> c(N);
    rep(i, N) {
        cin >> c[i];
        (c[i] == 0 ? id0 : id1).eb(i);
    }

    vector<vector<int>> deg(N, vector<int>(N, 0));
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u][u]++, deg[v][v]++;
        deg[u][v]--, deg[v][u]--;
    }

    int L = sz(id0);
    mat A(L, L);
    rep(i, L) {
        rep(j, L) {
            int u = id0[i], v = id0[j];
            A[i][j] = ld(deg[u][v]) / ld(deg[u][u]);
        }
    }
    A = A.inverse();

    int K = sz(id1);
    vector<vector<ld>> P(L, vector<ld>(K, 0));

    rep(i, K) {
        mat b(L, 1);
        rep(j, L) {
            int u = id0[j], v = id1[i];
            b[j][0] = ld(-deg[u][v]) / ld(deg[u][u]);
        }
        mat x = A * b;
        rep(j, L) P[j][i] = x[j][0];
    }

    // rep(i, L) print(P[i]);

    mat x(1, K);
    rep(i, K) x[0][i] = P[0][i];

    mat B(K, K);
    rep(i, K) {
        int u = id1[i];
        rep(j, K) {
            if (i == j) continue;
            int v = id1[j];
            B[i][j] += ld(-deg[u][v]) / ld(deg[u][u]);
        }
        rep(j, L) {
            int v = id0[j];
            rep(k, K) B[i][k] += P[j][k] * ld(-deg[u][v]) / ld(deg[u][u]);
        }
    }

    x *= B.pow(T - 2);

    cout << x[0][K - 1] << '\n';
}