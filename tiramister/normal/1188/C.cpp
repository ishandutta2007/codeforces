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

template <class T>
T Vec(T v) { return v; }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return std::vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}


using namespace std;
using mint = ModInt<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (auto& a : A) cin >> a;
    A.push_back(-1);
    sort(A.begin(), A.end());
    N = A.size() - 1;

    vector<int> prev(A.back() + 1);
    int itr = N;
    for (int x = A.back(); x >= 0; --x) {
        while (A[itr] > x) --itr;
        prev[x] = itr;
    }

    int MAXX = A.back() / (K - 1);
    vector<mint> pat(MAXX + 2, 0);

    auto dp = Vec<mint>(N + 1, K + 1, mint(0));
    for (int x = 1; x <= MAXX; ++x) {
        // count substrings whose beauty is no less than x

        for (auto& v : dp) fill(v.begin(), v.end(), mint(0));
        dp[0][0] = 1;
        // #substrings of A[1..i] whose length is k

        for (int i = 1; i <= N; ++i) {
            // don't use A[i]
            for (int k = 0; k <= K; ++k) {
                dp[i][k] += dp[i - 1][k];
            }

            // use A[i]
            dp[i][1] += 1;
            for (int k = 1; k < K; ++k) {
                // A[j] should be no more than A[i] - x.
                if (A[i] >= x) {
                    dp[i][k + 1] += dp[prev[A[i] - x]][k];
                }
            }
        }
        pat[x] = dp[N][K];
    }

    mint ans = 0;
    for (int x = 1; x <= MAXX; ++x) {
        ans += (pat[x] - pat[x + 1]) * x;
    }

    cout << ans << endl;
    return 0;
}