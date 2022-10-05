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

template <typename T, typename U>
Mod<T> powermod(const Mod<T> &a, const U &exp){
    assert(exp >= 0);
    Mod <T> aa = a, ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret *= aa;
        aa *= aa;
    }
    return ret;
}

template <typename U, typename T>
U& operator <<(U &ostream, Mod <T> &u){
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

//
// Created by  on 2022/1/6.
//

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
};

#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl
using ll = int64_t;
using pii = std::pair <int, int>;
const int N = 200010;

int a[N];
std::vector <int> vec[N];
pii c[N];
Mint dp[N], dp1[N], dp2[N];

void solve(){
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; ++ i){
        vec[i].clear();
    }
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++ i){
        c[i] = {a[i], -i};
    }
    std::sort(c, c + n);
    for (int i = 0; i < n; ++ i){
        a[i] = std::lower_bound(c, c + n, mp(a[i], -i)) - c;
    }
    BIT <Mint> bit(n + 5);
    for (int i = 0; i < n; ++ i){
        dp[i] = bit.query(a[i]) + 1;
        bit.add(a[i], dp[i]);
    }
    int max = -1;
    std::vector <int> maxs;
    for (int i = n - 1; i >= 0; -- i){
        if (a[i] > max){
            maxs.emplace_back(a[i]);
            max = a[i];
        }
    }
    for (int i = 0; i < n; ++ i){
        int pos = std::lower_bound(maxs.begin(), maxs.end(), a[i]) - maxs.begin();
        vec[pos].emplace_back(a[i]);
    }
    for (int i = 0; i < n; ++ i){
        dp2[i] = 0;
    }
    bit = BIT <Mint> (n + 5);
    for (int i = n - 1; i >= 0; -- i){
        dp1[i] = bit.query_up(a[i]) + 1;
        bit.add(a[i], dp1[i]);
    }
    int sz = maxs.size();
    bit = BIT <Mint> (n + 5);
    for (int i = 0; i < sz; ++ i){
        int sz1 = vec[i].size();
        for (int j = sz1 - 1; j >= 0; -- j){
            int x = vec[i][j];
            dp2[x] = bit.query_up(x) + (j == sz1 - 1 ? 1 : 0);
            bit.add(x, dp2[x]);
        }
    }
    Mint ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += dp[i] * (dp1[i] - dp2[a[i]]);
    }
    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}