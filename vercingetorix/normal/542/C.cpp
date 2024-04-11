#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <functional>
#include <array>
#include <valarray>
#include <iomanip>
#include <cassert>
#include <memory>
#include <complex>
#include <regex>

using namespace std;

#include <algorithm>
#include <inttypes.h>
#include <iostream>
#include <stdint.h>
#include <utility>
#include <vector>



// From algo/io/baseio.hpp


template<typename T> T read()
{
    T res;
    std::cin >> res;
    return res;
}

template<typename T> void print(const T& t)
{
    std::cout << t;
}

#ifndef LOCAL_PC
#define DEFINE_SIMPLE_READ_AND_PRINT(TYPE_NAME, FORMAT)  \
  template<>  \
  TYPE_NAME read<TYPE_NAME>() {  \
    TYPE_NAME res;  \
    int cnt = scanf(FORMAT, &res); \
    return res; \
  }\
\
  template<>  \
  void print<TYPE_NAME>(const TYPE_NAME& t) {  \
    printf(FORMAT, t); \
  }\

DEFINE_SIMPLE_READ_AND_PRINT(int, "%d");
DEFINE_SIMPLE_READ_AND_PRINT(unsigned int, "%u");
DEFINE_SIMPLE_READ_AND_PRINT(int64_t, "%lld");
DEFINE_SIMPLE_READ_AND_PRINT(float, "%f");
DEFINE_SIMPLE_READ_AND_PRINT(double, "%lf");
DEFINE_SIMPLE_READ_AND_PRINT(char, "%c");

#endif


// From iter/range.h

// Range-based style iteration helpers.
//
// * range(end)
//   Iterates over [0, end), e.g.:
//   ` for (auto i : range(5)) {
//   `     print(i);
//   ` }
//   prints "0 1 2 3 4"
//
// * range(begin, end)
//   Iterates over [begin, end), e.g.:
//   ` for (auto i : range(5, 10)) {
//   `     print(i);
//   ` }
//   prints "5 6 7 8 9"




namespace internal {

    template<typename ValueT>
    class IterableRange {
    public:
        class iterator {
        public:
            iterator(ValueT v__) : v_(v__) {}

            iterator& operator++() { ++v_; return *this; }

            bool operator==(iterator rhs) const { return v_ == rhs.v_; }
            bool operator!=(iterator rhs) const { return v_ != rhs.v_; }

            ValueT operator*() const  { return v_; }
            ValueT operator->() const { return v_; }

        private:
            ValueT v_ = {};
        };

        IterableRange(ValueT begin__, ValueT end__) : begin_value_(std::min(begin__, end__)), end_value_(end__) {}

        iterator begin() const { return {begin_value_}; }
        iterator end() const { return {end_value_}; }

    private:
        ValueT begin_value_ = {};
        ValueT end_value_ = {};
    };

}  // namespace internal


template<typename ValueT>
internal::IterableRange<ValueT> range(ValueT end) {
    return {{}, end};
}

template<typename ValueT>
internal::IterableRange<ValueT> range(ValueT begin, ValueT end) {
    return {begin, end};
}


// From algo/io/readvector.hpp


template<typename T>
std::vector<T> readVector(size_t size)
{
    std::vector<T> res(size);
    for (auto& elt : res)
        elt = read<T>();
    return res;
}


// From math/sign.h


template <typename T> int sgn( T val ) {
    return ( T( 0 ) < val ) - ( val < T( 0 ) );
}


// From algo/numbertheory/GreatestCommonDivisor.hpp


namespace
{
inline uint64_t gcdInternal( uint64_t a, uint64_t b )
{
    if ( b == 0 )
        return a;

    return gcdInternal( b, a % b );
}

inline uint64_t gcdDecompositionInternal( uint64_t a, uint64_t b, int64_t& x, int64_t& y )
{
    if ( b == 0 )
    {
        x = 1;
        y = 0;
        return a;
    }

    int64_t xx, yy;
    auto gcd = gcdDecompositionInternal( b, a % b, xx, yy );
    // ok, gcd = xx * b + (a % b) * yy = xx * b + (a - (a / b) * b) * yy =
    //         = b * (xx - (a / b) * yy) + a * yy
    x = yy;
    y = xx - ( a / b ) * yy;
    return gcd;
}

}

inline uint64_t greatestCommonDivisor( int64_t a, int64_t b )
{
    a *= sgn( a );
    b *= sgn( b );
    if ( a < b )
        std::swap( a, b );
    return gcdInternal( a, b );
}

inline uint64_t greatestCommonDivisor(const std::vector<int64_t>& numbers)
{
    uint64_t res = 0;
    for (auto a : numbers)
        res = greatestCommonDivisor(res, a);
    return res;
}

inline uint64_t gcdDecomposition( int64_t a, int64_t b, int64_t& x, int64_t& y )
{
    auto aUnsigned = a * sgn( a );
    auto bUnsigned = b * sgn( b );
    auto gcd = ( aUnsigned < bUnsigned ) ? gcdDecompositionInternal( aUnsigned, bUnsigned, x, y ) : gcdDecompositionInternal( bUnsigned, aUnsigned, y, x );
    x *= sgn( a );
    y *= sgn( b );
    return gcd;
}


// From Solvers/5xx/542/Solver542C.cpp

using namespace std;

class Solver542C {
public:
    void run();
};

int64_t nok(int64_t a, int64_t b) {
    return (a / greatestCommonDivisor(a, b)) * b;
}

void Solver542C::run() {
    int n = read<int>();
    auto f = readVector<int>(n);
    for (auto& elt : f) --elt;

    vector<vector<int>> ff(n, vector<int>(2 * n));
    for (int i : range(n)) ff[i][0] = i;
    for (int j : range(1, 2 * n))
        for (int i : range(n)) ff[i][j] = f[ff[i][j - 1]];

    vector<int> pre(n), len(n);
    for (int i : range(n)) {
        map<int, int> pos;
        for (int j : range(2 * n)) {
            int v = ff[i][j];
            if (pos.count(v) != 0) {
                pre[i] = pos[v];
                len[i] = j - pos[v];
                break;
            }
            pos[v] = j;
        }
    }

    int64_t d = 1;
    for (int i : range(n))
        d = nok(d, len[i]);

    int64_t m = *max_element(begin(pre), end(pre));
    int64_t k = d;
    while (k < m) k += d;
    cout << k;
}



int main() {
    Solver542C solver;
    solver.run();
}