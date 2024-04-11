#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T, class E>
constexpr T fexp(T x, E e) {
    T ans(1);
    for(; e > 0; e >>= 1) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    return ans;
}


template <class LOW, class HIGH, const LOW mod>
struct modBase {
    using mint = modBase<LOW, HIGH, mod>;
    constexpr modBase() : val(0) {}
    // be careful of negative numbers!
    constexpr modBase(const LOW v) : val((v % mod + mod) % mod) {} 
    LOW val;

    #define add(a, b) a + b >= mod ? a + b - mod : a + b
    #define sub(a, b) a < b ? a + mod - b : a - b

    constexpr mint &operator += (const mint &o) { return val = add(val, o.val), *this; }
    constexpr mint &operator -= (const mint &o) { return val = sub(val, o.val), *this; }
    constexpr mint &operator *= (const mint &o) { return val = (LOW) ((HIGH) val * o.val % mod), *this; }
    constexpr mint &operator /= (const mint &o) { return *this *= o.inverse(); }

    constexpr mint operator + (const mint &b) const { return mint(*this) += b; }
    constexpr mint operator - (const mint &b) const { return mint(*this) -= b; }
    constexpr mint operator * (const mint &b) const { return mint(*this) *= b; }
    constexpr mint operator / (const mint &b) const { return mint(*this) /= b; }

    constexpr mint operator - () const { return mint() - mint(*this); }
    constexpr bool operator == (const mint &b) const { return val == b.val; }
    constexpr bool operator != (const mint &b) const { return val != b.val; }

    template<class E> constexpr mint pow (E e) const { return fexp(*this, e); }
    constexpr mint inverse() const { return pow(mod - 2); }
    constexpr LOW get() const { return val; }
    static constexpr LOW getMod() { return mod; }

    friend std::ostream& operator << (std::ostream &os, const mint &p) { return os << p.val; }
    friend std::istream& operator >> (std::istream &is, mint &p) { return is >> p.val; }
};

template<const int mod> using modBase32 = modBase<int, long long, mod>;
const int MOD = 998244353;
using mint = modBase32<MOD>;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int zeroes = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            if(a[i] == 0) zeroes++;
        }
        int wrong = 0;
        for(int i = 0; i < zeroes; i++) {
            if(a[i] == 1) {
                wrong++;
            }
        }
        mint ans;
        mint totPairs = mint(n) * (n - 1) / 2;
        for(int i = 1; i <= wrong; i++) {
            int pairs = (int)((long long) i * i % MOD);
            ans += totPairs / pairs;
        }
        std::cout << ans << '\n';
    }
}