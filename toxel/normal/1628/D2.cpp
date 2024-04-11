//
// Created by  on 2022/1/22.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

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
    const static T moder = int(1e9) + 7;
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


class Comb{
public:
    std::vector <Mint> fac, inv, invf;

    Comb(int sz){
        sz += 10;
        fac.resize(sz);
        inv.resize(sz);
        invf.resize(sz);
        fac[0] = invf[0] = 1;
        const int moder = Mint::moder;
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

const int N = 2'000'100;
Mint ipower[N];

void solve(){
    int n, m, k;
    std::cin >> n >> m >> k;
    n = n - m;
    std::swap(n, m);
    Mint ans;
    if (m == 0){
        ans = Mint(n) * k;
    }
    else{
        ans = 0;
        Comb comb(n + m);
        for (int i = 1; i <= n; ++ i){
            ans += Mint(i) * comb.comb(n - i + m - 1, m - 1) * ipower[n + m - i];
        }
        ans *= k;
    }
    std::cout << ans << '\n';
}

/*const int N = 2010;

Mint dp[N][N];

void solve(){
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= n; ++ j){
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= n; ++ j){
            if (i == 0){
                dp[i][j] = 0;
            }
            else if (j == 0){
                dp[i][j] = i;
            }
            else{
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) / 2;
            }
        }
    }
    std::cout << dp[m][n - m] * k << '\n';
}*/

int main(){
    ipower[0] = 1;
    ipower[1] = Mint(1) / 2;
    for (int i = 2; i < N; ++ i){
        ipower[i] = ipower[i - 1] * ipower[1];
    }
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}
/*#include <bits/stdc++.h>

const int N = 100;

double dp[N][N];

int main(){
    int n = 10;
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= n; ++ j){
            if (j == 0){
                dp[i][j] = 1;
            }
            else if (i == 0){
                dp[i][j] = 2 * dp[i][j - 1];
            }
            else{
                double k = (dp[i - 1][j] - dp[i][j - 1]) / (dp[i - 1][j] + dp[i][j - 1]);
                dp[i][j] = (1 - k) * dp[i - 1][j];
            }
        }
    }
}
*/