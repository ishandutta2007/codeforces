#include <bits/stdc++.h>
using namespace std;

const int M = 998244353, L = 64;

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

using poly = vector<mint>;
const mint G = 3;

void fft(poly& a) {
    int n = a.size();

    vector<int> reverse(n);
    for (int i = 0; i < n; ++i) {
        reverse[i] = (reverse[i / 2] + (i % 2) * n) / 2;
        if (i < reverse[i]) {
            swap(a[i], a[reverse[i]]);
        }
    }

    for (int i = 1; i < n; i *= 2) {
        mint ratio = G.pow((M - 1) / i / 2);
        for (int j = 0; j < n; j += 2 * i) {
            mint root = 1;
            for (int k = 0; k < i; ++k) {
                mint l = a[j + k];
                mint r = a[i + j + k] * root;
                a[j + k] = l + r;
                a[i + j + k] = l - r;
                root *= ratio;
            }
        }
    }
}

poly operator*(poly a, poly b) {
    if (min(a.size(), b.size()) <= L) {
        poly c(a.size() + b.size() - 1);
        for (int i = 0; i < (int) a.size(); ++i) {
            for (int j = 0; j < (int) b.size(); ++j) {
                c[i + j] += a[i] * b[j];
            }
        }
        return c;
    }

    int n = 1, m = a.size() + b.size();
    while (n < m) {
        n *= 2;
    }

    a.resize(n), b.resize(n);
    fft(a), fft(b);

    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }
    fft(a);

    mint inv = mint(n).pow();
    for (auto &i : a) {
        i *= inv;
    }
    reverse(a.begin() + 1, a.end());

    a.resize(m - 1);
    return a;
}

poly operator+(poly a, poly b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }

    for (int i = 0; i < (int) b.size(); ++i) {
        a[i] += b[i];
    }
    return a;
}

poly operator-(const poly a, const poly &b) {
    return a + poly{-1} * b;
}

poly mod(const poly &a, int n) {
    if ((int) a.size() > n) {
        return poly(a.begin(), a.begin() + n);
    } else {
        return a;
    }
}

poly inv(const poly &a, int n) {
    int k = 1;
    poly p = {a[0].pow()};
    while (k < n) {
        k *= 2;
        p = mod(p * (poly{2} - p * mod(a, k)), k);
    }
    return mod(p, n);
}

poly sqrt(const poly &a, int n) {
    int k = 1;
    poly p = {1};
    while (k < n) {
        k *= 2;
        p = poly{mint(2).pow()} * mod(p + mod(a, k) * inv(p, k), k);
    }
    return mod(p, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    poly c;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x >= (int) c.size()) {
            c.resize(x + 1);
        }

        c[x] = 1;
    }

    poly ans = poly{2} * inv(poly{1} + sqrt(poly{1} - poly{4} * c, m + 1), m + 1);
    ans.resize(m + 1);

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << "\n";
    }
}