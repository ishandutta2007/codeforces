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

void fail(){
	std::cout << -1;
	std::exit(0);
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::set<int> set;
	std::set<int> was;
	VI ans;
	int cnt = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
			cnt++;
		if(a < 0){
			if(set.count(-a) == 0) fail();
			set.erase(-a);
		}else{
			if(set.count(a) != 0) fail();
			if(was.count(a)) fail();
			was.insert(a);
			set.insert(a);
		}
		if(SZ(set) == 0){
			was.clear();
			ans.push_back(cnt);
			cnt = 0;
		}
	}
	if(SZ(set)) fail();
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}