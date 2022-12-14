// Took too much time trying to get the order statistics tree to work (because I can't remember
// the template argument order)
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n;std::cin>>n;
	std::vector<int> pos(n);
	for(int i=0;i<n;++i){
		int ai;std::cin>>ai;
		--ai;
		pos[ai]=i;
	}

	__gnu_pbds::tree<int,__gnu_pbds::null_type,
		std::less<int>,
		__gnu_pbds::rb_tree_tag,
		__gnu_pbds::tree_order_statistics_node_update> t;

	int64_t ninv=0,notherswap=0;
	for(int ai=0;ai<n;++ai){
		int const p=pos[ai];
		auto const ord=t.order_of_key(p);
		ninv+=t.size()-ord;

		if(not t.empty()){
			auto const lmidord=(t.size()-1)/2;
			auto const rmidord=t.size()/2;
			int const lmid=*t.find_by_order(lmidord);
			int const rmid=lmidord==rmidord ? lmid : *t.find_by_order(rmidord);

			if(p>rmid)
				notherswap+=(p-rmid)-(ord-rmidord);
			else if(p<lmid)
				notherswap+=(lmid-p)-(lmidord-ord)-1;

			notherswap-=std::min(ord,t.size()-ord);
		}

		t.insert(p);
		std::cout<<ninv+notherswap<<' ';
	}
	std::cout<<'\n';
}