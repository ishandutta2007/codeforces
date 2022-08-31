#include <algorithm>
#include <array>
#include <cinttypes>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>



// From util/compilers.h



template <typename... Args>
void FIX_UNUSED(const Args&...) {}


// From io/targets.h





struct IOFileNames {
  public:
    std::string input_file_name;
    std::string output_file_name;
};

IOFileNames input_txt_output_txt() { return {"input.txt", "output.txt"}; }

IOFileNames foo_in_foo_out(const std::string& file_name_base) {
    return {file_name_base + ".in", file_name_base + ".out"};
}

IOFileNames custom_file_names(const std::string& input_file_name, const std::string& output_file_name) {
    return {input_file_name, output_file_name};
}

void set_io_file_names(const IOFileNames& names) {
    FIX_UNUSED(names);
#ifndef LOCAL_PC
    freopen(names.input_file_name.c_str(), "r", stdin);
    freopen(names.output_file_name.c_str(), "w", stdout);
#endif
}


// From util/types.h




using uint = unsigned;
using int64 = int64_t;
using uint64 = uint64_t;


// From util/macro.h



#define COMMA ,

#define NOOP() \
    do {       \
    } while (false)

#define STRINGIFY(x) #x


// From io/print.h

// Output functions.
//
// Print values to the standard output.
//
// * print(value1, [value2, [...]])
//   Prints one or more values separated by spaces.
//
// * print_ln([value1, [value2, [...]]])
//   Prints zero or more values separated by spaces and a newline character.
//
// * print_vec(vec, separator)
//   Prints all elements in container 'vec', separated by 'separator'.
//
// * print_vec_ln(vec, separator)
//   Prints all elements in container 'vec', separated by 'separator',
//   and a new line character.
//
// * LOG(<any valid print call>)  [thread-hostile!]
//   Does debug logging: outputs to stderr, and only on local machine.
//   E.g.: LOG(print(x))





#define FLOAT_OUTPUT_PRECISION 12


#define FLOAT_OUTPUT_PRECISION_STR STRINGIFY(FLOAT_OUTPUT_PRECISION)

#define DEFINE_SIMPLE_PRINT_TYPE(TYPE_NAME, FORMAT) \
    template <>                                     \
    void print<TYPE_NAME>(TYPE_NAME value) {        \
        printf(FORMAT, value);                      \
    }

#ifdef LOCAL_PC

namespace internal {
inline static bool redirect_to_cerr = false;
}

// Use iostream locally for redirections in unit tests
// TODO: Add checks so that it doesn't compile for unsupported types.
template <typename T>
void print(const T& value) {
    auto& stream = internal::redirect_to_cerr ? std::cerr : std::cout;
    stream << std::fixed << std::setprecision(FLOAT_OUTPUT_PRECISION) << value;
}

#else

template <typename T>
void print(T value);

// Use stdio remotely, because it's faster
DEFINE_SIMPLE_PRINT_TYPE(int, "%d");
DEFINE_SIMPLE_PRINT_TYPE(uint, "%u");
DEFINE_SIMPLE_PRINT_TYPE(int64, "%" PRId64);
DEFINE_SIMPLE_PRINT_TYPE(uint64, "%" PRIu64);
DEFINE_SIMPLE_PRINT_TYPE(float, "%." FLOAT_OUTPUT_PRECISION_STR "f");
DEFINE_SIMPLE_PRINT_TYPE(double, "%." FLOAT_OUTPUT_PRECISION_STR "lf");
DEFINE_SIMPLE_PRINT_TYPE(char, "%c");
DEFINE_SIMPLE_PRINT_TYPE(const char*, "%s");

template <>
void print<const std::string&>(const std::string& value) {
    printf("%s", value.c_str());
}

#endif


inline void print_ln() { print('\n'); }

template <typename T>
void print_ln(const T& value) {
    print(value);
    print_ln();
}


template <typename HeadT, typename... TailT>
void print(const HeadT& head, const TailT&... tail) {
    print(head);
    print(' ');
    print(tail...);
}

template <typename HeadT, typename... TailT>
void print_ln(const HeadT& head, const TailT&... tail) {
    print(head);
    print(' ');
    print_ln(tail...);
}


