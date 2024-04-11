#include <bits/stdc++.h>

#ifdef _MSC_VER
#  include <intrin.h>
#else
#  include <x86intrin.h>
#endif

#include <limits>
#include <type_traits>

namespace suisen {
// ! utility
template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}

// ! function
template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;

// ! integral
template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool is_nbit_v = is_nbit<T, n>::value;

// ?
template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long int> { using type = __uint128_t; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

template <typename T, typename = void>
struct rec_value_type {
    using type = T;
};
template <typename T>
struct rec_value_type<T, std::void_t<typename T::value_type>> {
    using type = typename rec_value_type<typename T::value_type>::type;
};
template <typename T>
using rec_value_type_t = typename rec_value_type<T>::type;

} // namespace suisen

// ! type aliases
using i128 = __int128_t;
using u128 = __uint128_t;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;

// ! macros (capital: internal macro)
#define OVERLOAD2(_1,_2,name,...) name
#define OVERLOAD3(_1,_2,_3,name,...) name
#define OVERLOAD4(_1,_2,_3,_4,name,...) name

#define REP4(i,l,r,s)  for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l);i<(r);i+=(s))
#define REP3(i,l,r)    REP4(i,l,r,1)
#define REP2(i,n)      REP3(i,0,n)
#define REPINF3(i,l,s) for(std::remove_reference_t<std::remove_const_t<decltype(l)>>i=(l);;i+=(s))
#define REPINF2(i,l)   REPINF3(i,l,1)
#define REPINF1(i)     REPINF2(i,0)
#define RREP4(i,l,r,s) for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l)+fld((r)-(l)-1,s)*(s);i>=(l);i-=(s))
#define RREP3(i,l,r)   RREP4(i,l,r,1)
#define RREP2(i,n)     RREP3(i,0,n)

#define rep(...)    OVERLOAD4(__VA_ARGS__, REP4   , REP3   , REP2   )(__VA_ARGS__)
#define rrep(...)   OVERLOAD4(__VA_ARGS__, RREP4  , RREP3  , RREP2  )(__VA_ARGS__)
#define repinf(...) OVERLOAD3(__VA_ARGS__, REPINF3, REPINF2, REPINF1)(__VA_ARGS__)

#define CAT_I(a, b) a##b
#define CAT(a, b) CAT_I(a, b)
#define UNIQVAR(tag) CAT(tag, __LINE__)
#define loop(n) for (std::remove_reference_t<std::remove_const_t<decltype(n)>> UNIQVAR(loop_variable) = n; UNIQVAR(loop_variable) --> 0;)

#define all(iterable) std::begin(iterable), std::end(iterable)
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

#ifdef LOCAL
#  define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)

template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* prefix = "[\033[32mDEBUG\033[m] ";
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << prefix << open_brakets << s << close_brakets << ": " << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << "\n";
}

#else
#  define debug(...) void(0)
#endif

// ! I/O utilities

// __int128_t
std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
// __uint128_t
std::ostream& operator<<(std::ostream& dest, __uint128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[value % 10];
            value /= 10;
        } while (value != 0);
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

// pair
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& a) {
    return out << a.first << ' ' << a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}
// vector
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
// array
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}

__int128_t parse_i128(std::string& s) {
    __int128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    if (s[0] == '-') ret = -ret;
    return ret;
}
__uint128_t parse_u128(std::string& s) {
    __uint128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    return ret;
}
// __int128_t
std::istream& operator>>(std::istream& in, __int128_t& v) {
    std::string s;
    in >> s;
    v = parse_i128(s);
    return in;
}
// __uint128_t
std::istream& operator>>(std::istream& in, __uint128_t& v) {
    std::string s;
    in >> s;
    v = parse_u128(s);
    return in;
}
// pair
template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& a) {
    return in >> a.first >> a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}
// vector
template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
// array
template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    (std::cin >> ... >> args);
}

// ! integral utilities

// Returns pow(-1, n)
template <typename T>
constexpr inline int pow_m1(T n) {
    return -(n & 1) | 1;
}
// Returns pow(-1, n)
template <>
constexpr inline int pow_m1<bool>(bool n) {
    return -int(n) | 1;
}

