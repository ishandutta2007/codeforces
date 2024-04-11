#include <bits/stdc++.h>
using namespace std;

const int A = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13;

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<998244353>;

mint ex_frequency[A];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, x, y, k, m; cin >> n >> a >> x >> y >> k >> m;

    mint n_inv = mint(n).pow(), ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += k * n_inv * (a - a % A);
        ++ex_frequency[a % A];
        a = (int) ((long long) a * x % m + y) % m;
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < A; ++j) {
            ans += ex_frequency[j] * n_inv * j;
            if (j % i > 0) {
                ex_frequency[j - j % i] += ex_frequency[j] * n_inv;
                ex_frequency[j] -= ex_frequency[j] * n_inv;
            }
        }
    }

    cout << ans * mint(n).pow(k) << "\n";
}