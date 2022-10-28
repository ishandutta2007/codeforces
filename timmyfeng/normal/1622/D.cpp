#include <bits/stdc++.h>
using namespace std;

const int N = 5001, M = 998244353;

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

mint choose[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (ranges::count(s, '1') < k) {
        cout << 1 << "\n";
        exit(0);
    }

    for (int i = 0; i <= n; ++i) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
        }
    }

    mint ans = 1;
    for (int i = 0; i < n; ++i) {
        int one_count = 0, zero_count = 0;
        for (int j = i; j < n; ++j) {
            one_count += s[j] == '1', zero_count += s[j] == '0';
            if (one_count <= k && j - i + 1 >= 2) {
                if (s[i] != s[j]) {
                    ans += choose[j - i - 1][one_count - 1];
                } else if (s[i] == '0' && s[j] == '0' && one_count >= 2) {
                    ans += choose[j - i - 1][one_count - 2];
                } else if (s[i] == '1' && s[j] == '1' && zero_count >= 2) {
                    ans += choose[j - i - 1][one_count];
                }
            }
        }
    }

    cout << ans << "\n";
}