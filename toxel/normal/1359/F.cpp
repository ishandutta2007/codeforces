#include <bits/stdc++.h>

const int N = 25010;
const long double eps = 1e-9;
const long double e = std::exp(1);
const long double PI = std::acos(-1.0);

inline long double sig(long double x){return (x > eps) - (x < -eps);}

struct P{
    long double x, y;

    explicit P(long double x = 0, long double y = 0)noexcept:x(x), y(y){}

    P operator +(const P &p)const{return P(x + p.x, y + p.y);}
    P operator *(const long double &p)const{return P(x * p, y * p);}
    P operator /(const long double &p)const{return P(x / p, y / p);}
    long double operator %(const P &p)const{return x * p.x + y * p.y;}
    long double abs2()const{return *this % *this;}
    long double abs()const{return std::sqrt(abs2());}
    void read(){
        scanf("%Lf%Lf", &x, &y);
    }

    P rot(const long double &rad)const{
        long double sin = std::sin(rad), cos = std::cos(rad);
        return P (x * cos - y * sin, x * sin + y * cos);
    }

    bool operator <(const P &p)const{
        int a1 = sig(x - p.x), a2 = sig(y - p.y);
        if (!a1){
            return a2 < 0;
        }
        return a1 < 0;
    }
};

struct Event{
    long double x, y;
    int id;
    bool in;

    bool operator <(const Event &e)const{
        int a1 = sig(x - e.x), a2 = sig(y - e.y);
        if (a1 == 0){
            if (a2 == 0){
                return int(in) > int(e.in);
            }
            return a2 < 0;
        }
        return a1 < 0;
    }
};

int n;
P p[N], d[N], s[N], t[N];

struct Line{
    static long double x;
    int id;

    long double get_y()const{
        long double dx = t[id].x - s[id].x, dy = t[id].y - s[id].y;
        return s[id].y + dy / dx * (x - s[id].x);
    }

    bool operator <(const Line &l)const{
        long double y1 = get_y(), y2 = l.get_y();
        return sig(y1 - y2) < 0;
    }
};

long double Line::x = 0;

bool check(long double mid){
    std::vector<Event> event;
    for (int i = 0; i < n; ++ i){
        s[i] = p[i];
        s[i] = s[i].rot(std::acos(e / PI));
        t[i] = p[i] + d[i] * mid;
        t[i] = t[i].rot(std::acos(e / PI));
        if (t[i] < s[i]){
            std::swap(s[i], t[i]);
        }
        event.push_back({s[i].x, s[i].y, i, true});
        event.push_back({t[i].x, t[i].y, i, false});
    }
    std::sort(event.begin(), event.end());
    std::multiset <Line> set;
    for (auto u : event){
        if (u.in){
            Line::x = u.x;
            set.insert({u.id});
        }
        else{
            auto it = set.lower_bound({u.id});
            if (it == set.end()){
                assert(true);
            }
            Line::x = u.x;
            if (it != set.begin()){
                auto it1 = std::prev(it);
                if (!(*it1 < *it)){
                    return true;
                }
            }
            if (std::next(it) != set.end()){
                auto it1 = std::next(it);
                if (!(*it < *it1)){
                    return true;
                }
            }
            set.erase(it);
        }
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        p[i].read();
        d[i].read();
        int s;
        scanf("%d", &s);
        d[i] = d[i] / d[i].abs() * s;
    }
    if (!check(1e10)){
        puts("No show :(");
        return 0;
    }
    long double left = 0, right = 1e10;
    for (int _ = 0; _ < 150; ++ _){
        long double mid = (left + right) * 0.5;
        if (check(mid)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.15Lf\n", left);
    return 0;
}