//
// Created by  on 2022/3/6.
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
using i128 = __int128_t;
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

constexpr int moder = 998'244'353;
using Mint = Mod<int, moder>;

#endif //WORKSPACE_MOD_H

//
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_COMB_H
#define WORKSPACE_COMB_H


template <typename T, T moder>
class Comb{
public:
    using Mint = Mod <T, moder>;
    std::vector <Mint> fac, inv, invf;

    explicit Comb(int sz){
        sz += 10;
        fac.resize(sz);
        inv.resize(sz);
        invf.resize(sz);
        fac[0] = invf[0] = 1;
        for (int i = 1; i < sz; ++ i){
            fac[i] = fac[i - 1] * i;
            inv[i] = i == 1 ? Mint(1) : -(moder / i) * inv[moder % i];
            invf[i] = invf[i - 1] * inv[i];
        }
    }

    Mint comb(int n, int m){
        if (m < 0 || n < m) return 0;
        return fac[n] * invf[m] * invf[n - m];
    }
};

#endif //WORKSPACE_COMB_H

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_BIT_H
#define WORKSPACE_BIT_H


template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 10), vec(sz + 10), sum(0){}

    void add(int sit, T value){
        sum += value;
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] += value;
        }
    }

    T query(int sit){
        T ret = 0;
        for (sit += 1; sit; sit -= sit & -sit){
            ret += vec[sit];
        }
        return ret;
    }

    T query_up(int sit){
        return sum - query(sit - 1);
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};

#endif //WORKSPACE_BIT_H

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> vec1(n), vec2(m);
        for (int i = 0; i < n; ++ i){
            std::cin >> vec1[i];
        }
        for (int i = 0; i < m; ++ i){
            std::cin >> vec2[i];
        }
        const int N = 200010;
        BIT <Mint> bit(N);
        Comb <int, moder> comb(N);
        std::vector <int> cnt(N);
        for (int i = 0; i < n; ++ i){
            ++ cnt[vec1[i]];
        }
        Mint down = 1;
        for (int i = 0; i < N; ++ i){
            if (cnt[i] > 0){
                bit.add(i, cnt[i]);
                down *= comb.invf[cnt[i]];
            }
        }
        Mint ans = 0;
        bool flag = true;
        for (int i = 0; i < n && i < m; ++ i){
            ans += comb.fac[n - i - 1] * down * bit.query(vec2[i] - 1);
            if (cnt[vec2[i]] == 0){
                flag = false;
                break;
            }
            down *= cnt[vec2[i]];
            -- cnt[vec2[i]];
            bit.add(vec2[i], -1);
        }
        if (n < m && flag){
            ans += down;
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