template <typename VectorT, typename SeparatorT = char>
void print_vector(const VectorT& vec, const SeparatorT& separator = ' ') {
    if (vec.empty())
        return;
    const auto end_it = std::prev(end(vec));
    for (auto it = begin(vec); it != end_it; ++it) {
        print(*it);
        print(separator);
    }
    print(*end_it);
}

template <typename VectorT, typename SeparatorT = char>
void print_vector_ln(const VectorT& vec, const SeparatorT& separator = ' ') {
    print_vector(vec, separator);
    print_ln();
}


#ifdef LOCAL_PC

#define LOG(print_call)                     \
    do {                                    \
        internal::redirect_to_cerr = true;  \
        print_call;                         \
        internal::redirect_to_cerr = false; \
    } while (false)

#else

#define LOG(print_call) \
    do {                \
    } while (false)

#endif


// From util/check.h

// Assertions.
//
// - CHECK: assertion that is always enabled.
// - CHECK_DEFAULT: check that is by default enabled everywhere.
// - CHECK_DEBUG: check that is by default enabled only during local launches.
// - CHECK_INTERNAL: checks used to spot internal error in the library,
//       expected to be disabled during the contest, even locally.
//
// Warning. Never put statements with side effects in checks other than CHECK!
//
// TODO: Instruction on enabling/disabling checks.
//
// The same as above, in a table form:
//
//                | On server         | On local PC       | In library tests  |
// ---------------+-------------------+-------------------+-------------------+
// CHECK          | Yes               | Yes               | Yes               |
// CHECK_DEFAULT  | Yes by default    | Yes               | Yes/No            |
// CHECK_DEBUG    | No by default     | Yes               | Yes/No            |
// CHECK_INTERNAL | No                | No                | Yes/No            |
//
// Note that library is tested both with checks and without to make sure that
// optional CHECKs don't have side effects.  // TODO: Don't forget to actually do this.





namespace internal {
bool library_tests__enable_checks();
}  // namespace internal

// TODO: Print line and file, as assert does.
#define CHECK(EXPRESSION)  \
    do {                   \
        if (!(EXPRESSION)) \
            abort();       \
    } while (false)

#define INTERNAL_CHECK_CONDITIONALLY(EXPRESSION) \
    do {                                         \
        if (library_tests__enable_checks())      \
            CHECK(EXPRESSION);                   \
    } while (false)


// clang-format off
#ifndef CHECK_LEVEL
#  if defined LIBRARY_TEST
#    define CHECK_LEVEL 3
#  elif defined LOCAL_PC
#    define CHECK_LEVEL 2
#  else
#    define CHECK_LEVEL 1
#  endif
#endif
// clang-format on

// clang-format off
#if CHECK_LEVEL == 0
#  define CHECK_DEFAULT(EXPRESSION)   NOOP()
#  define CHECK_DEBUG(EXPRESSION)     NOOP()
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 1
#  define CHECK_DEFAULT(EXPRESSION)   CHECK(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     NOOP()
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 2
#  define CHECK_DEFAULT(EXPRESSION)   CHECK(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     CHECK(EXPRESSION)
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 3
#  define CHECK_DEFAULT(EXPRESSION)   INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#  define CHECK_INTERNAL(EXPRESSION)  INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#endif
// clang-format on


// From iter/for_times.h

// A loop to repeat operation several times.
//
// * FOR_TIMES(n)
//   Repeats loop body n times, e.g.:
//   ` print("We all live in a");
//   ` FOR_TIMES(3) {
//   `     print(" yellow submarine");
//   ` }



#define FOR_TIMES(N_TIMES) for (auto __counter = (N_TIMES); __counter > 0; --__counter)


// From io/scan.h

