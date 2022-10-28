#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
struct mint {
    int value;
    mint() : value(0) {}
    template <class T> mint(T x) : value(x % M) { if (value < 0) value += M; }
    mint & operator-=(mint oth) { value -= oth.value; if (value < 0)  value += M; return *this; }
    mint & operator+=(mint oth) { value += oth.value; if (value >= M) value -= M; return *this; }
    mint & operator*=(mint oth) { value = (long long) value * oth.value % M; return *this; }
    mint & operator--() { if (--value == -1) value = M - 1; return *this; }
    mint & operator++() { if (++value == M) value = 0; return *this; }
    mint operator--(int) { mint temp = *this; --*this; return temp; }
    mint operator++(int) { mint temp = *this; ++*this; return temp; }
    mint operator-() const { return mint() - *this; }
    mint operator+() const { return *this; }
    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }
    friend mint operator-(mint a, mint b) { return a -= b; }
    friend mint operator+(mint a, mint b) { return a += b; }
    friend mint operator*(mint a, mint b) { return a *= b; }
    friend bool operator==(mint a, mint b) { return a.value == b.value; }
    friend bool operator!=(mint a, mint b) { return a.value != b.value; }
    friend ostream & operator<<(ostream &out, mint a) { out << a.value; return out; }
};

const int N = 1001;

mint ways[N][N][2][2][2];
set<char> alphabet[N][N];

int get(int i, int j, char c) {
    if (alphabet[i][j].count(c) == 0) {
        return -1;
    } else {
        return c == *alphabet[i][j].begin() ? 0 : 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0) {
                alphabet[i][j].insert(x[i - 1]);
            }
            if (j > 0) {
                alphabet[i][j].insert(y[j - 1]);
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            ++ways[i][j][0][0][0];
            for (int k = 0; k < 2; ++k) {
                for (int u = 0; u < 2; ++u) {
                    for (int v = 0; v < 2; ++v) {
                        if (i < n && (get(i, j, x[i]) != k || u + v == 0)) {
                            ways[i + 1][j][get(i + 1, j, x[i])][1][v] += ways[i][j][k][u][v];
                        }
                        if (j < m && (get(i, j, y[j]) != k || u + v == 0)) {
                            ways[i][j + 1][get(i, j + 1, y[j])][u][1] += ways[i][j][k][u][v];
                        }
                    }
                }
                ans += ways[i][j][k][1][1];
            }
        }
    }

    cout << ans << "\n";
}