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

	bool operator < (const P &p)const{
		if (sig(x - p.x)) return x < p.x;
		return y < p.y;
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

double isLL(L l1, L l2){
	P u = l2.p - l1.p;
	return (u ^ l2.v) / (l1.v ^ l2.v); //  p1v1 
}

double onLeft(L l, P p){
	return l.v ^ (p - l.p);
}

std::vector <P> convexHull(std::vector <P> &ps){
	const int N = 100010; //  
	static P stack[N];
	std::sort(ps.begin(), ps.end());
	int n = ps.size(), top = 0;
	for (int i = 0; i < n; ++ i){
		while (top > 1 && sig(onLeft(L (stack[top - 2], stack[top - 1]), ps[i])) <= 0){
			-- top;
		}
		stack[top ++] = ps[i];
	}
	int tmp = top;
	for (int i = n - 2; i >= 0; -- i){
		while (top > tmp && sig(onLeft(L (stack[top - 2], stack[top - 1]), ps[i])) <= 0){
			-- top;
		}
		stack[top ++] = ps[i];
	}
	if (n > 1) -- top;
	std::vector <P> ret;
	for (int i = 0; i < top; ++ i){
		ret.push_back(stack[i]);
	}
	return ret;
}

std::vector <P> isConL(std::vector <P> &ps, P p, P q){//
	std::vector <double> arc;
	int n = ps.size();
	for (int i = 0; i < n; ++ i){
		ps.push_back(ps[i]);
	}
	ps.push_back(ps[0]);
	for (int i = 0; i < n; ++ i){
		arc.push_back(L (ps[i], ps[i + 1]).angle);
		if (i && arc[i] < arc[i - 1]){
			arc[i] += 2 * PI;
		}
	}
	auto getseg = [&ps](L l, int left, int right){
		-- left;
		while (left < right){
			int mid = left + right + 1 >> 1;
			if (sig(l.v ^ (ps[mid] - l.p)) < 0){
				left = mid;
			}
			else{
				right = mid - 1;
			}
		}
		return left;
	};
	if (q < p) std::swap(p, q);
	L l1(p, q), l2(q, p);
	double al = l1.angle;
	if (al < arc[0]) al += 2 * PI;
	int left = (std::lower_bound(arc.begin(), arc.end(), al) - arc.begin()) % n;
	double ar = l2.angle;
    if (ar < arc[0]) ar += 2 * PI;
	int right = std::lower_bound(arc.begin(), arc.end(), ar) - arc.begin();
	int down = getseg(l1, left, right);
	int up = getseg(l2, right, left + n);
	std::vector <P> ret;
	if (down >= left && up >= right){
		double t = isLL(l1, L (ps[down], ps[down + 1]));
		ret.push_back(l1.point(t));
		t = isLL(l2, L (ps[up], ps[up + 1]));
		ret.push_back(l2.point(t));
	}
	ps.erase(ps.begin() + n, ps.end());
	return ret;
}

int main(){
    int n, p, q;
    scanf("%d%d%d", &n, &p, &q);
    std::vector <P> vec;
    int maxx = 0, maxy = 0;
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        vec.push_back(P(x, y));
        maxx = std::max(maxx, x);
        maxy = std::max(maxy, y);
    }
    vec.push_back(P(maxx, 0));
    vec.push_back(P(0, maxy));
    vec = convexHull(vec);
    vec = isConL(vec, P(0, 0), P(p, q));
    double ans = std::min(p / vec[0].x, p / vec[1].x);
    printf("%.10lf\n", ans);
    return 0;
}