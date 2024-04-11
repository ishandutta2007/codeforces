//
// Created by  on 2022/9/30.
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

#include <bits/stdc++.h>

template <typename T>
constexpr int ctz(T n){
    if (n == 0){
        return -1;
    }
    int ans = 0;
    while (n % 2 == 0){
        n /= 2;
        ++ ans;
    }
    return ans;
}

template <typename T>
constexpr int power_upperbound(T n){
    int ret = 1;
    while (ret <= n){
        ret *= 2;
    }
    return ret;
}

template <typename T>
constexpr int power_lowerbound(T n){
    int ret = 1;
    while (ret < n){
        ret *= 2;
    }
    return ret;
}

template <auto moder>
class NTT_Wrapper{
    static_assert(Prime::is_prime(moder) && moder != 2);

public:
    using Mint = Mod <moder>;
    using T = typename Mint::T;

    constexpr static int TZ = ctz(moder - 1);
    constexpr static T root = Prime::primitive_root(moder);
    constexpr static T invroot = powermod(root, moder - 2, moder);

    inline static std::vector <Mint> w[2];
    inline static int log_len_w = 0;

    NTT_Wrapper()=default;

    void resize_w(){
        const int BASE_LEN = 7;
        if (log_len_w == 0){
            log_len_w = BASE_LEN;
            for (int i = 0; i < 2; ++ i){
                w[i].resize(1 << BASE_LEN);
            }
            w[0][0] = w[1][0] = 1;
            w[0][1] = Mint(root).power((moder - 1) >> BASE_LEN);
            for (int i = 2; i < (1 << BASE_LEN); ++i){
                w[0][i] = w[0][i - 1] * w[0][1];
            }
            for (int i = 1; i < (1 << BASE_LEN); ++i){
                w[1][(1 << BASE_LEN) - i] = w[0][i];
            }
            return;
        }
        ++ log_len_w;
        for (int i = 0; i < 2; ++ i){
            w[i].resize(2 * w[i].size());
            for (int j = int(w[i].size()) - 2; j >= 2; j -= 2){
                w[i][j] = w[i][j / 2];
            }
            w[i][1] = Mint(i == 0 ? root : invroot).power((moder - 1) >> log_len_w);
            for (int j = 3; j < int(w[i].size()); j += 2){
                w[i][j] = w[i][j - 1] * w[i][1];
            }
        }
    }

    template <typename RandomAccessIterator, typename = std::enable_if_t<std::is_same_v<
            typename std::iterator_traits<RandomAccessIterator>::iterator_category,
            std::random_access_iterator_tag>
    >>
    void operator () (RandomAccessIterator a, int len, int type){
        assert(len <= (T{1} << TZ));
        while (int(w[0].size()) < len){
            resize_w();
        }
        for(int i = 1, j = 0; i < len - 1; ++i){
            for(int s = len; j ^= (s >>= 1), ~j & s; )
                ;
            if(i < j){
                std::swap(a[i], a[j]);
            }
        }
        for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
            const int SHIFT = log_len_w - d;
            for (int j = 0; j < len; j += i){
                auto u = a + j;
                for (int k = 0; k < i / 2; ++k){
                    Mint t = w[type][k << SHIFT] * u[k + i / 2];
                    u[k + i / 2] = u[k] - t; u[k] += t;
                }
            }
        }
        if (type == 0) return;
        Mint inv = Mint(len).power(moder - 2);
        for (int i = 0; i < len; ++i){
            a[i] *= inv;
        }
    }

    template <typename U, typename = std::enable_if_t<std::is_same_v<
            typename std::iterator_traits<typename U::iterator>::iterator_category,
            std::random_access_iterator_tag>
    >>
    void operator () (U &a, int len, int type){
        this -> operator()(a.begin(), len, type);
    }

    template <typename U>
    void operator () (U &a, int type){
        this -> operator()(a.begin(), a.size(), type);
    }
};

template <auto moder>
class poly{
public:
    using Mint = Mod <moder>;
    using T = typename Mint::T;
    constexpr static bool is_prime = Prime::is_prime(moder);
    inline static NTT_Wrapper <moder> NTT;

    std::vector <Mint> a;
    int len;

    poly() : len(-1) {}
    explicit poly(int len) : len(len) { a.resize(len + 1); }
    poly(const poly &p, int len) : len(len) {
        a.resize(len + 1);
        for (int i = 0; i <= len; ++i)
            a[i] = i > p.len ? 0 : p.a[i];
    }

    Mint &operator [] (int n) { assert(n >= 0 && n <= len); return a[n]; }

