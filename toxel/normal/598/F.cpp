#include<bits/stdc++.h>

const double eps = 1e-9;
const double PI = acos(-1.0);

inline int sig(double p){
	return (p > eps) - (p < -eps);
}

inline double sqr(double p){return p * p;}

class P{
public:
	double x, y;
	P (double x = 0, double y = 0) : x(x), y(y){}
	P operator + (const P &p)const &{return P (x + p.x, y + p.y);}
	P operator - (const P &p)const &{return P (x - p.x, y - p.y);}
	P operator * (const double &p)const&{return P (x * p, y * p);}
	friend P operator * (const double &d, const P &p){return P (d * p.x, d * p.y);}
	P operator / (const double &p)const &{return P (x / p, y / p);}
	double operator ^ (const P &p)const &{return x * p.y - y * p.x;}
	double operator % (const P &p)const &{return x * p.x + y * p.y;}
	double abs2()const &{return *this % *this;}
	double abs()const &{return std::sqrt(abs2());}
	double angle()const &{return std::atan2(y, x);}
	
	//  rad  
	P rot(const double &rad)const &{
		double sin = std::sin(rad), cos = std::cos(rad);
		return P (x * cos - y * sin, x * sin + y * cos);
	}
	
	bool operator < (const P &p)const &{
		if (!sig(x - p.x)) return sig(y - p.y) < 0;
		return sig(x - p.x) < 0;
	}
	
	bool operator == (const P &p)const &{
		return !sig(x - p.x) && !sig(y - p.y);
	}
	
	void read(){
		scanf("%lf%lf", &x, &y);
	}
};

bool parallel(P p1, P p2){
	return !sig(p1 ^ p2);
}

double isLL(P p1, P v1, P p2, P v2){
	P u = p2 - p1;
	return (u ^ v2) / (v1 ^ v2); // t  p1v1 
}

const int N = 1010;

int n, m;
P l1, l2;
P p[N];

double calc(P a, P b){
    std::vector <std::pair<P, int>> vec;
    for (int i = 0; i < n; ++ i){
    	P p1 = p[i], p2 = p[(i + 1) % n];
    	if (parallel(b - a, p2 - p1)) continue;
    	double t = isLL(p1, p2 - p1, a, b - a);
    	if (sig(t) < 0 || sig(t - 1) > 0) continue;
    	P p = p1 + t * (p2 - p1);
        vec.push_back({p, sig((::p[i] - a) ^ (b - a)) - sig((::p[(i + 1) % n] - a) ^ (b - a))});
    }
    int sign = 0;
    double temp = 0;
    P t;
    std::sort(vec.begin(), vec.end());
    for (int i = 0, sz = vec.size(); i < sz - 1; ++ i){
        sign += vec[i].second;
        t = vec[i].first;
        if (sign){
            temp += (vec[i + 1].first - t).abs();
        }
    }
    return temp;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n; ++ i){
    	p[i].read();
    }
    while (m --){
    	P a, b;
    	a.read(), b.read();
        printf("%lf\n",calc(a, b));
    }
    return 0;
}