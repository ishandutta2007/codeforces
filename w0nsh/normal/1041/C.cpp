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

int n, m, d, temp;
std::set<PII> set;
VI ans;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> d;
	FOR(i, n) std::cin >> temp, set.insert({temp, i});
	int day = 0;
	ans.resize(n);
	while(!set.empty()){
		int cur = 0;
		while(true){
			auto it = set.lower_bound(MP(cur, 0));
			if(it == set.end()) break;
			ans[it->Y] = day;
			cur = it->X + d + 1;
			set.erase(it);
		}
		day++;
	}
	std::cout << day << "\n";
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}