// Input functions. Come in several flavours:
//
// * try_scan<T>
//   Reads T from standard input, sets success bit.
//   If the call had failed, the retuned value is undefined.
//   For convenience has alias called try_scan_T,
//   expect (T == std::string) where the alias is try_scan_word.
//   TODO: Consider:
//           - swapping arguments (set variable, return success)
//           - using optionals instead
//
// * scan<T>
//   Reads T from standard input. Abort on failure.
//   For convenience has alias called scan_T,
//   expect (T == std::string) where the alias is scan_word.
//
// * scan
//   Automagically reads any type from standard input.
//   Can be used like this: ``int x = scan();  foo(scan());''
//   Abort on failure.
//
// * SCAN_2, SCAN_3, ...
//   Returns a brace-enclosed sequence of N object that can be used
//   to call an N-argument constructor:
//   ``Foo f = SCAN_3();  vec.push_back(SCAN_2());''
//   To call an explicit constructor put SCAN_x next to the type name:
//   ``Foo f SCAN_3();  vec.push_back(Bar SCAN_2());''
//   WARNING: Doesn't work in gcc < 4.9.1 and in MSVC (see below) -
//            execution order is not defined.
//            TODO: Check clang.
//            TODO: Add compile-time checks.
//
// * scan(...)
//   Scans one of more values from the input.
//   Abort if at least one element cannot be read.
//
// * scan_vector(n), scan_vector_2(n), scan_vector_3(n), ...
//   Returns vector of n elements, each requiring the corresponding
//   number of arguments to construct.
//   WARNING: scan_vector_K versions inherit SCAN_K limitations.
//
// Supported types are:
//
// * int, uint, int64, uint64
//   A decimal representation of an integer.
//
// * float, double
//   A decimal representation of a floating-point number,
//   either in fixed or in exponential format.
//
// * char
//   An ASCII character.
//
// * std::string
//   A word, i.e. a sequence of characters surrounded by whitespace.
//   Leading whitespace is ignored.
//
// * line (std::string)
//   A sequence of characters up to a new-line character.
//   Leading "\n" are ignored; leading whitespace is not.
//   Trailing "\n" is consumed, but not included in the result.
//
// TODO: Execution order warning.
//
// TODO: Leverage C++17 structured binding declaration
//
// WARNING. Scan functions rely both on cstdio (for chars, integers and floats)
//          and iostream (for strings), so std::ios_base::sync_with_stdio must
//          remain true!





#define DEFINE_SIMPLE_SCAN_TYPE(TYPE_NAME, FORMAT) \
    template <>                                    \
    TYPE_NAME try_scan<TYPE_NAME>(bool& success) { \
        TYPE_NAME result;                          \
        success = (scanf(FORMAT, &result) > 0);    \
        return result;                             \
    }

#ifdef LOCAL_PC

// Use iostream locally for redirections in unit tests
// TODO: Add checks so that it doesn't compile for unsupported types.
template <typename T>
T try_scan(bool& success) {
    T result;
    success = bool(std::cin >> result);
    return result;
}

#else

template <typename T>
T try_scan(bool& success);

// Use stdio remotely, because it's faster
DEFINE_SIMPLE_SCAN_TYPE(int, "%d");
DEFINE_SIMPLE_SCAN_TYPE(uint, "%u");
DEFINE_SIMPLE_SCAN_TYPE(int64, "%" SCNd64);
DEFINE_SIMPLE_SCAN_TYPE(uint64, "%" SCNu64);
DEFINE_SIMPLE_SCAN_TYPE(float, "%f");
DEFINE_SIMPLE_SCAN_TYPE(double, "%lf");
DEFINE_SIMPLE_SCAN_TYPE(char, "%c");  // TODO: sync with iostream (in terms of whitespace treatment)

template <>
std::string try_scan<std::string>(bool& success) {
    std::string result;
    success = bool(std::cin >> result);
    return result;
}

#endif

#if 0  // TODO try
template<typename Arg>
std::tuple<Arg> try_scan<std::tuple<Arg>>(bool& success) {
    return std::make_tuple(try_scan<Arg>(success));
}

template<typename Head, typename... Tail>
std::tuple<Head, Tail> try_scan<std::tuple<Head, Tail>>(bool& success) {
    auto head = try_scan<Head>(success);
    if (!success)
        return {};
    auto tail = try_scan<Tail>(success);
    return std::tuple_cat(head, tail);
}
#endif

inline int try_scan_int(bool& success) { return try_scan<int>(success); }
inline uint try_scan_uint(bool& success) { return try_scan<uint>(success); }
inline int64 try_scan_int64(bool& success) { return try_scan<int64>(success); }
inline uint64 try_scan_uint64(bool& success) { return try_scan<uint64>(success); }
inline float try_scan_float(bool& success) { return try_scan<float>(success); }
inline double try_scan_double(bool& success) { return try_scan<double>(success); }
inline char try_scan_char(bool& success) { return try_scan<char>(success); }
inline std::string try_scan_word(bool& success) { return try_scan<std::string>(success); }

