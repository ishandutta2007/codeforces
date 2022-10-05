#include <bits/stdc++.h>

using ll = long long;

struct Frac{
    ll x, y;

    Frac(ll x = 0, ll y = 1):x(x), y(y){}

    bool operator <(const Frac &f)const{
        return x * f.y < y * f.x;
    }
};

void update(Frac &diff, Frac diff1, int &cur, int x){
    if (diff1 < diff){
        diff = diff1;
        cur = x;
    }
    else if (!(diff < diff1)){
        cur = std::min(cur, x);
    }
}

void solve(){
    int h, c, t;
    scanf("%d%d%d", &h, &c, &t);
    if (t == h){
        puts("1");
        return;
    }
    if (2 * t <= h + c){
        puts("2");
        return;
    }
    int x1 = (t - c) / (2 * t - h - c), x2 = x1 + 1;
    int ans = INT_MAX;
    Frac diff(1, 0);
    if (x1 > 0){
        ll x = 1ll * x1 * h + 1ll * (x1 - 1) * c, y = 2 * x1 - 1;
        x -= y * t;
        update(diff, Frac(std::abs(x), y), ans, y);
    }
    if (x2 > 0){
        ll x = 1ll * x2 * h + 1ll * (x2 - 1) * c, y = 2 * x2 - 1;
        x -= y * t;
        update(diff, Frac(std::abs(x), y), ans, y);
    }
    update(diff, Frac(std::abs(h + c - 2 * t), 2), ans, 2);
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}