#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);


//geometry
//typedef ll coord_t;
typedef double coord_t;

struct pt{
	coord_t x, y;
	pt(){}
	pt(coord_t x, coord_t y): x(x), y(y){}
	pt operator+(const pt &p)const{return pt(x + p.x, y + p.y);}
	pt operator-(const pt &p)const{return pt(x - p.x, y - p.y);}
	pt operator*(coord_t a)const{return pt(a * x, a * y);}
	bool operator==(const pt &p)const{return ((*this) - p).sqrlen() < EPS;}
	bool operator<(const pt &p)const{
		if(x < p.x - EPS) return true;
		if(abs(x - p.x) > EPS) return false;
		return y + EPS < p.y;
	}
	pt rotate(const double a)const{
		double s = sin(a), c = cos(a);
		return pt(x * c - y * s, x * s + y * c);
	}
	coord_t sqrlen(){return pt::dot(*this, *this);}
	static coord_t sqrdist(const pt &p1, const pt &p2){return pt(p1 - p2).sqrlen();}
	static coord_t dot(const pt &v1, const pt &v2){return v1.x * v2.x + v1.y * v2.y;}
	static coord_t dot(const pt &p1, const pt &p2, const pt &p3){return dot(p2-p1, p3-p1);}
	static coord_t cross(const pt &v1, const pt &v2){return v1.x * v2.y - v1.y * v2.x;}
	static coord_t cross(const pt &p1, const pt &p2, const pt &p3){return cross(p2-p1, p3-p1);}
	static pt rotate90degrees(const pt p){return pt(-p.y, p.x);}
};

struct seg{
	pt p, q;
	int id;
	seg(){}
	seg(pt p, pt q): p(p), q(q){}
	seg(pt p, pt q, int id): p(p), q(q), id(id){}
	double get_y(double x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y +(q.y - p.y) * (x-p.x) / (q.x - p.x);
    }
};

bool operator<(const seg& a, const seg& b){
    double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}

double SegpointDist(seg s, pt c){
	if(s.p == s.q) return sqrt(pt::sqrdist(s.p,c));
	if(pt::dot(s.p, s.q, c) < EPS)return sqrt(pt::sqrdist(s.p,c));
	if(pt::dot(s.q, s.p, c) < EPS)return sqrt(pt::sqrdist(s.q,c));
	return abs(pt::cross(s.p, s.q, c) / sqrt(pt::sqrdist(s.p,s.q)));
}

bool onSegment(pt p, seg s){
	return (SegpointDist(s, p) < EPS);
}

bool intersect1d(coord_t l1, coord_t r1, coord_t l2, coord_t r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}

int sgn(double x) {
    return abs(x) < EPS ? 0 : x > 0 ? +1 : -1;
}

bool intersects(const seg& a, const seg& b){
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           sgn(pt::cross(a.p, a.q, b.p)) * sgn(pt::cross(a.p, a.q, b.q)) <= 0 &&
           sgn(pt::cross(b.p, b.q, a.p)) * sgn(pt::cross(b.p, b.q, a.q)) <= 0;
}

pt findIntersection(seg a, seg b){
	double a1 = a.q.y - a.p.y , b1 = a.p.x - a.q.x, c1 =  a1 * a.p.x + b1 * a.p.y;
	double a2 = b.q.y - b.p.y , b2 = b.p.x - b.q.x, c2 =  a2 * b.p.x + b2 * b.p.y;
	double det = a1 * b2 - a2 * b1;
	return pt( (b2 * c1 - b1 * c2) / det, (a1 * c2 - a2 * c1) / det);
}

void test_case(){
	int n, h;
	cin >> n >> h;
	vector<pt> pts(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		pts[i].x=x;
		pts[i].y=y;
	}
	seg s(pts[n-1]+pt(0, h), pts[n-1]);
	double res = 0.0;
	for(int i = n-2; i>=0; i--){
		if(pt::cross(s.p, s.q, pts[i])< EPS){// DIREITA OU COLINEAR
			if(abs(pt::cross(s.p, s.q, pts[i])) < EPS && abs(pt::cross(s.p, s.q, pts[i+1])) < EPS)
				res += sqrt(pt::sqrdist(pts[i], pts[i+1]));
			else res += sqrt(pt::sqrdist(findIntersection(seg(pts[i], pts[i+1]), s), pts[i]));
			s.q = pts[i];
		}
	}
	cout << setprecision(15) << fixed << res << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}