inline std::string try_scan_line(bool& success) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string result;
    success = bool(std::getline(std::cin, result));
    return result;
}


template <typename T>
T scan() {
    bool success = false;
    T result = try_scan<T>(success);
    CHECK(success);
    return result;
}

inline int scan_int() { return scan<int>(); }
inline uint scan_uint() { return scan<uint>(); }
inline int64 scan_int64() { return scan<int64>(); }
inline uint64 scan_uint64() { return scan<uint64>(); }
inline float scan_float() { return scan<float>(); }
inline double scan_double() { return scan<double>(); }
inline char scan_char() { return scan<char>(); }
inline std::string scan_word() { return scan<std::string>(); }

inline std::string scan_line() {
    bool success = false;
    std::string result = try_scan_line(success);
    CHECK(success);
    return result;
}


namespace internal {

class ScanResult {
  public:
    ScanResult(const ScanResult&) = delete;
    ScanResult& operator=(const ScanResult&) = delete;

    template <typename T>
    operator T() && {
        return scan<T>();
    }
};

}  // namespace internal

internal::ScanResult scan() { return {}; }

// TODO: fix for std::string
#define SCAN_2() \
    { scan(), scan() }
#define SCAN_3() \
    { scan(), scan(), scan() }
#define SCAN_4() \
    { scan(), scan(), scan(), scan() }
#define SCAN_5() \
    { scan(), scan(), scan(), scan(), scan() }
#define SCAN_6() \
    { scan(), scan(), scan(), scan(), scan(), scan() }
#define SCAN_7() \
    { scan(), scan(), scan(), scan(), scan(), scan(), scan() }
#define SCAN_8() \
    { scan(), scan(), scan(), scan(), scan(), scan(), scan(), scan() }


template <typename Arg>
void scan(Arg& arg) {
    arg = scan<Arg>();
}

template <typename Head, typename... Tail>
void scan(Head& head, Tail&... tail) {
    scan(head);
    scan(tail...);
}

#define DEFINE_SCAN_VECTOR_N(NAME, SCAN_FUNCTION)                  \
    template <typename ElementT>                                   \
    std::vector<ElementT> NAME(size_t n_elements) {                \
        CHECK(ssize_t(n_elements) >= 0);                           \
        std::vector<ElementT> result;                              \
        result.reserve(n_elements);                                \
        FOR_TIMES(n_elements) { result.push_back(SCAN_FUNCTION); } \
        return result;                                             \
    }

DEFINE_SCAN_VECTOR_N(scan_vector, scan())
DEFINE_SCAN_VECTOR_N(scan_vector_2, SCAN_2())
DEFINE_SCAN_VECTOR_N(scan_vector_3, SCAN_3())
DEFINE_SCAN_VECTOR_N(scan_vector_4, SCAN_4())
DEFINE_SCAN_VECTOR_N(scan_vector_5, SCAN_5())
DEFINE_SCAN_VECTOR_N(scan_vector_6, SCAN_6())
DEFINE_SCAN_VECTOR_N(scan_vector_7, SCAN_7())
DEFINE_SCAN_VECTOR_N(scan_vector_8, SCAN_8())

#undef DEFINE_SCAN_VECTOR_N


// From std.h




using namespace std;


// From codeforces/1107/C/c.cpp




class SolverC {
public:
  void run();
};

void SolverC::run() {
    int n = scan();
    int k = scan();
    auto a = scan_vector<int>(n);
    string s = scan_word();
    int start = 0;
    long long total_dmg = 0;
    for (int i = 1; i <= s.length(); ++i) {
        if (i == s.length() || s[i-1] != s[i]) {
            const int end = i;
            std::sort(a.begin() + start, a.begin() + end, [](int x, int y) { return x > y; });
            const int end_take = std::min(end, start + k);
            for (int j = start; j < end_take; ++j)
                total_dmg += a[j];
            start = end;
        }
    }
    cout<<total_dmg;
}


int main() {
    SolverC solver;
    solver.run();
}