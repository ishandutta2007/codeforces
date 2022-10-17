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

std::vector<VI> g;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::vector<int> deg(n);
	FOR(i, n) deg[i] = SZ(g[i]);
	std::queue<int> que;

	FOR(i, n) if(deg[i] == 1) que.push(i);
	while(true){
		if(SZ(que) == 1){
			int x = que.front();
			std::cout << "! " << x+1 << std::endl;
			return 0;
		}
		int a = que.front();
		que.pop();
		int b = que.front();
		que.pop();
		std::cout << "? " << a+1 << " " << b+1 << std::endl;
		int x;
		std::cin >> x;
		x--;
		if(x == a || x == b){
			std::cout << "! " << x+1 << std::endl;
			return 0;
		}
		TRAV(ch, g[a]){
			deg[ch]--;
			if(deg[ch] == 1) que.push(ch);
		}
		TRAV(ch, g[b]){
			deg[ch]--;
			if(deg[ch] == 1) que.push(ch);
		}
	}
	return 0;
}