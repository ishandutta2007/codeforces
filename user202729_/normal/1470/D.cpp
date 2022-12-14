// too slow.
// (not tested?)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}




void up(){
	int n, m; std::cin>>n>>m;
	std::vector<std::vector<int>> add;
	add.clear(); add.resize(n);
	for(int _=0; _<m; ++_){
		int u, v; std::cin>>u>>v;--u;--v; add[u].push_back(v); add[v].push_back(u);
	}

	std::vector<int> queue; queue.reserve(n);
	char const gray=-1, black=0, white=1, near=-2;
	std::vector<char> state(n, gray);
	int numBlack{};
	auto const markBlack=[&](int node){
		assert((node==0 and state[node]==gray) or state[node]==near);
		state[node]=black;
		++numBlack;
		for(auto other: add[node]){
			assert(state[other]==white or state[other]==gray or state[other]==near);
			if(state[other]!=white){
				state[other]=white;
				for(auto other2: add[other]) if(state[other2]==gray){
					state[other2]=near;
					queue.push_back(other2);
				}
			}
		}
	};
	markBlack(0);
	for(int index=0; index<(int)queue.size(); ++index){
		if(state[queue[index]]==near) markBlack(queue[index]);
	}
	if(std::any_of(begin(state), end(state), [&](auto const& it){return it==gray;})){
		std::cout<<"NO\n";
		return;
	}

	std::cout<<"YES\n";
	std::cout<<numBlack<<'\n';
	for(int node=0; node<n; ++node) if(state[node]==black){
		std::cout<<node+1<<' ';
	}
	std::cout<<'\n';
}