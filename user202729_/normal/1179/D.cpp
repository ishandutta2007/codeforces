// O(log n) factor optimization with respect to the previous submission.
// TODO: implement the convex hull trick solution.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<map>
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<algorithm>

std::vector<std::vector<int>> ad;
int n;
std::vector<int> sts; // subtree size

std::vector<int> first,last,order,par;
int num=0;
int dd(int x){ // compute sts & erase parent edge from ad
	first[x]=num++;
	order.push_back(x);
	int stsx=1;
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		par[y]=x;
		stsx+=dd(y);
	}
	last[x]=num;
	return sts[x]=stsx;
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;
	ad.resize(n);
	for(int z=n;--z;){
		int u,v;std::cin>>u>>v;
		--u;--v;
		ad[u].push_back(v);ad[v].push_back(u);
	}

	int root=int(std::find_if(begin(ad),end(ad),[](auto const& x){return x.size()>1;})-begin(ad));
	if(root==n){
		assert(n==2);
		std::cout<<"2\n";
		return 0;
	}

	sts.resize(n);
	first.resize(n);last.resize(n);par.resize(n);
	order.reserve(n);
	par[root]=-1;
	int n_=dd(root);
	assert(n==n_ and num==n and order.size()==(unsigned)n);

	auto const sqr=[](auto x){
		return (int64_t)x*x;
	};

	std::vector<int64_t> f(n);
	assert(order[0]==root);
	// f[0]=0;
	std::for_each(begin(order)+1,end(order),[&](int x){
			f[x]=f[par[x]]+sqr(sts[par[x]]-sts[x]);
			});

	// g = min {f over descendant leaves}
	auto g=f;
	std::for_each(order.rbegin(),order.rend(),[&](int x){
			if(not ad[x].empty()){
				g[x]=INT64_MAX;
				for(int y:ad[x])
					g[x]=std::min(g[x],g[y]);
				assert(g[x]!=INT64_MAX);
			};
	});

	std::vector<int64_t> sts_to_min_g(n+1);
	std::vector<int> inserted_sts_vals;inserted_sts_vals.reserve(2+(int)std::sqrt(n));

	int64_t out=INT64_MAX;
	for(int w=0;w<n;++w)if(ad[w].size()>=2){
		int64_t cur=INT64_MAX;

		inserted_sts_vals.clear();
		for(int x:ad[w])
			sts_to_min_g[sts[x]]=INT64_MAX;

		for(int x:ad[w]){
			for(auto sts_y:inserted_sts_vals){
				auto g_y=sts_to_min_g[sts_y];
				cur=std::min(cur,2*int64_t(sts[x]+sts[w]-n)*(sts_y+sts[w]-n)
						+g[x]+g_y);
			}

			if(sts_to_min_g[sts[x]]==INT64_MAX){
				inserted_sts_vals.push_back(sts[x]);
				sts_to_min_g[sts[x]]=g[x];
			}else{
				sts_to_min_g[sts[x]]=std::min(sts_to_min_g[sts[x]],g[x]);
			}
		}

		out=std::min(out,cur+2-2*f[w]-sqr(2*sts[w]-n));
	}
	std::cout<<sqr(n)-(n+out)/2<<'\n';
}