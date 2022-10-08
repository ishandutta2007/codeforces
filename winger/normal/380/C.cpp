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
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}


// Section with adoption of array and vector algorithms.


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
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
struct NoPropagateDown {
    static inline void propagate_down(size_t, size_t, size_t, T&, T&, T&) {}
};


template <class T>
struct InplaceFixUp {
    static inline void fix_up(size_t, size_t, size_t, T& p, T& l, T& r) {
        p = l;
        p.compose(r);
    }
};

template <class T>
struct stree {
    

    template<class C>
    stree(const C& c): n_(c.size()), size(segment_tree_impl::calc_size(n_)), ar(2 * size - 1) {
        for (int i = 0; i < n_; ++i) {
            ar[size - 1 + i] = {c[i]};
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

    
    //TODO
//    template<class Pred>
//    pair<size_t, T> smartSearch(Pred p) {
//        return smartSearch(0, 0, size, p);
//    }

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

    
    inline void propagate_down(size_t n, size_t nl, size_t mid, size_t nr) {
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

    
//    template<class Pred>
//    pair<size_t, T> smartSearch(size_t n, size_t nl, size_t nr, Pred p) {
//        if (nl + 1 == nr) {
//            return {nl, ar[n]};
//        }
//        size_t mid = (nl + nr) / 2;
//        propagate_down(n, nl, mid, nr);
//        if (p(ar[2 * n + 1], ar[2 * n + 2], nl, mid, nr)) {
//            return smartSearch(2 * n + 2, mid, nr, p);
//        } else {
//            return smartSearch(2 * n + 1, nl, mid, p);
//        };
//    }

    const size_t n_, size;
    vector<T> ar;
};

// ^^^^^^^^^^^^^^^^^ Library code end

struct Val : NoPropagateDown<Val>, InplaceFixUp<Val> {
    int ans = 0, l = 0, r = 0;

    Val() {}

    Val(char c) {
        (c == '(' ? l : r)++;
    }

    void compose(const Val& o) {
        int common = mn(l, o.r);
        ans += o.ans + common;
        l += o.l - common;
        r += o.r - common;
    }
};

void solve(istream& in, ostream& out) {
    string s = next<string>(in);
    stree<Val> t(s);
    int n = next<int>(in);
    forn (int, i, n) {
        int l = next<int>(in) - 1;
        int r = next<int>(in);
        out << 2 * t.sum_range(l, r).ans << "\n";
    }
}


int main() {
    solve(cin, cout);
    return 0;
}