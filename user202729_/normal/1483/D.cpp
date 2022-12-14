#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, m; std::cin>>n>>m;
	std::vector<std::vector<int64_t>> weight(n, std::vector<int64_t>(n, INT64_MAX/2));
	std::vector<std::array<int, 3>> edges(m);
	for(auto& [u, v, w]: edges){
		std::cin>>u>>v>>w;
		--u;--v;
		weight[u][v]=weight[v][u]=std::min(weight[u][v], (int64_t)w);
	}

	for(int a=0; a<n; ++a)
		for(int b=0; b<n; ++b)
			for(int c=0; c<n; ++c)
				weight[b][c]=std::min(weight[b][c], weight[b][a]+weight[a][c]);

	std::vector<std::vector<int64_t>> l2(n, std::vector<int64_t>(n, INT64_MAX/2));
	int q; std::cin>>q;
	for(int _=0; _<q; ++_){
		int u, v, w; std::cin>>u>>v>>w;
		--u;--v;
		l2[u][v]=l2[v][u]=std::min(l2[u][v], (int64_t)-w);
	}

	for(int a=0; a<n; ++a)
		for(int b=0; b<n; ++b)
			for(int c=0; c<n; ++c)
				l2[a][c]=std::min(l2[a][c], weight[a][b]+l2[b][c]);

	for(int a=0; a<n; ++a)
		for(int b=0; b<n; ++b)
			for(int c=0; c<n; ++c)
				l2[a][c]=std::min(l2[a][c], l2[a][b]+weight[b][c]);

	int result{};
	for(auto [u, v, w]: edges){
		if(w+l2[u][v]<=0)
			++result;
	}
	std::cout<<result<<'\n';
}