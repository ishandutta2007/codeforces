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

const int N = 1000001;

mint fact[N], inv_fact[N];

mint choose(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[n - k] * inv_fact[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = i * fact[i - 1];
        inv_fact[i] = fact[i].pow();
    }

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> tally(n + 1);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            ++tally[a];
        }

        auto [first, last] = ranges::remove(tally, 0);
        tally.erase(first, last);

        if (ssize(tally) == 1) {
            cout << 1 << "\n";
            continue;
        }

        vector<mint> rotate_sum(n + 1), rotate_ways(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (n % i != 0) {
                rotate_sum[i] = rotate_sum[gcd(i, n)];
                rotate_ways[i] = rotate_ways[gcd(i, n)];
                continue;
            }

            rotate_ways[i] = fact[i];
            rotate_sum[i] = choose(i, 2);
            for (auto count : tally) {
                if (count % (n / i) != 0) {
                    rotate_ways[i] = rotate_sum[i] = 0;
                    break;
                }

                rotate_ways[i] *= inv_fact[count / (n / i)];
                rotate_ways[i] *= fact[count];

                rotate_sum[i] -= choose(count / (n / i), 2);
            }

            rotate_sum[i] *= choose(i, 2).pow() * rotate_ways[i] * n;
        }

        cout << accumulate(begin(rotate_sum), end(rotate_sum), mint()) *
            accumulate(begin(rotate_ways), end(rotate_ways), mint()).pow() << "\n";
    }
}