// Returns floor(x / y)
template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + pow_m1(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + pow_m1(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u64(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int floor_log2(const T x) { return suisen::bit_num<T> -1 - count_lz(x); }
template <typename T>
constexpr inline int ceil_log2(const T x) { return floor_log2(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int kth_bit(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

// ! container

template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto priqueue_comp(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable& iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto generate_range_vector(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto generate_range_vector(T n) {
    return generate_range_vector(0, n);
}

template <typename T>
void sort_unique_erase(std::vector<T>& a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto foreach_adjacent_values(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto foreach_adjacent_values(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()) {
    foreach_adjacent_values(c.begin(), c.end(), f);
}

// ! other utilities

// x <- min(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmin(T& x, const T& y) {
    if (y >= x) return false;
    x = y;
    return true;
}
// x <- max(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmax(T& x, const T& y) {
    if (y <= x) return false;
    x = y;
    return true;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::string bin(T val, int bit_num = -1) {
    std::string res;
    if (bit_num >= 0) {
        for (int bit = bit_num; bit-- > 0;) res += '0' + ((val >> bit) & 1);
    } else {
        for (; val; val >>= 1) res += '0' + (val & 1);
        std::reverse(res.begin(), res.end());
    }
    return res;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> digits_low_to_high(T val, T base = 10) {
    std::vector<T> res;
    for (; val; val /= base) res.push_back(val % base);
    if (res.empty()) res.push_back(T{ 0 });
    return res;
}
template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> digits_high_to_low(T val, T base = 10) {
    auto res = digits_low_to_high(val, base);
    std::reverse(res.begin(), res.end());
    return res;
}

template <typename T>
std::string join(const std::vector<T>& v, const std::string& sep, const std::string& end) {
    std::ostringstream ss;
    for (auto it = v.begin(); it != v.end();) {
        ss << *it;
        if (++it != v.end()) ss << sep;
    }
    ss << end;
    return ss.str();
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} io_setup_{};

// ! code from here

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include <cassert>
#include <utility>

#ifndef COORDINATE_TYPE
#define COORDINATE_TYPE long long
#endif // COORDINATE_TYPE
#ifndef MULTIPLIED_TYPE
#define MULTIPLIED_TYPE long long
#endif // MULTIPLIED_TYPE

namespace suisen::integral_geometry {
    using coordinate_t = COORDINATE_TYPE;
    using multiplied_t = MULTIPLIED_TYPE;

    struct Point {
        coordinate_t x, y;
        constexpr Point(coordinate_t x = 0, coordinate_t y = 0) : x(x), y(y) {}

        template <typename T = coordinate_t, typename U = coordinate_t>
        operator std::pair<T, U>() const { return std::pair<T, U> { T{ x }, U{ y } }; }
        template <typename T, typename U>
        Point& operator=(const std::pair<T, U> &p) { x = p.first, y = p.second; return *this; }

        friend Point operator+(const Point& p) { return p; }
        friend Point operator-(const Point& p) { return { -p.x, -p.y }; }

        friend Point operator+(const Point& lhs, const Point& rhs) { return { lhs.x + rhs.x, lhs.y + rhs.y }; }
        friend Point operator-(const Point& lhs, const Point& rhs) { return { lhs.x - rhs.x, lhs.y - rhs.y }; }
        friend Point operator*(const Point& lhs, const Point& rhs) { return { lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x }; }

        friend Point& operator+=(Point& lhs, const Point& rhs) { lhs.x += rhs.x, lhs.y += rhs.y; return lhs; }
        friend Point& operator-=(Point& lhs, const Point& rhs) { lhs.x -= rhs.x, lhs.y -= rhs.y; return lhs; }
        friend Point& operator*=(Point& lhs, const Point& rhs) { return lhs = lhs * rhs; }

        friend Point operator+(const Point& p, coordinate_t real) { return { p.x + real, p.y }; }
        friend Point operator-(const Point& p, coordinate_t real) { return { p.x - real, p.y }; }
        friend Point operator*(const Point& p, coordinate_t real) { return { p.x * real, p.y * real }; }
        friend Point operator/(const Point& p, coordinate_t real) { return { p.x / real, p.y / real }; }

        friend Point operator+=(Point& p, coordinate_t real) { p.x += real; return p; }
        friend Point operator-=(Point& p, coordinate_t real) { p.x -= real; return p; }
        friend Point operator*=(Point& p, coordinate_t real) { p.x *= real, p.y *= real; return p; }
        friend Point operator/=(Point& p, coordinate_t real) { p.x /= real, p.y /= real; return p; }

        friend Point operator+(coordinate_t real, const Point& p) { return { real + p.x, p.y }; }
        friend Point operator-(coordinate_t real, const Point& p) { return { real - p.x, -p.y }; }
        friend Point operator*(coordinate_t real, const Point& p) { return { real * p.x, real * p.y }; }

        friend bool operator==(const Point& lhs, const Point& rhs) { return lhs.x == rhs.x and lhs.y == rhs.y; }
        friend bool operator!=(const Point& lhs, const Point& rhs) { return not (lhs == rhs); }

        friend std::istream& operator>>(std::istream& in, Point& p) { return in >> p.x >> p.y; }
        friend std::ostream& operator<<(std::ostream& out, const Point& p) { return out << p.x << ' ' << p.y; }

        template <std::size_t I>
        coordinate_t get() const {
            if constexpr (I == 0) return x;
            else if constexpr (I == 1) return y;
            else assert(false);
        }
        template <std::size_t I>
        coordinate_t& get() {
            if constexpr (I == 0) return x;
            else if constexpr (I == 1) return y;
            else assert(false);
        }
    };

    constexpr Point ZERO = { 0, 0 };
    constexpr Point ONE  = { 1, 0 };
    constexpr Point I    = { 0, 1 };

    constexpr auto XY_COMPARATOR         = [](const Point& p, const Point& q) { return p.x == q.x ? p.y < q.y : p.x < q.x; };
    constexpr auto XY_COMPARATOR_GREATER = [](const Point& p, const Point& q) { return p.x == q.x ? p.y > q.y : p.x > q.x; };
    constexpr auto YX_COMPARATOR         = [](const Point& p, const Point& q) { return p.y == q.y ? p.x < q.x : p.y < q.y; };
    constexpr auto YX_COMPARATOR_GREATER = [](const Point& p, const Point& q) { return p.y == q.y ? p.x > q.x : p.y > q.y; };
} // namespace suisen::integral_geometry

namespace std {
    template <>
    struct tuple_size<suisen::integral_geometry::Point> : integral_constant<size_t, 2> {};
    template <size_t I>
    struct tuple_element<I, suisen::integral_geometry::Point> { using type = suisen::integral_geometry::coordinate_t; };
}

namespace suisen::integral_geometry {
    // relations between three points X, Y, Z.
    struct ISP {
        static constexpr int L_CURVE = +1; // +---------------+ Z is in 'a' => ISP = +1
        static constexpr int R_CURVE = -1; // |aaaaaaaaaaaaaaa| Z is in 'b' => ISP = -1
        static constexpr int FRONT = +2;   // |ddd X eee Y ccc| Z is in 'c' => ISP = +2
        static constexpr int BACK = -2;    // |bbbbbbbbbbbbbbb| Z is in 'd' => ISP = -2
        static constexpr int MIDDLE = 0;   // +---------------+ Z is in 'e' => ISP =  0
    };

    enum class Containment { OUT, ON, IN };

    int sgn(coordinate_t x) { return x < 0 ? -1 : x > 0 ? +1 : 0; }
    int compare(coordinate_t x, coordinate_t y) { return sgn(x - y); }

    Point cartesian(const coordinate_t real, const coordinate_t imag) { return Point(real, imag); }
    Point conj(const Point& z) { return Point(z.x, -z.y); }
    double arg(const Point& z) { return std::atan2(z.y, z.x); }
    multiplied_t square_abs(const Point& z) { return multiplied_t(z.x) * z.x + multiplied_t(z.y) * z.y; }
    double abs(const Point& z) { return std::sqrt(square_abs(z)); }

    multiplied_t dot(const Point& a, const Point& b) { return multiplied_t(a.x) * b.x + multiplied_t(a.y) * b.y; }
    multiplied_t det(const Point& a, const Point& b) { return multiplied_t(a.x) * b.y - multiplied_t(a.y) * b.x; }

    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    int isp(const Point& a, const Point& b, const Point& c) {
        Point ab = b - a, ac = c - a;
        coordinate_t det_ab_ac = det(ab, ac);
        if (det_ab_ac > 0) return ISP::L_CURVE;
        if (det_ab_ac < 0) return ISP::R_CURVE;
        if (dot(ab, ac) < 0) return ISP::BACK;
        if (dot(a - b, c - b) < 0) return ISP::FRONT;
        return ISP::MIDDLE;
    }

    struct Line {
        Point a, b;
        Line() = default;
        Line(const Point& from, const Point& to) : a(from), b(to) {}
    };
    struct Ray {
        Point a, b;
        Ray() = default;
        Ray(const Point& from, const Point& to) : a(from), b(to) {}
    };
    struct Segment {
        Point a, b;
        Segment() = default;
        Segment(const Point& from, const Point& to) : a(from), b(to) {}
    };
    struct Circle {
        Point center;
        coordinate_t radius;
        Circle() = default;
        Circle(const Point& c, const coordinate_t& r) : center(c), radius(r) {}
    };

    // Triangle

    coordinate_t signed_area_doubled(const Point& a, const Point& b, const Point& c) {
        return det(b - a, c - a);
    }
    coordinate_t area_doubled(const Point& a, const Point& b, const Point& c) {
        return std::abs(signed_area_doubled(a, b, c));
    }

    // Line

    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
    template <typename line_t_1, typename line_t_2>
    auto is_parallel(const line_t_1& l1, const line_t_2& l2) -> decltype(l1.a, l1.b, l2.a, l2.b, bool()) {
        return det(l1.b - l1.a, l2.b - l2.a) == 0;
    }
    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
    template <typename line_t_1, typename line_t_2>
    auto is_orthogonal(const line_t_1& l1, const line_t_2& l2) -> decltype(l1.a, l1.b, l2.a, l2.b, bool()) {
        return dot(l1.b - l1.a, l2.b - l2.a) == 0;
    }
    template <typename line_t_1, typename line_t_2>
    auto on_the_same_line(const line_t_1& l1, const line_t_2& l2) -> decltype(l1.a, l1.b, l2.a, l2.b, bool()) {
        return is_parallel(l1, l2) and det(l1.b - l1.a, l2.a - l1.a) == 0;
    }

    Containment contains(const Line& l, const Point& p) {
        if (l.a.x == l.b.x) return p.x == l.a.x ? Containment::ON : Containment::OUT;
        coordinate_t a = p.x - l.a.x, b = p.y - l.a.y, c = l.b.x - p.x, d = l.b.y - p.y;
        return b * c == a * d ? Containment::ON : Containment::OUT;
    }
    Containment contains(const Ray& l, const Point& p) {
        if (contains(Line { l.a, l.b }, p) == Containment::OUT) return Containment::OUT;
        if (l.a.x == l.b.x) {
            if (l.a.y < l.b.y) return p.y >= l.a.y ? Containment::ON : Containment::OUT;
            else return p.y <= l.a.y ? Containment::ON : Containment::OUT;
        } else if (l.a.x < l.b.x) {
            return p.x >= l.a.x ? Containment::ON : Containment::OUT;
        } else {
            return p.x <= l.a.x ? Containment::ON : Containment::OUT;
        }
    }
    Containment contains(const Segment& l, const Point& p) {
        if (contains(Line { l.a, l.b }, p) == Containment::OUT) return Containment::OUT;
        if (l.a.x == l.b.x) {
            if (l.a.y < l.b.y) return p.y >= l.a.y and p.y <= l.b.y ? Containment::ON : Containment::OUT;
            else return p.y >= l.b.y and p.y <= l.a.y ? Containment::ON : Containment::OUT;
        } else if (l.a.x < l.b.x) {
            return p.x >= l.a.x and p.x <= l.b.x ? Containment::ON : Containment::OUT;
        } else {
            return p.x >= l.b.x and p.x <= l.a.x ? Containment::ON : Containment::OUT;
        }
    }

    bool operator==(const Line& l, const Line& m) {
        return on_the_same_line(l, m);
    }
    bool operator==(const Ray& l, const Ray& m) {
        return on_the_same_line(l, m) and l.a == m.a;
    }
    bool operator==(const Segment& l, const Segment& m) {
        return (l.a == m.a and l.b == m.b) or (l.a == m.b and l.b == m.a);
    }

    // "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"
    bool has_common_point(const Segment& l1, const Segment& l2) {
        int isp_1a = isp(l1.a, l1.b, l2.a), isp_1b = isp(l1.a, l1.b, l2.b);
        if (isp_1a * isp_1b > 0) return false;
        int isp_2a = isp(l2.a, l2.b, l1.a), isp_2b = isp(l2.a, l2.b, l1.b);
        if (isp_2a * isp_2b > 0) return false;
        return true;
    }

    // Polygon

    using Polygon = std::vector<Point>;

    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    coordinate_t signed_area_doubled(const Polygon& poly) {
        coordinate_t res = 0;
        int sz = poly.size();
        for (int i = 0; i < sz; ++i) {
            int j = i + 1;
            if (j == sz) j = 0;
            res += signed_area_doubled(ZERO, poly[i], poly[j]);
        }
        return res;
    }
    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    coordinate_t area_doubled(const Polygon& poly) {
        return std::abs(signed_area_doubled(poly));
    }
    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
    template <bool accept_180_degree = true>
    bool is_convex(const Polygon& poly) {
        int sz = poly.size();
        for (int i = 0; i < sz; ++i) {
            int j = i + 1, k = i + 2;
            if (j >= sz) j -= sz;
            if (k >= sz) k -= sz;
            int dir = isp(poly[i], poly[j], poly[k]);
            if constexpr (accept_180_degree) {
                if (dir == ISP::R_CURVE) return false;
            } else {
                if (dir != ISP::L_CURVE) return false;
            }
        }
        return true;
    }
    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
    Containment contains(const Polygon& poly, const Point& p) {
        bool in = false;
        int sz = poly.size();
        for (int i = 0; i < sz; ++i) {
            int j = i + 1;
            if (j == sz) j -= sz;
            Point a = poly[i] - p, b = poly[j] - p;
            if (a.y > b.y) std::swap(a, b);
            if (a.y <= 0 and b.y > 0 and det(a, b) < 0) in = not in;
            if (det(a, b) == 0 and dot(a, b) <= 0) return Containment::ON;
        }
        return in ? Containment::IN : Containment::OUT;
    }

    std::pair<int, int> convex_diameter(const Polygon& convex) {
        const int sz = convex.size();
        if (sz <= 2) return { 0, sz - 1 };
        auto [si, sj] = [&]{
            auto [it_min, it_max] = std::minmax_element(convex.begin(), convex.end(), XY_COMPARATOR);
            return std::pair<int, int> { it_min - convex.begin(), it_max - convex.begin() };
        }();
        coordinate_t max_dist = -1;
        std::pair<int, int> argmax{ -1, -1 };
        for (int i = si, j = sj; i != sj or j != si;) {
            if (multiplied_t dij = square_abs(convex[j] - convex[i]); dij > max_dist) max_dist = dij, argmax = { i, j };
            int ni = (i + 1) % sz, nj = (j + 1) % sz;
            if (det(convex[ni] - convex[i], convex[nj] - convex[j]) < 0) i = ni;
            else j = nj;
        }
        return argmax;
    }

    // Circle

    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    int tangent_num(const Circle& c1, const Circle& c2) {
        coordinate_t r1 = c1.radius, r2 = c2.radius;
        if (r1 > r2) return tangent_num(c2, c1);
        coordinate_t d2 = square_abs(c1.center - c2.center);
        coordinate_t dp = d2 - (r1 + r2) * (r1 + r2);
        if (dp > 0) return 4;
        if (dp == 0) return 3;
        coordinate_t dn = d2 - (r2 - r1) * (r2 - r1);
        if (dn > 0) return 2;
        if (dn == 0) return 1;
        return 0;
    }
    bool has_common_point(const Circle& c1, const Circle& c2) {
        int tnum = tangent_num(c1, c2);
        return 1 <= tnum and tnum <= 3;
    }
    bool has_cross_point(const Circle& c1, const Circle& c2) {
        return tangent_num(c1, c2) == 2;
    }

    Containment contains(const Circle& c, const Point& p) {
        coordinate_t df = square_abs(c.center - p) - c.radius * c.radius;
        if (df > 0) return Containment::OUT;
        if (df < 0) return Containment::IN;
        return Containment::ON;
    }
} // namespace suisen::integral_geometry

using namespace integral_geometry;

using fp = long double;

int main() {
    input(int, n, h);
    vector<Point> points(n);
    rep(i, n) {
        input(int, x, y);
        points[i] = { x, y };
    }

    fp ans = 0;
    Point eye{ points[n - 1].x, points[n - 1].y + h };
    Point prv = points[n - 1];
    rrep(i, n - 1) {
        Point cur = points[i], nxt = points[i + 1];
        if (int dir = isp(prv, eye, cur); dir == ISP::BACK or dir == ISP::L_CURVE) {
            fp x, y;
            if (isp(cur, nxt, eye) != ISP::FRONT) {
                Line l1{ cur, nxt };
                Line l2{ prv, eye };
                Point u = l1.b - l1.a, v = l2.a - l2.b, c = l2.a - l1.a;
                fp coef = fp(det(u, c)) / det(u, v);
                x = (l2.a.x - coef * v.x) - cur.x;
                y = (l2.a.y - coef * v.y) - cur.y;
            } else {
                x = nxt.x - cur.x;
                y = nxt.y - cur.y;
            }
            ans += sqrtl(x * x + y * y);
            prv = cur;
        }
    }
    print(ans);
    return 0;
}