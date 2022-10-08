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

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
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


#define dbg(...) ;


// ^^^^^^^^^^^^^^^^^ Library code end

int64_t solve1(vector<int64_t> as, int64_t c) {
    int n = (as.size() + 1) / 2;
    vector<int64_t> bs(n);
    bs[0] = mn(c, as[0]);
    vector<pair<int64_t, int64_t>> st, vals(n);
    st.push_back(vals[0] = {as[0], bs[0]});
    pair<int64_t, int64_t> add{0, 0};
    int lastGood = 0;
    int lastGood2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        int64_t mid = as[2 * i + 1];
        int64_t r = as[2 * i + 2];
        // (bs[i] + bs[i+1] >= mn(c, l + mid + r))
        add.first += mid + r;
        bs[i + 1] = mn(c, r);
        lastGood2 = mx(0, lastGood2 - 1);
        while (lastGood <= i && vals[lastGood].first + add.first > c) {
            ++lastGood;
        }
        while (lastGood2 < st.size() && st[lastGood2].first + add.first > c) {
            ++lastGood2;
        }
        if (lastGood > 0) {
            rmx(bs[i + 1], mn(c, vals[lastGood - 1].first + add.first) - (vals[lastGood - 1].second + add.second));
        }
        if (lastGood2 < st.size()) {
            rmx(bs[i + 1], mn(c, st[lastGood2].first + add.first) - (st[lastGood2].second + add.second));
        }
        add.second += bs[i + 1];
        vals[i + 1] = {r - add.first, bs[i + 1] - add.second};
        while (!st.empty() && st.back().first - st.back().second < vals[i + 1].first - vals[i + 1].second) {
            st.pop_back();
        }
        st.push_back(vals[i + 1]);
        dbg(add, st, vals, lastGood, lastGood2);
    }
    dbg(bs);
    int64_t ans = 0;
    for (int64_t x : bs) {
        ans += x;
    }
    return ans;
}


void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    int64_t c = next<int64_t>(in);
    auto as = next_vector<int64_t>(in, 2 * n - 1);
    out << solve1(as, c) << endl;
}


int main() {
    solve(cin, cout);
    return 0;
}