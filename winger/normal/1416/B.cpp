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
        int sum = 0;
        for (int a : as) {
            sum += a;
        }
        if (sum % n != 0) {
            out << "-1\n";
            continue;
        }
        sum /= n;
        vector<tuple<int, int, int>> ops;
        foran (int, i, 1, n) {
            if (as[i] % (i + 1) != 0) {
                ops.emplace_back(0, i, i + 1 - as[i] % (i + 1));
            }
            if ((as[i] + i) / (i + 1) > 0) {
                ops.emplace_back(i, 0, (as[i] + i) / (i + 1));
            }
        }
        foran (int, i, 1, n) {
            ops.emplace_back(0, i, sum);
        }
        out << ops.size() << "\n";
        for (auto op : ops) {
            int i = get<0>(op);
            int j = get<1>(op);
            int x = get<2>(op);
            assert(x >= 0);
            as[i] -= i * x;
            as[j] += i * x;
            assert(as[i] >= 0);
            out << (i + 1) << " " << (j + 1) << " " << x << "\n";
        }
        for (int a : as) {
            assert(a == sum);
        }
    }
}


int main() {
  solve(cin, cout);
  return 0;
}