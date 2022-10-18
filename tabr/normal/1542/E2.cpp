#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int mod = 2;

struct mint {
    int value;
    mint(int x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    mint& operator+=(const mint& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    mint& operator-=(const mint& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    mint& operator*=(const mint& other) {
        value = (int) (1LL * value * other.value % mod);
        return *this;
    }
    mint& operator/=(const mint& other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = (int) (value * a % mod);
        return *this;
    }
    mint operator+(const mint& rhs) const { return mint(*this) += rhs; }
    mint operator-(const mint& rhs) const { return mint(*this) -= rhs; }
    mint operator*(const mint& rhs) const { return mint(*this) *= rhs; }
    mint operator/(const mint& rhs) const { return mint(*this) /= rhs; }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) {
        mint result(*this);
        *this += 1;
        return result;
    }
    mint operator--(int) {
        mint result(*this);
        *this -= 1;
        return result;
    }
    mint operator-() const { return mint(-value); }
    bool operator==(const mint& rhs) const { return value == rhs.value; }
    bool operator!=(const mint& rhs) const { return value != rhs.value; }
    bool operator<(const mint& rhs) const { return value < rhs.value; }
};
string to_string(const mint& x) {
    return to_string(x.value);
}
ostream& operator<<(ostream& stream, const mint& x) {
    return stream << x.value;
}
istream& operator>>(istream& stream, mint& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

mint power(mint a, long long n) {
    mint res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    if (mod == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<mint>> dp(n + 1), aux(n + 1), auy(n + 1), auz(n + 1);
    vector<mint> b(n + 2);
    for (int i = n; i <= n; i++) {
        vector<mint> f(i * (i - 1) / 2 + 1);
        f[0] = 1;
        dp[1].emplace_back(1);
        for (int j = 1; j < i; j++) {
            vector<mint> new_f(i * (i - 1) / 2 + 1);
            mint s = 0;
            for (int k = 0; k < (int) new_f.size(); k++) {
                s += f[k];
                new_f[k] = s;
                if (k - j >= 0) {
                    s -= f[k - j];
                }
            }
            swap(f, new_f);
            dp[j + 1] = f;
            dp[j + 1].resize((j + 1) * j / 2 + 1);
            aux[j + 1] = dp[j + 1];
            int ii = j + 1;
            for (int jj = (int) dp[ii].size() - 1; jj > 0; jj--) {
                aux[ii][jj - 1] += aux[ii][jj];
            }
            auy[ii] = aux[ii];
            for (int jj = (int) dp[ii].size() - 1; jj > 0; jj--) {
                auy[ii][jj - 1] += auy[ii][jj];
            }
            auy[ii].emplace_back(0);
            swap(auz[ii], aux[ii]);
            for (int jj = (int) dp[ii].size() - 1; jj >= 0; jj--) {
                auz[ii][jj] *= jj;
            }
            for (int jj = (int) dp[ii].size() - 1; jj > 0; jj--) {
                auz[ii][jj - 1] += auz[ii][jj];
            }
            auz[ii].emplace_back(0);
            ii++;
            for (int jj = 0; jj + 2 < (int) dp[ii - 1].size(); jj++) {
                int l = min(ii, (int) dp[ii - 1].size() - jj - 1);
                mint t = (auy[ii - 1][jj + 2] - auy[ii - 1][jj + l + 1]) * (ii - 1 + jj + 2);
                t -= (auz[ii - 1][jj + 2] - auz[ii - 1][jj + l + 1]);
                b[ii] += dp[ii - 1][jj] * t;
            }
            ii--;
            vector<mint>().swap(dp[ii]);
            vector<mint>().swap(aux[ii]);
            vector<mint>().swap(auy[ii]);
            vector<mint>().swap(auz[ii]);
        }
    }
    mint ans = 0;
    vector<mint> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    vector<vector<mint>> C(n + 1, vector<mint>(n + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= n; i++) {
        ans += C[n][i] * fact[i] * b[n - i];
    }
    cout << ans << '\n';
    return 0;
}