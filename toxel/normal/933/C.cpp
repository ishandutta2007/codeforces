#include<bits/stdc++.h>

const double eps = 1e-9;
const double PI = acos(-1.0);
const double INF = 1e100;

inline int sig(double p){
	return (p > eps) - (p < -eps);
}

inline double sqr(double p){return p * p;}

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
	double angle()const{return std::atan2(y, x);}
	
	//  rad  
	P rot(const double &rad)const{
		double sin = std::sin(rad), cos = std::cos(rad);
		return P (x * cos - y * sin, x * sin + y * cos);
	}
	
	P rot90()const{
		return P (-y, x);
	}
	
	bool operator < (const P &p)const{
		if (sig(x - p.x)) return x < p.x;
		return y < p.y;
	}
	
	bool operator == (const P &p)const{
		return !sig(x - p.x) && !sig(y - p.y);
	}
	
	void read(){
		scanf("%lf%lf", &x, &y);
	}
	
	void write(){
		printf("%.10lf %.10lf\n", x, y);
	}
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

class C{
public:
	P o;
	double r;
	
	C (){}
	C (P o, double r):o(o), r(r){}
	
	P point(double angle){
		return P (o + P (std::cos(angle), std::sin(angle)) * r);
	}
};

double rad(P p1, P p2){
	return std::acos((p1 % p2) / (p1.abs() * p2.abs()));
}

// :-1:0:1:2:3:4 
std::pair <int, std::vector <P>> isCC(C c1, C c2){
	double d = (c1.o - c2.o).abs2();
	if (!sig(d)){
		if (!sig(c1.r - c2.r)){
			return {-1, {}};
		}
		return {0, {}};
	}
	if (sig(c1.r + c2.r - std::sqrt(d)) < 0) return {4, {}};
	if (sig(std::abs(c1.r - c2.r) - std::sqrt(d)) > 0) return {0, {}};
	double x = ((sqr(c1.r) - sqr(c2.r)) / d + 1) / 2;
	double y = std::max(sqr(c1.r) / d - sqr(x), 0.0);
	P q1 = c1.o + (c2.o - c1.o) * x;
	P q2 = ((c2.o - c1.o) * std::sqrt(y)).rot90(); 
	if (!sig(y)){
		return {!sig(c1.r + c2.r - std::sqrt(d)) ? 3 : 1, {q1}};
	}
	return {2, {q1 - q2, q1 + q2}};
}

int main(){
	int n;
	scanf("%d", &n);
	if (n == 1){
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		puts("2");
		return 0;
	}
	if (n == 2){
		int x1, y1, r1;
		int x2, y2, r2;
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		int dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int dis1 = (r1 + r2) * (r1 + r2);
		int dis2 = (r1 - r2) * (r1 - r2);
		puts(dis2 < dis && dis < dis1 ? "4" : "3");
		return 0;
	}
	C c[3];
	for (int i = 0; i < 3; ++ i){
		c[i].o.read();
		scanf("%lf", &c[i].r);
	}
	std::vector <double> angle[3];
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < 3; ++ i){
		for (int j = 0; j < 3; ++ j){
			if (i == j) continue;
			std::vector <P> vec = isCC(c[i], c[j]).second;
			for (auto u : vec){
				angle[i].push_back((u - c[i].o).angle());
			}
		}
		std::sort(angle[i].begin(), angle[i].end());
		angle[i].erase(std::unique(angle[i].begin(), angle[i].end(),
					[](const double &p1, const double &p2){return !sig(p1 - p2);}), 
					angle[i].end());
		if (!angle[i].size()){
			++ cnt;
		}
		ans += angle[i].size();
	}
	if (cnt == 1){
		++ ans;
	}
	else if (cnt == 3){
		ans += 2;
	}
	std::vector <P> ps;
	for (int i = 0; i < 3; ++ i){
		for (auto u : angle[i]){
			ps.push_back(c[i].point(u));
		}
	}
	std::sort(ps.begin(), ps.end());
	ps.erase(std::unique(ps.begin(), ps.end()), ps.end());
	ans -= ps.size();
	ans += 2;
	printf("%d\n", ans);
	return 0;
}