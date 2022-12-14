#include<iostream>
#include<vector>
#include<cmath>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<std::vector<int>> a(n,std::vector<int>(n));
	for(auto& r:a)for(int& x:r)std::cin>>x;
	for(int i=0;i<n;++i)
		std::cout<<(int)std::round(std::sqrt(
					a[i][(i+1)%n]*(int64_t)a[i][(i+2)%n]/a[(i+1)%n][(i+2)%n]
					))<<' ';
	std::cout<<'\n';
}