#ifndef LOCAL
#define NDEBUG
#endif
#include<iomanip>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<array>

std::vector<std::vector<int>> ad;
std::vector<std::array<std::pair<int,int>,2>> down; // {max depth of a node int the subtree wrt that node, child value} x2
std::vector<int> up, // max depth up
	root; // connected component id

void dd(int x,int par,int rootx){
	down[x]={{ {0,-1},{0,-1} }}; // self node
	root[x]=rootx;
	for(int y:ad[x])if(y!=par){
		dd(y,x,rootx);
		std::pair<int,int> p{down[y][0].first+1,y};
		if(p.first>down[x][1].first){
			down[x][1]=p;
			if(down[x][1].first>down[x][0].first)
				std::swap(down[x][1],down[x][0]);
		}
	}
}

std::vector<int> radz;
std::vector<std::vector<int>> rootradz; // connected component id => list of radiusz
void de(int x,int par,int uppar){
	int upx=0;
	if(par>=0){
		for(auto [len,child]:down[par])
			if(child!=x)
				upx=std::max(upx,len+1);
		upx=std::max(upx,uppar+1);
	}

	radz.push_back(std::max(down[x][0].first,upx));

	for(int y:ad[x])if(y!=par){
		de(y,x,upx);
	}
}

std::vector<std::vector<int64_t>> rootradz_sumsuffix;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m,q;std::cin>>n>>m>>q;
	ad.resize(n);
	for(int z=m,u,v;z--;){
		std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	down.resize(n);
	up.resize(n);
	root.assign(n,-1);
	for(int i=n;i--;)if(root[i]<0){
		dd(i,-1, (int)rootradz.size());
		radz.clear();
		de(i,-1,0);
		std::sort(begin(radz),end(radz));
		rootradz.push_back(std::move(radz));
	}

	rootradz_sumsuffix.resize(rootradz.size());
	std::transform(begin(rootradz),end(rootradz),begin(rootradz_sumsuffix),[](std::vector<int> const& zz){
			std::vector<int64_t> z(begin(zz),end(zz));
			assert(!z.empty());
			for(auto i=z.size()-1;i--;){
				z[i]+=z[i+1];
			}
			return z;
	});

	std::map<std::pair<int,int>,double> memo;
	std::cout<<std::fixed<<std::setprecision(10);
	for(int z=q,u,v;z--;){
		std::cin>>u>>v;--u;--v;
		u=root[u];v=root[v];
		if(u==v){
			std::cout<<"-1\n";
			continue;
		}

		auto iter=memo.find({u,v});
		double ans=0;
		if(iter!=memo.end()){
			ans=iter->second;
		}else{
			// compute ans
			auto const& r3=rootradz[u];
			auto const& r4=rootradz[v]; // TODO compress by tally
			auto const& r1=r3.size()>r4.size() ? r4 : r3; // smaller
			auto const& r2=r3.size()>r4.size() ? r3 : r4;

			auto const& f1=rootradz_sumsuffix[&r1-&rootradz[0]];
			auto const& f2=rootradz_sumsuffix[&r2-&rootradz[0]];

			int const d1=r1.back();
			int const d2=r2.back();
			int const x=std::max(d1,d2)-1;

			// ans = 1+E(max(x, a1+a2) for a1 int r1 for a2 int r2)
			ans=0;
			for(int a1:r1){
				auto iter=std::lower_bound(begin(r2),end(r2),x-a1); // iter will increase
				// before iter: a2 < x-a1 :: a2+a1<x :: max==x
				ans+=double(iter-begin(r2)) * x;
				// after iter: a2 >= x-a1 :: max==a1+a2
				ans+=double(end(r2)-iter) * a1 + f2[iter-begin(r2)];
			}
			ans/=r1.size()*(double)r2.size();
			++ans;

			memo.insert({{u,v},ans});
		}
		std::cout<<ans<<'\n';
	}
}