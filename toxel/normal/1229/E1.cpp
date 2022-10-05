//
// Created by  on 2022/3/19.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __uint128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_MOD_H
#define WORKSPACE_MOD_H

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

template<typename T, typename U>
constexpr T norm(U value, T moder){
    if (value < -moder || value >= moder){
        value %= moder;
    }
    value += value < 0 ? moder : 0;
    return value;
}

template <typename T>
constexpr T mult_mod(T a, T b, T moder){
    if constexpr (std::is_same_v<T, int>){
        a = norm(1ll * a * b, moder);
    }
    else if constexpr (std::is_same_v<T, ll>){
        ll q = ll((long double) a * b / moder);
        a = norm(a * b - q * moder, moder);
    }
    else{
        static_assert(std::is_same_v<T, int> || std::is_same_v<T, ll>, "Unsupported type");
    }
    return a;
}

template <typename T, typename U>
constexpr T powermod(T a, U exp, T moder){
    assert(exp >= 0);
    T ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret = mult_mod(ret, a, moder);
        a = mult_mod(a, a, moder);
    }
    return ret;
}

template <typename T, T moder>
class Mod{
public:
    T a;

    Mod():a(){}

    static constexpr T moder_expose = moder;

    template<typename U>
    Mod(const U &u){a = norm(u, moder);}

    Mod& operator +=(const Mod &u){ a += u.a; a -= a >= moder ? moder : 0; return *this; }
    Mod& operator -=(const Mod &u){ a -= u.a; a += a < 0 ? moder : 0; return *this; }
    Mod& operator ++(){ return *this += 1; }
    Mod& operator --(){ return *this -= 1; }
    Mod operator ++(int){ Mod result = *this; *this += 1; return result; }
    Mod operator --(int){ Mod result = *this; *this -= 1; return result; }
    Mod operator -()const{ return Mod(-a); }
    Mod& operator *=(const Mod &u){ a = mult_mod(a, u.a, moder); return *this; }
    Mod& operator /=(const Mod& u){ return *this *= inv(u.a, moder); }

    template <typename U>
    Mod powermod(U exp){
        return Mod(powermod(a, exp, moder));
    }
};

template <typename T, T moder> Mod<T, moder> operator +(const Mod<T, moder> &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) += v; }
template <typename T, T moder, typename U> Mod<T, moder> operator +(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) += v; }
template <typename T, T moder, typename U> Mod<T, moder> operator +(const Mod<T, moder> &u, const U &v){ return Mod<T, moder>(u) += v; }
template <typename T, T moder> Mod<T, moder> operator -(const Mod<T, moder> &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) -= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator -(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) -= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator -(const Mod<T, moder> &u, const U &v){ return Mod<T, moder>(u) -= v; }
template <typename T, T moder> Mod<T, moder> operator *(const Mod<T, moder> &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) *= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator *(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) *= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator *(const Mod<T, moder> &u, const U &v){ return Mod<T, moder>(u) *= v; }
template <typename T, T moder> Mod<T, moder> operator /(const Mod<T, moder> &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) /= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator /(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u) /= v; }
template <typename T, T moder, typename U> Mod<T, moder> operator /(const Mod<T, moder> &u, const U &v){ return Mod<T, moder>(u) /= v; }
template <typename T, T moder> bool operator ==(const Mod<T, moder> &u, const Mod<T, moder> &v){ return u.a == v.a; }
template <typename T, T moder, typename U> bool operator ==(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u).a == v.a; }
template <typename T, T moder, typename U> bool operator ==(const Mod<T, moder> &u, const U &v){ return u.a == Mod<T, moder>(v).a; }
template <typename T, T moder> bool operator !=(const Mod<T, moder> &u, const Mod<T, moder> &v){ return u.a != v.a; }
template <typename T, T moder, typename U> bool operator !=(const U &u, const Mod<T, moder> &v){ return Mod<T, moder>(u).a != v.a; }
template <typename T, T moder, typename U> bool operator !=(const Mod<T, moder> &u, const U &v){ return u.a != Mod<T, moder>(v).a; }

template <typename U, typename T, T moder>
U& operator <<(U &ostream, const Mod <T, moder> &u){
    return ostream << u.a;
}

template <typename U, typename T, T moder>
U& operator >>(U &istream, Mod <T, moder> &u){
    T x;
    istream >> x;
    u = x;
    return istream;
}

using Mint = Mod<int, int(1e9) + 7>;

#endif //WORKSPACE_MOD_H

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <std::vector <Mint>> prob(n);
        for (int i = 0; i < n; ++ i){
            prob[i].resize(n);
            for (int j = 0; j < n; ++ j){
                std::cin >> prob[i][j];
                prob[i][j] /= 100;
            }
        }
        std::map <i128, std::vector <i128>> trans;
        std::queue <i128> queue;
        queue.emplace(1);
        trans[1] = {};
        while (!queue.empty()){
            i128 u = queue.front();
            queue.pop();
            std::vector <i128> result(1 << n);
            for (int i = 0; i < 1 << n; ++ i){
                for (int state = 0; state < 1 << n; ++ state){
                    if (u >> state & 1){
                        int update = i & ~state;
                        for (int j = 0; j < n; ++ j){
                            if (update >> j & 1){
                                result[i] |= i128(1) << (state | 1 << j);
                            }
                        }
                    }
                }
            }
            trans[u] = result;
            for (auto v : result){
                if (v > 0 && !trans.count(v)){
                    queue.emplace(v);
                    trans[v] = {};
                }
            }
        }
        std::vector <std::map <i128, Mint>> dp(n + 1);
        dp[0][1] = 1;
        for (int i = 0; i < n; ++ i){
            std::vector <Mint> p(1 << n, 1);
            for (int j = 0; j < 1 << n; ++ j){
                for (int k = 0; k < n; ++ k){
                    if (j >> k & 1){
                        p[j] *= prob[i][k];
                    }
                    else{
                        p[j] *= 1 - prob[i][k];
                    }
                }
            }
            for (auto [state, value]: dp[i]){
                for (int j = 0; j < 1 << n; ++ j){
                    i128 n_state = trans[state][j];
                    if (n_state == 0){
                        continue;
                    }
                    dp[i + 1][n_state] += value * p[j];
                }
            }
        }
        Mint ans = 0;
        for (auto [state, value]: dp[n]){
            ans += value;
        }
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H