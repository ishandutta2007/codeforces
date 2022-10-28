#include <bits/stdc++.h>
using namespace std;

int M;
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

using mint = modint;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; cin >> n >> M;

    vector<mint> ways(n + 1), suffix_ways(n + 2);
    ways[n] = suffix_ways[n] = 1;

    for (int i = n - 1; i > 0; --i) {
        suffix_ways[i] = suffix_ways[i + 1];
        ways[i] = suffix_ways[i + 1];
        for (int j = 1; i * j <= n; ++j)
            ways[i] += j * (suffix_ways[i * j] - suffix_ways[min(n + 1, i * (j + 1))]);
        for (int j = 1; (i + 1) * j <= n; ++j)
            ways[i] -= j * (suffix_ways[(i + 1) * j] - suffix_ways[min(n + 1, (i + 1) * (j + 1))]);
        suffix_ways[i] += ways[i];
    }

    cout << ways[1] << "\n";
}