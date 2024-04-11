#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<vector>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	struct event{ // payout/receipt
		int evid,val;
	};
	std::vector<event> payouts;
	std::vector<event> lastreceipt(n);

	for(int i=0;i<n;++i){
		lastreceipt[i].evid=-1;
		std::cin>>lastreceipt[i].val;
	}
	int nev;std::cin>>nev;

	for(int evid=0;evid<nev;++evid){
		char type;std::cin>>type;
		if(type=='1'){
			int p,val;std::cin>>p>>val;
			lastreceipt[--p]={evid,val};
		}else{
			int val;std::cin>>val;
			payouts.push_back({evid,val});
		}
	}

	// max suffix payouts val
	if(not payouts.empty())
		for(auto evid=payouts.size();--evid;)
			payouts[evid-1].val=std::max(payouts[evid-1].val,payouts[evid].val);

	for(event e:lastreceipt){
		auto iter=std::lower_bound(begin(payouts),end(payouts),e.evid,[](event a,int b){
				return a.evid<b;
				});
		if(iter!=end(payouts))
			std::cout<<std::max(iter->val,e.val)<<' ';
		else
			std::cout<<e.val<<' ';
	}
	std::cout<<'\n';
}