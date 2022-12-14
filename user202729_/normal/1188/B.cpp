/*
 * Turns out the other method is indeed overkill.
 * [I have read the editorial (or equivalent).] (Too bad)
 */
#include<iostream>
#include<map>
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int MOD,n,k;std::cin>>n>>MOD>>k;
	std::map<int,int> cnt;
	int64_t ans =0;
	for(int z=n;z--;){
		int x;std::cin>>x;
		auto& c=cnt[(x*(int64_t)x%MOD*x%MOD*x+int64_t(MOD-k)*x)%MOD];
		ans+=c;
		++c;
	}
	std::cout<<ans<<'\n';
}