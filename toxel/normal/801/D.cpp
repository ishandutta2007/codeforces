#include<bits/stdc++.h>

#define sqr(x) ((x) * (x))

const double INF = 1e100;
const double eps = 1e-6;
const double PI = acos(-1);

struct P{
	double x, y;
	P (){x = 0, y = 0;}
	P (double x, double y) : x(x), y(y){}
	P add(P p){return {x + p.x, y + p.y};}
	P sub(P p){return {x - p.x, y - p.y};}
	double dot(P p){return x * p.x + y * p.y;}
	double det(P p){return x * p.y - p.x * y;}
	P mul(double p){return {x * p, y * p};}
	P div(double p){return {x / p, y / p};}
	double abs(){return sqrt(sqr(x) + sqr(y));}
	double abs2(){return sqr(x) + sqr(y);}
	//90 
	P rot90(){return {-y, x};}
};

int sig(double p){
	if (std::abs(p) < eps){
		return 0;
	}
	return p > 0 ? 1 : -1;
}

double disLP(P p1, P p2, P q){
	return std::abs(p2.sub(p1).det(q.sub(p1))) / p2.sub(p1).abs();
}

double disSP(P p1, P p2, P q){
	if (p2.sub(p1).dot(q.sub(p1)) < eps){
		return q.sub(p1).abs();
	}
	if (p1.sub(p2).dot(q.sub(p2)) < eps){
		return q.sub(p2).abs();
	}
	return disLP(p1, p2, q); 
}

inline bool crsSS(P p1, P p2, P q1, P q2){
	if (std::max(p1.x, p2.x) + eps < std::min(q1.x, q2.x)){
		return false;
	}
	if (std::max(q1.x, q2.x) + eps < std::min(p1.x, p2.x)){
		return false;
	}
	if (std::max(p1.y, p2.y) + eps < std::min(q1.y, q2.y)){
		return false;
	}
	if (std::max(q1.y, q2.y) + eps < std::min(p1.y, p2.y)){
		return false;
	}
	return sig(p2.sub(p1).det(q1.sub(p1))) * sig(p2.sub(p1).det(q2.sub(p1))) < eps
			&& sig(q2.sub(q1).det(p1.sub(q1))) * sig(q2.sub(q1).det(p2.sub(q1))) < eps;
}

// p1p2q1q2 
inline bool crsLS(P p1, P p2, P q1, P q2){
	return sig(p1.sub(q1).det(p2.sub(q1))) * sig(p1.sub(q2).det(p2.sub(q2))) <= 0;
}

inline bool crsCS(P c, double r, P p1, P p2){
	return disSP(p1, p2, c) < r + eps && (r < c.sub(p1).abs() + eps || r < c.sub(p2).abs() + eps);
}

bool crsCC(P c1, double r1, P c2, double r2){
	double dis = c1.sub(c2).abs();
	return dis < r1 + r2 + eps && std::abs(r1 - r2) < dis + eps;
}

P ccenter(P p1, P p2, P p3){
	double a1 = 2 * (p2.x - p1.x), b1 = 2 * (p2.y - p1.y), c1 = sqr(p2.x) + sqr(p2.y) - sqr(p1.x) - sqr(p1.y);
	double a2 = 2 * (p3.x - p2.x), b2 = 2 * (p3.y - p2.y), c2 = sqr(p3.x) + sqr(p3.y) - sqr(p2.x) - sqr(p2.y);
	return {(c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1), (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1)};
}

bool onSeg(P p1, P p2, P q){
	if (p1.x > p2.x - eps){
		std::swap(p1, p2);
	}
	if (q.x < p1.x - eps || q.x > p2.x + eps){
		return false;
	}
	return std::abs(p2.sub(p1).det(q.sub(p1))) < eps;
}

inline bool onLine(P p1, P p2, P q){
	return std::abs(p2.sub(p1).det(q.sub(p1))) < eps;
}

bool onCir(P p1, P p2, P p3, P p4){
	if (abs(p2.sub(p1).det(p3.sub(p1))) < eps){
		return false; // or true???
	}
	P c = ccenter(p1, p2, p3);
	return std::abs(c.sub(p1).abs2() - c.sub(p4).abs()) < eps;
}

P proj(P p1, P p2, P q){
	return p1.add(p2.sub(p1).mul(p2.sub(p1).dot(q.sub(p1)) / p2.sub(p1).abs2()));
}

