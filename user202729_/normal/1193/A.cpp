#define NDEBUG

#include<iostream>
#include<vector>
#include<cassert>
#include<unordered_map>

int nnode;
std::vector<int> ad;
std::vector<int> nad; // nad[i] = ~(1<<i|ad[i])

int const mod=998244353;
using ii=std::pair<int,int>;
std::vector<std::unordered_map<int,int>> mem; // [a][b]

/// Number of ways to order the edges int subset A such that all 
// vertices int B (B is a subset of A) are not top.
int f(int a,int b){
	if(a==b)return 0;
	assert(a!=0&&(a&b)==b);
	if((a^(a-1))>=a) // set A has 1 element
		return 1;

	auto iter=mem[a].find(b);
	if(iter!=end(mem[a]))
		return iter->second;

	int i=__builtin_ctz(a^b);
	// either that i is a top vertex
	int ans=f(a^(1<<i),b&nad[i]);
	// or i is not
	ans+=f(a,b|(1<<i));
	if(ans>=mod)ans-=mod;
	mem[a].insert({b,ans});
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nedge;
	std::cin>>nnode>>nedge;
	ad.resize(nnode);
	for(int _=nedge;_--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u]|=1<<v;
		ad[v]|=1<<u;
	}

	nad.resize(nnode);
	for(int i=nnode;i--;){
		nad[i]=~(1<<i|ad[i]);
	}

	mem.resize(1<<nnode);
	std::cout<<f((1<<nnode)-1,0)*(int64_t)nedge%mod
		*((mod+1)/2)%mod;
	std::cout<<'\n';
}