#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<set>
#include<climits>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

struct edge{
	int x,w;
};
std::vector<std::vector<edge>> ad;

struct res_t_item{
	int64_t f,g;
	// fgx[d].f = min del cost s.t. all vertex deg <= d
	// fgx[d].g = min del cost s.t. root deg <= d-1, other deg <= d
	// where fgx = dd(x), for valid int d
};

struct res_t{
	std::vector<res_t_item> a;
	int fi; // such that:
	void validate()const{
		assert(std::all_of(begin(a)+fi,end(a),[](res_t_item x){return x.f==x.g;}));
	}
};

res_t dd(int x){
	if(ad[x].empty()){
		return {
			{{0,INT64_MAX}},
			1
		};
	}

	struct childr_t{
		res_t r;
		int64_t weight;
	};
	std::vector<childr_t> childr(ad[x].size());
	std::transform(begin(ad[x]),end(ad[x]),begin(childr),[x](edge e)->childr_t{
			auto [y,weight]=e;
			ad[y].erase(std::find_if(begin(ad[y]),end(ad[y]),[x](edge e){return e.x==x;}));
			return {dd(y),weight};
			// childr.back().push_back({0,0});
			});

	std::sort(begin(childr),end(childr),[](auto const& a,auto const& b){
			return a.r.a.size()>b.r.a.size();
			});

	auto [out,out_fi]=std::move(childr[0].r);
	auto out_weight=childr[0].weight;
	childr.erase(begin(childr));
	out.resize(std::max(out.size(),ad[x].size()+1));

	// find min candidates to add
	std::multiset<int64_t> cand1 /* smaller */,cand2;
	int64_t sum_cand1=0;

	// TODO is it more efficient to use one set and an iterator?
	// use hand implemented/policy based data structure is also possible.
	auto const cand_add=[&](int64_t x){
		if(not cand2.empty() and x>=*cand2.begin())
			cand2.insert(x);
		else{
			cand1.insert(x);
			sum_cand1+=x;
		}
	};
	auto const cand_del=[&](int64_t x){
		if(not cand2.empty() and x>=*cand2.begin())
			cand2.erase(cand2.find(x));
		else{
			cand1.erase(cand1.find(x));
			sum_cand1-=x;
		}
	};
	auto const cand_balance=[&](std::size_t d){
		assert(cand1.empty() or cand2.empty() or *cand1.rbegin()<=*cand2.begin());
		while(not cand2.empty() and cand1.size()<d){
			cand1.insert(*cand2.begin());
			sum_cand1+=*cand2.begin();
			cand2.erase(cand2.begin());
		}
		while(cand1.size()>d){
			auto iter=--end(cand1);
			sum_cand1-=*iter;
			cand2.insert(begin(cand2),*iter);
			cand1.erase(iter);
		}
		assert(cand1.size()==d or cand2.empty());
	};

	int64_t sumf_removed=0;
	res_t_item out_lastd;
	for(std::size_t d=0,endd=out.size(); // NOTE slow
			d<endd;++d){
		if(d){
			{ // for out
				auto [cf,cg]=out_lastd;
				auto cf_=cf+out_weight;
				if(cg<cf_){
					cand_del(cg-cf_);
				}
			}
			for(auto const& [z_fi,weight]:childr){
				auto const& [z,_fi]=z_fi;
				auto [cf,cg]=d-1<z.size() ? z[d-1] : res_t_item{0,0};
				auto cf_=cf+weight;
				if(cg<cf_){
					cand_del(cg-cf_);
				}
			}
		}
		out_lastd=out[d];

		int64_t sumf=sumf_removed;
		{ // for out
			auto [cf,cg]=out[d];
			auto cf_=cf+out_weight;
			if(cg<cf_){
				cand_add(cg-cf_);
			}
			sumf+=cf_;
		}
		for(auto const& [z_fi,weight]:childr){
			auto const& [z,_fi]=z_fi;
			auto [cf,cg]=d<z.size() ? z[d] : res_t_item{0,0};
			auto cf_=cf+weight;
			if(cg<cf_){
				cand_add(cg-cf_);
			}
			sumf+=cf_;
		}

		cand_balance(d);
		out[d].f=sumf+sum_cand1;

		if(d==0)
			out[d].g=INT64_MAX;
		else{
			cand_balance(d-1);
			out[d].g=sumf+sum_cand1;
		}

		if(out[d].f!=out[d].g)
			out_fi=std::max(out_fi,(int)d);

		while(not childr.empty() and d>=childr.back().r.a.size()){
			sumf_removed+=childr.back().weight;
			childr.pop_back();
		}

		if(childr.empty() and d>=(int)out_fi and d>ad[x].size()){
			break;
		}
	}
	return {std::move(out),out_fi}; // TODO optimize
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int i=n,u,v,w;--i;){
		std::cin>>u>>v>>w;
		ad[--u].push_back({--v,w});
		ad[v].push_back({u,w});
	}
	auto [fg0,_]=dd(0);
	assert((int)fg0.size()<=n);
	for(auto [f0i,g0i]:fg0)
		std::cout<<f0i<<' ';
	for(auto z=n-(int)fg0.size();z--;)
		std::cout<<"0 ";
	std::cout<<'\n';
}