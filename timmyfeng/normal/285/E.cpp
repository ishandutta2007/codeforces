#include <bits/stdc++.h>
using namespace std;

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

using mint = modint<(int)(1e9 + 7)>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<mint> fact(n + 1), ifact(n + 1);
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = i * fact[i - 1];
        ifact[i] = fact[i].pow();
    }

    vector ways(n + 1, vector(n + 1, vector(4, mint())));
    ways[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int mask = 0; mask < 4; ++mask) {
                if (ways[i][j][mask] != 0) {
                    if (i > 0 && !(mask & 2)) ways[i + 1][j + 1][mask * 2 % 4] += ways[i][j][mask];
                    if (i < n - 1) ways[i + 1][j + 1][(mask * 2 + 1) % 4] += ways[i][j][mask];
                    ways[i + 1][j][mask * 2 % 4] += ways[i][j][mask];
                }
            }
        }
    }

    vector<mint> answer(n + 1);
    for (int i = n; i >= 0; --i) {
        for (auto x : ways[n][i]) answer[i] += x * fact[n - i];
        for (int j = i + 1; j <= n; ++j) {
            answer[i] -= answer[j] * fact[j] * ifact[i] * ifact[j - i];
        }
    }

    cout << answer[k] << "\n";
}