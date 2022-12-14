#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

std::vector<int> par,nless;
std::vector<int> postorder;
std::vector<int> val;
std::vector<std::vector<int>> ad;
int firstunused=1;

struct no_solution_error{};

void dd(int x){
	auto first=val.size();
	auto firstval=firstunused;
	for(int y:ad[x]){
		dd(y);
	}

	if(nless[x]>firstunused-firstval)
		throw no_solution_error{};
	
	int valx=firstval+nless[x];
	for(auto& x:val)
		if(x>=valx)
			++x;
	postorder[x]=val.size();
	val.push_back(valx);

	++firstunused;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	par.resize(n);
	int root=-1;
	nless.resize(n);
	ad.resize(n);
	for(int i=0;i<n;++i){
		std::cin>>par[i]>>nless[i];
		--par[i];
		if(par[i]<0)
			root=i;
		else
			ad[par[i]].push_back(i);
	}
	assert(root>=0);

	postorder.resize(n);
	val.reserve(n);
	try{
		dd(root);
	}catch(no_solution_error){
		std::cout<<"NO\n";
		return 0;
	}

	std::cout<<"YES\n";
	for(auto x:postorder){
		std::cout<<val[x]<<' ';
	}
	std::cout<<'\n';
}