    void setlen(int len) {
        a.resize(len + 1); this->len = len;
    }

    void normalize(){
        for ( ; ~len && !a[len]; --len)
            ;
    }

    poly operator << (const int &dis) const {
        poly ret(len + dis);
        std::copy(a.begin(), a.begin() + len + 1, ret.a.begin() + dis);
        return ret;
    }

    poly operator >> (const int &dis) const {
        if (dis > len) return poly(-1);
        int retlen = len - dis;
        poly ret(retlen);
        std::copy(a.begin(), a.begin() + retlen + 1, ret.a.begin());
        return ret;
    }

    Mint value(Mint x) {
        Mint now = 1, ret = 0;
        for (int i = 0; i <= len; ++i) {
            ret += a[i] * now;
            now *= x;
        }
        return ret;
    }

    poly operator + (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ret.a[i] += p.a[i];
        }
        ret.normalize();
        return ret;
    }

    poly operator - (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ret.a[i] -= p.a[i];
        }
        ret.normalize();
        return ret;
    }

    poly operator - () const {
        poly ret(len);
        for (int i = 0; i <= len; ++i){
            ret.a[i] = -a[i];
        }
        return ret;
    }

    poly operator * (const poly &p) const {
        if (!~len || !~p.len) return poly(-1);
        int n = len + p.len, lenret = power_upperbound(n);
        poly ret(*this, lenret);
        std::vector<Mint> aux(lenret);
        std::copy(p.a.begin(), p.a.begin() + p.len + 1, aux.begin());
        NTT(ret.a, lenret, 0);
        NTT(aux, lenret, 0);
        for (int i = 0; i < lenret; ++i)
            ret.a[i] *= aux[i];
        NTT(ret.a, lenret, 1);
        ret.len = n;
        return ret;
    }

    poly power(const int &p) const {
        if (!~len) return poly(-1);
        int n = len * p, lenret = power_upperbound(n);
        poly ret(*this, lenret);
        NTT(ret.a, lenret, 0);
        for (int i = 0; i < lenret; ++i)
            ret.a[i] = ret.a[i].power(p);
        NTT(ret.a, lenret, 1);
        ret.len = n;
        return ret;
    }

    poly &operator += (const poly &p){*this = *this + p; return *this;}
    poly &operator -= (const poly &p){*this = *this - p; return *this;}
    poly &operator *= (const poly &p){*this = *this * p; return *this;}

    poly der()const{
        if (!~len) return poly();
        poly ret(len - 1);
        for (int i = 0; i < len; ++ i){
            ret[i] = a[i + 1] * (i + 1);
        }
        return ret;
    }

    poly integral()const{
        static std::vector <Mint> inv_value;
        while (int(inv_value.size() < len + 1)){
            const int BASE_SIZE = 1 << 7;
            int L;
            if (inv_value.empty()){
                inv_value.resize(BASE_SIZE);
                inv_value[1] = 1;
                L = 2;
            }
            else{
                int sz = inv_value.size();
                inv_value.resize(sz * 2);
                L = sz;
            }
            for (int i = L; i < int(inv_value.size()); ++ i){
                inv_value[i] = -(moder / i) * inv_value[moder % i];
            }
        }
        poly ret(len + 1);
        for (int i = len + 1; i; -- i){
            ret[i] = a[i - 1] * inv_value[i];
        }
        return ret;
    }

    poly inv(int n) const {
        if constexpr (!is_prime){
            assert(("Inv could only be calculated for prime moder", false));
        }
        assert(~len && bool(a[0]));
        poly ret(0);
        ret.a[0] = a[0].power(moder - 2);
        for (int noweps = 0; noweps < n; ) {
            noweps = noweps << 1 | 1;
            poly aux = poly(*this, noweps) * (ret * ret);
            aux.setlen(noweps);
            ret = ret + ret - aux;
        }
        ret.setlen(n);
        return ret;
    }

    poly operator / (const poly &p) const {
        if constexpr (!is_prime){
            assert(("Division could only be calculated for prime moder", false));
        }
        assert(~p.len);
        if (p.len > len) return poly(-1);
        poly a(*this), b(p);
        std::reverse(a.a.begin(), a.a.begin() + a.len + 1);
        std::reverse(b.a.begin(), b.a.begin() + b.len + 1);
        poly ret(b.inv(len - p.len));
        ret *= a;
        int retlen = len - p.len;
        ret.setlen(retlen);
        std::reverse(ret.a.begin(), ret.a.begin() + retlen + 1);
        return ret;
    }

    poly &operator /= (const poly &p){*this = *this / p; return *this;}
    poly operator % (const poly &p){ return *this - (*this / p) * p; }
    poly &operator %= (const poly &p){*this = *this % p; return *this;}

    poly log(int n) const {
        if constexpr (!is_prime){
            assert(("Log could only be calculated for prime moder", false));
        }
        assert(~len && a[0] == 1);
        poly aux(*this, n), ret = aux.der() * aux.inv(n - 1);
        ret.setlen(n - 1);
        return ret.integral();
    }

    poly exp(int n) const {
        if constexpr (!is_prime){
            assert(("Exp could only be calculated for prime moder", false));
        }
        assert(!~len || !a[0]);
        poly ret(0);
        ret.a[0] = 1;
        poly unit = ret;
        for (int noweps = 0; noweps < n; ){
            noweps = noweps << 1 | 1;
            ret *= unit - ret.log(noweps) + poly(*this, noweps);
            ret.setlen(noweps);
        }
        ret.setlen(n);
        return ret;
    }
};

