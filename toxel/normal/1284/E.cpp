#include <bits/stdc++.h>

const int N = 2510;
using ll = long long;

struct P{
    ll x, y;

    explicit P(ll x = 0, ll y = 0):x(x), y(y){}

    int getdir()const{
        return y != 0 ? y > 0 : x > 0;
    }

    P operator -(const P &p)const{ return P(x - p.x, y - p.y); }
    ll operator ^(const P &p)const{ return x * p.y - y * p.x; }

    bool operator <(const P &p)const{
        int dir = getdir();
        int dir1 = p.getdir();
        if (dir != dir1){
            return dir > dir1;
        }
        return (*this ^ p) > 0;
    }
};

P p[N];

ll comb2(ll n){
    return n * (n - 1) / 2;
}

ll comb3(ll n){
    return n * (n - 1) * (n - 2) / 6;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        std::vector <P> vec;
        for (int j = 0; j < n; ++ j){
            if (i == j){
                continue;
            }
            vec.push_back(p[j] - p[i]);
        }
        std::sort(vec.begin(), vec.end());
        for (int j = 0; j < n - 1; ++ j){
            vec.push_back(vec[j]);
        }
        ll num = comb3(n - 1);
        for (int j = 0, k = 0; j < n - 1; ++ j){
            while (k < j + n - 1 && (vec[j] ^ vec[k]) >= 0){
                ++ k;
            }
            num -= comb2(k - j - 1);
        }
        ans += num;
    }
    ans *= (n - 4);
    printf("%lld\n", ans / 2);
    return 0;
}