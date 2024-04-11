#include<bits/stdc++.h>

typedef std::pair <double, double> pdd;
typedef std::pair <double, pdd> pddd;

std::vector <pddd> calc(int a, int b, int c, int x, int y){
    std::vector <pddd> ret;
    if (a){
        double xx = (-1.0 * b * y - c) / a;
        ret.push_back({std::abs(xx - x), {xx, y}});
    }
    if (b){
        double yy = (-1.0 * a * x - c) / b;
        ret.push_back({std::abs(yy - y), {x, yy}});
    }
    return ret;
}

inline double sqr(double x){return x * x;}

double calc1(pdd p1, pdd p2){
    return std::sqrt(sqr(p2.first - p1.first) + sqr(p2.second - p1.second));
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int x1, y1;
    int x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    double min = 1.0 * std::abs(x1 - x2) + std::abs(y1 - y2);
    std::vector <pddd> vec1 = calc(a, b, c, x1, y1), vec2 = calc(a, b, c, x2, y2);
    for (auto u : vec1){
        for (auto v : vec2){
            min = std::min(min, u.first + v.first + calc1(u.second, v.second));
        }
    }
    printf("%.12f\n", min);
    return 0;
}