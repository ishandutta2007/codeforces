#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnum,mod;std::cin>>nnum>>mod;
	std::vector<int> a(nnum);
	for(auto& ai:a)std::cin>>ai;

	int out=mod;
	for(int step=1<<20;step;step>>=1)if(out-step>=0){
		out-=step;
		int prevmin=0;
		for(int ai:a){
			// find min number int [ai .. (ai+out)%mod] >= prevmin
			int nxt=mod;
			auto const proclr=[&](int l,int r){
				if(r-1>=prevmin)
					nxt=std::min(nxt,std::max(l,prevmin));
			}; // half inc.sive

			if(ai+out<mod)
				proclr(ai,ai+out+1);
			else{
				proclr(ai,mod);
				proclr(0,ai+out+1-mod);
			}

			if(nxt<mod)
				prevmin=nxt;
			else{
				out+=step;
				goto nextstep;
			}
		}

nextstep:;
	}

	std::cout<<out<<'\n';
}