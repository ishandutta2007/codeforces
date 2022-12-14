#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cassert>
#include<iostream>
#include<vector>

using fact_t=std::vector<std::pair<int,int>>;
struct fact_hash{
	std::size_t operator()(fact_t const& f)const{
		std::size_t ans=43;
		for(auto [base,expo]:f)
			ans=(ans*7+base)*7+expo;
		return ans;
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	std::vector<int> sieve(std::max(5,
				*std::max_element(begin(a),end(a))+1
				));
	for(int i=2;i*i<(int)sieve.size();++i)
		if(sieve[i]==0){
			for(int j=i*i;j<(int)sieve.size();j+=i)
				sieve[j]=i;
		}

	auto const factorize=[&](int x)->fact_t{
		fact_t ans;
		std::map<int,int> cnt;
		while(sieve[x]){
			++cnt[sieve[x]];
			x/=sieve[x];
		}
		if(x>1)
			++cnt[x];

		return {begin(cnt),end(cnt)};
	};

	std::unordered_map<fact_t,int,fact_hash> cnt;
	int64_t ans=0;
	for(int x:a){
		fact_t fx=factorize(x);
		for(auto& [base,expo]:fx)
			expo%=k;
		fx.erase(std::remove_if(begin(fx),end(fx),[](auto be){return be.second==0;}),end(fx));

		auto fx_compl=fx;
		for(auto& [base,expo]:fx_compl)
			expo=k-expo;

		auto iter=cnt.find(fx_compl);
		if(iter!=end(cnt))
			ans+=iter->second;

		++cnt[fx];
	}
	std::cout<<ans<<'\n';
}