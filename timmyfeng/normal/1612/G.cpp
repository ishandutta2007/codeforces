#include <bits/stdc++.h>
using namespace std;

const int C = 1000000, M = 1000000007;

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

mint fact[C];
int tally[C];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < C; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        ++tally[c - 1];
    }

    for (int i = C - 3; i >= 0; --i) {
        tally[i] += tally[i + 2];
    }

    mint f = 0, index = 0;
    for (int i = -C + 1; i < C; ++i) {
        mint len = tally[abs(i)];
        f += (2 * index + len - 1) * len * i;
        index += len;
    }
    f *= mint(2).pow();

    mint ways = fact[tally[0]];
    for (int i = 1; i < C; ++i) {
        ways *= fact[tally[i]] * fact[tally[i]];
    }

    cout << f << " " << ways << "\n";
}