#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
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
    modular operator-() { return modular(-value); }
    modular operator+(modular rhs) { return modular(*this) += rhs; }
    modular operator-(modular rhs) { return modular(*this) -= rhs; }
    modular operator*(modular rhs) { return modular(*this) *= rhs; }
    modular operator/(modular rhs) { return modular(*this) /= rhs; }
    bool operator==(modular rhs) { return value == rhs.value; }
    bool operator!=(modular rhs) { return value != rhs.value; }
    bool operator<(modular rhs) { return value < rhs.value; }
};
template <long long mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
};
const long long mod = 998244353LL;
using mint = modular<mod>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> l[i];
        l[i] = 998244351 - l[i];
        r[i] = 998244351 - r[i];
        st.emplace_back(l[i]);
        st.emplace_back(r[i] + 1);
    }
    r[0] = 1;
    st.emplace_back(-1);
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    mint all = 1;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        all *= (r[i] + 1 - l[i]);
        l[i] = lower_bound(st.begin(), st.end(), l[i]) - st.begin();
        r[i] = lower_bound(st.begin(), st.end(), r[i] + 1) - st.begin();
    }
    int k = st.size();
    vector<vector<mint>> dp(n + 1, vector<mint>(k));
    dp[0][0] = 1;
    auto C = [&](int n, int k) {
        mint res = 1, td = 1;
        for (int i = n; i > n - k; i--) {
            res *= mint(i);
        }
        for (int i = 1; i <= k; i++) {
            td *= mint(i);
        }
        res /= td;
        return res;
    };
    for (int i = 0; i < n; i++) {
        for (int j = l[i]; j < r[i]; j++) {
            for (int t = j + 1; t < k - 1; t++) {
                int d = st[t + 1] - st[t];
                for (int s = i + 1; s <= n; s++) {
                    if (r[s] <= t || t < l[s]) {
                        break;
                    }
                    int c = s - i;
                    dp[s][t] += dp[i][j] * C(d + c - 1, c);
                }
            }
        }
    }
    mint ans = accumulate(dp[n].begin(), dp[n].end(), mint(0));
    ans /= all;
    cout << ans << '\n';
    return 0;
}