#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>

struct AA{
	int n;
	std::vector<std::vector<int>> ad,rad;
	AA(int n):n(n),ad(n),rad(n){}

	void addedge(int a,int b){
		// a implies b
		ad[a].push_back(b);
		rad[b].push_back(a);
	}

	std::vector<int> order;
	void toposort(int i){ // value = 0/1: not visited / visited
		if(value[i])return;
		value[i]=1;
		for(int j:ad[i])
			toposort(j);
		order.push_back(i);
	}

	std::vector<char> value;
	void assign_false(int x){
		if(value[x]==0)return;
		value[x]=0;
		for(int y:rad[x])
			assign_false(y);
	}

	bool run(){
		value.clear();value.resize(ad.size());
		order.clear();order.reserve(ad.size());
		// now value = [0] * n
		for(int i=0;i<ad.size();++i)
			toposort(i);
		// now value = [1 <- filled by toposort] * n

		assert((int)order.size()==n);
		int x=order.back();
		assign_false(x);

		return std::find(begin(value),end(value),1)!=end(value);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	while(ntest--){
		int n,m;std::cin>>n>>m;
		AA s(n);
		for(int z=0,u,v;z<m;++z){
			std::cin>>u>>v;
			if(u!=v){
				--u;--v;
				s.addedge(u,v);
			}
		}

		if(!s.run()){
			std::cout<<"No\n";
		}else{
			int njury=0;
			for(int i=0;i<n;++i)
				njury+=s.value[i];
			if(njury==n||njury==0)
				assert(false);

			std::cout<<"Yes\n";
			std::cout<<njury<<' '<<n-njury<<'\n';

			for(int i=0;i<n;++i)
				if(s.value[i])
					std::cout<<i+1<<' ';
			std::cout<<'\n';

			for(int i=0;i<n;++i)
				if(!s.value[i])
					std::cout<<i+1<<' ';
			std::cout<<'\n';
		}
	}
}