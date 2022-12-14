#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

int const MOD=1000000007;
int add(int a,int b){
	a+=b;if(a>=MOD)a-=MOD;
	return a;
}
int sub(int a,int b){
	return add(a,MOD-b);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol;std::cin>>nrow>>ncol;
	std::vector<std::string> t(nrow);
	for(auto& row:t){
		row.reserve(ncol);std::cin>>row;
	}

	if(t.back().back()=='R'){
		std::cout<<"0\n";
		return 0;
	}

	std::vector<std::vector<int>> sumd(nrow+1,std::vector<int>(ncol));
	for(int r=nrow;r--;){
		std::transform(begin(sumd[r+1]),end(sumd[r+1]),begin(t[r]),
				begin(sumd[r]),[](int cnt,char c){return cnt+(c=='R');});
	}

	std::vector<std::vector<int>> sumr(nrow); // accumulate rock count to the right
	std::transform(begin(t),end(t),begin(sumr),[](std::string const& s){
			std::vector<int> ans(s.size());
			ans.back()=s.back()=='R';
			for(unsigned i=s.size()-1;i--;)
				ans[i]=ans[i+1]+(s[i]=='R');
			return ans;
		});

	// dp functions. f[r][c] = number of ways to go from r,c to goal
	// if last move is {f}
	std::vector<std::vector<int>> down(nrow+1,std::vector<int>(ncol+1));
	std::vector<std::vector<int>> right(nrow+1,std::vector<int>(ncol+1));

	// right/down accumulation of the above functions.
	std::vector<std::vector<int>> downs(nrow+1,std::vector<int>(ncol+1));
	std::vector<std::vector<int>> rights(nrow+1,std::vector<int>(ncol+1));

	down[nrow][ncol-1]=1;
	std::fill(begin(downs.back()),--end(downs.back()),1);

	right[nrow-1][ncol]=1;
	std::for_each(begin(rights),--end(rights),[](auto& z){
			z.back()=1;
			});

	for(int r=nrow;r--;)
	for(int c=ncol;c--;){
		down[r][c] =sub(rights[r][c+1],rights[nrow-sumd[r][c]][c+1]);
		right[r][c]=sub(downs[r+1][c],downs[r+1][ncol-sumr[r][c]]);

		/*
		down[r][c] =r==nrow-1&&c==ncol-1 ? 1 : sub(rights[r][c+1],rights[nrow-sumd[r][c]][c+1]);
		right[r][c]=r==nrow-1&&c==ncol-1 ? 1 : sub(downs[r+1][c],downs[r+1][ncol-sumr[r][c]]);
		*/

		downs[r][c]=add(downs[r][c+1],down[r][c]);
		rights[r][c]=add(rights[r+1][c],right[r][c]);
	}

	std::cout<<down[0][0]<<'\n';
}