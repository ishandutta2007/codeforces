#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

std::set<int> my;
int test, n;
std::vector<VI> g;

int end = -1;
void dfs(int v, int par=-1){
	if(end != -1) return;
	if(my.count(v)){
		end = v;
		return;
	}
	TRAV(ch, g[v]){
		if(ch != par) dfs(ch, v);
	}
}

int ask(char c, int a){
	std::cout << c << " " << a+1 << "\n" << std::flush;
	int ret;
	std::cin >> ret;
	ret--;
	return ret;
}

void answer(int i){
	std::cout << "C " << i << "\n" << std::flush;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> test;
	while(test--){
		std::cin >> n;
		g.resize(n);
		FOR(i, n) g[i].clear();
		FOR(i, n-1){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		VI li;
		my.clear();
		int mk, lk;
		std::cin >> mk;
		FOR(i, mk){
			int a;
			std::cin >> a;
			a--;
			my.insert(a);
		}
		std::cin >> lk;
		FOR(i, lk){
			int a;
			std::cin >> a;
			a--;
			li.push_back(a);
		}
		int guess = ask('B', li[0]);
		bool good = false;
		TRAV(i, my) if(i == guess){
			good = true;
			answer(i+1);
			break;
		}
		if(good) continue;
		end = -1;
		dfs(guess);
		int need = end;
		int inthere = ask('A', need);
		TRAV(i, li) if(i == inthere){
			answer(need+1);
			good = true;
			break;
		}
		if(!good) answer(-1);
	}
	return 0;
}