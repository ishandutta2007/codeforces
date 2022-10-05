#include <bits/stdc++.h>

using ll = long long;
const int N = 500010;

struct P{
    ll x, y;

    explicit P(ll x = 0, ll y = 0):x(x), y(y){}

    ll operator %(const P &p)const{
        return x * p.x + y * p.y;
    }

    ll operator ^(const P &p)const{
        return x * p.y - y * p.x;
    }

    ll abs2()const{
        return *this % *this;
    }

    int pos()const{
        return y ? y > 0 : x > 0;
    }

    bool operator <(const P &p)const{
        int p1 = pos(), p2 = p.pos();
        if (p1 != p2){
            return p1 > p2;
        }
        return (*this ^ p) > 0;
    }
};

std::vector<double> chain[N];

int main(){
    int n, K;
    scanf("%d%d", &n, &K);
    std::vector<P> ps;
    for (int i = 0; i < n; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        if (x || y){
            ps.emplace_back(x, y);
        }
    }
    std::sort(ps.begin(), ps.end());
    int chain_cnt = 0;
    for (int i = 0, j = 0, sz = ps.size(); i < sz; i = j){
        while (j < sz && !(ps[i] < ps[j]) && !(ps[j] < ps[i])){
            ++ j;
        }
        for (int k = i; k < j; ++ k){
            chain[chain_cnt].emplace_back(std::sqrt(ps[k].abs2()));
        }
        std::sort(chain[chain_cnt].begin(), chain[chain_cnt].end());
        ++ chain_cnt;
    }
    std::vector<double> vec;
    for (int i = 0; i < chain_cnt; ++ i){
        int sz = chain[i].size();
        for (int j = sz - 1, now = 0; j >= 0 && now < K; -- j){
            ll pre = 1ll * now * (K - now);
            ++ now;
            ll cur = 1ll * now * (K - now);
            vec.emplace_back(chain[i][j] * (cur - pre));
        }
    }
    std::sort(vec.begin(), vec.end(), std::greater<double>());
    double ans = 0;
    if (K <= int(vec.size())){
        for (int i = 0; i < K; ++ i){
            ans += vec[i];
        }
    }
    double sum = 0;
    std::vector<double> chain_value(chain_cnt);
    for (int i = 0; i < chain_cnt; ++ i){
        int sz = chain[i].size();
        for (int j = sz - 1, now = 0; j >= 0; -- j){
            ++ now;
            ll cur = 1ll * now * (K - now);
            double diff = chain[i][j] - (j ? chain[i][j - 1] : 0);
            sum += diff * cur;
            chain_value[i] += diff * cur;
        }
    }
    for (int i = 0; i < chain_cnt; ++ i){
        double sum1 = sum - chain_value[i];
        int sz = chain[i].size();
        if (sz < n - K){
            continue;
        }
        int left_part = std::min(sz - (n - K), K / 2);
        for (int j = sz - 1, now = 0, cnt = 0; j >= 0; -- j){
            if (left_part <= cnt && cnt < left_part + (n - K)){
            }
            else{
                ++ now;
            }
            ++ cnt;
            ll cur = 1ll * now * (K - now);
            double diff = chain[i][j] - (j ? chain[i][j - 1] : 0);
            sum1 += diff * cur;
        }
        ans = std::max(ans, sum1);
    }
    printf("%.15f\n", ans);
    return 0;
}