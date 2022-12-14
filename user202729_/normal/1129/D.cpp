#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<vector>
#include<cassert>
#include<map>
#include<iostream>

int const MOD=998244353;

void add(int& a,int b){
	assert(0<=a and a<MOD);
	assert(0<=b and b<MOD);
	a+=b;
	if(a>=MOD)
		a-=MOD;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,maxu;std::cin>>n>>maxu;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	std::vector<int> dp(n+1);

	std::vector<int> b(n); // b[j] + boffset[n/BLOCKSIZE] = number of unique elems int j..i
	std::map<int,std::pair<int,int>> lastind; // val -> {most recent ocr, second most recent ocr or -1}

	int const BLOCKSIZE=300;
	int const nblock=(n-1)/BLOCKSIZE+1;

	std::vector<int> boffset(nblock);
	std::vector<std::vector<int>> bsum(nblock); // bsum[block][i] = sum of dp values int block block with b (ignore boffset) <= i.

	auto const updateb=[&](int n,int delta){
		int const blockn=n/BLOCKSIZE;
		for(int i=blockn;i--;)
			boffset[i]+=delta;

		if(n%BLOCKSIZE!=0){
			for(int j=n%BLOCKSIZE;j;--j){
				b[n-j]+=delta;
			}

			auto first=begin(b)+BLOCKSIZE*blockn;
			auto last=begin(b)+std::min((int)b.size(),BLOCKSIZE*(blockn+1));

			// recompute bsum[blockn]
			int of1=*std::min_element(first,last);
			if(of1){
				std::transform(first,last,first,[of1](int x){return x-of1;});
				boffset[blockn]+=of1;
			}

			auto& bsum_cur=bsum[blockn];
			bsum_cur.assign(*std::max_element(first,last)+1, 0);
			std::for_each(first,last,[&](int& x){
					add(bsum_cur[x], dp[&x-&b[0]]);
					});

			std::for_each(++begin(bsum_cur),end(bsum_cur),[&](int& x){
					add(x,(&x)[-1]);
					});
		}
	};

	auto const getle=[&](){
		// sum(dp[i] for i if b[i]<=maxu) % MOD
		int64_t ans=0;
		for(int blocki=0;blocki<nblock;++blocki)if(not bsum[blocki].empty()){
			int x=maxu-boffset[blocki];
			if(x>=0)
				ans+=bsum[blocki][std::min(x,(int)bsum[blocki].size()-1)];
		}
		return int(ans%MOD);
	};

	auto const setdp=[&](int i,int val){
		// update data structures
		int const blocki=i/BLOCKSIZE;
		assert(b[i]==0 || !(std::cerr<<b[i]<<' '<<i<<' '<<boffset[blocki]<<'\n'));
		assert(boffset[blocki]==0);
		if(bsum[blocki].empty())
			bsum[blocki].assign(1,val);
		else
			std::transform(begin(bsum[blocki]),end(bsum[blocki]),begin(bsum[blocki]),
					[val](int x){add(x,val);return x;});
	};

	setdp(0,dp[0]=1);
	for(int i=1;i<=n;++i){
		auto [iter,success]=lastind.insert({a[i-1], {i-1,-1} });
		if(!success){
			updateb(iter->second.first+1,-2);
			if(iter->second.second>=0){
				updateb(iter->second.second+1,1);
			}else{
				// second occurence
			}
			iter->second ={i-1, iter->second.first};
		}else{
			// first occurence
		}

		updateb(i,1);
		dp[i]=getle();

		if(i<n){
			setdp(i,dp[i]);
		}
	}
	std::cout<<dp[n]<<'\n';
}