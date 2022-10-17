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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int ans = 1;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	VI map(100005);
	std::set<PII> have;
	FOR(i, n){
		int a = A[i];
		int was = map[a];
		if(have.find(MP(was, a)) != have.end()) have.erase(MP(was, a));
		have.insert(MP(was+1, a));
		map[a]++;
		if(SZ(have) == 1) ans = i+1;
		else{
			int good = have.begin()->X;
			int nxt = std::next(have.begin(), 1)->X;
			int pre = std::next(have.end(), -2)->X;
			int last = (--have.end())->X;
			// std::cout << i+1 << ": " << good << " " << pre << " " << last << std::endl;
			if(pre == good && last == pre+1) ans = i+1;
			if(nxt == last && good == 1) ans = i+1;
		}
	}
	std::cout << ans;
	return 0;
}