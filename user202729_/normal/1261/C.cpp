#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

std::vector<std::string> t;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol;std::cin>>nrow>>ncol;
	t.resize(nrow);
	for(auto& row:t){
		row.reserve(ncol);
		std::cin>>row;
		assert((int)row.size()==ncol);
	}
	
	std::vector<std::vector<int>> dp(nrow); // max square size with top left at
	for(int r=nrow;r--;){
		dp[r].resize(ncol);
		for(int c=ncol;c--;){
			if(t[r][c]=='.') dp[r][c]=0;
			else if(r==nrow-1 or c==ncol-1) dp[r][c]=1;
			else dp[r][c]=1+std::min({dp[r][c+1],dp[r+1][c],dp[r+1][c+1]});
		}
	}

	std::vector<std::vector<int>> acm(nrow+1);
	int time=0;
	for(int step=1<<21;step;step>>=1)if(2*(time+step)+1<=std::min(nrow,ncol)){
		time+=step;
		for(int r=nrow+1;r--;){
			acm[r].assign(ncol+1,0);
		}
		int const sqside=2*time+1;
		for(int r=nrow;r--;)
		for(int c=ncol;c--;)
			if(dp[r][c]>=sqside){
				++acm[r][c];
				--acm[r][c+sqside];
				--acm[r+sqside][c];
				++acm[r+sqside][c+sqside];
			}

		for(int r=0;r<nrow-1;++r)
		for(int c=0;c<ncol;++c)
			acm[r+1][c]+=acm[r][c];

		for(int r=0;r<nrow;++r)
		for(int c=0;c<ncol-1;++c)
			acm[r][c+1]+=acm[r][c];

		for(int r=0;r<nrow;++r)
		for(int c=0;c<ncol;++c)
			if(t[r][c]=='X' and acm[r][c]==0){
				time-=step;
				goto nextstep;
			}
nextstep:;
	}
	std::cout<<time<<'\n';
	int const sqside=2*time+1;
	for(int r=0;r<nrow;++r){
		for(int c=0;c<ncol;++c)
			std::cout<<((r>=time and c>=time and dp[r-time][c-time]>=sqside) ? 'X' : '.');
		std::cout<<'\n';
	}
}