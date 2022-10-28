#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

struct mint {
    int x;

    mint() : x(0) {}

    template <class T> mint(T value) : x(value % M) { if (x < 0) x += M; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= M) x -= M; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += M; return *this; }

    mint & operator*=(const mint &oth) { x = (int) ((long long) x * oth.x % M); return *this; }

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

const int N = 23, ALPHA_SIZE = 26;

short char_count[1 << N][ALPHA_SIZE];
mint num_strings[1 << N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        for (auto c : s) {
            ++char_count[1 << i][c - 'a'];
        }
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        if (popcount((unsigned) mask) > 1) {
            for (int i = 0; i < ALPHA_SIZE; ++i) {
                char_count[mask][i] = min(
                    char_count[bit_floor((unsigned) mask)][i],
                    char_count[mask ^ bit_floor((unsigned) mask)][i]
                );
            }
        }

        num_strings[mask] = 1;
        for (int i = 0; i < ALPHA_SIZE; ++i) {
            num_strings[mask] *= char_count[mask][i] + 1;
        }

        if (popcount((unsigned) mask) % 2 == 0) num_strings[mask] *= -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            if ((mask & (1 << i)) == 0) {
                num_strings[mask ^ (1 << i)] += num_strings[mask];
            }
        }
    }

    long long ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum_indices = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) > 0) sum_indices += i + 1;
        }
        ans ^= (long long) num_strings[mask].x * popcount((unsigned) mask) * sum_indices;
    }

    cout << ans << "\n";
}