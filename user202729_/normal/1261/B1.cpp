#ifndef LOCAL
#define NDEBUG
#endif
#include<vector>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	struct item{
		int ind;
		int val;
		bool operator<(item x)const{
			return val!=x.val ? val>x.val : ind<x.ind;
		}
	};
	std::vector<item> is(n);
	for(int i=0;i<n;++i){
		std::cin>>is[i].val;
		is[i].ind=i;
	}
	std::sort(begin(is),end(is));

	int nquery;std::cin>>nquery;
	std::vector<int> out(nquery);
	struct query{
		int qind,k,pos;
	};
	std::vector<query> qs(nquery);
	for(int i=0;i<nquery;++i){
		auto& [qind,k,pos]=qs[i];
		qind=i;
		std::cin>>k>>pos;
		--pos;
	}
	std::sort(begin(qs),end(qs),[](query a,query b){
			return a.k>b.k;
			});

	__gnu_pbds::tree<int,int, // __gnu_pbds::null_type,
		std::less<int>,__gnu_pbds::rb_tree_tag,
		__gnu_pbds::tree_order_statistics_node_update> t;

	int k=0;
	for(auto [ind,val]:is){
		++k;
		t.insert({ind,val});

		while(not qs.empty() and qs.back().k==k){
			auto [qind,_,pos]=qs.back();qs.pop_back();
			out[qind]=t.find_by_order(pos)->second;
		}
	}
	
	for(auto x:out)
		std::cout<<x<<'\n';
}