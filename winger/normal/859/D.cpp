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


template<class T>
inline T mx(T arg) {
    return arg;
}


template<class T, class... Args>
inline bool rmx(T &to, Args... args) {
    auto v = mx(args...);
    if (to < v) {
        to = v;
        return true;
    }
    return false;
}


// Section with adoption of array and vector algorithms.


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

    
    // Return b copy of the value if set, or b given default if not.
    

    // Return b copy of the value if set, or b given default if not.
    

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

    template<int N>
    struct bytetype {
        
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
        static size_t get_dim(const shape<NDIMS>& s) {
            return __shape_traverse<I - 1, NDIMS - 1>::get_dim(s.subshape);
        }

        ///caide keep
        static const shape<NDIMS - I>& get_subshape(const shape<NDIMS>& s) {
            return __shape_traverse<I - 1, NDIMS - 1>::get_subshape(s.subshape);
        }
    };

    template <size_t NDIMS>
    struct __shape_traverse<0, NDIMS> {
        static size_t get_dim(const shape<NDIMS>& s) { return s.dim; }
        
    };

    template <size_t I, size_t NDIMS>
    size_t get_dim(const shape<NDIMS>& s) { return __shape_traverse<I, NDIMS>::get_dim(s); }

    ///caide keep
    template <size_t I, size_t NDIMS>
    const shape<NDIMS - I>& get_subshape(const shape<NDIMS>& s) { return __shape_traverse<I, NDIMS>::get_subshape(s); }

    
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

    
    ///caide keep
    template <class T, size_t NDIMS>
    struct vec_view_base;

    template <template<class, size_t> class Base, class T, size_t NDIMS>
    struct vec_mixin : public Base<T, NDIMS> {
        using Base<T, NDIMS>::Base;
        /// caide keep
        typedef Base<T, NDIMS> B;
        
        
        template <size_t I = 0> inline size_t dim() const { return get_dim<I>(B::s); }
        

        ///caide keep
        template <class... Indices, bool enabled = NDIMS == sizeof...(Indices), ENABLE_IF(enabled)>
        inline T& operator()(Indices... is) {
            size_t i = multivec_impl::get_shift(B::s, 0, is...);
            return B::data[i];
        }

        ///caide keep
        template <class... Indices, bool enabled = sizeof...(Indices) < NDIMS, ENABLE_IF(enabled)>
        inline vec_mixin<vec_view_base, T, NDIMS - sizeof...(Indices)> operator()(Indices... is) {
            size_t shift = multivec_impl::get_shift(B::s, 0, is...);
            const auto& subshape = multivec_impl::get_subshape<sizeof...(Indices)>(B::s);
            return {subshape, &B::data[shift]};
        }

        
        template <class F, class... Indices, typename result_of<F()>::type* = nullptr, ENABLE_IF(sizeof...(Indices) == NDIMS)>
        inline void fill(F f, Indices... is) {
            (*this)(is...) = f();
        };

        template <class F, class... Indices, ENABLE_IF(sizeof...(Indices) < NDIMS)>
        inline void fill(F f, Indices... is) {
            forn (size_t, i, dim<sizeof...(Indices)>()) fill(f, is..., i);
        };

        
//    protected:
        

    };

    template <class T, size_t NDIMS>
    struct vec_view_base {
        
        
    protected:
        multivec_impl::shape<NDIMS> s;
        T* data;
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


#define dbg(...) ;


// ^^^^^^^^^^^^^^^^^ Library code end

void solve(istream& in, ostream& out) {
    int n = 1 << next<int>(in);
    auto p = next_vec<int>(in, n, n);
    vector<vector<tuple<int, double, double>>> ds;
    forn (int, i, n) {
        ds.push_back({{i, 1, 0}});
    }
    auto merge = [&](vector<tuple<int, double, double>> lhs, vector<tuple<int, double, double>> rhs, double val) {
        vector<tuple<int, double, double>> ret;
        auto add = [&](vector<tuple<int, double, double>> lhs1, vector<tuple<int, double, double>> rhs1) {
            for (auto &u : lhs1) {
                int ui = get<0>(u);
                double up = get<1>(u);
                double ue = get<2>(u);
                double newp = 0, newe = 0;
                for (auto &v : rhs1) {
                    int vi = get<0>(v);
                    double vp = get<1>(v);
                    double ve = get<2>(v);
                    newp += up * vp * p(ui, vi) / 100.0;
                    rmx(newe, ve);
                }
                newe = ue + newe + newp * val;
                ret.emplace_back(ui, newp, newe);
            }
        };
        add(lhs, rhs);
        add(rhs, lhs);
        return ret;
    };
    double val = 1;
    while (ds.size() > 1) {
        decltype(ds) ds1;
        for (int i = 0; i < ds.size(); i += 2) {
            ds1.emplace_back(merge(ds[i], ds[i + 1], val));
        }
        ds = std::move(ds1);
        val *= 2;
        dbg(ds);
    }
    double ans = 0;
    for (auto v : ds[0]) {
        rmx(ans, get<2>(v));
    }
    out << setprecision(12) << ans << endl;
}


int main() {
    solve(cin, cout);
    return 0;
}