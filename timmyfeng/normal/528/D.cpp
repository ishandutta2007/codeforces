#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
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

void fft(vector<mint>& a) {
    int n = a.size();

    vector<int> reverse(n);
    for (int i = 0; i < n; ++i) {
        reverse[i] = (reverse[i / 2] + (i % 2) * n) / 2;
        if (i < reverse[i]) {
            swap(a[i], a[reverse[i]]);
        }
    }

    for (int i = 1; i < n; i *= 2) {
        mint root = mint(3).pow((M - 1) / 2 / i);
        for (int j = 0; j < n; j += 2 * i) {
            mint cur = 1;
            for (int k = 0; k < i; ++k) {
                mint l = a[j + k];
                mint r = a[i + j + k] * cur;
                a[j + k] = l + r;
                a[i + j + k] = l - r;
                cur *= root;
            }
        }
    }
}

vector<mint> mul(vector<mint> a, vector<mint> b) {
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

const string D = "AGTC";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    string s, t, chain;
    cin >> n >> m >> k >> s >> t;

    vector<vector<int>> sum(n + 1, vector<int>(4));
    for (int i = 0; i < n; ++i) {
        copy(sum[i].begin(), sum[i].end(), sum[i + 1].begin());
        ++sum[i + 1][find(D.begin(), D.end(), s[i]) - D.begin()];
    }

    vector<mint> f;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 4; ++j) {
            f.push_back(find(D.begin(), D.end(), t[i]) - D.begin() == j);
        }
    }

    vector<mint> g;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            g.push_back(sum[min(n, i + k + 1)][j] - sum[max(0, i - k)][j] > 0);
        }
    }

    reverse(f.begin(), f.end());
    vector<mint> h = mul(f, g);

    int ones = count(f.begin(), f.end(), 1), ans = 0;
    for (int i = 0; i + m <= n; ++i) {
        ans += h[4 * (i + m) - 1] == ones;
    }

    cout << ans << "\n";
}