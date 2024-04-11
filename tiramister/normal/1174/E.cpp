#include <iostream>
#include <algorithm>
#include <vector>

template <int MOD>
class ModInt {
    using lint = long long;

public:
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // assignment
    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->val = x.val; }
        return *this;
    }

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator~() const { return *this ^ (MOD - 2); }

    // increment / decrement
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt before = *this;
        ++(*this);
        return before;
    }
    ModInt operator--(int) {
        ModInt before = *this;
        --(*this);
        return before;
    }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator%(const ModInt& x) const { return ModInt(*this) %= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt operator^(const ModInt& x) const { return ModInt(*this) ^= x; }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator%=(const ModInt& x) {
        val %= x.val;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= ~x; }
    ModInt& operator^=(const ModInt& x) {
        int n = x.val;
        ModInt b = *this;
        if (n < 0) n = -n, b = ~b;

        *this = 1;
        while (n > 0) {
            if (n & 1) *this *= b;
            n >>= 1;
            b *= b;
        }
        return *this;
    }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
};

using namespace std;


using mint = ModInt<1000000007>;

mint calc(const vector<int>& A, int N) {
    vector<bool> used(N + 1, false);
    vector<mint> cnt(A.size(), 0);

    int prod = 1;
    for (int i = 0; i < A.size(); ++i) {
        prod *= A[i];
        // prod
        for (int p = 1; p <= N; ++p) {
            if (!used[p] && p % prod != 0) {
                ++cnt[i];
                used[p] = true;
            }
        }
    }

    mint elem = 0, ret = 1;
    for (int i = 0; i < A.size(); ++i) {
        // cnt[i]
        ret *= cnt[i];

        // (elem + 1)*...*(elem + cnt[i] - 1)
        for (mint n = elem + 1; n < elem + cnt[i]; ++n) {
            ret *= n;
        }
        elem += cnt[i];
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    int two = 30;
    while (N < (1 << two)) --two;

    mint ans = 0;
    vector<int> A(two, 2);
    ans += calc(A, N);

    if ((1 << (two - 1)) * 3 <= N) {
        A.back() = 3;
        do {
            ans += calc(A, N);
        } while (next_permutation(A.begin(), A.end()));
    }

    cout << ans << endl;
    return 0;
}