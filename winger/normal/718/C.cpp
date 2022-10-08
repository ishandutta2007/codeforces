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


#define F1(e) [&](size_t i1) {return e;}


using namespace std;

// TC_REMOVE_BEGIN
/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);
// TC_REMOVE_END


template <class T>
T gen_pow(T ret, T x, uint64_t pow) {
    while (pow) {
        if (pow & 1) {
            ret *= x;
        }
        pow /= 2;
        if (pow) {
            x *= x;
        }
    }
    return ret;
}


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


namespace segment_tree_impl {
    size_t calc_size(size_t n) {
        size_t ret = 1;
        while (ret < n) {
            ret *= 2;
        }
        return ret;
    }
}


template <class T>
struct SimplePropagateDown {
    static inline void propagate_down(size_t, size_t, size_t, T& p, T& l, T& r) {
        l.apply_updates(p);
        r.apply_updates(p);
        p.clear_updates();
    }
};


template <class T>
struct InplaceFixUp {
    static inline void fix_up(size_t, size_t, size_t, T& p, T& l, T& r) {
        p = l;
        p.clear_updates();
        p.compose(r);
    }
};

template <class T>
struct stree {
    

    template<class F>
    stree(size_t n, F f): n_(n), size(segment_tree_impl::calc_size(n)), ar(2 * size - 1) {
        for (int i = 0; i < n; ++i) {
            ar[size - 1 + i] = f(i);
        }
        init(0, 0, size);
    }

    
    template <class T1 = T>
    T1 sum_range(size_t l, size_t r, T1 v = {}) {
        assert(l <= r && r <= n_);
        if (l == r) {
            return {};
        }
        sum_range(0, 0, size, l, r, v);
        return v;
    }

    template <class U>
    void update_range(size_t l, size_t r, U u) {
        assert(l <= r && r <= n_);
        update_range(0, 0, size, l, r, u);
    }

    
protected:

    void init(size_t n, size_t nl, size_t nr) {
        if (nl + 1 == nr) {
            return;
        }
        size_t mid = (nl + nr) / 2;
        init(2 * n + 1, nl, mid);
        init(2 * n + 2, mid, nr);
        T::fix_up(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    inline void fix_up(size_t n, size_t nl, size_t mid, size_t nr) {
        T::fix_up(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    inline void propagate_down(size_t n, size_t nl, size_t mid, size_t nr) {
        if (nl + 1 == nr) {
            return;
        }
        T::propagate_down(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    template <class T1>
    void sum_range(size_t n, size_t nl, size_t nr, size_t l, size_t r, T1& out) {
        assert(l < nr && nl < r);
        size_t mid = (nl + nr) / 2;
        propagate_down(n, nl, mid, nr);
        if (l <= nl && nr <= r) {
            out.compose(ar[n]);
            return;
        }
        if (l < mid) {
            sum_range(2 * n + 1, nl, mid, l, r, out);
        }
        if (mid < r) {
            sum_range(2 * n + 2, mid, nr, l, r, out);
        }
    }

    template <class U>
    void update_range(size_t n, size_t nl, size_t nr, size_t l, size_t r, U u) {
        assert(l < nr && nl < r);
        if (l <= nl && nr <= r) {
            ar[n].apply_updates(u);
            return;
        }
        size_t mid = (nl + nr) / 2;
        propagate_down(n, nl, mid, nr);
        if (l < mid) {
            update_range(2 * n + 1, nl, mid, l, r, u);
        }
        if (mid < r) {
            update_range(2 * n + 2, mid, nr, l, r, u);
        };
        fix_up(n, nl, mid, nr);
    }

    
    const size_t n_, size;
    vector<T> ar;
};


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

    explicit inline operator uint64_t() const {
        return v();
    }

    typename template_util::minimal_uint<mod_impl::max_mod(MOD_VALUE)>::type v() const {
        return mod_impl::smart_mod<T, MOD_VALUE, MAX>(value);
    }
};


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


template <class T, T MOD_VALUE, class MOD_TYPE>
struct ModCompanion {
    typedef MOD_TYPE mod_type;
    typedef ModVal<mod_type, MOD_VALUE> type;
    

    template <uint64_t C>
    inline static constexpr ModVal<mod_type, MOD_VALUE, C> c() {
        return {C, DenormTag()};
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


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

template<class T>
vector<T> next_vector(istream& in, size_t n) {
    vector<T> ret(n);
    for (size_t i = 0; i < n; ++i) {
        ret[i] = next<T>(in);
    }
    return ret;
}


// ^^^^^^^^^^^^^^^^^ Library code end

const uint32_t mod = 1000000007;
typedef Mod<mod> md;
typedef md::type mt;
REGISTER_MOD_LITERAL(md, mod)

struct Fib {
    mt a = 1_mod, b = 0_mod;

    Fib(mt a, mt b): a(a), b(b) {}
};

const Fib fibone = {1_mod, 0_mod}, fibzero = {0_mod, 0_mod}, X = {0_mod, 1_mod};

Fib& operator+=(Fib& l, Fib r) {
    return l = {l.a + r.a, l.b + r.b};
}

Fib& operator*=(Fib& l, Fib r) {
    auto tmp = l.b * r.b;
    return l =  {l.a * r.a + tmp, l.a * r.b + l.b * r.a + tmp};
}

struct Val : SimplePropagateDown<Val>, InplaceFixUp<Val> {
    Fib range_update = fibone, sum = fibzero;

    Val() {}

    Val(Fib f): sum(f) {}

    void apply_updates(const Val& o) {
        sum *= o.range_update;
        range_update *= o.range_update;
    }

    void apply_updates(const Fib& o) {
        sum *= o;
        range_update *= o;
    }

    void clear_updates() {
        range_update = fibone;
    }

    void compose(const Val& o) {
        sum += o.sum;
    }
};

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    int m = next<int>(in);
    auto a = next_vector<int>(in, n);
    stree<Val> t(n, F1(gen_pow(fibone, X, a[i1])));
    for (int i = 0; i < m; ++i) {
        if (next<int>(in) == 1) {
            int l = next<int>(in) - 1;
            int r = next<int>(in);
            int x = next<int>(in);
            t.update_range(l, r, gen_pow(fibone, X, x));
        } else {
            int l = next<int>(in) - 1;
            int r = next<int>(in);
            out << (uint64_t)(t.sum_range(l, r).sum.b) << endl;
        }
    }
}


int main() {
    solve(cin, cout);
    return 0;
}