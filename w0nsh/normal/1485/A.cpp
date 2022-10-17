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

	int t;
	std::cin >> t;
	while(t--){
		int a, b;
		std::cin >> a >> b;
		PII cur = MP(a, b);
		std::map<PII, int> map;
		map[cur] = 0;
		std::queue<PII> que;
		que.push(cur);

		auto add = [&](PII x, int d){
			if(x.X == 0){
				std::cout << d << "\n";
				return true;
			}
			if(map.count(x) == 0){
				map[x] = d;
				que.push(x);
			}
			return false;
		};
		while(true){
			auto v = que.front();
			que.pop();
			int d = map[v]+1;
			if(add(MP(v.X/v.Y, v.Y), d) || add(MP(v.X, v.Y+1), d)) break;
		}
	}

	return 0;
}