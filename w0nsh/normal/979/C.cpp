#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

const int NMAX = 300005;
int n, x, y;
std::vector<std::vector<int> > g;
int pre[NMAX], post[NMAX], parent[NMAX];
bool between[NMAX];
int _tick = 1;

void answer(){
	long long all = 1ll*n*(n-1);
	long long not_between = 1;
	for(auto &ch : g[x]){
		if(!between[ch]) not_between += ((post[ch]-pre[ch])/2+1);
	}
	long long sub = 1ll*not_between * ((post[y]-pre[y])/2+1);
	std::cout << all - sub << "\n";
}

void dfs0(int v, int p=-1){
	parent[v] = p;
	pre[v] = _tick++;
	for(auto &ch : g[v]){
		if(pre[ch] == 0){
			dfs0(ch, v);
			if(between[ch]) between[v] = true;
		}
	}
	post[v] = _tick++;
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> x >> y;
	g.resize(n);
	x--;y--;
	for(int i = 0; i < n-1; ++i){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

}

int main(){
	read();
	between[y] = true;
	dfs0(x);
	answer();
	return 0;
}