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


using namespace std;

// TC_REMOVE_BEGIN
/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);
// TC_REMOVE_END


// Section with adoption of array and vector algorithms.


#define ENABLE_IF(e) typename enable_if<e>::type* = nullptr

namespace template_util {
    

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

    
    /// caide keep
    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


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
             ENABLE_IF(IF_THRESHOLD * max_mod(MOD_VALUE) < MAX || is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        return (RET)(value % mod(MOD_VALUE));
    }
}


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


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_mul(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator*(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename Ret::storage(typename Ret::storage(1) * o1.value * o2.value), DenormTag()};
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

    
};


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


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


#define dbg(...) ;


// ^^^^^^^^^^^^^^^^^ Library code end

using md = Mod<1000000007>;
using mt = md::type;
REGISTER_MOD_LITERAL(md, mod)

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    unordered_map<int, int> p;
    forn (int, i, n) {
        int a = next<int>(in) - 1;
        int b = next<int>(in) - 1;
        p[a] = b;
    }
    vector<int> targets;
    for (auto pr : p) {
        if (!p.count(pr.second)) {
            targets.push_back(pr.second);
        }
    }
    for (int x : targets) {
        p[x] = -1;
    }
    int cs = 0;
    unordered_map<int, int> toComp;
    for (auto pr : p) {
        int i = pr.first;
        while (i != -1 && !toComp.count(i)) {
            toComp[i] = -1;
            i = p[i];
        }
        int c;
        if (i == -1 || toComp[i] == -1) {
            c = cs++;
        } else {
            c = toComp[i];
        }
        i = pr.first;
        while (i != -1 && toComp[i] == -1) {
            toComp[i] = c;
            i = p[i];
        }
    }
    vector<int> compSize(cs);
    vector<bool> isTree(cs), badLoop(cs);
    for (auto pr : toComp) {
        compSize[pr.second]++;
        if (p[pr.first] == -1) {
            isTree[pr.second] = true;
        }
        if (p[pr.first] == pr.first) {
            badLoop[pr.second] = true;
        }
    }
    dbg(compSize);
    dbg(isTree);
    dbg(badLoop);
    mt ans = 1_mod;
    forn (int, c, cs) {
        if (isTree[c]) {
            ans *= md::wrap<1000000>(compSize[c]);
        } else if (!badLoop[c]) {
            ans *= 2_mod;
        }
    }
    out << ans << endl;
}


int main() {
    solve(cin, cout);
    return 0;
}