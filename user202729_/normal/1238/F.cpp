#include<iostream>
#include<vector>


std::vector<std::vector<int>> ad;

std::pair<int,int> dfs(int x,int par){ // {max ans, max temp value}
	int maxans=ad[x].size()+1; // x->x path
	int maxtmp=ad[x].size() /* x->x path */,maxtmp2=-1;

	for(int y:ad[x])if(y!=par){
		auto [ans1,tmp1]=dfs(y,x);
		maxans=std::max(maxans,ans1);
		maxtmp2=std::max(maxtmp2,tmp1+(int)ad[x].size()-1);
		if(maxtmp2>maxtmp)
			std::swap(maxtmp2,maxtmp);
	}

	maxans=std::max(maxans,maxtmp+maxtmp2-(int)ad[x].size()+1);
	return {maxans,maxtmp};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int n;std::cin>>n;
		ad.clear();ad.resize(n);
		for(int i=n;--i;){
			int x,y;std::cin>>x>>y;--x;--y;
			ad[x].push_back(y);ad[y].push_back(x);
		}
		std::cout<<dfs(0,-1).first<<'\n';
	}
}