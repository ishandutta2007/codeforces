#include <vector>
#include <deque>
#include <queue>
#include <stack>
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
#include <optional>

using namespace std;

#include <algorithm>
#include <inttypes.h>
#include <iostream>
#include <vector>



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
    
    template <typename ValueT>
    class IterableRange {
    public:
        class iterator {
        public:
            iterator(ValueT v__) : v_(v__) {}
            
            iterator& operator++() {
                ++v_;
                return *this;
            }
            
            bool operator==(iterator rhs) const { return v_ == rhs.v_; }
            bool operator!=(iterator rhs) const { return v_ != rhs.v_; }
            
            ValueT operator*() const { return v_; }
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


template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT end) {
    return {{}, end};
}

template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT begin, ValueT end) {
    return {begin, end};
}


// From util/relax.h


template <typename T>
void relax_max(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::max(relaxWhat, relaxBy);
}

template <typename T>
void relax_min(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::min(relaxWhat, relaxBy);
}


// From algo/io/baseio.h


template <typename T>
T read() {
    T res;
    std::cin >> res;
    return res;
}
static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;
    
    inline char get_char() {
        if (buf_pos >= chars_read) {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }
    
    inline void tie(int) {}
    
    inline explicit operator bool() {
        return cur != -1;
    }
    
    inline static bool is_blank(char c) {
        return c <= ' ';
    }
    
    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }
    
    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }
    
    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }
    
    template <typename T>
    inline FastInput& read_integer(T& n) {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
            int sign = +1;
            if (cur == '-') {
                sign = -1;
                get_char();
            }
            do {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
        return read_integer(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline FastInput& operator>>(__int128& n) {
        return read_integer(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

#define cin fast_input

static struct FastOutput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;
    
    inline void put_char(char c) {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }
    
    ~FastOutput() {
        fwrite(buf, 1, buf_pos, out);
    }
    
    inline FastOutput& operator<<(char c) {
        put_char(c);
        return *this;
    }
    
    inline FastOutput& operator<<(const char* s) {
        while (*s) {
            put_char(*s++);
        }
        return *this;
    }
    
    inline FastOutput& operator<<(const string& s) {
        for (int i = 0; i < (int) s.size(); i++) {
            put_char(s[i]);
        }
        return *this;
    }
    
    template <typename T>
    inline char* integer_to_string(T n) {
        // beware of TMP_SIZE
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
            *--p = '0';
        } else {
            bool is_negative = false;
            if (n < 0) {
                is_negative = true;
                n = -n;
            }
            while (n > 0) {
                *--p = (char) ('0' + n % 10);
                n /= 10;
            }
            if (is_negative) {
                *--p = '-';
            }
        }
        return p;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
        return integer_to_string(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline char* stringify(__int128 n) {
        return integer_to_string(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }
    
    template <typename T>
    inline FastOutput& operator<<(const T& n) {
        auto p = stringify(n);
        for (; *p != 0; p++) {
            put_char(*p);
        }
        return *this;
    }
} fast_output;

#define cout fast_output


// From algo/io/readvector.h



template <typename T>
std::vector<T> readVector(size_t size) {
    std::vector<T> res(size);
    for (auto& elt : res)
        elt = read<T>();
    return res;
}


// From Solvers/16xx/1637/Solver1637E.cpp


using namespace std;

// Solution for Codeforces problem http://codeforces.com/contest/1637/problem/E

class Solver1637E {
public:
    void run();
};

void Solver1637E::run() {
    for (int i : range(read<int>())) {
        int n,m;
        cin>>n>>m;
        vector<int> v(n);
        for(auto j : range(n)) cin>>v[j];
        set<pair<int, int>> bad_pairs;
        for (auto j: range(m)) {
            int x,y;
            cin>>x>>y;
            bad_pairs.insert({min(x, y), max(x,y)});
        }
        map<int, int> counts;
        for (auto elt: v) ++counts[elt];
        vector<pair<int, int>> choices;
        for (auto [value, count]: counts) choices.emplace_back(count, -value);
        sort(choices.begin(), choices.end());
        vector<int> optimal_choice_indices;
        int current_count = 0;
        for (auto j: range(choices.size())) {
            if (choices[j].first > current_count) {
                current_count = choices[j].first;
                optimal_choice_indices.push_back(j);
            }
        }
        
        int64_t answer = 0;
        for (int j: range(choices.size())) {
//            for (auto optimal_choice_index: optimal_choice_indices) {
            for(int k : range(optimal_choice_indices.size())) {
                int optimal_choice_index = optimal_choice_indices[k];
                int next_optimal_choice_index = (k + 1 == optimal_choice_indices.size()) ? (int)choices.size() : optimal_choice_indices[k+1];
                for (auto choice_index: range<int>(optimal_choice_index, next_optimal_choice_index)) {
                    if (choices[choice_index].first > choices[optimal_choice_index].first) break;
                    auto v_1 = -choices[j].second;
                    auto v_2 = -choices[choice_index].second;
                    if (choice_index != j && bad_pairs.count({min(v_1, v_2), max(v_1, v_2)}) == 0) {
                        relax_max(answer, int64_t(choices[j].first + choices[choice_index].first) * (v_1 + v_2));
                        break;
                    }
                }
            }
        }
        cout<<answer<<'\n';
    }
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    Solver1637E solver;
    solver.run();
}