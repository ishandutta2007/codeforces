#include <bits/stdc++.h>
using namespace std;

const int N = 501, K = N * N / 2;

int M;

struct mint {
    int x;

    mint() : x(0) {}

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

mint ways[2][2 * K], choose[N][N], fact[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> M;

    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 0; i < N; ++i) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
        }
    }

    mint ans = 0;
    fill(ways[0] + K, ways[0] + 2 * K, 1);
    for (int i = 1; i < n; ++i) {
        mint sum = 0;
        for (int j = 0; j < 2 * K; ++j) {
            ways[i % 2][j] = (j > 0 ? ways[i % 2][j - 1] : 0) + sum;
            sum -= ways[1 - i % 2][j] - (j >= i ? ways[1 - i % 2][j - i] : 0);
            sum += ways[1 - i % 2][min(2 * K - 1, j + i)] - ways[1 - i % 2][j];
        }

        for (int j = 0; j <= i; ++j) {
            for (int k = j + 1; k <= i; ++k) {
                ans += choose[n][i + 1] * fact[n - i - 1] * ways[i % 2][K + j - k - 1];
            }
        }
    }

    cout << ans << "\n";
}