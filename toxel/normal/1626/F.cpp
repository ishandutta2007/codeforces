//
// Created by  on 2022/1/16.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

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

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 800010;
const int M = 200;

Mint prob[M];
Mint cnt[N], sum[N];

void solve(){
    int n, a0, x, y, k, M;
    std::cin >> n >> a0 >> x >> y >> k >> M;
    int lcm = 1;
    std::vector <int> a(n);
    a[0] = a0;
    for (int i = 1; i < n; ++ i){
        a[i] = (1ll * a[i - 1] * x + y) % M;
    }
    for (int i = 1; i <= 16; ++ i){
        lcm = std::lcm(i, lcm);
    }
    for (int i = 0; i < n; ++ i){
        int x = a[i] % lcm;
        ++ cnt[x];
        sum[x] += a[i];
    }
    Mint ans = 0;
    Mint invn = Mint(1) / n;
    Mint coe = invn * (n - 1);
    for (int i = 0; i < lcm; ++ i){
        Mint e1;
        ll e0 = 0;
        int max = 0;
        prob[0] = 1;
        for (int j = 1; j <= k; ++ j){
            assert(i - max >= 0);
            for (int u = max; u >= 0; -- u){
                Mint x = prob[u] * invn;
                e0 -= 1ll * u * x.a;
                e1 += x;
                if ((i - u) % j == 0){
                }
                else{
                    int nu = u + (i - u) % j;
                    max = std::max(max, nu);
                    prob[nu] += x;
                    prob[u] *= coe;
                }
            }
        }
        memset(prob, 0, sizeof(prob[0]) * (max + 1));
        ans += Mint(e0) * cnt[i] + e1 * sum[i];
    }
    ans *= Mint(n).powermod(k);
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