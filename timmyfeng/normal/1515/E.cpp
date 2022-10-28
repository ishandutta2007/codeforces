#include <bits/stdc++.h>
using namespace std;

const int N = 402;

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

mint ways[N][N][N], inv[N], pow2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> M;

    pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        inv[i] = mint(i).pow();
        pow2[i] = 2 * pow2[i - 1];
    }

    ways[0][0][0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                ways[i][j][0] += pow2[k - 1] * ways[i - 1][j][k];
            }

            if (j > 0) {
                for (int k = 1; k <= n; ++k) {
                    ways[i][j][k] = ways[i - 1][j - 1][k - 1] * inv[k];
                }
            }
        }
    }

    mint fact = 1, ans = 0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
        ans += fact * ways[n + 1][i][0];
    }

    cout << ans << "\n";
}