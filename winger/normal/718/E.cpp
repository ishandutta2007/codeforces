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
#define foran(t, i, a, n) for (t i = (a); i < (n); ++i)


#define F1(e) [&](size_t i1) {return e;}
#define F2(e) [&](size_t i1, size_t i2) {return e;}


using namespace std;

/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);

template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}


template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}


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

    
    template <template<class, size_t> class Base, class T, size_t NDIMS>
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

        
        inline void fill(const T& val) & {
            std::fill(raw_data(), raw_data() + B::s.size(), val);
        };

        template <class F, class... Indices, typename result_of<F(Indices...)>::type* = nullptr, ENABLE_IF(sizeof...(Indices) == NDIMS)>
        inline void fill(F f, Indices... is) & {
            (*this)(is...) = f(is...);
        };

        
        template <class F, class... Indices, ENABLE_IF(sizeof...(Indices) < NDIMS)>
        inline void fill(F f, Indices... is) & {
            forn (size_t, i, dim()) fill(f, i, is...);
        };

        
//    protected:
        inline T* raw_data() {
            return &B::data[0];
        }

        
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


template <class T>
inline void inplace_set_bit(T& mask, int bit) {
    assert(0 <= bit && bit < numeric_limits<T>::digits);
    mask |= ((T)(1) << bit);
}

template <class T>
inline void inplace_unset_bit(T& mask, int bit) {
    assert(0 <= bit && bit < numeric_limits<T>::digits);
    mask &= ~((T)(1) << bit);
}

template <class T>
inline void inplace_set_bit(T& mask, int bit, bool val) {
    if (val) {
        inplace_set_bit(mask, bit);
    } else {
        inplace_unset_bit(mask, bit);
    }
}

template <class T>
inline bool superset(T mask1, T mask2) {
    return (mask1 & mask2) == mask2;
}


// ^^^^^^^^^^^^^^^^^ Library code end

const int alpha = 8;
const int inf = 1000000000;

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    auto str = next<string>(in);
    auto s = make_vec<int8_t>(n);
    s.fill(F1((int8_t)(str[i1] - 'a')));
    auto g = make_vec<int>(alpha, alpha);
    g.fill(F2(i1 == i2 ? 1 : inf));
    forn (int, i, n) {
        foran (int, j, i + 1, min(n, i + 2 * alpha + 1)) {
            rmn(g(s(i), s(j)), j - i + 1);
            rmn(g(s(j), s(i)), j - i + 1);
        }
    }
    forn (int, k, alpha) {
        forn (int, i, alpha) {
            forn (int, j, alpha) {
                rmn(g(i, j), g(i, k) + g(k, j));
            }
        }
    }
    auto masks = make_vec<int>(n);
    auto masks_cnt = make_vec<int>(1 << alpha);
    auto super_masks_cnt = make_vec<int>(1 << alpha);
    auto dists = make_vec<int>(alpha);
    auto pairsWithDist = make_vec<int64_t>(2 * alpha + 2);
    pairsWithDist.fill(0LL);
    pairsWithDist(0) = n;
    forn (int, c1, alpha) {
        masks_cnt.fill(0);
        forn (int, i, n) {
            if (s(i) != c1) {
                continue;
            }
            dists.fill(inf);
            foran (int, j, max(0, i - alpha), min(n, i + alpha + 1)) {
                rmn(dists(s(j)), abs(i - j));
            }
            forn (int, c2, alpha) {
                forn (int, c3, alpha) {
                    rmn(dists(c3), dists(c2) + g(c2, c3));
                }
            }
            int mask = 0;
            forn (int, c2, alpha) {
                assert(g(c1, c2) - 1 <= dists(c2) && dists(c2) <= g(c1, c2));
                inplace_set_bit(mask, c2, dists(c2) == g(c1, c2));
            }
            masks_cnt(mask)++;
            masks(i) = mask;
        }
        forn (int, mask, 1 << alpha) {
            super_masks_cnt(mask) = 0;
            forn (int, mask1, 1 << alpha) {
                if (superset(mask1, mask)) {
                    super_masks_cnt(mask) += masks_cnt(mask1);
                }
            }
        }
        if (super_masks_cnt(0) == 0) {
            continue;
        }
        forn (int, i, n) {
            dists.fill(inf);
            foran (int, j, max(0, i - alpha), min(n, i + alpha + 1)) {
                rmn(dists(s(j)), abs(i - j));
            }
            forn (int, c2, alpha) {
                forn (int, c3, alpha) {
                    rmn(dists(c3), dists(c2) + g(c2, c3));
                }
            }
            int minDist = inf, minDistMask = 0;
            forn (int, c2, alpha) {
                int cur = g(c1, c2) + dists(c2);
                if (rmn(minDist, cur)) {
                    minDistMask = 0;
                }
                if (minDist == cur) {
                    inplace_set_bit(minDistMask, c2);
                }
            }
            pairsWithDist(minDist) += super_masks_cnt(0) - super_masks_cnt(minDistMask);
            pairsWithDist(minDist + 1) += super_masks_cnt(minDistMask);
            foran (int, j, max(0, i - alpha), min(n, i + alpha + 1)) {
                if (s(j) == c1) {
                    int d = superset(masks(j), minDistMask) ? minDist + 1 : minDist;
                    pairsWithDist(d)--;
                    pairsWithDist(mn(d, abs(i - j)))++;
                }
            }
        }
    }
    int64_t total = 0;
    forn (int, i, pairsWithDist.dim()) {
        assert(pairsWithDist(i) % 2 == 0);
        total += pairsWithDist(i) / 2;
    }
    assert(total == 1LL * n * (n + 1) / 2);
    int ans = pairsWithDist.dim() - 1;
    while (pairsWithDist(ans) == 0) {
        --ans;
    }
    out << ans << " " << pairsWithDist(ans) / 2 << endl;
}


int main() {
    solve(cin, cout);
    return 0;
}