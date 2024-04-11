#include<bits/stdc++.h>

typedef long long ll;
const int N = 100010;
const int M = 100;
const ll INF = 1e15;

int w[N], phi[M];

ll update(int w, ll exp){
    if (w == 1){
        return 1;
    }
    if (exp >= 50){
        return INF;
    }
    return (ll) std::min((double) INF, pow(w, exp));
}

int getphi(int m){
    int ret = 1;
    for (int i = 2; i * i <= m; ++ i){
        if (m % i == 0){
            while (m % i == 0){
                ret *= i;
                m /= i;
            }
            ret = ret / i * (i - 1);
        }
    }
    if (m > 1){
        ret *= m - 1;
    }
    return ret;
}

int powermod(int a, int exp, int moder){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret % moder;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int mm = m;
    std::set <int> one;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &w[i]);
        if (w[i] == 1){
            one.insert(w[i]);
        }
    }
    int cnt = 0;
    phi[cnt ++] = m;
    while (m > 1){
        phi[cnt ++] = m = getphi(m);
    }
    m = mm;
    int q;
    scanf("%d", &q);
    while (q --){
        int l, r;
        scanf("%d%d", &l, &r);
        -- l, -- r;
        if (l == r){
            printf("%d\n", w[l] % m);
            continue;
        }
        auto u = one.upper_bound(std::min(l + cnt - 1, r));
        int lastone = u == one.end() ? n : *u;
        lastone = std::min(lastone, r + 1);
        if (r - l + 1 > cnt){
            r = l + cnt - 1;
        }
        ll appr = 0;
        if (lastone - r >= 10){
            appr = INF;
        }
        else{
            appr = 1;
            for (int i = lastone - 1; i > r; -- i){
                appr = update(w[i], appr);
            }
        }
        int pre = 1;
        for (int i = r; i >= l; -- i){
            int exp = appr >= phi[i + 1 - l] ? pre + phi[i + 1 - l] : pre;
            pre = powermod(w[i], exp, phi[i - l]);
            appr = update(w[i], appr);
        }
        printf("%d\n", pre % m);
    }
    return 0;
}