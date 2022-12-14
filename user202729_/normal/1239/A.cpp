#include<iostream>
#include<vector>

int const MOD=1000000007;


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	std::vector<int> a(std::max(m,n)+2);
	a[1]=2;
	a[2]=4;
	for(unsigned i=3;i<a.size();++i)
		a[i]=(a[i-1]+a[i-2])%MOD;

	int ans=(a[n]-2+a[m]-2 + 2)%MOD;
	std::cout<<ans<<'\n';
}