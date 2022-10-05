//
// Created by  on 2022/1/6.
//
#include <bits/stdc++.h>

using ll = int64_t;

template <typename T>
T inv(T a, T moder){
    T b = moder, s = 1, t = 0;
    while (b){
        T tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s; s = t; t = tmp - s * q;
    }
    // if (a > 1) return -1;
    assert(a == 1);
    return s < 0 ? s + moder : s;
}

template <typename T>
class Mod{
public:
    const static T moder = 998'244'353;
    T a;

    Mod():a(){}

    template<typename U>
    Mod(const U &u){a = norm(u);}

    template<typename U>
    static T norm(U value){
        if (value < -moder || value >= moder){
            value %= moder;
        }
        value += value < 0 ? moder : 0;
        return value;
    }

    Mod& operator +=(const Mod &u){ a += u.a; a -= a >= moder ? moder : 0; return *this; }
    Mod& operator -=(const Mod &u){ a -= u.a; a += a < 0 ? moder : 0; return *this; }
    Mod& operator ++(){ return *this += 1; }
    Mod& operator --(){ return *this -= 1; }
    Mod operator ++(int){ Mod result = *this; *this += 1; return result; }
    Mod operator --(int){ Mod result = *this; *this -= 1; return result; }
    Mod operator -()const{ return Mod(-a); }
    template<typename U = T>std::enable_if_t<std::is_same_v<U, int>, Mod>& operator *=(const Mod &u){
        a = norm(1ll * a * u.a);
        return *this;
    }
    template<typename U = T>std::enable_if_t<std::is_same_v<U, ll>, Mod>& operator *=(const Mod &u){
        ll q = ll((long double) a * u.a / moder);
        a = norm(a * u.a - q * moder);
        return *this;
    }
    Mod& operator /=(const Mod& u){return *this *= inv(u.a, moder);}

    template <typename U>
    Mod powermod(U exp){
        assert(exp >= 0);
        Mod aa = *this, ret = 1;
        for ( ; exp > 0; exp >>= 1){
            if (exp & 1) ret *= aa;
            aa *= aa;
        }
        return ret;
    }
};

template <typename T> Mod<T> operator +(const Mod<T> &u, const Mod<T> &v){ return Mod<T>(u) += v; }
template <typename T, typename U> Mod<T> operator +(const U &u, const Mod<T> &v){ return Mod<T>(u) += v; }
template <typename T, typename U> Mod<T> operator +(const Mod<T> &u, const U &v){ return Mod<T>(u) += v; }
template <typename T> Mod<T> operator -(const Mod<T> &u, const Mod<T> &v){ return Mod<T>(u) -= v; }
template <typename T, typename U> Mod<T> operator -(const U &u, const Mod<T> &v){ return Mod<T>(u) -= v; }
template <typename T, typename U> Mod<T> operator -(const Mod<T> &u, const U &v){ return Mod<T>(u) -= v; }
template <typename T> Mod<T> operator *(const Mod<T> &u, const Mod<T> &v){ return Mod<T>(u) *= v; }
template <typename T, typename U> Mod<T> operator *(const U &u, const Mod<T> &v){ return Mod<T>(u) *= v; }
template <typename T, typename U> Mod<T> operator *(const Mod<T> &u, const U &v){ return Mod<T>(u) *= v; }
template <typename T> Mod<T> operator /(const Mod<T> &u, const Mod<T> &v){ return Mod<T>(u) /= v; }
template <typename T, typename U> Mod<T> operator /(const U &u, const Mod<T> &v){ return Mod<T>(u) /= v; }
template <typename T, typename U> Mod<T> operator /(const Mod<T> &u, const U &v){ return Mod<T>(u) /= v; }

template <typename U, typename T>
U& operator <<(U &ostream, const Mod <T> &u){
    return ostream << u.a;
}

template <typename U, typename T>
U& operator >>(U &istream, Mod <T> &u){
    T x;
    istream >> x;
    u = x;
    return istream;
}

using Mint = Mod<int>;

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
const int BIT = 30;

Mint solve1(std::vector <int> vec0, std::vector <int> vec1, int cur, int x, int before){
    if (cur == -1){
        Mint ans = Mint(2).powermod(vec0.size() + vec1.size());
        // std::cout << ans << "\n";
        return ans;
    }
    if (before == 0){
        if (vec0.empty()){
            return 1;
        }
        if (vec1.empty()){
            std::vector <int> vec2, vec3;
            for (auto u : vec0){
                (u >> cur & 1? vec3 : vec2).emplace_back(u);
            }
            if (x >> cur & 1){
                return solve1(vec2, vec3, cur - 1, x, 1);
            }
            Mint ans1 = solve1(vec2, {}, cur - 1, x, 0);
            Mint ans2 = solve1(vec3, {}, cur - 1, x, 0);
            // std::cout << ans1 << " " << ans2 << "\n";
            return ans1 + ans2 - 1;
        }
        assert(false);
    }
    if (vec0.empty() || vec1.empty()){
        return Mint(2).powermod(vec0.size() + vec1.size());
    }
    std::vector <int> vec2, vec3, vec4, vec5;
    for (auto u : vec0){
        (u >> cur & 1? vec3 : vec2).emplace_back(u);
    }
    for (auto u : vec1){
        (u >> cur & 1? vec5 : vec4).emplace_back(u);
    }
    if (x >> cur & 1){
        return solve1(vec2, vec5, cur - 1, x, 1) * solve1(vec3, vec4, cur - 1, x, 1);
    }
    return solve1(vec2, vec4, cur - 1, x, 1) + solve1(vec3, vec5, cur - 1, x, 1) +
           Mint(2).powermod(vec2.size() + vec3.size()) + Mint(2).powermod(vec4.size() + vec5.size()) -
           Mint(2).powermod(vec2.size()) - Mint(2).powermod(vec3.size()) -
           Mint(2).powermod(vec4.size()) - Mint(2).powermod(vec5.size()) + 1;
}

void solve(){
    int n, x;
    std::cin >> n >> x;
    std::vector <int> vec;
    for (int i = 0; i < n; ++ i){
        int y;
        std::cin >> y;
        vec.emplace_back(y);
    }
    std::cout << solve1(vec, {}, BIT, x, 0) - 1 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    while (test --){
        solve();
    }
    return 0;
}