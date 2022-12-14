#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::array<int, 19> add;

bool adjacent(int first, int sec){return bool(add[first]>>sec&1);}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numEdge; std::cin>>number>>numEdge;
	assert(number<=(int)add.size());
	for(int _=0; _<numEdge; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first]|=1<<sec;
		add[sec]|=1<<first;
	}

	std::vector<std::array<int64_t, 19>> count;
	int64_t result{};
	for(int node=number; node--;){
		count.clear(); count.resize(1<<(node+1));
		count[0][node]=1;
		for(int mask=0; mask<(int)count.size(); ++mask){
			for(int end=node; end>=0; --end)if(auto const cur=count[mask][end]){
				assert(not(mask>>end&1));
				// cur=number of paths from (node) to (end) passing through (mask)

				for(int tmp=
						add[end]&(~mask)&((1<<node)-1)
						; tmp;){
					auto const next=__builtin_ctz(tmp); tmp-=1<<next;
					assert(next!=end);
					assert(next<node);
					count[mask|(1<<end)][next]+=cur;
				}

				if(mask!=(1<<node) and (add[end]>>node&1))
					result+=cur;
			}
		}
	}
	std::cout<<result/2<<'\n';
}