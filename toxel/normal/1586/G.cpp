//
// Created by  on 2022/2/5.
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

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_BIT_H
#define WORKSPACE_BIT_H

#include <bits/stdc++.h>

template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 1), vec(sz + 1), sum(0){}

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

void solve(){
    int n;
    std::cin >> n;
    std::vector <int> b(2 * n + 1), a(2 * n + 1);
    std::vector <pii> p;
    for (int i = 0; i < n; ++ i){
        int aa, bb;
        std::cin >> aa >> bb;
        b[aa] = bb;
        a[bb] = aa;
        p.emplace_back(aa, bb);
    }
    std::vector <Mint> dp(2 * n + 1);
    BIT <Mint> bit(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++ i){
        if (a[i] == 0){
            continue;
        }
        dp[i] = bit.query(a[i] + 1, i - 1) + 1;
        bit.add(a[i], dp[i]);
    }
    int t;
    std::cin >> t;
    std::vector <pii> concern;
    for (int i = 0; i < t; ++ i){
        int id;
        std::cin >> id;
        concern.emplace_back(p[id - 1]);
    }
    std::sort(concern.begin(), concern.end(), [&](const pii &p1, const pii &p2){return p1.second > p2.second;});
    std::vector <pii> concern1;
    int max = 0;
    for (auto pair : concern){
        if (pair.first > max){
            concern1.emplace_back(pair);
            max = pair.first;
        }
    }
    int sz = concern1.size();
    bit = BIT <Mint>(2 * n + 1);
    Mint ans = 0;
    for (int i = sz - 1, cur = 2 * n; i >= 0; -- i){
        int left = i == 0 ? 1 : concern1[i - 1].first;
        while (cur >= left){
            if (b[cur] != 0){
                bit.add(b[cur], dp[b[cur]]);
            }
            -- cur;
        }
        ans += bit.query(concern1[i].second - 1) + 1;
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H