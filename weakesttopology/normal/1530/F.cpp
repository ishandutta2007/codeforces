#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fwht {
    template<typename T>
    using Matrix = array<array<T, 2>, 2>;
    template<typename T>
    void insert(int b, vector<T>& v, Matrix<T> A) {
        int N = (int)size(v);
        for (int pos = 0; pos < N; pos += 2 * b) {
            for (int i = 0; i < b; ++i) {
                T x = v[pos + i], y = v[pos + b + i];
                v[pos + i] = A[0][0] * x + A[0][1] * y;
                v[pos + b + i] = A[1][0] * x + A[1][1] * y;
            }
        }
    }
    template<typename T>
    vector<T> fwht(vector<T> v, Matrix<T> A) {
        int N = (int)size(v);
        for (int b = 1; b < N; b <<= 1) insert(b, v, A);
        return v;
    }
    template<typename T>
    Matrix<T> or_matrix() { return {{{1, 1}, {1, 0}}}; }
    template<typename T>
    Matrix<T> and_matrix() { return {{{1, 1}, {0, 1}}}; }
    template<typename T>
    Matrix<T> xor_matrix() { return {{{+1, +1}, {+1, -1}}}; }
    template<typename T>
    Matrix<T> inverse(Matrix<T> A) {
        T det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
        assert(det != T(0));
        swap(A[0][0], A[1][1]);
        A[0][1] *= -1;
        A[1][0] *= -1;
        for (int s : {0, 1}) {
            for (int t : {0, 1}) {
                A[s][t] /= det;
            }
        }
        return A;
    }
}
template<int mod>
struct Mint {
    int x;
    Mint() : x(0) {}
    Mint(int x_) {
        x = x_ % mod;
        if (x < 0) x += mod;
    }
    Mint& operator+=(Mint rhs) {
        x += rhs.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(Mint rhs) {
        x -= rhs.x;
        if (x < 0) x += mod;
        return *this;
    }
    Mint& operator*=(Mint rhs) {
        x = x * rhs.x % mod;
        return *this;
    }
    Mint& operator/=(Mint rhs) {
        return *this *= rhs.power(-1);
    }
    Mint power(ll p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Mint operator-() const {
        return Mint() - *this;
    }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator!=(Mint rhs) const { return x != rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a) {
        int x;
        in >> x;
        a = Mint(x);
        return in;
    }
    inline static const Mint X = [](){
        uniform_int_distribution<ll> unif(1, mod - 1);
        mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using mint = Mint<31'607>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<mint>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
            //p[i][j] = 1 + rng() % 1'000;
            p[i][j] /= 10'000;
            p[i][j] = 1 - p[i][j];
        }
    }
    // L = {one cell fails for every vertical and horizontal line}
    // D = {one cell fails for both diagonals}
    // ans  = 1 - P(L cap D)
    //      = 1 - P(L) + P(Dc cap L)
    //      = 1 - P(L) + P(D1c cap L) + P(D2c cap L) - P(D1c cap D2c cap L)
    auto A = fwht::or_matrix<mint>();
    vector<vector<mint>> dphat(4, vector<mint>(1 << n, 1));
    for (int i = 0; i < n; ++i) {
        vector<mint> prob(1 << n);
        prob[0] = 1;
        mint none = 1;
        for (int j = 0; j < n; ++j) {
            none *= 1 - p[i][j];
            prob[1 << j] = p[i][j] / (1 - p[i][j]);
        }
        for (int mask = 1; mask < (1 << n); ++mask) {
            int lsb = mask & -mask;
            prob[mask] = prob[mask ^ lsb] * prob[lsb];
        }
        prob[0] = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            prob[mask] *= none;
        }
        int d[2] = {i, n - 1 - i};
        for (int j = 0; j < n; ++j) {
            if (j != d[0] && j != d[1]) {
                fwht::insert(1 << j, prob, A);
            }
        }
        auto init = prob;
        // skip t, but not t ^ 1
        for (int t : {0, 1}) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (mask >> d[t] & 1) prob[mask] = 0;
            }
            fwht::insert(1 << d[t], prob, A);
            if (d[0] != d[1]) {
                fwht::insert(1 << d[t ^ 1], prob, A);
            }
            for (int mask = 0; mask < (1 << n); ++mask) {
                dphat[t][mask] *= prob[mask];
            }
            prob = init;
        }
        // skip both
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (1 << d[0] | 1 << d[1])) {
                prob[mask] = 0;
            }
        }
        fwht::insert(1 << d[0], prob, A);
        if (d[0] != d[1]) {
            fwht::insert(1 << d[1], prob, A);
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            dphat[2][mask] *= prob[mask];
        }
        prob = init;
        // skip none
        fwht::insert(1 << d[0], prob, A);
        if (d[0] != d[1]) {
            fwht::insert(1 << d[1], prob, A);
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            dphat[3][mask] *= prob[mask];
        }
    }
    int coef[4] = {+1, +1, -1, -1};
    mint ans = 1;
    for (int t = 0; t < 4; ++t) {
        auto dp = fwht::fwht(dphat[t], fwht::inverse(A));
        ans += coef[t] * dp.back();
    }
    cout << ans << '\n';
    exit(0);
}