#include <bits/stdc++.h>
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

int n, d1, d2, state, ans;
PII A[100005], B[100005];

inline bool equal(double a, double b){
	return std::abs(a-b) <= 0.000000001;
}

inline bool smaller(double a, double b){
	return equal(std::max(0.0, a-b), 0.0);
}

inline double dist(double x1, double y1, double x2, double y2){
	return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double dist(std::pair<double, double> a, std::pair<double, double> b){
	return dist(a.X, a.Y, b.X, b.Y);
}

std::pair<double, double> linear(double x1, double y1, double x2, double y2, double val){
	return MP(x1*(1.0-val)+x2*val, y1*(1.0-val)+y2*val);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> d1 >> d2;
	FOR(i, n) std::cin >> A[i].X >> A[i].Y >> B[i].X >> B[i].Y;
	FOR(i, n-1){
		if(smaller(d2, dist(A[i].X, A[i].Y, B[i].X, B[i].Y))) state = 0;
		if(state == 1) continue;
		double min_dist = std::min(dist(A[i].X, A[i].Y, B[i].X, B[i].Y), dist(A[i+1].X, A[i+1].Y, B[i+1].X, B[i+1].Y));
		double left = 0, right = 1;
		while(!equal(std::abs(right-left), 0.0)){
			double m1 = left + (right-left)/3.0;
			double m2 = right - (right-left)/3.0;
			double dist_m1 = dist(linear(A[i].X, A[i].Y, A[i+1].X, A[i+1].Y, m1), linear(B[i].X, B[i].Y, B[i+1].X, B[i+1].Y, m1));
			double dist_m2 = dist(linear(A[i].X, A[i].Y, A[i+1].X, A[i+1].Y, m2), linear(B[i].X, B[i].Y, B[i+1].X, B[i+1].Y, m2));
			if(dist_m1 > dist_m2) left = m1;
			else right = m2;
		}
		min_dist = std::min(min_dist, dist(linear(A[i].X, A[i].Y, A[i+1].X, A[i+1].Y, (left+right)/2.0),
										linear(B[i].X, B[i].Y, B[i+1].X, B[i+1].Y, (left+right)/2.0)));
		// std::cout << i+1 << ": " << min_dist << "\n";
		if(smaller(min_dist, d1)) ans++, state = 1;
	}
	std::cout << ans << "\n";
	return 0;
}