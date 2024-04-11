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

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::set<int> plu;
	std::set<int> set;
	VI licz(n);
	VI ans(2*n, -1);
	FOR(i, 2*n){
		char a;
		std::cin >> a;
		if(a == '+'){
			plu.insert(i);
		}else{
			int x;
			std::cin >> x;
			x--;
			licz[x] = i;
			set.insert(i);
		}
	}

	FOR(i, n){
		int pos = licz[i];
		auto it = plu.lower_bound(pos);
		if(it == plu.begin()) fail();
		--it;
		int p = *it;
		auto xd = set.lower_bound(p);
		assert(xd != set.end());
		if(*xd < pos) fail();
		set.erase(pos);
		plu.erase(it);
		ans[p] = i+1;
	}

	std::cout << "YES\n";
	FOR(i, 2*n) if(ans[i] != -1) std::cout << ans[i] << " ";
	std::cout << "\n";

	return 0;
}