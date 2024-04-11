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

template <typename T, T (*add)(T, T), T (*mul)(T, T), T e0, T e1>
struct Semi_Ring {
    T x;
    Semi_Ring() {}
    Semi_Ring(T x) : x(x) {}

    Semi_Ring &operator+=(const Semi_Ring &p) {
        if (x == e0) return *this = p.x;
        if (p.x == e0) return *this;
        return *this = add(x, p.x);
    }

    Semi_Ring &operator*=(const Semi_Ring &p) {
        if (x == e1) return *this = p.x;
        if (p.x == e1) return *this;
        return *this = mul(x, p.x);
    }

    // (a+b)+c = a+(b+c), 0+a = a+0 = a, a+b = b+a
    // (a*b)*c = a*(b*c), 1*a = a*1 = a
    // a*(b+c) = a*b+a*c, (a+b)*c = a*c+b*c
    // 0*a = a*0 = 0
    //  (+,*), (XOR,AND), (min,+), (max,+) 

    Semi_Ring operator+(const Semi_Ring &p) const { return Semi_Ring(*this) += p; }

    Semi_Ring operator*(const Semi_Ring &p) const { return Semi_Ring(*this) *= p; }

    friend ostream &operator<<(ostream &os, const Semi_Ring &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Semi_Ring &p) {
        T a;
        is >> a;
        p = Semi_Ring(a);
        return is;
    }
};

template <typename t, t (*add)(t, t), t (*mul)(t, t), t e0, t e1>
struct Abstract_Matrix {
    using T = Semi_Ring<t, add, mul, e0, e1>;
    vector<vector<T>> A;

    Abstract_Matrix(int n, int m) : A(n, vector<T>(m, T(e0))) {}

    int height() const { return A.size(); }

    int width() const { return A.front().size(); }

    inline const vector<T> &operator[](int k) const { return A[k]; }

    inline vector<T> &operator[](int k) { return A[k]; }

    static Abstract_Matrix I(int l) {
        Abstract_Matrix ret(l, l);
        for (int i = 0; i < l; i++) ret[i][i] = T(e1);
        return ret;
    }

    Abstract_Matrix &operator*=(const Abstract_Matrix &B) {
        int n = height(), m = width(), p = B.width();
        assert(m == B.height());
        Abstract_Matrix ret(n, p);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                for (int j = 0; j < p; j++) ret[i][j] += A[i][k] * B[k][j];
            }
        }
        swap(A, ret.A);
        return *this;
    }

    Abstract_Matrix operator*(const Abstract_Matrix &B) const { return Abstract_Matrix(*this) *= B; }

    Abstract_Matrix pow(long long k) {
        int n = height(), m = width();
        assert(n == m);
        Abstract_Matrix now = *this, ret = I(n);
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }
};

ll add(ll x, ll y) { return max(x, y); };

ll mul(ll x, ll y) { return x + y; };

template <typename T>
struct Matrix {
    vector<vector<T>> A;

    Matrix(int m, int n) : A(m, vector<T>(n, -INF)) {}

    int height() const { return A.size(); }

    int width() const { return A.front().size(); }

    inline const vector<T> &operator[](int k) const { return A[k]; }

    inline vector<T> &operator[](int k) { return A[k]; }

    static Matrix I(int l) {
        Matrix ret(l, l);
        for (int i = 0; i < l; i++) ret[i][i] = 0;
        return ret;
    }

    Matrix &operator*=(const Matrix &B) {
        int m = height(), n = width(), p = B.width();
        assert(n == B.height());
        Matrix ret(m, p);
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < p; j++) ret[i][j] = max(ret[i][j], A[i][k] + B[k][j]);
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
                if (A[i][j] != 0) pivot = i;
                // if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
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
                if (A[i][j] != 0) pivot = i;
                // if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
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

int main() {
    ll N;
    string T;
    cin >> N >> T;

    int M = sz(T);

    int K = 11;
    vector<vector<string>> S(K + 1);

    rep(i, M) {
        rep2(j, 2, K + 1) {
            if (i + j > M) break;
            string X = T.substr(i, j);
            S[j].eb(X);
        }
    }

    vector<vector<int>> d(4, vector<int>(4, inf));

    rep2(i, 2, K + 1) {
        rearrange(S[i]);
        vector<vector<int>> c(4, vector<int>(4, 1 << (2 * i - 4)));
        each(e, S[i]) {
            int x = e[0] - 'A', y = e[i - 1] - 'A';
            c[x][y]--;
        }
        rep(x, 4) rep(y, 4) {
            if (c[x][y] > 0) chmin(d[x][y], i);
        }
    }

    rep(i, 4) {
        rep(j, 4) {
            assert(d[i][j] <= K); //
        }
    }

    using mat = Matrix<ll>;
    int L = K - 2;
    mat A(L * 16 + 5, L * 16 + 5);

    rep(i, 4) rep(j, 4) {
        int t = d[i][j] - 2;
        int k = 4 * i + j;
        if (t == 0) {
            A[L * 16 + i][L * 16 + j] = 1;
        } else {
            A[L * 16 + i][L * k] = 0;
            rep(s, t - 1) A[L * k + s][L * k + s + 1] = 0;
            A[L * k + t - 1][L * 16 + j] = 1;
        }
    }
    rep(i, 4) A[L * 16 + 4][L * 16 + i] = 1;

    mat x(1, L * 16 + 5);
    x[0][L * 16 + 4] = 0;

    x *= A.pow(N);
    ll ans = -INF;
    rep(i, L * 16 + 5) chmax(ans, x[0][i]);

    cout << ans << '\n';
}