#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 2001, M = 1000000007;

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

mint sum[N][N], ways[N][N];
bool solved[N][N];
string s, t;
int n;

bool matches(int a, char b) {
    return b == '?' || b == a + '0';
}

pair<mint, mint> solve(int suffix, int offset) {
    if (suffix == n) return {0, offset == 0};

    if (!solved[suffix][offset + n]) {
        sum[suffix][offset + n] = ways[suffix][offset + n] = 0;
        for (int i : {0, 1}) {
            for (int j : {0, 1}) {
                if (matches(i, s[suffix]) && matches(j, t[suffix])) {
                    int offset_new = j - (i + offset);
                    auto [sum_nxt, ways_nxt] = solve(suffix + 1, offset_new);
                    sum[suffix][offset + n] += sum_nxt + abs(offset_new) * ways_nxt;
                    ways[suffix][offset + n] += ways_nxt; 
                }
            }
        }
        solved[suffix][offset + n] = true;\
    }

    return {sum[suffix][offset + n], ways[suffix][offset + n]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test; cin >> test;

    while (test--) {
        cin >> n >> s >> t;
        for (int i = 0; i < n; ++i) {
            fill(solved[i], solved[i] + N, false);
        }
        cout << solve(0, 0).first << "\n";
    }
}