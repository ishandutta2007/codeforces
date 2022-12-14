#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,maxchange;std::cin>>n>>maxchange;
	std::vector<std::string> t(n);
	for(auto& row:t){
		std::cin>>row;
	}

	int maxl=0;
	bool dbg_check=false;

	std::vector<std::vector<int>> dp(n,std::vector<int>(n));
	// dp[i][j] = max # of 'a' on any path (0,0)..(i,j)
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j){
		if(i) dp[i][j]=dp[i-1][j];
		if(j) dp[i][j]=std::max(dp[i][j],dp[i][j-1]);
		if(t[i][j]=='a') ++dp[i][j];

		// check if it's possible for all cells on that path to be 'a' after making maxchange changes
		if(dp[i][j]+maxchange>=i+j+1){
			if(i+j+1>maxl) dbg_check=false;
			maxl=std::max(maxl,i+j+1);
			if(dp[i][j]+maxchange==i+j+1) dbg_check=true;
		}
	}

	if(maxl<2*n-1)
		assert(dbg_check==(maxl>0));

	std::string out;out.reserve(2*n-1);out.assign(maxl,'a');
	std::vector<char> ok(n); // indices of i such that there exists j s.t. i+j+1 == maxl and
	// there exists a smallest possible string (0,0) .. (i..j), or (i..j) overflows

	if(maxl==0){
		maxl=1;
		out.push_back(t[0][0]);
		ok[0]=true;
	}else{
		for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)if(maxl==i+j+1){
			if(dp[i][j]+maxchange>=i+j+1){
				ok[i]=true;
			}
		}
	}

	std::vector<char> nxt; // temp

	while((int)out.size()<2*n-1){
		char minc=127;
		for(int i=0;i<n;++i)if(ok[i]){
			int j=maxl-1-i;
			if(j<0 or j>=n)continue;
			if(i<n-1) minc=std::min(minc,t[i+1][j]);
			if(j<n-1) minc=std::min(minc,t[i][j+1]);
		}
		assert(minc<127);
		out+=minc;

		nxt.assign(n,false);
		for(int i=0;i<n;++i)if(ok[i]){
			int j=maxl-1-i;
			if(j<0 or j>=n)continue;
			if(i<n-1 and minc==t[i+1][j])nxt[i+1]=true;
			if(j<n-1 and minc==t[i][j+1])nxt[i]=true;
		}

		std::swap(ok,nxt);
		++maxl;
	}
	if(not nxt.empty()){
		assert(std::all_of(begin(ok),--end(ok),[](char x){return not x;}));
		assert(ok.back());
	}

	assert((int)out.size()==2*n-1);
	for(char c:out)
		assert('a'<=c and c<='z');
	std::cout<<out<<'\n';
}