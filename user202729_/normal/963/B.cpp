#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> ad;

void delvert(int x){ std::cout<<x+1<<'\n'; }

void dd2(int x){ // delete subtree rooted at x. Parent of x must be deleted
	assert(ad[x].size()%2==0);
	delvert(x);
	for(int y:ad[x]) dd2(y);
}

bool dd(int x,bool havepar){ // return (x is deleted)
	ad[x].erase(std::remove_if(begin(ad[x]),end(ad[x]),[&](int y){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		bool y_removed =dd(y,true);
		return y_removed;
	}),end(ad[x]));

	if((ad[x].size()+havepar)%2!=0){ // cannot remove this now
		return false;
	}else{
		delvert(x);
		for(auto y:ad[x]) dd2(y);
		return true;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int i=0;i<n;++i){
		int p;std::cin>>p;
		if(p>0){
			--p;
			ad[p].push_back(i);
			ad[i].push_back(p);
		}
	}
	if(n%2==0){
		std::cout<<"NO\n";
		return 0;
	}
	std::cout<<"YES\n";
	auto root_deleted =dd(0,false);
	assert(root_deleted);
}