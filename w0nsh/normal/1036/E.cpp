#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Line{
	double A, B, C;
	Line(){}
	Line(double a, double b, double c) : A(a), B(b), C(c) {}
};
struct Intersection{
	double X, Y;
	Intersection(){}
	Intersection(double a, double b) : X(a), Y(b) {}
};
inline bool equal(double a, double b){
	return std::abs(a-b) < 0.000000001;
}
bool are_parallel(Line &x, Line &y){
	return equal(x.A/x.B, y.A/y.B);
}
inline Line get_line(double x1, double y1, double x2, double y2){
	return Line(y1-y2, x2-x1, (x1-x2)*y1+(y2-y1)*x1);
}
Intersection get_intersection(Line &x, Line &y){
	return Intersection((x.C*y.B-x.B*y.C)/(x.B*y.A-x.A*y.B), (x.A*y.C-x.C*y.A)/(x.B*y.A-x.A*y.B));
}


int n;
ll total = 0;
std::vector<PR<PII, PII> > A;
std::map<PII, std::set<int> > multi;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i].X.X >> A[i].X.Y >> A[i].Y.X >> A[i].Y.Y;
	TRAV(pr, A) total += std::__gcd(std::abs(pr.X.X-pr.Y.X), std::abs(pr.X.Y-pr.Y.Y))+1;
	FOR(i, n) REP(j, i+1, n){
		// if((A[i].X.X == A[j].X.X && A[i].X.Y == A[j].X.Y) || (A[i].Y.X == A[j].Y.X && A[i].Y.Y == A[j].Y.Y)){
		// 	total--;
		// 	continue;
		// }
		auto a = get_line(A[i].X.X, A[i].X.Y, A[i].Y.X, A[i].Y.Y);
		auto b = get_line(A[j].X.X, A[j].X.Y, A[j].Y.X, A[j].Y.Y);
		auto in = get_intersection(a, b);
		if(std::abs(in.X) < 2000000.0 && std::abs(in.Y) < 2000000.0){
			if(equal(in.X, std::round(in.X)) && equal(in.Y, std::round(in.Y))){
				int good = 0;
				if(std::round(in.X) <= std::max(A[i].X.X, A[i].Y.X) &&
					std::round(in.X) >= std::min(A[i].X.X, A[i].Y.X) &&
					std::round(in.Y <= std::max(A[i].X.Y, A[i].Y.Y) &&
					std::round(in.Y >= std::min(A[i].X.Y, A[i].Y.Y)))) good++;
				if(std::round(in.X) <= std::max(A[j].X.X, A[j].Y.X) &&
					std::round(in.X) >= std::min(A[j].X.X, A[j].Y.X) &&
					std::round(in.Y <= std::max(A[j].X.Y, A[j].Y.Y) &&
					std::round(in.Y >= std::min(A[j].X.Y, A[j].Y.Y)))) good++;
				if(good == 2) multi[MP((int)std::round(in.X), (int)std::round(in.Y))].insert(i),
					multi[MP((int)std::round(in.X), (int)std::round(in.Y))].insert(j);
			}
		}
	}
	ll min = 0;
	TRAV(kvp, multi){
		min += kvp.Y.size()-1;
	}
	std::cout << total - min << "\n";
	return 0;
}