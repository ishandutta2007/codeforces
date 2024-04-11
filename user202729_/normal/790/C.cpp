// Somehow this problem took me a few days (!!!) to solve... the implementation time is short as usual. (~= 15 minutes)
#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<cassert>
#include<iostream>
#include<vector>
#include<string>
#include<array>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::string s;s.reserve(n);std::cin>>s;
#define n

	std::array<std::vector<int>,3> pos;
	std::array<std::vector<int>,3> cnt; // [char][i] -> n char == char int first i+1 chars of s
	for(auto& cnti:cnt)cnti.resize(s.size());

	for(unsigned i=0;i<s.size();++i){
		char& c=s[i];
		c=c=='V' ? 0 : c=='K' ? 1 : 2;
		pos[c].push_back(i);
		++cnt[c][i];
	}

	for(auto& cnti:cnt)
		for(unsigned i=1;i<s.size();++i)
			cnti[i]+=cnti[i-1];

	std::vector<std::vector<std::vector<std::array<int,2>>>> dp // n0, n1, n2, last_is_0 => min nswap for prefix
		(pos[0].size()+1,
		 std::vector<std::vector<std::array<int,2>>>(pos[1].size()+1,
			 std::vector<std::array<int,2>>(pos[2].size()+1,
				 {{INT_MAX,INT_MAX}}
				 )));

	dp[0][0][0][false]=0;

	for(int n0=0;n0<=(int)pos[0].size();++n0)
	for(int n1=0;n1<=(int)pos[1].size();++n1)
	for(int n2=0;n2<=(int)pos[2].size();++n2)
	for(int last_is_0=0;last_is_0<2;++last_is_0)if(dp[n0][n1][n2][last_is_0]<INT_MAX){
		int const cur_nswap=dp[n0][n1][n2][last_is_0];
		std::array<int,3> coord{{n0,n1,n2}};

		for(int nc=0;nc<3;++nc /* next char */)if(coord[nc]<(int)pos[nc].size()){
			if(nc==1 and last_is_0)continue;

			int added=0;
			auto const p=pos[nc][coord[nc]];
			for(int c=0;c<3;++c)if(c!=nc){
				added+=std::max(0,cnt[c][p]-coord[c]);
			}
			assert(cnt[nc][p]-coord[nc]==1);

			++coord[nc];
			auto& nxt=dp[coord[0]][coord[1]][coord[2]][nc==0];
			--coord[nc];

			nxt=std::min(nxt,cur_nswap+added);
		}

	}

	std::cout<<std::min(dp.back().back().back()[true], dp.back().back().back()[false])<<'\n';
}