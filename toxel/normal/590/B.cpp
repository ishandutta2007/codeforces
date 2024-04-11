#include<bits/stdc++.h>

const double eps = 1e-9;

inline int sig(double p){return (p > eps) - (p < -eps);}
inline double sqr(double p){return p * p;}

struct P{
    double x, y;

    P():x(0), y(0){}
    P(double x, double y):x(x), y(y){}

    P operator + (const P &p)const{
        return P(x + p.x, y + p.y);
    }

    P operator - (const P &p)const{
        return P(x - p.x, y - p.y);
    }

    P operator * (const double &p)const{
        return P(x * p, y * p);
    }

    P operator / (const double &p)const{
        return P(x / p, y / p);
    }

    double operator % (const P &p)const{
        return x * p.x + y * p.y;
    }

    double operator ^ (const P &p)const{
        return x * p.y - y * p.x;
    }

    double abs()const{
        return std::sqrt(sqr(x) + sqr(y));
    }

    void read(){
        scanf("%lf%lf", &x, &y);
    }

    bool operator == (const P &p)const{
        return !sig(x - p.x) && !sig(y - p.y);
    }
};

int main(){
    P s, e;
    s.read(), e.read();
    if (s == e){
        puts("0");
        return 0;
    }
    int v, t;
    scanf("%d%d", &v, &t);
    P w1, w2;
    w1.read(), w2.read();
    double left = 0, right = 1e9;
    for (int i = 0; i < 200; ++ i){
        double mid = (left + right) / 2;
        P ss = s + w1 * std::min((double) t, mid);
        ss = ss + w2 * std::max(0.0, mid - t);
        if (mid >= (ss - e).abs() / v){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.10lf\n", left);
    return 0;
}