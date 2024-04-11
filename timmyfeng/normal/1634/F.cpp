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
        modint f = *this, p = 1;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q >> M;

    vector<modint> fibonacci(n + 1);
    fibonacci[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    vector<modint> reduced(n);
    for (auto &i : reduced) {
        int a; cin >> a;
        i = a;
    }
    for (auto &i : reduced) {
        int b; cin >> b;
        i -= b;
    }

    int zeroes = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= 2 && i - j >= 0; ++j) {
            reduced[i] -= reduced[i - j];
        }
        zeroes += (reduced[i] == 0);
    }

    auto update = [&](int i, modint x) {
        if (reduced[i] == 0) --zeroes;
        reduced[i] += x;
        if (reduced[i] == 0) ++zeroes;
    };

    while (q--) {
        char c; cin >> c;
        int l, r; cin >> l >> r; --l;

        update(l, c == 'A' ? 1 : -1);
        if (r < n) update(r, (c == 'A' ? -1 : 1) * fibonacci[r - l + 1]);
        if (r + 1 < n) update(r + 1, (c == 'A' ? -1 : 1) * fibonacci[r - l]);

        cout << (zeroes == n ? "YES" : "NO") << "\n";
    }
}