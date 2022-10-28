#include <bits/stdc++.h>
using namespace std;

const int N = 4042, M = 998244353;

struct mint {
    int x;

    mint() {}

    template <class T> mint(T value) : x(value % M) { if (x < 0) x += M; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= M) x -= M; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += M; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % M; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = M - 1; return *this; }

    mint & operator++() { if (++x == M) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = M - 2) const {
        mint ans = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                ans *= b;
            }
            b *= b;
            e /= 2;
        }
        return ans;
    }
};

mint fact[N], inv[N], sum[N][N];

mint choose(int n, int k) {
    return fact[n] * inv[k] * inv[n - k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = i * fact[i - 1];
        inv[i] = fact[i].pow();
    }

    int n, m;
    cin >> n >> m;

    mint ans = 0;
    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                sum[i][j] = sum[i][j - 1] + choose(j - 1 + i, j - 1) * choose(n - j + i - 1, n - j);
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                ans += 2 * choose(j - 1 + i, j - 1) * choose(n - j + i - 1, n - j) * sum[m - i][n - j - k];
            }
        }
        swap(n, m);
    }

    cout << ans << "\n";
}