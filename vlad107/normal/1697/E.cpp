#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

template<typename T>
struct Modular;

template<typename T, T Mod>
struct Modular<typename std::integral_constant<T, Mod>> {
    using IntConstT = typename std::integral_constant<T, Mod>;
    
    static int const mod = Mod;
    
    Modular() : value() {}
    template<typename U> Modular(U const &value) : value(normalize(value)) { }
    
    Modular(Modular const &other) { value = other.value; }
    Modular(Modular &&other) { value = other.value; }
    
    Modular &operator=(Modular<IntConstT> const &other) { value = other.value; return *this; }
    
    explicit operator T() const { return value; }
    T operator()() const {
    	return value;
    }
    
    template<typename U>
    inline static T normalize(U const &value) { return ((value % mod) + mod) % mod; }
    
    inline void normalize_fast() {
    	if (value >= mod) value -= mod;
    	if (value < 0) value += mod;
    }
    
    Modular &operator+=(Modular const &other) { value += other.value; normalize_fast(); return *this; }
    Modular &operator-=(Modular const &other) { value -= other.value; normalize_fast(); return *this; }
    
    template<
    	typename U = T,
    	typename std::enable_if_t<!std::is_same_v<U, int>, bool> = true
    > 
    Modular &operator*=(Modular const &other) { throw std::runtime_error("default *= doesn't exist"); }
    
    template<
    	typename U = T,
    	typename std::enable_if_t<std::is_same_v<U, int>, bool> = true
    >
    Modular &operator*=(Modular const &other) { 
    	value = (static_cast<long long>(value) * other.value) % mod;
    	return *this;
    }
    
    Modular &operator/=(Modular const &other) {
    	Modular rev_value = other.pow(mod - 2);
    	return *this *= rev_value;
    }
    
    template<typename U>
    Modular pow(U const &x) const {
    	Modular res(1);
    	Modular cur_p(value);
    	U p(x);
    	while (p) {
    	    if (p % 2) res *= cur_p;
    	    cur_p *= cur_p;
    	    p /= 2;
    	}
    	return res;
    }
    
    void print() {
    	std::cerr << value << " " << mod << std::endl;
    }
    
    Modular &operator++() { return *this += 1; }
    Modular operator++(int) const {
    	Modular res(*this);
    	++*this;
    	return res;
    }
    Modular &operator--() { return *this += 1; }
    Modular operator--(int) const {
        Modular res(*this);
    	--*this;
    	return *this += 1; 
    }
    
    friend bool operator==(const Modular<T>& lhs, const Modular<T>& rhs);
    friend bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs);

private:
	T value;
};

#define defineop(op) \
template<typename T> Modular<T> operator op (const Modular<T>& lhs, const Modular<T>& rhs) { return Modular(lhs) op ##= rhs; } \
template<typename T, typename U> Modular<T> operator op (const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) op ##= rhs; } \
template<typename T, typename U> Modular<T> operator op (U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) op ##= rhs; }

defineop(+)
defineop(-)
defineop(*)
defineop(/)

template<typename T> 
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template<typename T> 
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value != rhs.value; }

using Mod = Modular<std::integral_constant<int, 998244353>>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;

    std::vector<std::vector<int>> d(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> d_set(n);

    for (int i = 0; i < n; i++) {
        std::vector<std::pair<int, int>> dd;
        int min_d = std::numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            d[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            if ((j != i) && (d[i][j] < min_d)) {
                min_d = d[i][j];
            }
        }
        d_set[i].push_back(i);
        for (int j = 0; j < n; j++) {
            if (d[i][j] == min_d) d_set[i].push_back(j);
        }
        std::sort(d_set[i].begin(), d_set[i].end());
    }
    std::vector<int> sizes;
    std::vector<bool> marked(n);
    for (int i = 0; i < n; i++) {
        if (marked[i]) continue;
        bool sets_same = true;
        for (int x : d_set[i]) {
            if (d_set[i] != d_set[x]) {
                sets_same = false;
                break;
            }
        }
        if (sets_same) {
            sizes.push_back(d_set[i].size());
            for (int x : d_set[i]) marked[x] = true;
        } else {
            sizes.push_back(1);
            marked[i] = 1;
        }
    }

    int k = sizes.size();
    std::vector<std::vector<Mod>> f(k + 1, std::vector<Mod>(n + 1, 0));
    f[0][0] = 1;
    std::vector<Mod> fact(n + 1);
    fact[0] = 1;
    for (int i = 1 ; i <= n; i++)  {
        fact[i] = fact[i - 1] * i;
    }
    for (int i = 0; i < k; i++) {
        int sz = sizes[i];
        for (int j = 0; j < n; j++) {
            if (f[i][j]() == 0) continue;

            f[i + 1][j + 1] += f[i][j];
            if ((sz != 1) && (j + sz <= n)) {
                f[i + 1][j + sz] += f[i][j];
            }
        }
    }
    Mod sum = 0;
    for (int i = 1; i <= n; i++) sum += (f[k][i] * fact[n] / fact[n - i]);
    std::cout << sum() << std::endl;

    return 0;
}