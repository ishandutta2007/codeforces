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

int n;
std::vector<PII> ilo, ed;
std::set<int> fill;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	REP(i, 0, n+1) ilo.push_back({0, i});
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		if(a == b) fail();
		if(a != n && b != n) fail();
		ilo[a==n?b:a].X++;
	}
	REP(i, 1, n) if(ilo[i].X == 0) fill.insert(i);
	std::sort(ilo.begin(), ilo.end());
	while(!ilo.empty() && ilo.back().X > 0){
		int cur = ilo.back().Y;
		int to_fill = ilo.back().X - 1;
		int last = n;
		while(to_fill--){
			if(fill.lower_bound(cur) == fill.begin()) fail();
			auto it = --fill.lower_bound(cur);
			ed.push_back(MP(last, *it));
			last = *it;
			fill.erase(it);
		}
		ed.push_back(MP(last, cur));
		ilo.pop_back();
	}
	if(!fill.empty()) fail();
	std::cout << "YES\n";
	TRAV(pr, ed) std::cout << pr.X << " " << pr.Y << "\n";
	return 0;
}