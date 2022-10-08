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

#define rforn(t, i, n) for (t i = (n) - 1; i >= 0; --i)

#define all(c) c.begin(), c.end()


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


struct Node {
    array<int, 2> c = {0, 0};
    array<int, 2> sub = {-1, -1};
} *nodes;

void solve(istream& in, ostream& out) {
    nodes = new Node[30 * 300000];
    int n = next<int>(in);
    auto as = next_vector<int>(in, n);
    int root = 0, nnode = 1;
    array<int64_t, 30> s[2];
    fill(all(s[0]), 0);
    fill(all(s[1]), 0);
    for (int a : as) {
        int n = root;
        rforn (int, shift, 30) {
            int bit = (a >> shift) & 1;
            s[bit][shift] += nodes[n].c[bit ^ 1];
            nodes[n].c[bit]++;
            if (nodes[n].sub[bit] == -1) {
                nodes[n].sub[bit] = nnode++;
            }
            n = nodes[n].sub[bit];
        }
    }
    int64_t ans = 0;
    int x = 0;
    forn (int, shift, 30) {
        ans += mn(s[0][shift], s[1][shift]);
        if (s[0][shift] > s[1][shift]) {
            x |= 1 << shift;
        }
    }
    out << ans << " " << x << "\n";
}


int main() {
  solve(cin, cout);
  return 0;
}