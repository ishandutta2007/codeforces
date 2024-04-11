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

int n, A[105];
std::map<int, int> map, what;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		A[i] = a;
		map[a]++;
	}
	TRAV(kvp, map){
		if(kvp.Y == 1) what[0]++;
		if(kvp.Y == 2) what[1]++;
		if(kvp.Y > 2) what[2]++;
	}
	if(what[2] > 0 || what[0] % 2 == 0) std::cout << "YES\n";
	else{
		std::cout << "NO\n";
		return 0;
	}
	bool add = false;
	if(what[0] % 2 == 1) add = true;
	bool which = true;
	FOR(i, n){
		if(map[A[i]] == 2) std::cout << "A";
		else if(map[A[i]] > 2){
			if(add) std::cout << "B";
			else std::cout << "A";
			add = false;
		}else{
			std::cout << (which ? "A" : "B");
			which = (which+1)%2;
		}
	}
	return 0;
}