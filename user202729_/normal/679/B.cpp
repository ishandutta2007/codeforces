#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>
#include<cmath>

int64_t cube(int x){return (int64_t)x*x*x;}

std::vector<int> const dp=[]{
	std::vector<int> dp(100);
	dp[0]=0;
	for(unsigned i=1,j=1;i<dp.size();++i){
		while(cube(j+1)<=i)
			++j;
		dp[i]=1+dp[i-cube(j)];
	}
	return dp;
}();

int floor_cbrt(int64_t x){
	auto sign=(x>0)-(x<0);
	auto ans=2+sign*(int)std::pow(x*sign,1./3);
	while(cube(ans)>x) --ans;
	return ans;
}

int ceil_cbrt(int64_t x){
	auto sign=(x>0)-(x<0);
	auto ans=-2+sign*(int)std::pow(x*sign,1./3);
	while(cube(ans)<x) ++ans;
	return ans;
}

std::pair<int,int64_t> solve(int64_t l,int64_t r);

std::pair<int,int64_t> solve_(int64_t l,int64_t r){
	if(l>=r)
		return {-1,-1};
	if(r<dp.size()){
		std::pair<int,int64_t> ans{-1,-1};
		for(auto x=l;x<r;++x)
			ans=std::max(ans,{dp[x],x});
		return ans;
	}

	auto x=floor_cbrt(r-1);
	if(floor_cbrt(l)==x){
		auto ans=solve(l-cube(x),r-cube(x));
		++ans.first;
		ans.second+=cube(x);
		return ans;
	}

	auto l1=ceil_cbrt(l-1);
	auto r2=floor_cbrt(r);
	assert(l1<=r2);
	auto ans=std::max(solve(l,cube(l1)),solve(cube(r2),r));
	if(l1<r2)
		ans=std::max(ans,solve(cube(r2-1),cube(r2)));
	return ans;
}

std::pair<int,int64_t> solve(int64_t l,int64_t r){
	auto ans=solve_(l,r);
#ifdef LOCAL
	if(l<r){
		std::cerr<<l<<' '<<r<<' '<<ans.first<<' '<<ans.second<<'\n';
		assert(l<=ans.second&&ans.second<r);
	}else{
		assert(ans.first<0);
	}
#endif
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t n;std::cin>>n;
	auto ans=solve(1,n+1);
	std::cout<<ans.first<<' '<<ans.second<<'\n';
}