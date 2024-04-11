//
// Created by  on 2022/4/20.
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

#include<bits/stdc++.h>

typedef long long ll;
const int MAX = 20;
const int moder = 998244353;
const int root = 3;
const int invroot = (moder + 1) / root;

int w[2][1 << MAX];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void init(){
    w[0][0] = w[1][0] = 1;
    w[0][1] = powermod(root, (moder - 1) >> MAX);
    for (int i = 2; i < (1 << MAX); ++i){
        w[0][i] = 1ll * w[0][i - 1] * w[0][1] % moder;
    }
    for (int i = 1; i < (1 << MAX); ++i){
        w[1][(1 << MAX) - i] = w[0][i];
    }
}

void NTT(std::vector <int> &a, int len, int type){
    for(int i = 1, j = 0; i < len - 1; ++i){
        for(int s = len; j ^= (s >>= 1), ~j & s; )
            ;
        if(i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (int j = 0; j < len; j += i){
            auto u = a.begin() + j;
            for (int k = 0; k < i / 2; ++k){
                int t = 1ll * w[type][k << (MAX - d)] * u[k + i / 2] % moder;
                u[k + i / 2] = u[k] - t + (u[k] - t < 0 ? moder : 0);
                u[k] += t; u[k] -= u[k] >= moder ? moder : 0;
            }
        }
    }
    if (type == 0) return;
    int inv = powermod(len, moder - 2);
    for (int i = 0; i < len; ++i){
        a[i] = 1ll * a[i] * inv % moder;
    }
}

const int N = 500010;

int fac[N], inv[N], invf[N];

struct poly{
    std::vector<int> a; int len; poly() : len(-1) {}
    poly(int len) : len(len) { a.resize(len + 1); }
    poly(const poly &p, int len) : len(len) {
        a.resize(len + 1);
        for (int i = 0; i <= len; ++i)
            a[i] = i > p.len ? 0 : p.a[i];
    }
    int &operator [] (int n) { assert(n >= 0 && n <= len); return a[n]; }
    void setlen(int len) {
        a.resize(len + 1); this->len = len;
    }
    //  x ^ dis
    poly operator << (const int &dis) const {
        poly ret(len + dis);
        std::copy(a.begin(), a.begin() + len + 1, ret.a.begin() + dis);
        return ret;
    }
    //  x ^ dis
    poly operator >> (const int &dis) const {
        if (dis > len) return poly(-1);
        int retlen = len - dis;
        poly ret(retlen);
        std::copy(a.begin(), a.begin() + retlen + 1, ret.a.begin());
        return ret;
    }
    int value(int x) {
        int now = 1, ret = 0;
        for (int i = 0; i <= len; ++i) {
            ret = (ret + 1ll * a[i] * now) % moder;
            now = 1ll * now * x % moder;
        }
        return ret;
    }
    poly operator + (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ret.a[i] += p.a[i];
            ret.a[i] -= ret.a[i] >= moder ? moder : 0;
        }
        for ( ; ~ret.len && !ret.a[ret.len]; --ret.len)
            ;
        return ret;
    }

    poly operator - (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ret.a[i] -= p.a[i];
            ret.a[i] += ret.a[i] < 0 ? moder : 0;
        }
        for ( ; ~ret.len && !ret.a[ret.len]; --ret.len)
            ;
        return ret;
    }

    poly operator - () const {
        poly ret(len);
        for (int i = 0; i <= len; ++i){
            ret.a[i] = a[i] ? moder - a[i] : 0;
        }
        return ret;
    }
    poly operator * (const poly &p) const {
        if (!~len || !~p.len) return poly(-1);
        int n = len + p.len, lenret = 1;
        for ( ; lenret <= n; lenret <<= 1);
        poly ret(*this, lenret);
        std::vector<int> aux(lenret);
        std::copy(p.a.begin(), p.a.begin() + p.len + 1, aux.begin());
        NTT(ret.a, lenret, 0); NTT(aux, lenret, 0);
        for (int i = 0; i < lenret; ++i)
            ret.a[i] = 1ll * ret.a[i] * aux[i] % moder;
        NTT(ret.a, lenret, 1); ret.len = n;
        return ret;
    }
    friend poly operator * (const int &q, const poly &p){return p * q;}
    poly &operator += (const poly &p){*this = *this + p; return *this;}
    poly &operator -= (const poly &p){*this = *this - p; return *this;}
    poly &operator *= (const poly &p){*this = *this * p; return *this;}
    poly &operator *= (const int &p){*this = *this * p; return *this;}
    poly der()const{
        if (!~len) return poly();
        poly ret(len - 1);
        for (int i = 0; i < len; ++ i){
            ret[i] = 1ll * a[i + 1] * (i + 1) % moder;
        }
        return ret;
    }
    poly integral()const{
        poly ret(len + 1);
        for (int i = len + 1; i; -- i){
            ret[i] = 1ll * a[i - 1] * ::inv[i] % moder;
        }
        return ret;
    }
    //ninvlogexp
    poly inv(int n) const {
        assert(~len && a[0]);
        poly ret(0);
        ret.a[0] = powermod(a[0], moder - 2);
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
        assert(~p.len);
        if (p.len > len) return poly(-1);
        poly a(*this), b(p);
        std::reverse(a.a.begin(), a.a.begin() + a.len + 1);
        std::reverse(b.a.begin(), b.a.begin() + b.len + 1);
        poly ret(b.inv(len - p.len));
        ret *= a;
        int retlen = len - p.len;
        ret.setlen(retlen);
        std::reverse(ret.a.begin(), ret.a.begin()+retlen+1);
        return ret;
    }
    poly log(int n) const {
        assert(~len && a[0] == 1);
        poly aux(*this, n), ret = aux.der() * aux.inv(n - 1);
        ret.setlen(n - 1);
        return ret.integral();
    }
    poly exp(int n) const {
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        poly p(n), q(n / 2);
        for (int i = 0; i <= n; ++ i){
            p[i] = invf[i];
        }
        for (int i = 1; i <= n / 2; ++ i){
            q[i] = fac[n - i - 1];
        }
        p = p * q;
        std::vector <int> dp(n + 1), dp1(n + 1), ans(n + 1);
        for (int i = 2; i <= n / 2 + 1; ++ i){
            dp[i] = 1ll * fac[n - i] * invf[i - 2] % moder * p[n - i + 1] % moder;
        }
        for (int i = 2; i <= n / 2 + 1; ++ i){
            dp1[i] = (1ll * fac[n - 1] * invf[i - 1] - dp[i]) % moder;
            dp1[i] += dp1[i] < 0 ? moder : 0;
        }
        int cur = 0;
        for (int i = n / 2 + 1; i >= 2; -- i){
            ans[i] = (fac[n - 1] - 1ll * dp[i] * fac[i - 1]) % moder;
            ans[i] = (ans[i] - cur) % moder;
            ans[i] += ans[i] < 0 ? moder : 0;
            cur = (cur + 1ll * fac[i - 2] * dp1[i]) % moder;
        }
        ans[1] = fac[n - 1];
        for (int i = 2; i <= n; ++ i){
            ans[1] -= ans[i];
            ans[1] += ans[1] < 0 ? moder : 0;
        }
        for (int i = 1; i <= n; ++ i){
            std::cout << ans[i] << " \n"[i == n];
        }
    }
};

int main(){
    init();
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H