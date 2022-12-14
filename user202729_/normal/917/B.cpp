#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<std::array<char,26>>> win; // win[first pos][second pos][lastc] -> (3: true, 2: false)
struct edge{ int x,val; };
std::vector<std::vector<edge>> ad;

bool cpu_win(int firstp,int secondp,int lastc){
	// total complexity: 26*n**3 = 26000000. Is recursion fast enough?
	auto& cur=win[firstp][secondp][lastc];
	if(cur!=0) return cur&1;
	cur=2;
	for(auto [nxt,edgeval]:ad[firstp])
		if(edgeval>=lastc and not cpu_win(secondp,nxt,edgeval)){
			cur=3;
			return true;
		}
	return false;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nedge;std::cin>>n>>nedge;

	ad.resize(n);
	for(int z=nedge,u,v;z--;){
		char c;
		std::cin>>u>>v>>c;
		--u;--v;
		c-='a';
		ad[u].push_back({v,c});
	}

	win.resize(n); for(auto& winx:win) winx.resize(n);
	for(auto firstp=0;firstp<n;++firstp){
		for(auto secondp=0;secondp<n;++secondp)
			std::cout<<(cpu_win(firstp,secondp,0)?'A':'B');
		std::cout<<'\n';
	}
}