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


template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}


// Section with adoption of array and vector algorithms.


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


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


// ^^^^^^^^^^^^^^^^^ Library code end

void solve(istream& in, ostream& out) {
    int64_t n = next<int64_t>(in);
    int64_t ans = 4 * n;
    for (int64_t x = 1; x <= n; ++x) {
        if (x * x >= n) {
            rmn(ans, 4 * x);
        }
        if (x * (x + 1) >= n) {
            rmn(ans, 4 * x + 2);
        }
    }
    out << ans << endl;
}


int main() {
    solve(cin, cout);
    return 0;
}