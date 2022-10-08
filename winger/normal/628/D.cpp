// vvvvvvvvvvvvvvvvv Library code start


#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>
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

#define forn(t, i, n) for (t i = 0; i < (n); ++i)
#define all(c) c.begin(), c.end()

using namespace std;

/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


#define ENABLE_IF(e) typename enable_if<e>::type* = nullptr

namespace template_util {


    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    /// caide keep
    template<int N>
    struct bytetype {
    };

    /// caide keep
    template<>
    struct bytetype<4> {
        typedef uint32_t type;
    };

    /// caide keep
    template<>
    struct bytetype<3> {
    };

    /// caide keep
    template<>
    struct bytetype<2> {
    };

    /// caide keep
    template<>
    struct bytetype<1> {
        typedef uint8_t type;
    };

    /// caide keep
    template<>
    struct bytetype<0> {
        typedef uint8_t type;
    };

    /// caide keep
    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


/*
TODOs:
 subtraction
 inverse
 pow
 (+-*)=
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
        return numeric_limits<T>::max();
    }

    template <class T>
    constexpr inline T abs_mod(int64_t v, T mod) {
        return (T) (v < 0 ? v + mod : v);
    }

    constexpr inline uint64_t combine_max_sum(uint64_t a, uint64_t b) {
        return a > ~b ? 0 : a + b;
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

    explicit inline ModVal(int v): value(mod_impl::abs_mod(v % (int64_t)MOD, MOD)) {
        assert(MOD >= 2);
    };


    inline ModVal(storage v, DenormTag): value(v) {
        assert(MOD >= 2);
        assert(v <= MAX);
    };

    inline operator ModVal<T, MOD_VALUE>() {
        return {mod_impl::smart_mod<T, MOD_VALUE, MAX>(value), DenormTag()};
    };

    explicit inline operator uint64_t() const {
        return mod_impl::smart_mod<T, MOD_VALUE, MAX>(value);
    }
};

template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_sum(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class RET = ModVal<T, MOD_VALUE, NEW_MAX>>
inline RET operator+(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename RET::storage() + o1.value + o2.value, DenormTag()};
}


#undef MOD
#undef MAX_MOD

template <class T, T MOD_VAL, class MOD_TYPE>
struct ModCompanion {
    typedef MOD_TYPE mod_type;
    typedef ModVal<mod_type, MOD_VAL> type;
    T mod = MOD_VAL;


    template <uint64_t C>
    static constexpr ModVal<mod_type, MOD_VAL, C> c() {
        return {C, DenormTag()};
    };

};

template <uint64_t MOD_VAL>
struct Mod : ModCompanion<uint64_t, MOD_VAL, typename template_util::minimal_uint<MOD_VAL>::type> {
    template<uint64_t VAL>
    static constexpr uint64_t literal_builder() {
        return VAL;
    }

    template<uint64_t VAL, char DIGIT, char... REST>
    static constexpr uint64_t literal_builder() {
        return literal_builder<(10 * VAL + DIGIT - '0') % MOD_VAL, REST...>();
    }
};


#define REGISTER_MOD_LITERAL(mod, suffix) \
template <char... DIGITS> mod::type operator "" _##suffix() { \
    return mod::c<mod::literal_builder<0, DIGITS...>()>(); \
}


namespace index_iterator_impl {
    template <class T>
    struct member_dispatch_helper {

    private:
        T value;
    };

    // Have to caide keep all the members to comply to iterator concept
    // Otherwise generated code won't be portable between clang and g++
    template <class C, bool reverse = false>
    struct index_iterator {
        /// caide keep
        typedef random_access_iterator_tag iterator_category;
        /// caide keep
        typedef decltype(((C*)nullptr)->operator[](size_t(0))) reference;
        /// caide keep
        typedef typename remove_reference<reference>::type value_type;
        /// caide keep
        typedef ptrdiff_t difference_type;
        /// caide keep
        typedef conditional<
                is_reference<reference>::value,
                typename add_pointer<value_type>::type,
                member_dispatch_helper<value_type>> pointer;

        /// caide keep
        typedef index_iterator<C, reverse> self_t;

        /// caide keep
        static const difference_type dir = reverse ? -1 : 1;

        /// caide keep
        index_iterator() = default;

        inline index_iterator(C* containter_, difference_type index_) : container(containter_), index(index_) {}

        inline bool operator==(const self_t& o) { return index == o.index; }
        /// caide keep
        inline bool operator!=(const self_t& o) { return index != o.index; }
        /// caide keep
        inline bool operator<(const self_t& o) { return reverse ? index > o.index : index < o.index; }
        /// caide keep
        inline bool operator>(const self_t& o) { return reverse ? index < o.index : index > o.index; }
        /// caide keep
        inline bool operator<=(const self_t& o) { return reverse ? index >= o.index : index <= o.index; }
        /// caide keep
        inline bool operator>=(const self_t& o) { return reverse ? index <= o.index : index >= o.index; }

        /// caide keep
        inline reference operator*() { return (*container)[index]; }
        /// caide keep
        inline const reference operator*() const { return (*container)[index]; }
        /// caide keep
        inline pointer operator->() { return pointer((*container)[index]); }

        /// caide keep
        inline self_t& operator++() { index += dir; return *this; }
        /// caide keep
        inline self_t operator++(int) { auto copy = *this; index += dir; return copy; }
        /// caide keep
        inline self_t& operator--() { index -= dir; return *this; }
        /// caide keep
        inline self_t operator--(int) { auto copy = *this; index -= dir; return copy; }

        /// caide keep
        inline self_t& operator+=(difference_type n) { index += dir * n; return *this; };
        /// caide keep
        inline self_t& operator-=(difference_type n) { index -= dir * n; return *this; };
        /// caide keep
        inline friend self_t operator-(self_t a, difference_type n) { return a -= n; };
        /// caide keep
        inline friend self_t operator+(difference_type n, self_t a) { return a += n; };
        /// caide keep
        inline friend self_t operator+(self_t a, difference_type n) { return a += n; };
        /// caide keep
        inline friend difference_type operator-(const self_t& a, const self_t& b) { return dir * (a.index - b.index); };

        /// caide keep
        inline reference operator[](difference_type n) { return (*container)[index + dir * n]; };
        /// caide keep
        inline const reference operator[](difference_type n) const { return (*container)[index + dir * n]; };

    private:
        C* container;
        difference_type index;
    };
}

namespace multivec_impl {
    template <size_t NDIMS>
    struct shape {
        size_t dim, stride;
        shape<NDIMS - 1> subshape;
        shape(size_t dim_, shape<NDIMS - 1>&& s): dim(dim_), stride(s.size()), subshape(s) {}
        size_t size() const { return dim * stride; }
    };
    template <> struct shape<0> { size_t size() const { return 1; } };

    template <size_t I, size_t NDIMS>
    struct __shape_traverse {

    };

    template <size_t NDIMS>
    struct __shape_traverse<0, NDIMS> {
        static size_t get_dim(const shape<NDIMS> &s) { return s.dim; }
    };

    template <size_t I, size_t NDIMS>
    size_t get_dim(const shape<NDIMS> &s) { return __shape_traverse<I, NDIMS>::get_dim(s); }


    template <class Index, class... Rest, size_t NDIMS, ENABLE_IF(is_integral<Index>::value)>
    size_t get_shift(const shape<NDIMS>& s, size_t cur_shift, Index i, Rest... is) {
        assert(0 <= i && i < s.dim);
        return get_shift(s.subshape, cur_shift + i * s.stride, is...);
    }

    template <size_t NDIMS> size_t get_shift(const shape<NDIMS>&, size_t cur_shift) { return cur_shift; }
    template <class... T> shape<sizeof...(T)> make_shape(T... dims);

    template <class Dim, class... Rest, ENABLE_IF(is_integral<Dim>::value)>
    shape<sizeof...(Rest) + 1> make_shape(Dim dim, Rest... dims) {
        assert(dim >= 0);
        return {(size_t)dim, make_shape<Rest...>(dims...)};
    }

    template <> shape<0> make_shape() { return {}; }


    template <template<class T, size_t NDIMS> class Base, class T, size_t NDIMS>
    struct vec_mixin : public Base<T, NDIMS> {
        using Base<T, NDIMS>::Base;
        /// caide keep
        typedef Base<T, NDIMS> B;
        typedef index_iterator_impl::index_iterator<vec_mixin<Base, T, NDIMS>> iterator;

        template <size_t I = 0> inline size_t dim() const { return get_dim<I>(B::s); }

        template <class... Indices, bool enabled = NDIMS == sizeof...(Indices), ENABLE_IF(enabled)>
        inline T& operator()(Indices... is) {
            size_t i = multivec_impl::get_shift(B::s, 0, is...);
            return B::data[i];
        }


        inline auto operator[](size_t i) -> decltype(this->operator()(i)) { return this->operator()(i); }

        inline iterator begin() { return {this, 0}; }
        inline iterator end() { return {this, (ptrdiff_t)dim()}; }


    protected:

    };


    template <class T, size_t NDIMS>
    struct vec_base {
        inline vec_base(multivec_impl::shape<NDIMS>&& s_, const T& val = T()): s(move(s_)), data(new T[s.size()]) {
            fill(data.get(), data.get() + s.size(), val);
        }
    protected:
        multivec_impl::shape<NDIMS> s;
        unique_ptr<T[]> data;
    };

}

/*
TODO
 - do we need vec_view_const?
 - add more features (copy, lambda initialization etc.)
*/

template <class T, size_t NDIMS>
using vec = multivec_impl::vec_mixin<multivec_impl::vec_base, T, NDIMS>;


template <class T, class... NDIMS>
inline vec<T, sizeof...(NDIMS)> make_vec(NDIMS... dims) { return {multivec_impl::make_shape(dims...)}; }

template <class T, class... NDIMS>
inline vec<T, sizeof...(NDIMS)> make_vec_fill(const T& val, NDIMS... dims) { return {multivec_impl::make_shape(dims...), val}; }


// ^^^^^^^^^^^^^^^^^ Library code end

/// caide keep
typedef Mod<1000000007> mod;
typedef mod::type mt;
REGISTER_MOD_LITERAL(mod, mod)

void solve(istream& in, ostream& out) {
    auto m = next<int>(in);
    auto d = next<int>(in);
    auto a = next<string>(in);
    auto b = next<string>(in);
    auto din = make_vec<mt>(m);
    auto din1 = make_vec<mt>(m);
    int eqa = 1, eqb = 1, eqab = 1;
    int xa = 0, xb = 0;
    forn(int, i, a.size()) {
        fill(all(din1), 0_mod);
        int eqa1 = 0, eqb1 = 0, eqab1 = 0;
        forn(int, dig, 10) {
            if ((i % 2 == 1 && dig != d) || (i % 2 == 0 && dig == d)) {
                continue;
            }
            forn (int, x, m) {
                int y = (10 * x + dig) % m;
                din1[y] = din1[y] + din[x];
            }
            if (eqab) {
                if (a[i] - '0' < dig && dig < b[i] - '0') {
                    int y = (10 * xa + dig) % m;
                    din1[y] = din1[y] + 1_mod;
                }
            } else {
                if (eqa && a[i] - '0' < dig) {
                    int y = (10 * xa + dig) % m;
                    din1[y] = din1[y] + 1_mod;
                }
                if (eqb && dig < b[i] - '0') {
                    int y = (10 * xb + dig) % m;
                    din1[y] = din1[y] + 1_mod;
                }
            }
            eqa1 |= eqa && dig == a[i] - '0';
            eqb1 |= eqb && dig == b[i] - '0';
            eqab1 |= eqab && dig == a[i] - '0' & dig == b[i] - '0';
        }
        xa = (10 * xa + (a[i] - '0')) % m;
        xb = (10 * xb + (b[i] - '0')) % m;
        eqa = eqa1;
        eqb = eqb1;
        eqab = eqab1;
        swap(din, din1);
    }
    mt ans = din[0];
    if (eqab) {
        ans = ans + mt(xa == 0);
    } else {
        ans = ans + mt(eqa && xa == 0);
        ans = ans + mt(eqb && xb == 0);
    }
    auto test = make_vec_fill<int>(100, m);
    sort(all(test));
    out << (uint64_t)ans;
}


int main() {
    solve(cin, cout);
    return 0;
}

//const int n0 = 1;
//
//template <int N = n0>
//struct A {};
//
//int main() {
//    A<1> a;
//    return 0;
//}