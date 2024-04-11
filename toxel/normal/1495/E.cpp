#include <bits/stdc++.h>

const int moder = int(1e9) + 7;
const int N = 5000010;
using ll = long long;

int p[N], k[N], b[N], w[N];
int a[N], t[N], aa[N];
int seed = 0;
int base = 0;

int rnd(){
    int ret = seed;
    seed = (1ll * seed * base + 233) % moder;
    return ret;
}

void gen(int m){
    p[0] = 0;
    for (int i = 1; i <= m; ++ i){
        seed = b[i];
        base = w[i];
        for (int j = p[i - 1] + 1; j <= p[i]; ++ j){
            t[j] = (rnd() % 2) + 1;
            a[j] = (rnd() % k[i]) + 1;
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i){
        scanf("%d%d%d%d", &p[i], &k[i], &b[i], &w[i]);
    }
    gen(m);
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++ i){
        aa[i] = a[i];
        if (t[i] == 1){
            sum1 += a[i];
        }
        else{
            sum2 += a[i];
        }
    }
    if (sum1 != sum2){
        int big_type = sum1 > sum2 ? 1 : 2;
        ll cur = 0;
        if (t[1] == big_type){
            -- a[1];
        }
        for (int _ = 0; _ < 5; ++ _){
            for (int i = 1; i <= n; ++ i){
                if (t[i] == big_type){
                    int x = std::min(cur, ll(a[i]));
                    cur -= x;
                    a[i] -= x;
                }
                else{
                    cur += a[i];
                    a[i] = 0;
                }
            }
        }
    }
    else{
        for (int i = 1; i <= n; ++ i){
            a[i] = 0;
        }
    }
    int ret = 1;
    for (int i = 1; i <= n; ++ i){
        ll x = (1ll * i * i) ^ (aa[i] - a[i]);
        x = (x + 1) % moder;
        ret = x * ret % moder;
    }
    printf("%d\n", ret);
    return 0;
}