template <auto moder>
class FFT_Helper{
public:
    using Mint = Mod <moder>;
    using Poly = poly <moder>;
    using T = typename Mint::T;

    std::vector <Poly> aux;

    void resize_aux(int n){
        int max = 1;
        while (max <= n + 10){
            max <<= 1;
        }
        aux.resize(max << 1);
    }

    void dfs(int l, int r, int id, const std::vector<Mint> &vec){
        if (l == r) {
            aux[id] = Poly(1);
            aux[id][1] = 1;
            aux[id][0] = -vec[l];
            return;
        }
        int mid = (l + r) >> 1;
        dfs(l, mid, id << 1, vec);
        dfs(mid + 1, r, id << 1 | 1, vec);
        aux[id] = aux[id << 1] * aux[id << 1 | 1];
    }

    std::vector <Mint> solve1(int l, int r, int id, Poly p) {
        if (l == r) return {p.len == -1 ? 0 : p[0]};
        int mid = (l + r) >> 1;
        std::vector <Mint> vec1 = solve1(l, mid, id << 1, p % aux[id << 1]);
        std::vector <Mint> vec2 = solve1(mid + 1, r, id << 1 | 1, p % aux[id << 1 | 1]);
        vec1.insert(vec1.end(), vec2.begin(), vec2.end());
        return vec1;
    }

    std::vector <Mint> multi_value(Poly p, std::vector<Mint> vec){
        int n = vec.size();
        resize_aux(n);
        dfs(0, n - 1, 1, vec);
        p = p % aux[1];
        return solve1(0, n - 1, 1, p);
    }

    Poly solve2(int l, int r, int id, std::vector <Mint> &vec){
        if (l == r){
            Poly p(0);
            p[0] = vec[l];
            return p;
        }
        int mid = (l + r) >> 1;
        Poly p1 = solve2(l, mid, id << 1, vec);
        Poly p2 = solve2(mid + 1, r, id << 1 | 1, vec);
        return p1 * aux[id << 1 | 1] + p2 * aux[id << 1];
    }

    Poly interpolation(const std::vector <Mint> &vecx, const std::vector <Mint> &vecy){
        int n = vecx.size() - 1;
        resize_aux(n);
        dfs(0, n, 1, vecx);
        Poly p = aux[1].der();
        std::vector <Mint> vec = multi_value(p, vecx);
        for (int i = 0; i <= n; ++ i){
            vec[i] = vecy[i] * vec[i].power(moder - 2);
        }
        return solve2(0, n, 1, vec);
    }
};

template <auto moder>
class multipoly{
public:
    using Mint = Mod <moder>;
    using T = typename Mint::T;
    inline static NTT_Wrapper <moder> NTT;
    constexpr static int MAX_SIZE = 20;

    using Arr = std::array <int, MAX_SIZE>;
    using MArr = std::array <Mint, MAX_SIZE>;
    using Raw_Poly = std::vector <MArr>;
    std::vector<Mint> a;
    std::vector<int> index;
    int dim;
    Arr len, base;
    multipoly() : dim(0), len(), base() {base[0] = 1;}
    multipoly(int dim, Arr len) : dim(dim), len(len), base(){
        base[0] = 1;
        for (int i = 1; i <= dim; ++ i){
            base[i] = base[i - 1] * len[i - 1];
        }
        a.resize(base[dim]);
        index.resize(base[dim]);
        for (int i = 0; i < base[dim]; ++ i){
            for (int j = 1; j < dim; ++ j){
                index[i] = (index[i] + i / base[j]) % dim;
            }
        }
    }
    Mint &operator [] (int n) { return a[n]; }
    static void MultiNTT(std::vector <MArr> &vec, int len, int len2, int type){
        for (int i = 0; i < len2; ++ i){
            std::vector <Mint> a(len);
            for (int j = 0; j < len; ++ j){
                a[j] = vec[j][i];
            }
            NTT(a, len, type);
            for (int j = 0; j < len; ++ j){
                vec[j][i] = a[j];
            }
        }
    }

