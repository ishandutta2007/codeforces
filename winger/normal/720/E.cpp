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


using namespace std;

/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);


namespace option_detail {
    /// caide keep
    struct NoneHelper {};
}


template<class Value>
class Option {
public:
    

    static_assert(!std::is_reference<Value>::value,
                  "Option may not be used with reference types");
    static_assert(!std::is_abstract<Value>::value,
                  "Option may not be used with abstract types");

    
    Value* get_pointer() && = delete;

    
    // Return a copy of the value if set, or a given default if not.
    

    // Return a copy of the value if set, or a given default if not.
    

private:
    

    struct StorageTriviallyDestructible {
        // uninitialized
        
        bool hasValue;

        
    };

    /// caide keep
    struct StorageNonTriviallyDestructible {
        // uninitialized
        union { Value value; };
        bool hasValue;

        
        ~StorageNonTriviallyDestructible() {
            clear();
        }

        void clear() {
            if (hasValue) {
                hasValue = false;
                value.~Value();
            }
        }
    };

    /// caide keep
    using Storage =
    typename std::conditional<std::is_trivially_destructible<Value>::value,
            StorageTriviallyDestructible,
            StorageNonTriviallyDestructible>::type;

    Storage storage_;
};


// Comparisons.


template<class V> bool operator< (const Option<V>&, const V& other) = delete;
template<class V> bool operator<=(const Option<V>&, const V& other) = delete;
template<class V> bool operator>=(const Option<V>&, const V& other) = delete;
template<class V> bool operator> (const Option<V>&, const V& other) = delete;
template<class V> bool operator< (const V& other, const Option<V>&) = delete;
template<class V> bool operator<=(const V& other, const Option<V>&) = delete;
template<class V> bool operator>=(const V& other, const Option<V>&) = delete;
template<class V> bool operator> (const V& other, const Option<V>&) = delete;


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
        
    };

    /// caide keep
    template<>
    struct bytetype<0> {
        
    };

    /// caide keep
    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
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
        
        shape(size_t dim_, shape<NDIMS - 1>&& s): dim(dim_), stride(s.size()), subshape(std::move(s)) {}
        size_t size() const { return dim * stride; }
        
        
    };
    template <> struct shape<0> { size_t size() const { return 1; } };
    

    template <size_t I, size_t NDIMS>
    struct __shape_traverse {
        

    };

    template <size_t NDIMS>
    struct __shape_traverse<0, NDIMS> {
        static size_t get_dim(const shape<NDIMS>& s) { return s.dim; }
        
    };

    template <size_t I, size_t NDIMS>
    size_t get_dim(const shape<NDIMS>& s) { return __shape_traverse<I, NDIMS>::get_dim(s); }

    
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
        
        
        template <size_t I = 0> inline size_t dim() const { return get_dim<I>(B::s); }
        

        template <class... Indices, bool enabled = NDIMS == sizeof...(Indices), ENABLE_IF(enabled)>
        inline T& operator()(Indices... is) {
            size_t i = multivec_impl::get_shift(B::s, 0, is...);
            return B::data[i];
        }

        
//        inline auto operator[](size_t i) -> decltype(this->operator()(i)) { return this->operator()(i); }

        
        template <class F, class... Indices, class T1 = vec_mixin, typename result_of<F()>::type* = nullptr>
        inline typename enable_if<NDIMS == 1, T1&>::type fill(F f, Indices...) & {
            forn (size_t, i, dim()) B::data[i] = f();
            return *this;
        };

        
        // TODO fluent api does not work properly with rvalue refs
//        inline vec_mixin&& fill(const T& val) && { fill(val); return std::move(*this); }
//
//        template <class F, class... Indices>
//        inline vec_mixin&& fill(F f, Indices... is) && { fill(f, is...); return std::move(*this); }

        
//    protected:
        

    };

    
    template <class T, size_t NDIMS>
    struct vec_base {
        inline vec_base(multivec_impl::shape<NDIMS>&& s_): s(move(s_)), data(new T[s.size()]) {}
        
        
        inline vec_base(const vec_base& o): s(o.s), data(new T[s.size()]) {
            memcpy(data.get(), o.data.get(), sizeof(T) * s.size());
        }
        
    protected:
        multivec_impl::shape<NDIMS> s;
        unique_ptr<T[]> data;
    };
}

