#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	int ns = n;
	VI mam(n);

	auto add = [&](int a, int b){
		if(a > b) std::swap(a, b);
		if(mam[a] == 0) ns--;
		mam[a]++;
	};
	
	auto remove = [&](int a, int b){
		if(a > b) std::swap(a, b);
		mam[a]--;
		if(mam[a] == 0) ns++;
	};

	auto ans = [&](){
		return ns;
	};

	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		add(a, b);
	}

	int q;
	std::cin >> q;
	while(q--){
		int what;
		std::cin >> what;
		if(what == 3){
			std::cout << ans() << "\n";
		}else{
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			if(what == 1) add(a, b);
			else remove(a, b);
		}
	}

	return 0;
}