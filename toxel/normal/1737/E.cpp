//
// Created by  on 2022/10/8.
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

const int moder = int(1e9) + 7;
using Mint = Mod<moder>;

class Solver{
public:
    Comb <moder> comb;
    std::vector <Mint> power, ipower;

    Solver(): comb(10){}

    /*Mint calc2(int num, int j){
        if (num == 0 && j == 0){
            return 1;
        }
        if (num == 0){
            return 0;
        }
        if (j == 0){
            return power[num - 1];
        }
        Mint ans = 0;
        for (int i = j; i <= num; ++ i){
            ans += comb.comb(num - 1, i - 1) * comb.comb(i, j);
        }
        return ans;
    }

    Mint calc1(int num, int j){
        if (num == 0 && j == 0){
            return 1;
        }
        Mint coe = comb.invf[j] * comb.fac[num] * comb.invf[num - j];
        Mint sum = power[num - j] * num;
        if (num >= j + 1){
            sum -= (num - j) * power[num - j - 1];
        }
        return sum * coe;
    }

    Mint calc(int n, int decrease){
        Mint sum = 0;
        for (int j = 0; ; ++ j){
            int num = n - j * decrease;
            if (num < j){
                break;
            }
            // sum += (j & 1 ? -1 : 1) * calc1(num, j);
            sum += (j & 1 ? -1 : 1) * calc2(num, j);
        }
        return sum;
    }*/

    void solve(){
        int n;
        std::cin >> n;
        if (n == 1){
            std::cout << "1\n";
            return;
        }
        comb = Comb <moder>(n + 10);
        const Mint inv2 = Mint(1) / 2;
        power.resize(n + 1), ipower.resize(n + 1);
        power[0] = ipower[0] = 1;
        for (int i = 1; i <= n; ++ i){
            power[i] = power[i - 1] * 2;
            ipower[i] = ipower[i - 1] * inv2;
        }
        std::vector <Mint> ans(n + 1);
        std::vector <Mint> dp(n + 2), suf(n + 2);
        dp[n] = suf[n] = 1;
        for (int i = n - 1; i >= 1; -- i){
            dp[i] = suf[i + 1] - suf[std::min(n + 1, 2 * i)];
            suf[i] = suf[i + 1] + dp[i];
        }
        for (int i = 2; i <= n; ++ i){
            int up = i / 2;
            Mint coe = power[up];
            ans[i] = coe * dp[i];
        }
        Mint sum = 0;
        for (int i = 1; i <= n; ++ i){
            ans[i] *= ipower[n - 1];
            std::cout << ans[i] << "\n";
            sum += ans[i];
        }
        std::cerr << sum << '\n';
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