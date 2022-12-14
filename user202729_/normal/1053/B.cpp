#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<array>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n;std::cin>>n;
	std::vector<char> prefix_parity;
	prefix_parity.reserve(n+1);prefix_parity.push_back(0);
	std::vector<int> nbit(n);
	int maxbitall=0;
	for(auto& nbiti:nbit){
		int64_t ai;
		std::cin>>ai;
		nbiti=__builtin_popcountll(ai);
		assert(nbiti>0);
		maxbitall= std::max(maxbitall,nbiti);
		prefix_parity.push_back(prefix_parity.back()^(nbiti&1));
	}

	std::vector<std::array<int,2>> cntr(n+1);
	for(int p=0;p<2;++p)
		cntr.back()[p]=prefix_parity.back()==p;

	for(int i=n;i--;)
		for(int p=0;p<2;++p)
			cntr[i][p]=cntr[i+1][p]+(prefix_parity[i]==p);

	int64_t out=0;
	for(int l=0;l<n;++l){
		for(int r=l+1,maxbit=nbit[l],sumbit=nbit[l];
				;
				maxbit=std::max(maxbit,nbit[r]),
				sumbit+=nbit[r],
				++r
				){
			if(2*maxbitall<=sumbit){
				out+=cntr[r][prefix_parity[l]];
				break;
			}

			if(prefix_parity[l]==prefix_parity[r] and 2*maxbit<=sumbit)
				++out;
			if(r==n)
				break;
		}
	}
	std::cout<<out<<'\n';
}