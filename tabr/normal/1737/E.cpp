#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
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
        value = value * a % mod;
        return *this;
    }
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

constexpr long long mod = (int) 1e9 + 7;
using mint = modular<mod>;

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

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

void Cinit(int n) {
    fact = vector<mint>(n + 1);
    finv = vector<mint>(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n] = 1 / fact[n];
    for (int i = n - 1; i >= 0; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = (int) 1e6 + 10;
    vector<mint> invp2(N);
    invp2[0] = 1;
    for (int i = 1; i < N; i++) {
        invp2[i] = invp2[i - 1] * 500000004;
    }
    vector<mint> p2(N);
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    Cinit(N);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        vector<mint> ans;
        vector<mint> dp(n);
        dp[0] = 1;
        mint sum_dp = 0;
        int j = 0;
        for (int i = 0; i < n - 1; i++) {
            while (j < i && i - (n - i) >= j) {
                sum_dp -= dp[j] * invp2[i - j];
                j++;
            }
            mint p = dp[i];
            // for (int j = 1; j < n - i && i - j >= 0; j++) {
            //     p += dp[i - j] * invp2[j];
            // }
            p += sum_dp;
            dp[i] = p;
            dp[0] = 2;
            sum_dp += dp[i];
            sum_dp *= invp2[1];
            // int l = n - i;
            // for (int c = 0; c * l <= i; c++) {
            //     p += C(i - c * l + c, c) * p2[i - c * l] * (c % 2 == 0 ? 1 : -1);
            // }
            // int j = i - l;
            // for (int c = 0; c * l <= j; c++) {
            //     p -= C(j - c * l + c, c) * p2[j - c * l] * (c % 2 == 0 ? 1 : -1);
            // }
            // p *= invp2[i];
            // debug(i, p);
            p *= invp2[(n + i + 1) / 2 - i];
            ans.emplace_back(p);
        }
        ans[0] *= 2;
        ans.emplace_back(0);
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}