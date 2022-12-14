#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n); for(auto& x:a) std::cin>>x;
	std::multiset<int> p;
	for(int z=n;z--;){
		int pi;std::cin>>pi;
		p.insert(pi);
	}

	for(auto ai:a){
		int l=0,step=1<<30;
		while(step>1){
			assert((l&(-step))==l);
			assert((1<<__builtin_ctz(step))==step);

			int pl=(ai&(-(step>>1))) xor l;
			assert((pl&(-(step>>1)))==pl);
			auto iter=p.lower_bound(pl);
			if(iter!=end(p) and *iter<pl+(step>>1)){
				// good
			}else{
				l+=step>>1;
			}

			step>>=1;
		}
		std::cout<<l<<' '; // found o[i] value
		p.erase(p.find(l xor ai));
	}
	std::cout<<'\n';
}