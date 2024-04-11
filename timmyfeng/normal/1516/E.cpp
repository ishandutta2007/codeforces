#include <bits/stdc++.h>
using namespace std;

const int N = 401, M = 1000000007;

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

mint ways[N][N];

mint solve(int n, int k) {
    mint coeff = 1, ans = 0;
    for (int i = 0; i <= 2 * (n - k); ++i) {
        if (k >= n - i) {
            ans += coeff * ways[i][k - (n - i)];
        }
        coeff *= n - i;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    ways[0][0] = 1;
    for (int i = 2; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            mint coeff = 1;
            for (int k = 1; j + i * k < N; ++k) {
                coeff *= mint(i * k).pow();
                for (int l = 0; l + k < N; ++l) {
                    ways[j + i * k][l + k] += coeff * ways[j][l];
                }
            }
        }
    }

    int n, k;
    cin >> n >> k;

    mint even = 1, odd = 0;
    for (int i = 1; i <= k; ++i) {
        if (i % 2 == 1) {
            odd += solve(n, n - i);
            cout << odd << " ";
        } else {
            even += solve(n, n - i);
            cout << even << " ";
        }
    }
}