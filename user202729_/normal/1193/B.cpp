#include<iostream>
#include<vector>
#include<map>

std::vector<std::vector<int>> ad;
std::vector<int> weight,day;

using Fn=std::map<int,int64_t>;

Fn merge(Fn a,Fn b){
	if(a.size()<b.size())
		std::swap(a,b);
	for(auto p:b){
		auto result=a.insert(p);
		bool success=result.second;
		if(!success)
			result.first->second+=p.second;
	}
	return a;
}

Fn dfs(int x){ // time -> value change, repr a nondec func of time -> ans
	Fn ans;
	for(int y:ad[x])
		ans=merge(std::move(ans),dfs(y));
	if(weight[x]){
		int wleft=weight[x];
		auto iter=ans.insert({day[x],0}).first;
		auto nxt=std::next(iter);
		while(wleft){
			if(nxt==end(ans)){
				iter->second+=wleft;
				break;
			}
			if(wleft<nxt->second){
				iter->second+=wleft;
				nxt->second-=wleft;
				break;
			}
			wleft-=int(nxt->second);
			iter->second+=nxt->second;
			nxt=ans.erase(nxt);
		}
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nfruit,maxday;std::cin>>nnode>>nfruit>>maxday;
	ad.resize(nnode);
	for(int i=1;i<nnode;++i){
		int p;std::cin>>p;--p;
		ad[p].push_back(i);
	}

	weight.resize(nnode);day.resize(nnode);
	for(int _=nfruit;_--;){
		int vertex,dayi,weighti;std::cin>>vertex>>dayi>>weighti;
		weight[--vertex]=weighti;
		day[vertex]=dayi;
	}
	auto ans=dfs(0);
	int64_t ans_=0;
	for(auto p:ans)
		ans_+=p.second;
	std::cout<<ans_<<'\n';
}