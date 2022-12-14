/*
 * I have read the editorial :(
 *
 * initially I considered counting the complement like the ballot problem, but I can't figure
 * out how to "flip" it such that the endpoints are fixed and quickly skip through that possibility.
 * I even considered using generating function without success, just to solve the
 * easier version of the problem (without #) 
 *
 * Total implementation time: 10 min.
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

int const MOD=1000000007;
int nrow,ncol;
std::vector<std::vector<int>> a; // number of ways to move from [cur] to a particular cell (X)
std::vector<std::string> t; // table ('.' or '#')

void solve(int r,int c){ // set cell X to (r,c) and update a
	a.assign(nrow+1,std::vector<int>(ncol+1,0));
	for(int i=r;i>=0;--i)
	for(int j=c;j>=0;--j)
		if(t[i][j]=='.')
			a[i][j]=(i==r and j==c)?1:((a[i+1][j]+a[i][j+1])%MOD);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nrow>>ncol;
	t.resize(nrow);
	for(auto& r:t){r.resize(ncol);std::cin>>r;}
	solve(nrow-2,ncol-1);
	auto m=a[0][1];
	auto n=a[1][0];
	solve(nrow-1,ncol-2);
	std::cout<<(m*(int64_t)a[1][0]+(MOD-n)*(int64_t)a[0][1])%MOD<<'\n';
}