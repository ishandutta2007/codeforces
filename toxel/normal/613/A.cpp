#include<bits/stdc++.h>

typedef long long ll;
inline ll sqr(int n){return 1ll * n * n;}
inline double sqr(double d){return d * d;}

struct P{
    int x, y;

    P(int x, int y):x(x), y(y){}
    
    P operator - (const P &p)const{
        return P(x - p.x, y - p.y);
    }

    ll operator ^ (const P &p)const{
        return 1ll * x * p.y - 1ll * y * p.x;
    }

    ll operator % (const P &p)const{
        return 1ll * x * p.x + 1ll * y * p.y;
    }
};

double disSP(P p1, P p2, P q){
    P v1 = p2 - p1, v2 = q - p1, v3 = q - p2;
    if (v1 % v2 < 0) return sqr(v2.x) + sqr(v2.y);
    if (v1 % v3 > 0) return sqr(v3.x) + sqr(v3.y);
    return sqr(std::abs(v1 ^ v2) * 1.0) / (sqr(v1.x) + sqr(v1.y));
}

const int N = 100010;

int px[N], py[N];

int main(){
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    double max = 0, min = 1e100;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &px[i], &py[i]);
        ll dis = sqr(x - px[i]) + sqr(y - py[i]);
        max = std::max(max, 1.0 * dis);
        min = std::min(min, 1.0 * dis);
    }
    for (int i = 0; i < n; ++ i){
        min = std::min(min, disSP(P(px[i], py[i]), P(px[(i + 1) % n], py[(i + 1) % n]), P(x, y)));
    }
    printf("%.10lf\n", (max - min) * std::acos(-1));
    return 0;
}