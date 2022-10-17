#include <bits/stdc++.h>
#define ll long long
#define FOR(i, n) for(int i =0; i  < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define PR std::pair
#define PII std::pair<int, int>
#define SZ(i) ((int)((i).size()))
#define VI std::vector<int>
#define MP std::make_pair
#define X first
#define Y second

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<PR<PII, PII> > ex;
	std::map<int, int> isex;
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;b--;
		ex.push_back(MP(MP(a, b), MP(c, i)));
		isex[b+1] = i;
	}
	std::set<PR<PII, int> > set;
	std::sort(ex.begin(), ex.end());
	VI ans(n);
	auto it = ex.begin();
	FOR(i, n){
		while(it != ex.end() && it->X.X == i){
			set.insert(MP(MP(it->X.Y, it->Y.X), it->Y.Y));
			it++;
		}
		if(isex.count(i)){
			ans[i] = m+1;
			TRAV(j, set) if(j.Y == isex[i]){
				std::cout << -1;
				return 0;
			}
		}
		else{
			if(set.empty()) ans[i] = 0;
			else{
				auto cur = set.begin();
				PR<PII, int> nw = MP(MP(cur->X.X, cur->X.Y-1), cur->Y);
				ans[i] = nw.Y+1;
				set.erase(cur);
				if(nw.X.Y > 0) set.insert(nw);
			}
		}
	}
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}