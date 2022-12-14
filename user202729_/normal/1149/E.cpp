#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

#define r(x) begin(x),end(x)

std::vector<std::vector<int>> ad;


std::vector<int> fm; // f memoization
std::vector<bool> tmp;
int f(int x){
	if(fm[x]>=0)
		return fm[x];

	for(int y:ad[x])
		f(y);
	for(int y:ad[x])
		tmp[fm[y]]=true;
	fm[x]=int(std::find(begin(tmp),end(tmp),false)-begin(tmp));
	for(int y:ad[x]){
		tmp[fm[y]]=false;
	}
	return fm[x];
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	std::vector<int> h(n);for(int& x:h)std::cin>>x;

	ad.resize(n);
	for(int z=m;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
	}

	std::vector<int> val(n); // nim value of the whole game
	fm.assign(n,-1);
	tmp.resize(n);
	for(int i=n;i--;)
		val[f(i)]^=h[i];
	while(!val.empty()&&val.back()==0)
		val.pop_back();
	if(val.empty()){
		std::cout<<"LOSE\n";
		return 0;
	}

	std::cout<<"WIN\n";
	int i=0;
	while(fm[i]!=val.size()-1||(h[i]^val.back())>h[i]){
		++i;
	}

	h[i]^=val.back();
	std::vector<bool> ok(val.size()-1);
	for(int j:ad[i])if((unsigned)fm[j]<ok.size()&&!ok[fm[j]]){
		ok[fm[j]]=true;
		h[j]^=val[fm[j]];
	}

	for(auto x:h)std::cout<<x<<' ';
	std::cout<<'\n';
}