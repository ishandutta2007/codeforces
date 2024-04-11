// vvvvvvvvvvvvvvvvv Library code start


#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>


#define forn(t, i, n) for (t i = 0; i < (n); ++i)
#define foran(t, i, a, n) for (t i = (a); i < (n); ++i)


using namespace std;

// TC_REMOVE_BEGIN
/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);
// TC_REMOVE_END


template<class T>
inline T mx(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mx(T arg, Ts... args) {
    auto arg1 = mx(args...);
    return arg > arg1 ? arg : arg1;
}


// Section with adoption of array and vector algorithms.


#include <cmath>


template <class T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

//TODO extended gcd


// TODO(alf): Tests


// TODO: test on timus problem
// vector<double> polynomeEquationSolve() {}

//struct Rational {
//    pair<int64, int64> num;
//
//    Rational(int64 num_, int64 denom_) {
//        num = {num_, denom_};
//        if (!num.second) {
//            throw 42;
//        }
//        int64 gcd = abs(gcd(num.first, num.second));
//        if (num.second > 0) {
//            num.first /= gcd;
//            num.second /= gcd;
//        } else {
//            num.first = -num.first / gcd;
//            num.second = -num.second / gcd;
//        }
//    }
//
//    bool operator < (const Rational& p) const {
//        return num.first * p.num.second < num.second * p.num.first;
//    }
//
//    bool operator == (const Rational& p) const {
//        return num.first * p.num.second == num.second * p.num.first;
//    }
//
//    pair<int64, int64> asPair() const {
//        return num;
//    }
//};


#define ENABLE_IF(e) typename enable_if<e>::type* = nullptr

namespace template_util {
    template<class T>
    constexpr T min(T a, T b) {
        return a < b ? a : b;
    }

    
    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        typedef uint64_t type;
    };

    template<>
    struct bytetype<4> {
        typedef uint32_t type;
    };

    template<>
    struct bytetype<3> {
        typedef uint32_t type;
    };

    
    template<>
    struct bytetype<1> {
        typedef uint8_t type;
    };

    template<>
    struct bytetype<0> {
        typedef uint8_t type;
    };

    /// caide keep
    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


#define dbg(...) ;


/*
TODOs:
 cache invs
 primitive root
 discrete log

 tests!!!
*/

namespace mod_impl {
    /// caide keep
    template <class T>
    constexpr inline T mod(T MOD) {
        return MOD;
    }

    /// caide keep
    template <class T>
    constexpr inline T mod(T* MOD) {
        return *MOD;
    }

    /// caide keep
    template <class T>
    constexpr inline T max_mod(T MOD) {
        return MOD - 1;
    }

    /// caide keep
    template <class T>
    constexpr inline T max_mod(T*) {
        return numeric_limits<T>::max() - 1;
    }

    
    constexpr inline uint64_t combine_max_sum(uint64_t a, uint64_t b) {
        return a > ~b ? 0 : a + b;
    }

    constexpr inline uint64_t combine_max_mul(uint64_t a, uint64_t b) {
        return a > numeric_limits<uint64_t>::max() / b ? 0 : a * b;
    }

    /// caide keep
    template <class T>
    constexpr inline uint64_t next_divisible(T mod, uint64_t max) {
        return max % mod == 0 ? max : combine_max_sum(max, mod - max % mod);
    }

    /// caide keep
    template <class T>
    constexpr inline uint64_t next_divisible(T*, uint64_t) {
        return 0;
    }

    //caide keep
    constexpr int IF_THRESHOLD = 2;

    template <class T, T MOD_VALUE, uint64_t MAX,
            class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
            ENABLE_IF(MAX <= max_mod(MOD_VALUE) && !is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        return value;
    }

    template <class T, T MOD_VALUE, uint64_t MAX,
            class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
            ENABLE_IF(max_mod(MOD_VALUE) < MAX && MAX <= IF_THRESHOLD * max_mod(MOD_VALUE) && !is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        while (value >= mod(MOD_VALUE)) {
            value -= mod(MOD_VALUE);
        }
        return (RET)value;
    }

    template <class T, T MOD_VALUE, uint64_t MAX,
             class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
             ENABLE_IF(IF_THRESHOLD * max_mod(MOD_VALUE) < MAX || is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        return (RET)(value % mod(MOD_VALUE));
    }
}

#define MOD mod_impl::mod(MOD_VALUE)
#define MAX_MOD mod_impl::max_mod(MOD_VALUE)

struct DenormTag {};

template <class T, T MOD_VALUE, uint64_t MAX = MAX_MOD, ENABLE_IF(MAX_MOD >= 2)>
struct ModVal {
    typedef typename template_util::minimal_uint<MAX>::type storage;
    storage value;

    /// caide keep
    inline ModVal(): value(0) {
        assert(MOD >= 2);
    }

    
    inline ModVal(storage v, DenormTag): value(v) {
        assert(MOD >= 2);
        assert(v <= MAX);
    };

    inline operator ModVal<T, MOD_VALUE>() {
        return {v(), DenormTag()};
    };

    
    typename template_util::minimal_uint<mod_impl::max_mod(MOD_VALUE)>::type v() const {
        return mod_impl::smart_mod<T, MOD_VALUE, MAX>(value);
    }
};

template <class T, T MOD_VALUE, uint64_t MAX,
        uint64_t NEW_MAX = mod_impl::next_divisible(MOD_VALUE, MAX),
        ENABLE_IF(NEW_MAX != 0),
        class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator-(const ModVal<T, MOD_VALUE, MAX>& o) {
    static_assert(NEW_MAX <= numeric_limits<typename Ret::storage>::max(), "bad unary minus template");
    assert(NEW_MAX % MOD == 0 && o.value <= NEW_MAX);
    return {typename Ret::storage(NEW_MAX - o.value), DenormTag()};
}


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_sum(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator+(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename Ret::storage(typename Ret::storage() + o1.value + o2.value), DenormTag()};
}


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_mul(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator*(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename Ret::storage(typename Ret::storage(1) * o1.value * o2.value), DenormTag()};
}


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_mul(MAX1, MAX2),
        uint64_t NEW_MAX1 = mod_impl::combine_max_mul(MAX_MOD, template_util::min(MAX1, MAX2)),
        ENABLE_IF(NEW_MAX == 0 && NEW_MAX1 != 0 && MAX2 < MAX1),
        class Ret = ModVal<T, MOD_VALUE, mod_impl::combine_max_mul(MAX_MOD, MAX2)>>
inline Ret operator*(const ModVal<T, MOD_VALUE, MAX1>& o1, const ModVal<T, MOD_VALUE, MAX2>& o2) {
    return {typename Ret::storage(typename Ret::storage(1) * o1.v() * o2.value), DenormTag()};
}

template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_mul(MAX1, MAX2),
        uint64_t NEW_MAX1 = mod_impl::combine_max_mul(MAX_MOD, template_util::min(MAX1, MAX2)),
        ENABLE_IF(NEW_MAX == 0 && NEW_MAX1 == 0),
        class Ret = ModVal<T, MOD_VALUE, mod_impl::combine_max_mul(MAX_MOD, MAX_MOD)>>
inline Ret operator*(const ModVal<T, MOD_VALUE, MAX1>& o1, const ModVal<T, MOD_VALUE, MAX2>& o2) {
    return {typename Ret::storage(typename Ret::storage(1) * o1.v() * o2.v()), DenormTag()};
}

template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2>
inline auto operator-(const ModVal<T, MOD_VALUE, MAX1>& lhs, const ModVal<T, MOD_VALUE, MAX2>& rhs) -> decltype(lhs + (-rhs)) {
    return lhs + (-rhs);
}

template <class T, T MOD_VALUE, uint64_t MAX>
inline ModVal<T, MOD_VALUE>& operator+=(ModVal<T, MOD_VALUE>& lhs, const ModVal<T, MOD_VALUE, MAX>& rhs) {
    lhs = lhs + rhs;
    return lhs;
}

template <class T, T MOD_VALUE, uint64_t MAX>
inline ModVal<T, MOD_VALUE>& operator-=(ModVal<T, MOD_VALUE>& lhs, const ModVal<T, MOD_VALUE, MAX>& rhs) {
    lhs = lhs - rhs;
    return lhs;
}

template <class T, T MOD_VALUE, uint64_t MAX>
inline ModVal<T, MOD_VALUE>& operator*=(ModVal<T, MOD_VALUE>& lhs, const ModVal<T, MOD_VALUE, MAX>& rhs) {
    lhs = lhs * rhs;
    return lhs;
}


template <class T, T MOD_VALUE, class MOD_TYPE>
struct ModCompanion {
    typedef MOD_TYPE mod_type;
    typedef ModVal<mod_type, MOD_VALUE> type;
    

    template <uint64_t C>
    inline static constexpr ModVal<mod_type, MOD_VALUE, C> c() {
        return {C, DenormTag()};
    };

    template <uint64_t MAX = numeric_limits<uint64_t>::max()>
    inline static ModVal<mod_type, MOD_VALUE, MAX> wrap(uint64_t x) {
        assert(x <= MAX);
        return {typename ModVal<mod_type, MOD_VALUE, MAX>::storage(x), DenormTag()};
    };

    template <uint64_t MAX, ENABLE_IF(!is_pointer<T>::value && MAX <= MAX_MOD)>
    inline static ModVal<mod_type, MOD_VALUE> inv(const ModVal<mod_type, MOD_VALUE, MAX>& x) {
        if (x.value == 1) {
            return c<1>();
        }
        return -(wrap<MAX_MOD / 2>(MOD / x.value) * inv(wrap<MAX>(MOD % x.value)));
    };

    
    template <uint64_t MAX>
    inline static ModVal<mod_type, MOD_VALUE> pow(const ModVal<mod_type, MOD_VALUE, MAX>& x, uint64_t n) {
        if (n == 0) {
            return c<1>();
        }
        auto v = pow(x * x, n / 2);
        return (n & 1) ? x * v : v;
    };
};


#undef MOD
#undef MAX_MOD

template <uint64_t MOD_VALUE>
struct Mod : ModCompanion<uint64_t, MOD_VALUE, typename template_util::minimal_uint<MOD_VALUE>::type> {
    template<uint64_t VAL>
    static constexpr uint64_t literal_builder() {
        return VAL;
    }

    template<uint64_t VAL, char DIGIT, char... REST>
    static constexpr uint64_t literal_builder() {
        return literal_builder<(10 * VAL + DIGIT - '0') % MOD_VALUE, REST...>();
    }
};


#define REGISTER_MOD_LITERAL(mod, suffix) \
template <char... DIGITS> mod::type operator "" _##suffix() { \
    return mod::c<mod::literal_builder<0, DIGITS...>()>(); \
}