inline P isLL(P p1, P p2, P q1, P q2){
	double d = q2.sub(q1).det(p2.sub(p1));
	if (std::abs(d) < eps){
		return {INF, INF};
	}
	return p1.add(p2.sub(p1).mul(q2.sub(q1).det(q1.sub(p1)) / d));
}

inline std::vector <P> isCL(P c, double r, P p1, P p2){
	double x = p1.sub(c).dot(p2.sub(p1));
	double y = p2.sub(p1).abs2();
	double d = sqr(x) - y * (p1.sub(c).abs2() - sqr(r));
	if (d < -eps){
		return {};
	}
	if (d < 0){
		d = 0;
	}
	P q1 = p1.sub(p2.sub(p1).mul(x / y));
	P q2 = p2.sub(p1).mul(sqrt(d) / y);
	return {q1.sub(q2), q1.add(q2)};
}

std::vector <P> isCC(P c1, double r1, P c2, double r2){
	double x = c1.sub(c2).abs2();
	double y = ((sqr(r1) - sqr(r2)) / x + 1) / 2;
	double d = sqr(r1) / x - sqr(y);
	if (d < -eps){
		return {};
	}
	if (d < 0){
		d = 0;
	}
	P q1 = c1.add(c2.sub(c1).mul(y));
	P q2 = c2.sub(c1).mul(sqrt(d)).rot90();
	return {q1.sub(q2), q1.add(q2)};
}

std::vector <P> tanCP(P c, double r, P p){
	double x = p.sub(c).abs2();
	double d = x - sqr(r);
	if (d < -eps){
		return {};
	}
	if (d < 0){
		d = 0;
	}
	P q1 = p.sub(c).mul(sqr(r) / x);
	P q2 = p.sub(c).mul(-r * sqrt(d) / x).rot90();
	return {c.add(q1.sub(q2)), c.add(q1.add(q2))};
}

std::vector <std::pair <P, P>> tanCC(P c1, double r1, P c2, double r2){
	std::vector <std::pair <P, P>> ret;
	if (std::abs(r1 - r2) < eps){
		P dir = c2.sub(c1);
		dir = dir.mul(r1 / dir.abs()).rot90();
		ret.push_back({c1.add(dir), c2.add(dir)});
		ret.push_back({c1.sub(dir), c2.sub(dir)});
	}
	else{
		P p = c1.mul(-r2).add(c2.mul(r1)).div(r1 - r2);
		std::vector <P> ps = tanCP(c1, r1, p);
		std::vector <P> qs = tanCP(c2, r2, p);
		for (int i = 0; i < (int) ps.size() && i < (int) qs.size(); ++ i){
			ret.push_back({ps[i], qs[i]});
		}
	}
	P p = c1.mul(r2).add(c2.mul(r1)).div(r1 + r2);
	std::vector <P> ps = tanCP(c1, r1, p);
	std::vector <P> qs = tanCP(c2, r2, p);
	for (int i = 0; i < (int) ps.size() && i < (int) qs.size(); ++ i){
		ret.push_back({ps[i], qs[i]});
	}
	return ret;
}

inline double areaCC(P c1, double r1, P c2, double r2){
	double d = c1.sub(c2).abs();
	if (r1 + r2 < d + eps){
		return 0;
	}
	if (d < std::abs(r1 - r2) + eps){
		double r = std::min(r1, r2);
		return sqr(r) * PI;
	}
	double x = (sqr(d) + sqr(r1) - sqr(r2)) / (2 * d);
	double t1 = acos(x / r1);
	double t2 = acos((d - x) / r2);
	return sqr(r1) * t1 + sqr(r2) * t2 - d * r1 * sin(t1);
}

inline double rad(P p1, P p2){
	return acos(p1.dot(p2) / (p1.abs() * p2.abs()));
}

// (0, 0) 
inline double areaCT(double r, P p1, P p2){
	std::vector <P> qs = isCL({0, 0}, r, p1, p2);
	if (!(int) qs.size()){
		return sqr(r) * rad(p1, p2) / 2;
	}
	bool b1 = p1.abs() > r + eps, b2 = p2.abs() > r + eps;
	if (b1 && b2){
		if ((p1.sub(qs[0])).dot(p2.sub(qs[0])) < eps && p1.sub(qs[1]).dot(p2.sub(qs[1])) < eps){
			return (sqr(r) * (rad(p1, p2) - rad(qs[0], qs[1])) + std::abs(qs[0].det(qs[1]))) / 2;
		}
		else{
			return sqr(r) * rad(p1, p2) / 2;
		}
	}
	else if (b1){
		return (sqr(r) * rad(p1, qs[0]) + std::abs(qs[0].det(p2))) / 2;
	}
	else if (b2){
		return (sqr(r) * rad(qs[1], p2) + std::abs(p1.det(qs[1]))) / 2;
	}
	else{
		return std::abs(p1.det(p2)) / 2;
	}
}

