#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<map>

std::vector<std::map<int,int>> ad; // x -> value

std::vector<int> path;

template<bool store> // include first x parameter, include leaf, exclude par
int leaf(int x,int par){
	if(store)
		path.push_back(x);

	assert(par<0 or ad[x].count(par));
	if(par<0){
		if(ad[x].empty())
			return x;
	}else{
		if(ad[x].size()==1){
			assert(ad[x].begin()->first==par);
			return x;
		}
	}

	auto iter=ad[x].begin();
	while(iter->first==par)++iter;
	return leaf<store>(iter->first,x);
}

std::vector<int> pathleaf(int x,int par){
	path.clear();
	leaf<true>(x,par);
	return std::move(path);
}

void subpath(std::vector<int> const& p1,int w){
	if(w==0)return;
	for(unsigned x=1;x<p1.size();++x){
		int a=p1[x-1];
		int b=p1[x];
		ad[a].at(b)-=w;
		ad[b].at(a)-=w;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	// note: ops are commutative
	ad.resize(n);
	for(int z=n;--z;){
		int u,v,w;std::cin>>u>>v>>w;
		ad[--u].emplace(--v,w);
		ad[v].emplace(u,w);
	}

	std::vector<char> isleaf(n);
	std::transform(begin(ad),end(ad),begin(isleaf),[](auto const& x){return x.size()==1;});

	for(int i=0;i<n;++i)if(ad[i].size()==2){
		// remove 
		auto iter=ad[i].begin();
		auto y=*iter++;
		auto z=*iter++;
		if(y.second!=z.second){
			std::cout<<"NO\n";
			return 0;
		}
		ad[i].clear();
		ad[y.first].erase(i);
		ad[z.first].erase(i);
		ad[y.first].emplace(z.first,y.second);
		ad[z.first].emplace(y.first,y.second);
	}

	int x=0; // any undeleted node
	while(ad[x].empty())++x;

	struct op{int x,y,w;};
	std::vector<op> ops;
	while(not ad[x].empty()){
		assert(std::none_of(begin(ad),end(ad),[](auto const& x){return x.size()==2;}));
		for(int i=0;i<n;++i)
			if(ad[i].size()==1)
				assert(isleaf[i]);

		x=leaf<false>(x,-1);
		assert(isleaf[x]);
		auto [y,w]=*ad[x].begin();
		ad[x].erase(ad[x].begin());

		ad[y].erase(x);
		auto p1=pathleaf(y,-1);
		if(ad[y].size()!=2){
			if(w){
				subpath(p1,w);
				assert(isleaf[p1.back()]);
				ops.push_back({x,p1.back(),w});
			}
			x=y;
			continue;
		}

		assert(ad[y].size()==2);

		auto p2=pathleaf(y,p1[1]);

		auto m=ad[y].at(p1[1]);
		auto n=ad[y].at(p2[1]);

		assert((m-n+w)%2==0);
		int a=(m-n+w)/2;
		int d1=a;
		int d2=w-a;
		assert(m-d1 == n-d2);

		bool odd=d1&1;
		if(odd){
			++d1;
			++d2;
		}

		assert(isleaf[p1.back()]);
		assert(isleaf[p2.back()]);
		if(a)
			ops.push_back({x,p1.back(),a});
		if(w-a)
			ops.push_back({x,p2.back(),w-a});
		if(odd)
			ops.push_back({p1.back(),p2.back(),1});

		subpath(p1,d1);
		subpath(p2,d2);
		{
			auto p=p1[1];
			auto q=p2[1];
			ad[y].clear();

			auto iterp=ad[p].find(y);
			auto iterq=ad[q].find(y);
			auto w1=iterq->second;
			assert(iterp->second==w1);

			ad[p].erase(iterp);
			ad[q].erase(iterq);
			ad[p].emplace(q,w1);
			ad[q].emplace(p,w1);

			x=p;
		}

	}

	assert(std::all_of(begin(ad),end(ad),[](auto& t){return t.empty();}));

	std::cout<<"YES\n"<<ops.size()<<'\n';
	for(auto [x,y,w]:ops){
		assert(isleaf[x]);
		assert(isleaf[y]);
		std::cout<<x+1<<' '<<y+1<<' '<<w <<'\n';
	}
}