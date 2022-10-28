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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<mint> pie(n + 1);
    pie[0] = 1;

    vector<pair<int, mint>> mono = {{0, 0}};
    mint sum_of_prefix = 0;
    for (int i = 0; i < n; ++i) {
        mint sum_of_seg = (i % 2 ? 1 : -1) * pie[i];
        while (mono.back().first >= a[i]) {
            auto [min_a, x] = mono.back();
            mono.pop_back();
            sum_of_prefix -= min_a * x;
            sum_of_seg += x;
        }

        mono.push_back({a[i], sum_of_seg});
        sum_of_prefix += a[i] * sum_of_seg;

        pie[i + 1] = (i % 2 ? 1 : -1) * sum_of_prefix;
    }

    cout << pie[n] << "\n";
}