#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

    int value;

    mint() : value(0) {}

    template <class T>
    mint(T x) {
        value = x % M;
        if (value < 0) {
            value += M;
        }
    }

    mint & operator++() {
        if (++value == M) {
            value = 0;
        }
        return *this;
    }

    mint & operator--() {
        if (--value == -1) {
            value = M - 1;
        }
        return *this;
    }

    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }

    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }

    mint & operator+=(mint oth) {
        value += oth.value;
        if (value >= M) {
            value -= M;
        }
        return *this;
    }

    mint & operator-=(mint oth) {
        value -= oth.value;
        if (value < 0) {
            value += M;
        }
        return *this;
    }

    mint & operator*=(mint oth) {
        value = (long long) value * oth.value % M;
        return *this;
    }

    mint operator+() const {
        return *this;
    }

    mint operator-() const {
        return mint() - *this;
    }

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

    friend mint operator+(mint a, mint b) {
        return a += b;
    }

    friend mint operator-(mint a, mint b) {
        return a -= b;
    }

    friend mint operator*(mint a, mint b) {
        return mint(a) *= b;
    }

    friend bool operator==(mint a, mint b) {
        return a.value == b.value;
    }

    friend bool operator!=(mint a, mint b) {
        return a.value != b.value;
    }

    friend ostream & operator<<(ostream &out, mint a) {
        out << a.value;
        return out;
    }

};

const int N = 100000 + 1;

mint fact[N], inv[N];

mint choose(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    } else {
        return fact[n] * inv[n - k] * inv[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
        inv[i] = fact[i].pow();
    }

    int n, k;
    string s;
    cin >> n >> k >> s;

    mint ans = 0, prefix = 0;

    for (int i = n - 2; i >= 0; --i) {
        prefix += s[n - 2 - i] - '0';
        ans += prefix * mint(10).pow(i) * choose(n - 2 - i, k - 1);
    }

    for (int i = 0; i < n; ++i) {
        ans += (s[i] - '0') * mint(10).pow(n - 1 - i) * choose(i, k);
    }

    cout << ans << "\n";
}