#include <bits/stdc++.h>

const int N = 100010;
const double eps = 1e-9;
inline double sqr(double x){return x * x;}

inline int sig(double p){return (p > eps) - (p < -eps);}

struct P{
    double x, y;

    explicit P(double x = 0, double y = 0):x(x), y(y){}

    P operator +(const P &p)const{return P(x + p.x, y + p.y);}

    P operator -(const P &p)const{return P(x - p.x, y - p.y);}

    P operator *(const double &p)const{return P(x * p, y * p);}

    double operator ^(const P &p)const{return x * p.y - y * p.x;}

    bool operator <(const P &p)const{
        int s = sig(x - p.x);
        if (s){
            return s < 0;
        }
        return sig(y - p.y) < 0;
    }

    void read(){
        scanf("%lf%lf", &x, &y);
    }
};

P cross(P p1, P p2, double y){
    double k = (p2.x - p1.x) / (p2.y - p1.y);
    double b = p1.x - p1.y * k;
    return P(k * y + b, y);
}

struct Event{
    double a, b, c, t;

    bool operator <(const Event &e)const{
        return t < e.t;
    }
};

std::vector<Event> event;
int id[N], q[N];
double ans[N];

void insert_tria(double x1, double x2, double h, int coe){
    if (sig(x2 - x1) <= 0){
        return;
    }
    double area = h * (x2 - x1) * 0.5;
    double coe1 = area / sqr(x2 - x1);
    double a = 1, b = -2 * x2, c = sqr(x2);
    a *= coe1, b *= coe1, c *= coe1;
    a = -a, b = -b, c = area - c;
    event.push_back({a * coe, b * coe, c * coe, x1});
    event.push_back({-a * coe, -b * coe, (area - c) * coe, x2});
}

void insert_rect(double x1, double x2, double h, int coe){
    if (sig(x2 - x1) <= 0){
        return;
    }
    double area = h * (x2 - x1);
    double b = h, c = -x1 * h;
    event.push_back({0, b * coe, c * coe, x1});
    event.push_back({0, -b * coe, (area - c) * coe, x2});
}

void insert(P p1, P p2, P p3, P p4, int coe){
    double h = p3.y - p1.y;
    double x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
    if (x1 > x3){
        std::swap(x1, x3);
        std::swap(x2, x4);
    }
    if (x2 > x4){
        std::swap(x2, x4);
    }
    insert_tria(x1, x3, h, -coe);
    insert_rect(x1, x2, h, coe);
    insert_tria(x2, x4, h, coe);
}

int main(){
    int n, test;
    scanf("%d%d", &n, &test);
    std::vector<P> ps(n);
    for (int i = 0; i < n; ++ i){
        ps[i].read();
    }
    auto pos = std::min_element(ps.begin(), ps.end(), [&](const P &p1, const P &p2){return p1.y < p2.y;});
    std::rotate(ps.begin(), pos, ps.end());
    if (((ps[1] - ps[0]) ^ (ps[n - 1] - ps[0])) > 0){
        std::reverse(ps.begin() + 1, ps.end());
    }
    int top = std::max_element(ps.begin(), ps.end(), [&](const P &p1, const P &p2){return p1.y < p2.y;}) - ps.begin();
    for (int i = 0; i < n; ++ i){
        ps.emplace_back(ps[i]);
    }
    P p1 = ps[0], p2 = ps[0];
    for (int i = 0, j = n; i < top || j > top; ){
        int s = sig(ps[i + 1].y - ps[j - 1].y);
        P p3, p4;
        if (s == -1){
            p3 = ps[i + 1], p4 = cross(p2, ps[j - 1], ps[i + 1].y);
            ++ i;
        }
        else if (s == 0){
            p3 = ps[i + 1], p4 = ps[j - 1];
            ++ i, -- j;
        }
        else{
            p3 = cross(p1, ps[i + 1], ps[j - 1].y), p4 = ps[j - 1];
            -- j;
        }
        P p5 = (p1 + p2) * 0.5;
        P p6 = (p3 + p4) * 0.5;
        insert(p1, p5, p3, p6, -1);
        insert(p5, p2, p6, p4, 1);
        p1 = p3, p2 = p4;
    }
    std::sort(event.begin(), event.end());
    for (int i = 0; i < test; ++ i){
        scanf("%d", &q[i]);
        id[i] = i;
    }
    std::sort(id, id + test, [&](const int &p1, const int &p2){return q[p1] < q[p2];});
    std::sort(q, q + test);
    double total = 0;
    for (int i = 1; i < n - 1; ++ i){
        total += (ps[i] - ps[0]) ^ (ps[i + 1] - ps[0]);
    }
    total = std::abs(total) * 0.5;
    int sz = event.size();
    double a = 0, b = 0, c = 0;
    for (int i = 0, j = 0; i < test; ++ i){
        while (j < sz && event[j].t <= q[i]){
            a += event[j].a;
            b += event[j].b;
            c += event[j].c;
            ++ j;
        }
        ans[id[i]] = total + (a * sqr(q[i]) + b * q[i] + c);
    }
    for (int i = 0; i < test; ++ i){
        printf("%.15f\n", ans[i]);
    }
    return 0;
}