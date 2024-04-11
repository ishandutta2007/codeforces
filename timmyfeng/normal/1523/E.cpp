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

using mint = modint<1000000007>;

const int N = 1e5 + 1;

mint fact[N], ifact[N];

mint choose(int n, int k) {
    return fact[n] * ifact[n - k] * ifact[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = i * fact[i - 1];
        ifact[i] = fact[i].pow();
    }

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        mint answer = 1;
        for (int i = 1; 1 + k * (i - 1) <= n; ++i) {
            answer += choose(n - (k - 1) * (i - 1), i) * choose(n, i).pow();
        }

        cout << answer << "\n";
    }
}