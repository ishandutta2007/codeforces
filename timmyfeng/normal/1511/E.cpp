#include <bits/stdc++.h>
using namespace std;

const int N = 300001, M = 998244353;

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

mint ways[N][2], sum[N][2], pow2[N];
string grid[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ways[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        ways[i][1] = 2 * ways[i - 1][0] + ways[i - 1][1];
        sum[i][1] = 2 * sum[i - 1][0] + sum[i - 1][1] + ways[i - 1][0];
        ways[i][0] = ways[i - 1][1];
        sum[i][0] = sum[i - 1][1];
    }

    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow2[i] = pow2[i - 1] * 2;
    }

    int n, m;
    cin >> n >> m;

    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        total += count(grid[i].begin(), grid[i].end(), 'o');
    }

    mint ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0, k = 0; j < m; j = k) {
            while (k < m && grid[i][j] == grid[i][k]) {
                ++k;
            }
            if (grid[i][j] == 'o') {
                ans += pow2[total - (k - j)] * (sum[k - j][0] + sum[k - j][1]);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0, k = 0; j < n; j = k) {
            while (k < n && grid[j][i] == grid[k][i]) {
                ++k;
            }
            if (grid[j][i] == 'o') {
                ans += pow2[total - (k - j)] * (sum[k - j][0] + sum[k - j][1]);
            }
        }
    }

    cout << ans << "\n";
}