inline double areaT(P p1, P p2, P p3){
	return std::abs(p2.sub(p1).det(p3.sub(p1))) / 2;
}

// 
//ps 
inline double areaP(std::vector <P> &ps){
	int n = ps.size();
	if (n <= 2){
		return 0;	
	}
	double ret = 0;
	for (int i = 1; i < n - 1; ++ i){
		int x = sig(ps[i].sub(ps[0]).det(ps[i + 1].sub(ps[0])));
		ret += areaT(ps[0], ps[i], ps[i + 1]) * x;
	}
	return std::abs(ret);
}

//  
struct cmp{
	P minpoint;
	
	cmp(P p) : minpoint(p){
	}
	
	bool operator()(P p1, P p2){
		
		/*--------------------------------------------------------
		// 
		if (p1.y < minpoint.y - eps && p2.y > minpoint.y + eps){
			return false;
		}
		if (p1.y > minpoint.y + eps && p2.y < minpoint.y - eps){
			return true;
		}
		--------------------------------------------------------*/
		
		double x = p1.sub(minpoint).det(p2.sub(minpoint));
		if (std::abs(x) < eps){
			return p1.y < p2.y;
		}
		return x > eps;
	}
};

inline void sortByAngle(std::vector <P> &ps){
	int n = ps.size();
	if (n <= 1){
		return;
	}
	std::pair <double, double> min = {INF, INF};
	int sit;
	for (int i = 0; i < n; ++ i){
		std::pair <double, double> pr = {ps[i].y, ps[i].x};
		if (min > pr){
			min = pr;
			sit = i;
		}
	}
	std::swap(ps[0], ps[sit]);
	auto u = ps.begin();
	std::sort(++ u, ps.end(), cmp({min.second, min.first}));
}

// psqs 
// ps

inline void convexHull(std::vector <P> &ps, std::vector <P> &qs){
	int n = ps.size(), k = 0;
	if (n <= 1){
		qs = ps;
		return;
	}
	sortByAngle(ps);
	qs.clear();
	for (int i = 0; i < n; ++ i){
		qs.push_back({0, 0});
	}
	for (int i = 0; i < n; qs[k ++] = ps[i ++]){
		if (i && !sig(ps[i].x - ps[0].x) && !sig(ps[i].y - ps[0].y)){
			continue;
		}
		while (k > 1 && qs[k - 1].sub(qs[k - 2]).det(ps[i].sub(qs[k - 1])) < eps){
			-- k;
		}
	}
	qs.erase(qs.begin() + k, qs.end());
}

void convexCut(std::vector <P> &ps, std::vector <P> &qs, P p1, P p2){
	int n = ps.size();
	qs.clear();
	for (int i  =0; i < n; ++ i){
		int d1 = sig(p2.sub(p1).det(ps[i].sub(p1)));
		int d2 = sig(p2.sub(p1).det(ps[(i + 1) % n].sub(p1)));
		if (d1 >= 0){
			qs.push_back(ps[i]);
		}
		if (d1 * d2 < 0){
			qs.push_back(isLL(p1, p2, ps[i], ps[(i + 1) % n]));
		}
	}
}

//  : 1,  : -1,  : 0
inline int contains(std::vector <P> &ps, P q){
	int n = ps.size();
	int ret = -1;
	for (int i = 0; i < n; ++ i){
		P a = ps[i].sub(q), b = ps[(i + 1) % n].sub(q);
		if (a.y > b.y){
			std::swap(a, b);
		}
		if (a.y < eps && b.y > eps && a.det(b) > eps){
			ret = -ret;
		}
		if (std::abs(a.det(b)) < eps && a.dot(b) < eps){
			return 0;
		}
	}
	return ret;
}

bool in(P p1, P p2, P q){
	return p1.det(q) > -eps && p2.det(q) < eps;
}

bool in(P p1, P p2, P p3, P p4, P q){
	P o12 = p1.sub(p2).rot90();
	P o23 = p2.sub(p3).rot90();
	P o34 = p3.sub(p4).rot90();
	return in(o12, o23, q.sub(p2)) || in(o23, o34, q.sub(p3))
			|| in(o23, p3.sub(p2), q.sub(p2)) && in(p2.sub(p3), o23, q.sub(p3));
}

