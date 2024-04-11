#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MX = 2000005;
PII find(int m){
	int h, a, x, y;
	std::cin >> h >> a >> x >> y;
	
	int cnt = 0;
	while(h != a){
		cnt++;
		if(cnt > MX){
			std::cout << -1 << "\n";
			std::exit(0);
		}
		h = (1ll*x*h+y)%m;
	}

	int cyc = 0;
	do{
		h = (1ll*x*h+y)%m;
		cyc++;
		if(cyc > MX){
			return MP(cnt, -1);
		}
	}while(h != a);

	return MP(cnt, cyc);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m;
	std::cin >> m;
	
	auto a = find(m);
	auto b = find(m);
//	std::cout << a.X << " " << a.Y << ", " << b.X << " " << b.Y << std::endl;

	if(a.Y == -1 && b.Y == -1){
		if(a.X == b.X) std::cout << a.X << "\n";
		else std::cout << -1 << "\n";
		return 0;
	}

	if(b.Y == -1) std::swap(a, b);
	if(a.Y == -1){
		if(a.X >= b.X && (a.X-b.X)%b.Y == 0) std::cout << a.X << "\n";
		else std::cout << -1 << "\n";
		return 0;
	}

	if(a.X > b.X) std::swap(a, b);
	int st = (a.Y - (b.X-a.X)%a.Y)%a.Y;
	int k = b.Y;
	int md = a.Y;

//	std::cout << a.X << " " << a.Y << ", " << b.X << " " << b.Y << std::endl;

	// want k*x = st mod md
	FOR(i, MX){
		int cr = (1ll*k*i)%md;
		if(cr == st){
			std::cout << 1ll*b.X + 1ll*k*i << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";


	return 0;
}