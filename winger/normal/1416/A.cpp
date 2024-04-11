#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
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
#define foran(t, i, a, n) for (t i = (a); i < (n); ++i)


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


template<class T>
inline T mx(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mx(T arg, Ts... args) {
    auto arg1 = mx(args...);
    return arg > arg1 ? arg : arg1;
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

template<class T>
vector<T> next_vector(istream& in, size_t n) {
    vector<T> ret(n);
    for (size_t i = 0; i < n; ++i) {
        ret[i] = next<T>(in);
    }
    return ret;
}


void solve(istream& in, ostream& out) {
    int tests = next<int>(in);
    forn (int, test, tests) {
        int n = next<int>(in);
        auto as = next_vector<int>(in, n);
        unordered_map<int, int> prev, gap;
        forn (int, i, n) {
            if (!prev.count(as[i])) {
                prev[as[i]] = -1;
            }
            rmx(gap[as[i]], i - prev[as[i]] - 1);
            prev[as[i]] = i;
        }
        vector<int> ans(n + 1, n + 1);
        for (auto kv : gap) {
            int g = mx(kv.second, n - prev[kv.first] - 1);
            rmn(ans[g + 1], kv.first);
        }
        forn (int, i, n) {
            rmn(ans[i + 1], ans[i]);
        }
        foran (int, i, 1, n + 1) {
            out << (ans[i] == n + 1 ? -1 : ans[i]) << " ";
        }
        out << "\n";
    }
}


int main() {
  solve(cin, cout);
  return 0;
}