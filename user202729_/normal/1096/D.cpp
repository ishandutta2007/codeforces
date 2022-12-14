#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<iterator>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;s.reserve(*std::istream_iterator<unsigned>(std::cin));
	std::cin>>s;
	std::vector<int> cost(s.size());for(int& x:cost)std::cin>>x;
	
	char const* avoidstr="hard";

	std::vector<std::array<int64_t,5>> dp(s.size()+1);
	// dp[prefix][prefix length to avoid] = min cost
	dp[0][0]=(int64_t)1e16;
	for(unsigned plen=1;plen<dp.size();++plen){
		for(int i=0;i<5;++i){
			dp[plen][i]=std::min(
					// remove s[plen-1]
					cost[plen-1]+dp[plen-1][i],
					// not remove s[plen-1]
					dp[plen-1][(i!=0&&s[plen-1]==avoidstr[i-1])?i-1:i]
					);
		}
	}
	std::cout<<dp[s.size()][4]<<'\n';
}