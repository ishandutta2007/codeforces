#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;

	std::map<int, VI> map;
	VI vals(n);
	FOR(i, n-1){
		std::cout << "XOR " << 1 << " " << i+2 << std::endl;
		int x;
		std::cin >> x;
		vals[i+1] = x;
		map[x].push_back(i+1);
	}

	VI A(n, -1);

	auto answer = [&](){
		int ind = -1;
		FOR(i, n) if(A[i] != -1) ind = i;
		assert(ind != -1);
		if(ind > 0){
			A[0] = vals[ind]^A[ind];
		}
		REP(i, 1, n){
			int heh = vals[i]^A[0];
			if(A[i] != -1) assert(heh == A[i]);
			A[i] = heh;
		}
		std::cout << "! ";
		FOR(i, n) std::cout << A[i] << " ";
		std::cout << std::endl;
		std::exit(0);
	};

	auto same = [&](int a, int b){
		std::cout << "OR " << a+1 << " " << b+1 << std::endl;
		int x;
		std::cin >> x;
		A[a] = x;
		A[b] = x;
		answer();
	};

	if(map.count(0)){
		int b = map[0][0];
		same(0, b);
	}

	TRAV(pr, map){
		if(SZ(pr.Y) > 1){
			int a = pr.Y[0];
			int b = pr.Y[1];
			same(a, b);
		}
	}

	assert(map.count(1));
	assert(map.count(2));
	int j = map[1][0];
	int d = map[2][0];
	std::cout << "AND " << 1 << " " << j+1 << std::endl;
	int fs;
	std::cin >> fs;
	std::cout << "AND " << 1 << " " << d+1 << std::endl;
	int sc;
	std::cin >> sc;
	A[0] = sc | fs;
	answer();

	return 0;
}