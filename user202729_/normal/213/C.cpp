#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<std::vector<int>> a(n);
	for(auto& row:a){
		row.resize(n);for(int& x:row)std::cin>>x;
	}

	std::vector<std::vector<int>> dp(n,std::vector<int>(n,INT_MIN)); // [col1][col2]
	dp[0][0]=a[0][0];

	std::vector<std::vector<int>> nextdp; // temp

	for(int sum=0;sum<2*n-2;++sum){
		nextdp.resize(n); for(auto& r:nextdp) r.assign(n,INT_MIN);

		for(int c1=0;c1<n;++c1)
		for(int cur,c2=0;c2<n;++c2)if((cur=dp[c1][c2])!=INT_MIN){
			for(int dc1=(sum-c1==n-1 ? 1 : 0);dc1<(c1==n-1 ? 1 : 2);++dc1)
			for(int dc2=(sum-c2==n-1 ? 1 : 0);dc2<(c2==n-1 ? 1 : 2);++dc2)
				nextdp[c1+dc1][c2+dc2]=std::max(nextdp[c1+dc1][c2+dc2],
						cur
						+a[sum+1-c1-dc1][c1+dc1]
						+(c1+dc1==c2+dc2 ? 0 : a[sum+1-c2-dc2][c2+dc2])
						); // boring...?
		}

		std::swap(dp,nextdp);
	}

	std::cout<<dp[n-1][n-1]<<'\n';
}