    static void MultiNTT2D(std::vector <MArr> &vec, int len, int len2, int len2_lower_bound, int type){
        if (type == 0){
            MultiNTT(vec, len, len2, type);
            for (int i = 0; i < len; ++ i){
                NTT(vec[i], len2_lower_bound, type);
            }
        }
        else{
            for (int i = 0; i < len; ++ i){
                NTT(vec[i], len2_lower_bound, type);
            }
            MultiNTT(vec, len, len2, type);
        }
    }

    multipoly operator * (const multipoly &p) const {
        assert(dim == p.dim && len == p.len);
        if (dim == 0){
            multipoly ret(dim, len);
            ret[0] = a[0] * p.a[0];
            return ret;
        }
        int n = base[dim] * 2, lenret = power_upperbound(n);
        std::vector <MArr> b(lenret), c(lenret);
        for (int i = 0; i < base[dim]; ++ i){
            b[i][index[i]] = a[i];
            c[i][index[i]] = p.a[i];
        }
        MultiNTT(b, lenret, dim, 0); MultiNTT(c, lenret, dim, 0);
        std::vector <MArr> d(lenret);
        for (int i = 0; i < lenret; ++ i){
            for (int j = 0; j < dim; ++ j){
                for (int k = 0; k < dim; ++ k){
                    int x = j + k;
                    x -= x >= dim ? dim : 0;
                    d[i][x] += b[i][j] * c[i][k];
                }
            }
        }
        MultiNTT(d, lenret, 1);
        multipoly ret(dim, len);
        for (int i = 0; i < base[dim]; ++ i){
            ret[i] = d[i][index[i]];
        }
        return ret;
    }
};



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

const int N = 10;

Mint dp[N][N];

class Solver{
public:
    void solve(){
        /*for (int i = 0; i < N; ++ i){
            for (int j = 0; j < N; ++ j){
                dp[i][j] = 1;
                for (int k = 0; k < i; ++ k){
                    for (int u = 0; u < j; ++ u){
                        dp[i][j] += dp[k][u];
                    }
                }
            }
        }
        for (int i = 0; i < N; ++ i){
            for (int j = 0; j < N; ++ j){
                std::cout << dp[i][j] << " \n"[j == N - 1];
            }
        }
        return;
        */

        int n;
        std::cin >> n;
        std::vector <ll> s(n), pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; ++ i){
            std::cin >> s[i];
            pre[i + 1] = pre[i] + s[i];
        }
        for (int i = n - 1; i >= 0; -- i){
            suf[(n - 1 - i) + 1] = suf[n - 1 - i] + s[i];
        }
        std::map <ll, pii> map1, map2;
        for (int i = 1, j = 1; i <= n; i = j){
            while (j <= n && pre[i] == pre[j]){
                ++ j;
            }
            map1[pre[i]] = {i, j - 1};
        }
        for (int i = 1, j = 1; i <= n; i = j){
            while (j <= n && suf[i] == suf[j]){
                ++ j;
            }
            map2[suf[i]] = {i, j - 1};
        }
        std::vector <std::pair <pii, pii>> events;
        for (auto [k, v]: map1){
            auto it = map2.find(k);
            if (it != map2.end()){
                events.emplace_back(v, it -> second);
            }
        }
        Mint ans = 1;
        Comb <moder> comb(n + 10);
        bool end = false;
        for (auto [p1, p2]: events){
            auto [l1, r1] = p1;
            auto [l2, r2] = p2;
            poly <moder> poly1(r1 - l1), poly2(r2 - l2);
            for (int i = 0; i <= r1 - l1; ++ i){
                poly1[i] = comb.invf[i];
            }
            for (int i = 0; i <= r2 - l2; ++ i){
                poly2[i] = comb.invf[i];
            }
            poly1 *= poly2;
            Mint pre_ans = ans;
            for (int i = l1 + l2; i <= r1 + r2; ++ i){
                if (i > n){
                    end = true;
                    break;
                }
                ans += poly1[i - (l1 + l2)] * comb.fac[i - (l1 + l2)] * pre_ans;
            }
            if (end){
                break;
            }
        }
        std::cout << ans << '\n';
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