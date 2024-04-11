#include <bits/stdc++.h>

using ll = long long;
const ll N = 5010;
const ll MAX = 20;
const ll moder = 998244353;
const ll root = 3;
const ll invroot = (moder + 1) / root;

ll w[2][1 << MAX];

ll powermod(ll a, ll exp){
    ll ret = 1;
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
    for (ll i = 2; i < (1 << MAX); ++i){
        w[0][i] = 1ll * w[0][i - 1] * w[0][1] % moder;
    }
    for (ll i = 1; i < (1 << MAX); ++i){
        w[1][(1 << MAX) - i] = w[0][i];
    }
}

void NTT(std::vector <ll> &a, ll len, ll type){
    for(ll i = 1, j = 0; i < len - 1; ++i){
        for(ll s = len; j ^= (s >>= 1), ~j & s; )
            ;
        if(i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (ll i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (ll j = 0; j < len; j += i){
            auto u = a.begin() + j;
            for (ll k = 0; k < i / 2; ++k){
                ll t = 1ll * w[type][k << (MAX - d)] * u[k + i / 2] % moder;
                u[k + i / 2] = u[k] - t + (u[k] - t < 0 ? moder : 0);
                u[k] += t; u[k] -= u[k] >= moder ? moder : 0;
            }
        }
    }
    if (type == 0) return;
    ll inv = powermod(len, moder - 2);
    for (ll i = 0; i < len; ++i){
        a[i] = 1ll * a[i] * inv % moder;
    }
}

const ll UP = 4096;

ll l[N];
ll inv[N], fac[N], invf[N];
std::vector <ll> vec[UP];

int main(){
    init();
    inv[1] = 1;
    for (ll i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
    fac[0] = invf[0] = 1;
    for (ll i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
        invf[i] = 1ll * inv[i] * invf[i - 1] % moder;
    }
    ll n, K;
    scanf("%lld%lld", &n, &K);
    ll sum = 0;
    for (ll i = 0; i < n; ++ i){
        scanf("%lld", &l[i]);
        sum += l[i];
    }
    if (K == sum){
        puts("0");
        return 0;
    }
    for (ll i = 0; i < UP; ++ i){
        vec[i] = {1};
    }
    for (ll i = 0; i < n; ++ i){
        ll upper_bound = l[i] / K;
        std::vector <ll> vec1(UP), vec2(UP);
        ll q = 1ll * l[i] * inv[sum] % moder;
        ll k = 1ll * K * inv[l[i]] % moder;
        for (ll j = 0; j <= upper_bound; ++ j){
            ll x = 1ll * q * j % moder * k % moder - q;
            x %= moder;
            if (x == 0){
                vec1[j] = 0;
                continue;
            }
            x = 1ll * powermod(x, j) * invf[j] % moder;
            x += x < 0 ? moder : 0;
            vec1[j] = x;
        }
        for (ll j = 0; j <= upper_bound - 1; ++ j){
            ll x = 1ll * q * j % moder * k % moder;
            x = (x + 1ll * q * k) % moder;
            x = x - q;
            x %= moder;
            if (x == 0){
                vec2[j + 1] = 0;
                continue;
            }
            x = 1ll * powermod(x, j) * invf[j] % moder;
            x = (moder - x) % moder;
            x += x < 0 ? moder : 0;
            vec2[j + 1] = x;
        }
        NTT(vec1, UP, 0);
        NTT(vec2, UP, 0);
        for (ll j = 0; j < UP; ++ j){
            vec[j].emplace_back(0);
            ll sz = vec[j].size();
            for (ll k = sz - 2; k >= 0; -- k){
                vec[j][k + 1] = (vec[j][k + 1] + 1ll * vec[j][k] * vec2[j]) % moder;
                vec[j][k] = 1ll * vec[j][k] * vec1[j] % moder;
            }
        }
    }
    ll sz = vec[0].size();
    for (ll i = 0; i < sz; ++ i){
        std::vector <ll> tmp;
        for (ll j = 0; j < UP; ++ j){
            tmp.emplace_back(vec[j][i]);
        }
        NTT(tmp, UP, 1);
        for (ll j = 0; j < UP; ++ j){
            vec[j][i] = tmp[j];
        }
    }
    assert(vec[0][0] == 1);
    ll b = 1ll * K * inv[sum] % moder;
    ll ans = 0;
    for (ll i = 0; i < UP; ++ i){
        for (ll j = 0; j < sz; ++ j){
            if (i == 0 && j == 0){
                continue;
            }
            if (!vec[i][j]){
                continue;
            }
            ll aa = i - j;
            assert(aa >= 0);
            ll bb = (1 - 1ll * b * i) % moder;
            bb += bb < 0 ? moder : 0;
            ans = (ans + 1ll * fac[aa] * powermod(1 - bb, moder - 1 - aa - 1) % moder * vec[i][j]) % moder;
        }
    }
    ans += ans < 0 ? moder : 0;
    ans = (moder - ans) % moder;
    printf("%lld\n", ans);
    return 0;
}