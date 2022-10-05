//
// Created by  on 2022/3/20.
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
    Mod power(U exp){
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

using Mint = Mod<int, 998'244'353>;

#endif //WORKSPACE_MOD_H

//
// Created by  on 2022/1/9.
//

#ifndef WORKSPACE_PRIME_H
#define WORKSPACE_PRIME_H

namespace Prime {
    std::vector<int> min, prime;

    std::vector <int> mu, phi, cnt, power, sigma;

    void init(int n) {
        int N = n + 10;
        min.resize(N);
        mu.resize(N);
        phi.resize(N);
        cnt.resize(N);
        power.resize(N);
        sigma.resize(N);
        mu[1] = phi[1] = sigma[1] = 1;

        for (int i = 2; i < N; ++i) {
            if (!min[i]) {
                min[i] = i;
                prime.push_back(i);

                mu[i] = -1;
                phi[i] = i - 1;
                cnt[i] = 1;
                power[i] = i;
                sigma[i] = i + 1;
            }
            for (auto u : prime) {
                if (i * u >= N) {
                    break;
                }
                min[i * u] = u;
                if (i % u == 0) {
                    mu[i * u] = 0;
                    phi[i * u] = phi[i] * u;
                    cnt[i * u] = cnt[i] + 1;
                    power[i * u] = power[i] * u;
                    sigma[i * u] = sigma[i / power[i]] * power[i * u] + sigma[i];

                    break;
                }

                mu[i * u] = -mu[i];
                phi[i * u] = phi[i] * (u - 1);
                cnt[i * u] = 1;
                power[i * u] = u;
                sigma[i * u] = sigma[i] * (u + 1);
            }
        }
    }

    template <typename T>
    constexpr bool is_prime(T n){
        if (n <= 1){
            return false;
        }
        for (T i = 2; i * i <= n; ++ i){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    constexpr T primitive_root(T n){
        T x = n - 1;
        T fact[20]{};
        int cnt = 0;
        for (T i = 2; i * i <= x; ++ i){
            if (x % i == 0){
                fact[cnt ++] = i;
                while (x % i == 0){
                    x /= i;
                }
            }
        }
        if (x > 1){
            fact[cnt ++] = x;
        }
        for (T i = 1; i < n; ++ i){
            bool flag = true;
            for (int j = 0; j < cnt; ++ j){
                if (powermod(i, (n - 1) / fact[j], n) == 1){
                    flag = false;
                    break;
                }
            }
            if (flag){
                return i;
            }
        }
        return -1;
    }
}

#endif //WORKSPACE_PRIME_H

const int N = 200010;
std::vector <piiii> edge;
std::vector <int> e[N];

class Solver{
public:
    std::vector <Mint> value;
    std::vector <int> prime, cnt;

    void dfs(int u, int fa){
        for (auto ed: e[u]){
            auto [uu, vv, xx, yy] = edge[ed];
            int v, x, y;
            if (u == uu){
                v = vv;
                x = xx;
                y = yy;
            }
            else{
                v = uu;
                x = yy;
                y = xx;
            }
            if (v == fa){
                continue;
            }
            value[v] = value[u] / x * y;
            int z = y;
            while (z > 1){
                ++ cnt[Prime::min[z]];
                z /= Prime::min[z];
            }
            z = x;
            while (z > 1){
                int t = Prime::min[z];
                -- cnt[t];
                prime[t] = std::max(prime[t], -cnt[t]);
                z /= t;
            }
            dfs(v, u);
            z = x;
            while (z > 1){
                int t = Prime::min[z];
                ++ cnt[t];
                z /= t;
            }
            z = y;
            while (z > 1){
                -- cnt[Prime::min[z]];
                z /= Prime::min[z];
            }
        }
    }

    void solve(){
        int n;
        std::cin >> n;
        edge.clear();
        for (int i = 0; i <= n; ++ i){
            e[i].clear();
        }
        int sz = n + 10;
        value.resize(sz);
        prime.resize(sz);
        cnt.resize(sz);
        for (int i = 0; i < n - 1; ++ i){
            int u, v, x, y;
            std::cin >> u >> v >> x >> y;
            edge.emplace_back(u, v, x, y);
            e[u].emplace_back(i);
            e[v].emplace_back(i);
        }
        value[1] = 1;
        dfs(1, 0);
        Mint ans = 0;
        for (int i = 1; i <= n; ++ i){
            ans += value[i];
        }
        for (int i = 1; i <= n; ++ i){
            if (prime[i] > 0){
                ans *= Mint(i).power(prime[i]);
            }
        }
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    Prime::init(N);
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H