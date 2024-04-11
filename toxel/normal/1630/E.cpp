//
// Created by  on 2022/9/18.
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

using ll = long long;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;





#include <bits/stdc++.h>

using ll = long long;

template <typename T>
T inv(T a, T moder){
    T b = moder, s = 1, t = 0;
    while (b){
        T tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s; s = t; t = tmp - s * q;
    }
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

template <auto moder>
class Mod{
public:
    using T = decltype(moder);
    T a;
    static constexpr T moder_expose = moder;

    Mod():a(){}

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
    explicit operator bool()const{return a;}

    template <typename U>
    Mod power(U exp)const{
        return Mod(powermod(a, exp, moder));
    }
};

template <auto moder> Mod<moder> operator +(const Mod<moder> &u, const Mod<moder> &v){ return Mod<moder>(u) += v; }
template <auto moder, typename U> Mod<moder> operator +(const U &u, const Mod<moder> &v){ return Mod<moder>(u) += v; }
template <auto moder, typename U> Mod<moder> operator +(const Mod<moder> &u, const U &v){ return Mod<moder>(u) += v; }
template <auto moder> Mod<moder> operator -(const Mod<moder> &u, const Mod<moder> &v){ return Mod<moder>(u) -= v; }
template <auto moder, typename U> Mod<moder> operator -(const U &u, const Mod<moder> &v){ return Mod<moder>(u) -= v; }
template <auto moder, typename U> Mod<moder> operator -(const Mod<moder> &u, const U &v){ return Mod<moder>(u) -= v; }
template <auto moder> Mod<moder> operator *(const Mod<moder> &u, const Mod<moder> &v){ return Mod<moder>(u) *= v; }
template <auto moder, typename U> Mod<moder> operator *(const U &u, const Mod<moder> &v){ return Mod<moder>(u) *= v; }
template <auto moder, typename U> Mod<moder> operator *(const Mod<moder> &u, const U &v){ return Mod<moder>(u) *= v; }
template <auto moder> Mod<moder> operator /(const Mod<moder> &u, const Mod<moder> &v){ return Mod<moder>(u) /= v; }
template <auto moder, typename U> Mod<moder> operator /(const U &u, const Mod<moder> &v){ return Mod<moder>(u) /= v; }
template <auto moder, typename U> Mod<moder> operator /(const Mod<moder> &u, const U &v){ return Mod<moder>(u) /= v; }
template <auto moder> bool operator ==(const Mod<moder> &u, const Mod<moder> &v){ return u.a == v.a; }
template <auto moder, typename U> bool operator ==(const U &u, const Mod<moder> &v){ return Mod<moder>(u).a == v.a; }
template <auto moder, typename U> bool operator ==(const Mod<moder> &u, const U &v){ return u.a == Mod<moder>(v).a; }
template <auto moder> bool operator !=(const Mod<moder> &u, const Mod<moder> &v){ return u.a != v.a; }
template <auto moder, typename U> bool operator !=(const U &u, const Mod<moder> &v){ return Mod<moder>(u).a != v.a; }
template <auto moder, typename U> bool operator !=(const Mod<moder> &u, const U &v){ return u.a != Mod<moder>(v).a; }

template <typename U, auto moder>
U& operator <<(U &ostream, const Mod <moder> &u){
    return ostream << u.a;
}

template <typename U, auto moder>
U& operator >>(U &istream, Mod <moder> &u){
    typename Mod <moder>::T x;
    istream >> x;
    u = x;
    return istream;
}


template <auto moder>
class Comb{
public:
    using Mint = Mod <moder>;
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


const int moder = 998'244'353;
using Mint = Mod<moder>;

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> cnt(n + 1);
        for (int i = 0; i < n; ++ i){
            int a;
            std::cin >> a;
            ++ cnt[a];
        }
        std::vector <int> cnts;
        for (int i = 0; i <= n; ++ i){
            if (cnt[i] > 0){
                cnts.emplace_back(cnt[i]);
            }
        }
        if (cnts.size() == 1){
            std::cout << "1\n";
            return;
        }
        int gcd = 0;
        for (auto u : cnts){
            gcd = std::gcd(gcd, u);
        }
        Comb <moder> comb(n + 1);
        std::vector <Mint> ans0(n + 1), ans1(n + 1);
        for (int i = 1; i <= n; ++ i){
            if (n % i != 0){
                continue;
            }
            if (gcd % (n / i) != 0){
                continue;
            }
            std::vector <int> cnt1 = cnts;
            for (auto &u : cnt1){
                u /= n / i;
            }
            Mint x = comb.fac[i];
            for (auto u : cnt1){
                x *= comb.invf[u];
            }
            ans0[i] += x;
            assert(i >= 2);
            x = comb.fac[i - 2];
            for (auto u : cnt1){
                x *= comb.invf[u];
            }
            Mint sum2 = 0, sum1 = 0;
            for (auto u : cnt1){
                sum1 += u;
                sum2 += Mint(u) * u;
            }
            ans1[i] += x * (sum1 * sum1 - sum2) * n;
        }
        Mint e0 = 0, e1 = 0;
        for (int i = 1; i <= n; ++ i){
            int x = std::gcd(i, n);
            e0 += ans0[x];
            e1 += ans1[x];
        }
        std::cout << e1 / e0 << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H