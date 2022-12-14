// I think I have read the problem statement of this problem before...?
#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<cassert>
#include<iostream>
#include<vector>
#include<unordered_map>

std::vector<std::vector<int>> ad;
std::vector<char> val; // par(x) .. x
std::vector<int> ansof;

struct a{ // set of 22-bit numbers that support fast get max value, flip a bit of a number and merging
	std::unordered_map<unsigned,int> val;
	unsigned f; // flip value
	int ofs;

	a():val(),f(){}

	void add(unsigned x,int v){
		rawadd(x^f,v-ofs);
	}

	void rawadd(unsigned x,int v){
		auto [iter,success]=val.insert({x,v});
		if(!success)
			iter->second=std::max(iter->second,v);
	}

	int get(unsigned x)const{
		auto iter=val.find(x^f);
		return iter==end(val)?INT_MIN:iter->second+ofs;
	}

	void ff(unsigned x){
		f^=x;
	}

	void addall(int v){
		ofs+=v;
	}

	void merge(a mya){
		if(val.size()<mya.val.size())
			std::swap(*this,mya);
		auto const fx= mya.f ^ f;
		auto const ofsx= mya.ofs - ofs;
		for(auto [x,v]:mya.val)
			rawadd(x^fx,v+ofsx);
	}
};

a solve(int x){
	a total;
	total.add(0u, 0);
	int ans=0;
	for(int y:ad[x]){
		char c=val[y];
		a tmp=solve(y);
		tmp.ff(1u<<(c-'a'));
		tmp.addall(1);

		auto const& largeset= total.val.size()<tmp.val.size() ? tmp : total;
		auto const& smallset= total.val.size()<tmp.val.size() ? total : tmp;
		for(auto [rawx,rawval]:smallset.val){
			auto x=rawx^smallset.f;
			auto v=rawval+smallset.ofs;
			assert(v>=0);

			auto tmp2=largeset.get(x);
			if(tmp2!=INT_MIN){
				assert(tmp2>=0);
				ans=std::max(ans,v+tmp2);
			}

			for(char c='a';c<='v';++c){
				auto tmp2=largeset.get(x^(1u<<(c-'a')));
				if(tmp2!=INT_MIN){
					assert(tmp2>=0);
					ans=std::max(ans,v+tmp2);
				}
			}
		}
		total.merge(std::move(tmp));

		ans=std::max(ans,ansof[y]);
	}
	ansof[x]=ans;
	return total;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);val.resize(n);
	for(int i=1;i<n;++i){
		int j;
		std::cin>>j>>val[i];
		--j;
		ad[j].push_back(i);
	}

	ansof.resize(n);
	solve(0);
	for(auto ans:ansof)
		std::cout<<ans<<' ';
	std::cout<<'\n';
}