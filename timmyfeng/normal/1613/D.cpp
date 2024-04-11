#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<mint> total_one_greater(n + 2);
        vector<mint> total_all_less(n + 2);
        total_all_less[0] = 1;

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            if (a > 0) {
                total_one_greater[a - 1] += total_all_less[a - 1] + total_one_greater[a - 1];
            }

            total_all_less[a + 1] += total_all_less[a + 1];
            total_one_greater[a + 1] += total_one_greater[a + 1];

            total_all_less[a + 1] += total_all_less[a];
        }

        mint ans = 0;
        for (int i = 0; i < n + 2; ++i) {
            ans += total_one_greater[i] + total_all_less[i];
        }

        cout << ans - 1 << "\n";
    }
}