/*
TODO
 - do we need vec_view_const?
 - add more features (lambda initialization etc.)
 - properly use const
 - proper tests coverage
*/

template <class T, size_t NDIMS>
using vec = multivec_impl::vec_mixin<multivec_impl::vec_base, T, NDIMS>;


template <class T, class... NDIMS>
inline vec<T, sizeof...(NDIMS)> make_vec(NDIMS... dims) {
    return {multivec_impl::make_shape(dims...)};
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


template<class T, class... Dims>
vec<T, sizeof...(Dims)> next_vec(istream& in, Dims... dims) {
    auto tmp = make_vec<T>(dims...);
    tmp.fill([&]() { return next<T>(in); });
    return tmp;
}


// ^^^^^^^^^^^^^^^^^ Library code end

using H = tuple<uint64_t, uint64_t>;

inline H operator*(H a, H b) {
    return H{get<0>(a) * get<1>(b) + get<0>(b), get<1>(a) * get<1>(b)};
}

H zero = H{0, 1};

auto one = [](char c) { return H{c, 239}; };

inline H pow(H x, int64_t pow) {
    assert(pow >= 0);
    H ret = zero;
    while (pow > 0) {
        if (pow & 1) {
            ret = ret * x;
        }
        pow /= 2;
        x = x * x;
    }
    return ret;
}

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    string vs = next<string>(in);
    auto cs = next_vec<string>(in, n);
    int64_t v = 0;
    int64_t last = 1;
    forn (int, i, n) {
        last = 10 * last;
        v = 10 * v + vs[i] - '0';
    }
    auto pow10 = make_vec<int64_t>(n + 1);
    pow10(0) = 1;
    forn (int, i, n) {
        pow10(i + 1) = pow10(i) * 10;
    }
    auto chs = make_vec<H>(n, 10);
    forn (int, i, n) {
        forn (int, j, 10) {
            chs(i, j) = pow(one(cs(i)[j]), pow10(n - i - 1));
        }
    }
    auto chs10 = make_vec<H>(n);
    forn (int, i, n) {
        chs10(i) = zero;
        forn (int, j, 10) {
            chs10(i) = chs10(i) * chs(i, j);
        }
    }
    auto h = [&](int64_t from, int64_t to, int at) {
        H cur;
        int64_t p10 = pow10(n - at - 1);
        if (from / p10 == to / p10) {
            cur = pow(one(cs(at)[from / p10 % 10]), to - from);
        } else {
            cur = pow(one(cs(at)[from / p10 % 10]), (from / p10 + 1) * p10 - from);
            int64_t from1 = from / p10 + 1, to1 = to / p10;
            while (from1 < to1 && from1 % 10 != 0) {
                cur = cur * chs(at, from1 % 10);
                from1++;
            }
            int64_t add10 = (to1 - from1) / 10;
            cur = cur * pow(chs10(at), add10);
            from1 += add10 * 10;
            while (from1 < to1) {
                cur = cur * chs(at, from1 % 10);
                from1++;
            }
            cur = cur * pow(one(cs(at)[to / p10 % 10]), to - (to / p10) * p10);
        }
        return cur;
    };
    int64_t l = -1, r = last - v;
    while (l + 1 < r) {
        int64_t mid = (l + r) / 2;
        auto h0 = make_vec<H>(n);
        forn (int, at, n) {
            h0(at) = h(v, v + mid + 1, at);
        }
        forn (int, at, n) {
            int d = vs[at] - '0';
            forn (int, d1, 10) {
                if (d == d1 || cs(at)[d] != cs(at)[d1]) {
                    continue;
                }
                int64_t v1 = v + pow10(n - at - 1) * (d1 - d);
                if (v1 + mid + 1 > last) {
                    continue;
                }
                forn (int, at1, at + 1) {
                    if (h0(at1) != h(v1, v1 + mid + 1, at1)) {
                        goto cnt;
                    }
                }
                l = mid;
                goto next;
                cnt:;
            }
        }
        r = mid;
        next:;
    }
    out << r << endl;
}


int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve(cin, cout);
    }
    return 0;
}