//ps 
//pps 
double disConvexP(std::vector <P> &ps, P q){
	int n = ps.size();
	int left = 0, right = n;
	while (right - left > 1){
		int mid = left + right >> 1;
		if (in(ps[(left + n - 1) % n], ps[left], ps[mid], ps[(mid + 1) % n], q)){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	return disSP(ps[left], ps[right % n], q);
}

double convexDiameter(std::vector <P> &ps){
	int n = ps.size();
	int is = 0, js = 0;
	for (int i = 1; i < n; ++ i){
		if (ps[i].x > ps[is].x){
			is = i;
		}
		if (ps[i].x < ps[js].x){
			js = i;
		}
	}
	double maxd = ps[is].sub(ps[js]).abs();
	int i = is, j = js;
	do{
		if (ps[(i + 1) % n].sub(ps[i]).det(ps[(j + 1) % n].sub(ps[j])) >= 0){
			j = (j + 1) % n;
		}
		else{
			i = (i + 1) % n;
		}
		maxd = std::max(maxd, ps[i].sub(ps[j]).abs());
	}
	while (i != is || j != js);
	return maxd;
}

int rand_int(int n){
	return (rand() * rand() + rand() + 1) % n;
}

inline std::pair <P, double> minCoverC(std::vector <P> &ps){
	int n = ps.size();
	srand(time((unsigned) NULL));
	for (int i = 1; i < n; ++ i){
		int j = rand_int(i);
		std::swap(ps[i], ps[j]);
	}
	P c = ps[0];
	double r = 0;
	for (int i = 1; i < n; ++ i){
		if (ps[i].sub(c).abs() > r + eps){
			c = ps[i];
			r = 0;
			for (int j = 0; j < i; ++ j){
				if (ps[j].sub(c).abs() > r + eps){
					c = ps[i].add(ps[j]).div(2);
					r = ps[i].sub(c).abs();
					for (int k = 0; k < j; ++ k){
						if (ps[k].sub(c).abs() > r + eps){
							c = ccenter(ps[i], ps[j], ps[k]);
							r = ps[i].sub(c).abs();
						}
					}
				}
			}
		}
	}
	return {c, r};
}

inline double areaTT(std::vector <P> &ps, std::vector <P> &qs){
	std::vector <P> pss;
	for (auto u : ps){
		if (contains(qs, u) >= 0){
			pss.push_back(u);
		}
	}
	for (auto u : qs){
		if (contains(ps, u) >= 0){
			pss.push_back(u);
		}
	}
	const int N = 3;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			if (!crsSS(ps[i], ps[(i + 1) % N], qs[j], qs[(j + 1) % N])){
				continue;
			}
			P p = isLL(ps[i], ps[(i + 1) % N], qs[j], qs[(j + 1) % N]);
			if (p.x > INF / 10){
				continue;
			}
			pss.push_back(p);
		}
	}
	std::vector <P> qss;
	convexHull(pss, qss);
	return areaP(qss);
}

inline P centerOfMassT(P p1, P p2, P p3){
	return p1.add(p2).add(p3).div(3);
}

inline P centerOfMassP(std::vector <P> &ps){
	int n = ps.size();
	P center(0, 0);
	double mass = 0;
	for (int i = 1; i < n - 1; ++ i){
		double x = sig(ps[i + 1].sub(ps[0]).det(ps[i].sub(ps[0])));
		double m = areaT(ps[0], ps[i], ps[i + 1]) * x;
		mass += m;
		center = center.add(centerOfMassT(ps[0], ps[i], ps[i + 1]).mul(m));
	}
	return center.div(mass);
}

double solve(P p1, P p2, P p3){
	double left = 0, right = 1e10;
	while (right - left > eps){
		double mid = (left + right) / 2;
		std::vector <std::pair <P, P>> vec = tanCC(p1, mid, p3, mid);
		double dis1 = disLP(vec[0].first, vec[0].second, p2);
		double dis2 = disLP(vec[1].first, vec[1].second, p2);
		if (dis1 < 2 * mid + eps && dis2 < 2 * mid + eps){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	return left / 2;
}

std::vector <P> ps;
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		double x, y;
		scanf("%lf%lf", &x, &y);
		ps.push_back({x, y});	
	}
	double ans = INF;
	for (int i = 0; i < n; ++ i){
		ans = std::min(ans, solve(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]));
	}
	return printf("%.10lf\n", ans), 0;
}