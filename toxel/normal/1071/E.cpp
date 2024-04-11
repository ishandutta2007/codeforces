#include<bits/stdc++.h>

const int N = 100010;
const double eps = 1e-9;
const double PI = acos(-1.0);
const double INF = 1e100;

typedef std::pair <int, int> pii;
typedef long long ll;

struct frac{
    ll x, y;

    frac operator +(const frac &f)const{
        return {x * f.y + y * f.x, y * f.y};
    }

    frac operator -(const frac &f)const{
        return {x * f.y - y * f.x, y * f.y};
    }

    frac operator *(const frac &f)const{
        return {x * f.x, y * f.y};
    }

    frac operator /(const frac &f)const{
        return {x * f.y, y * f.x};
    }

    void norm(){
        if (y < 0){
            x = -x;
            y = -y;
        }
    }

    bool operator < (const int &f)const{
        return x < y * f;
    }

    bool operator > (const int &f)const{
        return x > y * f;
    }
};

inline int sig(double x){return (x > eps) - (x < -eps);}
inline double sqr(double p){return p * p;}

double calc(double x1, double x2, double y1, double y2){
    double diff = x2 - x1;
    return x2 + diff * y2 / y1;
}

class P{
public:
    double x, y;
    explicit P (double x = 0, double y = 0): x(x), y(y){}
    P operator + (const P &p)const{return P (x + p.x, y + p.y);}
    P operator - (const P &p)const{return P (x - p.x, y - p.y);}
    P operator * (const double &p)const{return P (x * p, y * p);}
    friend P operator * (const double &d, const P &p){return P (d * p.x, d * p.y);}
    P operator / (const double &p)const{return P (x / p, y / p);}
    double operator ^ (const P &p)const{return x * p.y - y * p.x;}
    double operator % (const P &p)const{return x * p.x + y * p.y;}
    double abs2()const{return *this % *this;}
    double abs()const{return std::sqrt(abs2());}
};

class L{
public:
    P p, v;
    double angle;
    
    L (){}
    L (P a, P b):p(a), v(b - a){angle = std::atan2(v.y, v.x);}
    
    bool operator < (const L &l)const{
        return angle < l.angle;
    }
    
    P point(double t){
        return p + v * t;
    }
};

// v1  v2  
double isLL(L l1, L l2){
    P u = l2.p - l1.p;
    return (u ^ l2.v) / (l1.v ^ l2.v); //  p1v1 
}

bool para(L l1, L l2){
    return !sig(l1.v ^ l2.v);
}

// >0 q  l  
double onLeft(L l, P p){
    return l.v ^ (p - l.p);
}

bool in(P p, std::vector <P> ps){
    for (int i = 0, sz = ps.size(); i < sz; ++ i){
        if (sig(onLeft(L(ps[i], ps[(i + 1) % sz]), p)) < 0){
            return false;
        }
    }
    return true;
}

std::vector <P> isHalfPlane(std::vector <L> &ls){
    std::vector <L> tmp;
    for (auto u : ls){
        if (!sig(u.v.x) && !sig(u.v.y)){
            continue;
        }
        tmp.push_back(u);
    }
    ls = tmp;
    std::sort(ls.begin(), ls.end());
    std::deque <L> dq;
    std::deque <P> ps;
    dq.push_back(ls[0]);
    int n = ls.size();
    auto isLLP = [](L l1, L l2){return l1.point(isLL(l1, l2));};
    for (int i = 1; i < n; ++ i){
        while (!ps.empty() && sig(onLeft(ls[i], ps.back())) <= 0) ps.pop_back(), dq.pop_back();
        while (!ps.empty() && sig(onLeft(ls[i], ps.front())) <= 0) ps.pop_front(), dq.pop_front();
        L l = dq.back();
        if (sig(ls[i].v ^ l.v)){
            dq.push_back(ls[i]);
            ps.push_back(isLLP(l, ls[i]));
        }
        else{
            if (sig(onLeft(l, ls[i].p)) > 0){
                dq.pop_back();
                if (!dq.empty()){
                    ps.pop_back();
                    ps.push_back(isLLP(dq.back(), ls[i]));
                }
                dq.push_back(ls[i]);
            }
        }
    }
    while (!ps.empty() && sig(onLeft(dq.front(), ps.back())) <= 0) ps.pop_back(), dq.pop_back();
    if (dq.size() <= 2) return {};
    ps.push_back(isLLP(dq.front(), dq.back()));
    std::vector <P> ret;
    while (!ps.empty()){
        ret.push_back(ps.front());
        ps.pop_front();
    }
    return ret;
}

std::vector <pii> vec[N];
double up[N], down[N];

