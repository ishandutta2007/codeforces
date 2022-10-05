//
// Created by  on 2022/3/2.
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
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_HASH_H
#define WORKSPACE_HASH_H

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

// using Mint = Mod<int, UNDEFINED>;

#endif //WORKSPACE_MOD_H

using pii = std::pair <int, int>;
const int N = 300010;
const int BIT = 20;

int fa[N][BIT];
char value[N];

template <int MODER, int BASE>
class Hash{
public:
    using Mint = Mod <int, MODER>;
    std::vector <Mint> power;
    std::vector <std::array <Mint, BIT>> hash;

    explicit Hash(){
        const int power_size = 1 << BIT;
        power.resize(power_size);
        hash.resize(power_size);
        power[0] = 1;
        for (int i = 1; i < power_size; ++ i){
            power[i] = power[i - 1] * BASE;
        }
    }

    void update(int u, int ch){
        hash[u][0] = ch;
        for (int i = 1; i < BIT; ++ i){
            hash[u][i] = hash[u][i - 1] * power[1 << (i - 1)] + hash[fa[u][i - 1]][i - 1];
        }
    }
};

template <typename... T>
class Hasher: public T...{
public:
    explicit Hasher():T()...{}

    bool equal(int u, int v, int bit)const{
        return (... && (T::hash[u][bit] == T::hash[v][bit]));
    }

    bool compare(int u, int v){
        for (int i = BIT - 1; i >= 0; -- i){
            if (equal(u, v, i)){
                u = fa[u][i], v = fa[v][i];
            }
        }
        return value[u] < value[v];
    }

    void update(int u, int pa, char ch){
        fa[u][0] = pa;
        for (int i = 1; i < BIT; ++ i){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        value[u] = ch;
        (... , T::update(u, ch == '(' ? 1 : 2));
    }
};

using MyHash = Hasher <
        // Hash <1001452733, 31>,
        // Hash <1001452759, 79>,
        // Hash <1001452787, 37>,
        Hash <1001452789, 53>,
        Hash <1001452871, 47>
>;
#endif //WORKSPACE_HASH_H

//
// Created by  on 2022/1/16.
//

#ifndef WORKSPACE_MONOTONICSTACK_H
#define WORKSPACE_MONOTONICSTACK_H

template <typename T, bool MAX>
class Stack{
private:
    std::vector <T> a;

    void calculate_min(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] > a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

    void calculate_max(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] < a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

public:
    std::vector <int> l, r;

    explicit Stack(const std::vector <T> &el):a(), l(), r(){
        int n = el.size();
        a = el;
        l.resize(n, -1);
        r.resize(n, n);
        for (int i = 0; i < n; ++ i){
            a[i] = el[i];
        }
        if constexpr (MAX){
            calculate_max();
        }
        else{
            calculate_min();
        }
    }
};

#endif //WORKSPACE_MONOTONICSTACK_H

class Solver{
public:
    void solve(){
        std::string s;
        std::cin >> s;
        int n = s.size();
        std::vector <int> pre(n + 1);
        for (int i = 1; i <= n; ++ i){
            pre[i] = pre[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        }
        Stack <int, false> stack(pre);
        std::map <int, std::vector <int>> map;
        for (int i = 0; i <= n; ++ i){
            map[pre[i]].emplace_back(i);
        }
        std::map <int, int> next;
        for (const auto &[u, vec]: map){
            int sz = vec.size();
            for (int i = 0; i < sz - 1; ++ i){
                if (stack.r[vec[i]] >= vec[i + 1]){
                    next[vec[i]] = vec[i + 1];
                }
            }
        }
        MyHash myHash;
        std::map <int, int> alias;
        for (int i = n; i >= 1; -- i){
            int nxt = i == n ? 0 : alias[i + 1];
            myHash.update(i, nxt, s[i - 1]);
            if (!next.count(i - 1)){
                alias[i] = i;
                continue;
            }
            int nxt1 = i;
            int nxt2 = next[i - 1] + 1;
            nxt2 = nxt2 == n + 1 ? 0 : alias[nxt2];
            if (!myHash.compare(nxt1, nxt2)){
                std::swap(nxt1, nxt2);
            }
            alias[i] = nxt1;
        }
        int start = alias[1];
        while (start != 0){
            std::cout << value[start];
            start = fa[start][0];
        }
        std::cout << '\n';
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