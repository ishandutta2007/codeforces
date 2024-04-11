#include <bits/stdc++.h>
#define int long long
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

struct Num{
	int a, b;
	Num (){}
	Num(int x, int y){
		a = x;
		b = y;
		assert(x != 0 || y != 0);
		a /= std::__gcd(x, y);
		b /= std::__gcd(x, y);
		if(b < 0){
			b *= -1;
			a *= -1;
		}
	}
	void norm(){
		int x = a;
		int y = b;
		a /= std::__gcd(x, y);
		b /= std::__gcd(x, y);
		if(b < 0){
			b *= -1;
			a *= -1;
		}
	}
};

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	std::map<PII, std::set<PII> > map;
	FOR(i, n){
		REP(j, i+1, n){
			Num a, b;
			if(A[i].X == A[j].X) a = Num(1000000000000000000, 1000000000000000001), b = Num(A[i].X, 1);
			else a = Num(A[i].Y-A[j].Y,A[i].X-A[j].X), b = Num(A[i].Y*a.b - A[i].X*a.a, a.b);
			map[MP(a.a, a.b)].insert(MP(b.a, b.b));
		}
	}
	int all = 0;
	TRAV(pr, map) all += SZ(pr.Y);
	int ans = 0;
	TRAV(pr, map){
		ans += SZ(pr.Y)*(all-SZ(pr.Y));
	}
	std::cout << ans/2;
	return 0;
}