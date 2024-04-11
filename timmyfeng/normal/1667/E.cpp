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

using mint = modint<998244353>;

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<mint> fact(n + 1); 
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;

    vector<mint> answer(n + 1);
    answer[1] = fact[n - 1];
    for (int i = 2; i <= (n + 1) / 2; ++i)
        answer[i] = fact[n - i] * fact[(n - 1) / 2] * fact[(n + 1) / 2 - i].pow();

    mint suffix_sum = 0;
    for (int i = n; i >= 1; --i) {
        answer[i] -= suffix_sum * mint(i).pow();
        suffix_sum += answer[i];
    }

    for (int i = 1; i <= n; ++i) cout << answer[i] << " ";
    cout << "\n";
}