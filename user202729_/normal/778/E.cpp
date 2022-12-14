/*
 * After having the solution, the implementation doesn't take very long, expect that it's necessary to consider
 * (and debug) the case when cost of zero is > 0.
 * 
 * Total implementation time: 59 minutes. (can be determined
 * with the Vim plugin Mundo)
 * (!! how is this consider "not very long" ??)
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<array>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::string a;std::cin>>a>>n;
	auto maxlen=a.size();
	std::vector<std::string> b(n);for(auto& x:b){
		std::cin>>x;
		maxlen=std::max(maxlen,x.size());
	}
	std::array<int,10> cost;for(auto& x:cost)std::cin>>x;

	auto const l=int(maxlen+1);

	auto lead=int(l-a.size());
	assert(a[0]!='0');
	int const nilmark='0'-1; // mark unused leading zero
	a.insert(begin(a),lead,nilmark);
	for(auto& x:b){
		assert(x[0]!='0');
		x.insert(begin(x),l-x.size(),nilmark);
	}

	std::vector<std::vector<int>> dp(l+1,std::vector<int>(n+1,-1)); // [startindex][ncarry] = max cost
	dp[l][0]=0;
	std::vector<int> ind(n); // sorted by decreasing suffix value
	std::iota(begin(ind),end(ind),0);
	for(int i=l;i;--i){
		if(i<l)
			std::stable_sort(begin(ind),end(ind),[&](int x,int y){
					return std::max('0',b[x][i])>std::max('0',b[y][i]);
					});

		char const na=std::max('0',a[i-1]);
		bool anil=a[i-1]==nilmark;

		std::array<int,10> cn{},cc{}; // count digit 0-9 at position i-1 (carry or not carry)
		// exclude nil if anil
		for(auto const& x:b){
			auto c=x[i-1];
			if(not anil or c!=nilmark) ++cn[std::max(0,c-'0')];
		}

		for(int ncarry=0;;){
			auto costi=dp[i][ncarry];
			if(costi>=0){
				auto const process =[&](int digit){
					int newcost=costi,new_ncarry=0;
					auto const proc2 =[&](int newdigit,int cnt){
						if(newdigit>=10){
							newdigit-=10;
							new_ncarry+=cnt;
						}
						newcost+=cost[newdigit]*cnt;
					};

					for(int k=0;k<10;++k){
						proc2(k+digit,cn[k]);
						proc2(k+digit+1,cc[k]);
					}
					dp[i-1][new_ncarry]=std::max(dp[i-1][new_ncarry],newcost);
				};

				if(na=='?') // complexity 1000**2 * 10**2 ?
					for(int digit=(i-1==lead ? 1 : 0);digit<10;++digit)
						process(digit);
				else
					process(na-'0');
			}

			if(ncarry==n){
				assert(std::all_of(begin(cn),end(cn),[](int x){return x==0;}));
				break;
			}

			{
				auto c=b[ind[ncarry]][i-1];
				if(not anil or c!=nilmark) --cn[std::max(0,c-'0')];
			}
			++cc[std::max(0,b[ind[ncarry]][i-1]-'0')];
			++ncarry;
		}
	}
	std::cout<<dp[0][0]<<'\n';
}