int main(){
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    int e1, e2;
    scanf("%d%d", &e1, &e2);
    for (int i = 0, t, x, y; i < n; ++ i){
        scanf("%d%d%d", &t, &x, &y);
        vec[t].push_back({x, y});
    }
    for (int i = 0; i < N; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
        vec[i].erase(std::unique(vec[i].begin(), vec[i].end()), vec[i].end());
        if ((int) vec[i].size() >= 2){
            if (vec[i][0].second == vec[i][1].second){
                puts("-1");
                return 0;
            }
            frac k = {vec[i][1].first - vec[i][0].first, vec[i][1].second - vec[i][0].second};
            frac b = (frac){vec[i][0].first, 1} - k * (frac){vec[i][0].second, 1};
            for (auto u : vec[i]){
                if ((k * (frac){u.second, 1} + b - (frac){u.first, 1}).x){
                    puts("-1");
                    return 0;
                }
            }
            frac f = k * (frac){h, 1} + b;
            f.norm(), b.norm();
            if (f < 0 || f > w || b < 0 || b > w){
                puts("-1");
                return 0;
            }
            up[i] = 1.0 * b.x / b.y;
            down[i] = 1.0 * f.x / f.y;
        }
    }
    double left = 0, right = 2 * w;
    for (int _ = 0; _ < 20; ++ _){
        double mid = (left + right) / 2;
        bool flag = true;
        std::vector <P> ps = {P(0, 0), P(w, 0), P(w, w), P(0, w)};
        for (int i = N - 1; i > 0; -- i){
            if (vec[i].empty()){
                continue;
            }
            double move = mid;
            for (int j = i - 1; j >= 0; -- j){
                if (!vec[j].empty() || j == 0){
                    move *= i - j;
                    break;
                }
            }
            std::vector <P> tmp;
            if (vec[i].size() >= 2){
                if (!in(P(up[i], down[i]), ps)){
                    flag = false;
                    break;
                }
                tmp.push_back(P(up[i], down[i]));
                tmp.push_back(P(up[i], down[i]));
            }
            else{
                double x = vec[i][0].first, y = vec[i][0].second;
                double l = 0, r = w;
                double ll = calc(l, x, y, h - y);
                double rr = calc(r, x, y, h - y);
                std::vector <double> vec;
                L l1(P(l, ll), P(r, rr));
                for (int i = 0, sz = ps.size(); i < sz; ++ i){
                    L l2(ps[i], ps[(i + 1) % sz]);
                    if (para(l1, l2)){
                        continue;
                    }
                    double t = isLL(l2, l1);
                    if (sig(t) < 0 || sig(t - 1) > 0){
                        continue;
                    }
                    vec.push_back(isLL(l1, l2));
                }
                std::sort(vec.begin(), vec.end());
                vec.erase(std::unique(vec.begin(), vec.end(),
                            [&](const double &q1, const double &q2){return !sig(q1 - q2);}), vec.end());
                if (vec.empty()){
                    flag = false;
                    break;
                }
                if ((int) vec.size() == 1){
                    if (0 <= vec[0] && vec[0] <= 1){
                        tmp.push_back(l1.point(vec[0]));
                        tmp.push_back(l1.point(vec[0]));
                    }
                }
                else{
                    vec[0] = std::max(vec[0], 0.0);
                    vec[1] = std::min(vec[1], 1.0);
                    if (vec[0] <= vec[1]){
                        tmp.push_back(l1.point(vec[0]));
                        tmp.push_back(l1.point(vec[1]));
                    }
                }
            }
            std::vector <L> ls;
            ls.push_back(L(tmp[1] + P(-move, -move), tmp[1] + P(move, -move)));
            ls.push_back(L(tmp[1] + P(move, -move), tmp[1] + P(move, move)));
            ls.push_back(L(tmp[0] + P(move, move), tmp[0] + P(-move, move)));
            ls.push_back(L(tmp[0] + P(-move, move), tmp[0] + P(-move, -move)));
            ls.push_back(L(tmp[1] + P(move, move), tmp[0] + P(move, move)));
            ls.push_back(L(tmp[0] + P(-move, -move), tmp[1] + P(-move, -move)));

            ls.push_back(L(P(0, 0), P(w, 0)));
            ls.push_back(L(P(w, 0), P(w, w)));
            ls.push_back(L(P(w, w), P(0, w)));
            ls.push_back(L(P(0, w), P(0, 0)));
            ps = isHalfPlane(ls);
        }
        if (!in(P(e1, e2), ps)){
            flag = false;
        }
        if (flag){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.15f\n", left);
    return 0;
}