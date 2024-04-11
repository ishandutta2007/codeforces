#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;
const long double eps = 1e-9;
int sig(long double p){return (p > eps) - (p < -eps);}
long double sqr(long double p){return p * p;}
ll sqr(int p){return 1ll * p * p;}

struct P{
    long double x, y;

    explicit P(long double x = 0, long double y = 0):x(x), y(y){}

    P operator +(const P &p)const{return P(x + p.x, y + p.y);}
    P operator -(const P &p)const{return P(x - p.x, y - p.y);}
    P operator *(const long double &p)const{return P(x * p, y * p);}
    long double operator %(const P &p)const{ return x * p.x + y * p.y; }
    long double abs2()const{ return *this % *this; }
    P rot90()const{ return P(-y, x); }
};

int n;
int x[N], y[N];

struct C{
    P o;
    long double r;

    C(P o, long double r):o(o), r(r){}
};

std::vector <P> isCC(C c1, C c2){
    if (!sig(c1.o.x - c2.o.x) && !sig(c1.o.y - c2.o.y)){
        return {};
    }
    long double d = (c1.o - c2.o).abs2();
    long double x = ((c1.r - c2.r) / d + 1) / 2;
    long double y = std::max(c1.r / d - sqr(x), 0.0L);
    P q1 = c1.o + (c2.o - c1.o) * x;
    P q2 = ((c2.o - c1.o) * std::sqrt(y)).rot90();
    return {q1 - q2, q1 + q2};
}

void solve(){
    std::vector <ll> dis(n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &dis[i]);
    }
    std::sort(dis.begin(), dis.end());
    long double avgx = 0, avgy = 0, avgx2 = 0, avgy2 = 0, avgdis = 0;
    for (int i = 0; i < n; ++ i){
        avgx += x[i];
        avgy += y[i];
        avgx2 += sqr(x[i]);
        avgy2 += sqr(y[i]);
        avgdis += dis[i];
    }
    long double r = avgdis / n + sqr(avgx / n) + sqr(avgy / n) - avgx2 / n - avgy2 / n;
    C basic(P(avgx / n, avgy / n), r);
    std::vector <P> points;
    using pii = std::pair <int, int>;
    std::vector <pii> ans;
    for (int i = 0; i < n; ++ i){
        C circle(P(x[0], y[0]), dis[i]);
        auto ps = isCC(circle, basic);
        for (auto p : ps){
            int xx = std::round(p.x), yy = std::round(p.y);
            const int S = 20;
            for (int u = xx - S; u <= xx + S; ++ u){
                for (int v = yy - S; v <= yy + S; ++ v){
                    if (sqr(u - x[0]) + sqr(v - y[0]) == dis[i]){
                        ans.emplace_back(u, v);
                    }
                }
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    std::vector <pii> ret;
    for (auto p : ans){
        std::vector <ll> real_dis(n);
        for (int i = 0; i < n; ++ i){
            real_dis[i] = sqr(p.first - x[i]) + sqr(p.second - y[i]);
        }
        std::sort(real_dis.begin(), real_dis.end());
        if (dis == real_dis){
            ret.push_back(p);
        }
    }
    printf("%d", (int) ret.size());
    for (auto p : ret){
        printf(" %d %d", p.first, p.second);
    }
    puts("");
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}