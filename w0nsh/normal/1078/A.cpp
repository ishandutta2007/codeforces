#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

struct Intersection{
	double X, Y;
	Intersection(){}
	Intersection(double a, double b) : X(a), Y(b) {}
};
struct Line{
	double A, B, C;
	Line(){}
	Line(double a, double b, double c) : A(a), B(b), C(c) {}
};
Intersection get_intersection(Line &x, Line &y){
	return Intersection((x.C*y.B-x.B*y.C)/(x.B*y.A-x.A*y.B), (x.A*y.C-x.C*y.A)/(x.B*y.A-x.A*y.B));
}
inline Line get_line(double x1, double y1, double x2, double y2){
	return Line(y1-y2, x2-x1, (x1-x2)*y1+(y2-y1)*x1);
}
double dist(double x1, double y1, double x2, double y2){
	return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int a, b, c;
int x1, yy1, x2, y2;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> a >> b >> c;
	std::cin >> x1 >> yy1 >> x2 >> y2;
	if(x1 > x2){
		std::swap(x1, x2);
		std::swap(yy1, y2);
	}
	double manh = 1.0*std::abs(x1-x2) + 1.0*std::abs(yy1-y2);
	if(b == 0 || a == 0 || x1 == x2 || yy1 == y2){
		std::cout << std::fixed << std::setprecision(15) << manh << "\n";
		return 0;
	}
	// if(b < 0){
	// 	b = -b;
	// 	a = -a;
	// 	c = -c;
	// }
	// double na = -1.0*a/b;
	// double nb = -1.0*c/b;
	// if((na > 0) != (y2 > yy1)){
	// 	std::cout << manh << "\n";
	// 	return 0;
	// }
	Line lin = Line(a, b, c);
	Line my = get_line(x1, yy1, x2, yy1);
	Line his = get_line(x1, y2, x2, y2);
	Line up = get_line(x2, yy1, x2, y2);
	Line down = get_line(x1, yy1, x1, y2);
	auto mi = get_intersection(lin, my);
	auto hi = get_intersection(lin, his);
	auto ui = get_intersection(lin, up);
	auto di = get_intersection(lin, down);
	double c2 = dist(mi.X, mi.Y, x1, yy1) + dist(hi.X, hi.Y, x2, y2) + dist(mi.X, mi.Y, hi.X, hi.Y);
	c2 = std::min(c2, dist(mi.X, mi.Y, x1, yy1) + dist(ui.X, ui.Y, x2, y2) + dist(mi.X, mi.Y, ui.X, ui.Y));
	c2 = std::min(c2, dist(di.X, di.Y, x1, yy1) + dist(ui.X, ui.Y, x2, y2) + dist(di.X, di.Y, ui.X, ui.Y));
	c2 = std::min(c2, dist(di.X, di.Y, x1, yy1) + dist(hi.X, hi.Y, x2, y2) + dist(di.X, di.Y, hi.X, hi.Y));
	std::cout << std::fixed << std::setprecision(15) << std::min(c2, manh) << "\n";
	return 0;
}