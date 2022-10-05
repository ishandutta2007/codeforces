   //
// Created by  on 2022/2/23.
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
};

const int N = 100010;

int dp[N];
int n, m;

void calc(int l, int r, const std::vector <int> &cnt){
    if (l == r){
        return;
    }
    int mid = (l + r) / 2;
    poly p(mid - l), q(r - mid - 1);
    const int inv2 = powermod(2, moder - 2);
    for (int i = l; i <= mid; ++ i){
        p[i - l] = powermod(2, cnt[i]);
    }
    for (int i = mid + 1; i <= r; ++ i){
        q[i - mid - 1] = powermod(inv2, cnt[i]);
    }
    p = p * q;
    int len = p.len;
    for (int i = 0; i <= len; ++ i){
        int real = i + l + mid + 1 + 1;
        if (real % 2 == 0 && real <= 4 * n && real >= 2 * n + 2){
            int &u = dp[real / 2 - n];
            u += p[i];
            u -= u >= moder ? moder : 0;
        }
    }
    calc(l, mid, cnt);
    calc(mid + 1, r, cnt);
}

class Solver{
public:
    void solve(){
        std::cin >> n >> m;
        std::vector <int> a(n + 1), cnt(3 * n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        for (int i = 0; i < m; ++ i){
            int x;
            std::cin >> x;
            ++ cnt[x + n];
        }
        for (int i = 1; i <= 3 * n; ++ i){
            cnt[i] += cnt[i - 1];
        }
        calc(0, 3 * n, cnt);
        int ans = 0;
        const int inv2 = powermod(2, moder - 2);
        for (int i = 1; i <= n; ++ i){
            int x = dp[i];
            int num = std::min(i + n, 3 * n + 1 - (n + i));
            x = (x - 1ll * num * powermod(inv2, m)) % moder;
            x += x < 0 ? moder : 0;
            ans = (ans + 1ll * x * a[i]) % moder;
        }
        ans = 1ll * ans * powermod(2, m) % moder;
        ans = 1ll * ans * powermod(powermod(2, m) - 1, moder - 2) % moder;
        ans += ans < 0 ? moder : 0;
        std::cout << ans << "\n";
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H