template <class T, T MOD_VALUE, uint64_t MAX>
inline ostream& operator<<(ostream& s, ModVal<T, MOD_VALUE, MAX> val) {
    s << val.v();
    return s;
}

// ^^^^^^^^^^^^^^^^^ Library code end

using md = Mod<1000000007>;
using mt = md::type;
REGISTER_MOD_LITERAL(md, mod)

void solve(istream& in, ostream& out) {
    string s1 = next<string>(in);
    string s2 = next<string>(in);
    int n = next<int>(in);
    int nom = 0, denom = 0, addNom = 0, addDenom = 0;
    for (char c : s1) {
        if (c == 'B') {
            denom--;
        } else {
            nom++;
            if (c == '?') {
                addNom++;
            }
        }
    }
    for (char c : s2) {
        if (c == 'A') {
            nom--;
        } else {
            denom++;
            if (c == '?') {
                addDenom++;
            }
        }
    }
    mt perfectMatch = 0_mod;
    if (s1.length() == s2.length()) {
        perfectMatch = 1_mod;
        forn (int, i, s1.length()) {
            if (s1[i] == '?') {
                if (s2[i] == '?') {
                    perfectMatch *= 2_mod;
                }
            } else if (s1[i] != s2[i] && s2[i] != '?') {
                perfectMatch = 0_mod;
                break;
            }
        }
    }
    mt totalStrs = md::pow(2_mod, n + 1) - 2_mod;
    mt ans = perfectMatch * totalStrs * totalStrs;
    vector<mt> fs(addNom + addDenom + 1), invFs(addNom + addDenom + 1);
    fs[0] = invFs[0] = 1_mod;
    foran (int, i, 1, fs.size()) {
        fs[i] = fs[i - 1] * md::wrap<1000001>(i);
        invFs[i] = md::inv(fs[i]);
    }
    for (int delta = 0; delta <= addNom + addDenom; ++delta) {
        auto cnt = fs[addNom + addDenom] * invFs[delta] * invFs[addNom + addDenom - delta];
        int x = nom - delta, y = denom - delta;
        if (x < 0 && y < 0) {
            x *= -1;
            y *= -1;
        }
        if (x == 0 && y == 0) {
            mt any = 0_mod;
            vector<mt> f(n + 1);
            foran (int, i, 1, n + 1) {
                f[i] += md::pow(2_mod, i);
                auto maxCnt = md::wrap<1000000>(n / i);
                any += f[i] * maxCnt * maxCnt;
                for (int j = 2 * i; j <= n; j += i) {
                    f[j] -= f[i];
                }
            }
            dbg(f, any, cnt, perfectMatch);
            ans += (cnt - perfectMatch) * any;
        } else if (x > 0 && y > 0) {
            int g = gcd(x, y);
            x /= g;
            y /= g;
            mt cur = md::pow(2_mod, n / mx(x, y) + 1) - 2_mod;
            dbg(x, y, cnt, cur);
            ans += cnt * cur;
        }
    }
    out << ans;
}


int main() {
    solve(cin, cout);
    return 0;
}