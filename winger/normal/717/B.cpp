// vvvvvvvvvvvvvvvvv Library code start


#include <type_traits>


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


using namespace std;

/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);


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


template<class T, class F, class... Args, ENABLE_IF(is_integral<T>::value)>
inline T bs01(T l, T r, F pred, Args... args) {
    assert(!pred(l, args...) && pred(r, args...));
    while (l + 1 < r) {
        //TODO overflow
        T mid = (l + r) / 2;
        if (pred(mid, args...)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


// ^^^^^^^^^^^^^^^^^ Library code end

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    int64_t c0 = next<int64_t>(in);
    int64_t c1 = next<int64_t>(in);
    if (c0 > c1) {
        swap(c0, c1);
    }
    if (c0 == 0) {
        out << (n - 1) * c1;
        return;
    }
    auto f = [&](int64_t k) {
        int64_t cnt = 0, sumVals = 0;
        for (int i = 0; c1 * i <= k && cnt < n; ++i) {
            int64_t maxj = (k - c1 * i) / c0;
            if (i == 0) {
                cnt += maxj + 1;
                sumVals += (maxj * c0) * (maxj + 1) / 2;
            } else {
                int64_t c = 1;
                for (int j = 0; c1 * i + c0 * j <= k && cnt < n; ++j) {
                    cnt += c;
                    sumVals += c * (c1 * i + c0 * j);
                    c = c * (i + j + 1) / (j + 1);
                }
            }
        }
        return make_pair(cnt, sumVals);
    };
    int64_t lastVal = bs01(0LL, 1000000000000000000LL, [&](int64_t k) { return f(k).first >= n; });
    auto tmp = f(lastVal - 1);
    out << tmp.second + lastVal * (n - 1 - tmp.first) + (n - 1) * (c0 + c1);
}


int main() {
    solve(cin, cout);
    return 0;
}