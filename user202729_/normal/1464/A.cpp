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
	std::vector<int> to(n, -1);
	for(int _=0; _<m; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		assert(to[first]==-1);
		if(first!=sec)
			to[first]=sec;
	}
	int result{};
	for(int i=0; i<n; ++i) if(to[i]>=0){
		int x=i;
		do{
			std::tie(x, to[x])=std::pair(to[x], -1);
			++result;
		}while(to[x]>=0);
		if(x==i)
			++result;
	}
	std::cout<<result<<'\n';

}