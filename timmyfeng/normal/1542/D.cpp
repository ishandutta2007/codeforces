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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '-') {
            a[i] = -1;
        } else {
            cin >> a[i];
        }
    }

    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            continue;
        }

        vector<mint> ways(n);
        ways[0] = 1;

        for (int j = 0; j < i; ++j) {
            vector<mint> new_ways(n);
            for (int k = 0; k < n; ++k) {
                if (a[j] == -1) {
                    new_ways[max(0, k - 1)] += ways[k];
                    new_ways[k] += ways[k];
                } else if (a[j] <= a[i]) {
                    new_ways[min(n - 1, k + 1)] += ways[k];
                    new_ways[k] += ways[k];
                } else {
                    new_ways[k] += 2 * ways[k];
                }
            }
            swap(ways, new_ways);
        }

        for (int j = i + 1; j < n; ++j) {
            vector<mint> new_ways(n);
            for (int k = 0; k < n; ++k) {
                if (a[j] == -1) {
                    if (k > 0) {
                        new_ways[k - 1] += ways[k];
                    }
                    new_ways[k] += ways[k];
                } else if (a[j] < a[i]) {
                    new_ways[min(n - 1, k + 1)] += ways[k];
                    new_ways[k] += ways[k];
                } else {
                    new_ways[k] += 2 * ways[k];
                }
            }
            swap(ways, new_ways);
        }

        ans += accumulate(ways.begin(), ways.end(), mint()) * a[i];

        
    }

    cout << ans << "\n";
}