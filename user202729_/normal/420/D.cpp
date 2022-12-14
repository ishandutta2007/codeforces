//http://codeforces.com/contest/420/problem/D
#include<iostream>
#include<vector>
#include<functional>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int nCup,nOperation;
	std::cin>>nCup>>nOperation;
	__gnu_pbds::tree<int,int,std::less<int>,__gnu_pbds::rb_tree_tag,
			__gnu_pbds::tree_order_statistics_node_update> cups;
	// position id -> cup ID (0 .. n-1)
	// initially the cups are ordered in increasing ID
	std::vector<int> cupMarkWithId(nCup); // or 0 if not known
	for(int cupId=0;cupId<nCup;++cupId)
		cups.insert({cupId,cupId});
	int lastUsedPositionId=0;
	while(nOperation--){
		int mark,position;std::cin>>mark>>position;--position;
		auto it=cups.find_by_order(position);
		int cupId=it->second;
		if(cupMarkWithId[cupId]==0)
			cupMarkWithId[cupId]=mark;
		else if(cupMarkWithId[cupId]!=mark){
			std::cout<<"-1\n";
			return 0;
		}
		cups.erase(it);
		cups.insert({--lastUsedPositionId,cupId});
	}
	
	std::vector<char> markIsUsed(nCup+1,false); // index 0 not used
	for(int cupId=0;cupId<nCup;++cupId){
		int mark=cupMarkWithId[cupId];
		if(mark==0)continue;
		if(markIsUsed[mark]){
			std::cout<<"-1\n";
			return 0;
		}
		markIsUsed[mark]=true;
	}
	std::vector<int> unusedMarks;unusedMarks.reserve(nCup);
	for(int mark=nCup;mark;--mark)
		if(!markIsUsed[mark])
			unusedMarks.push_back(mark);

	for(int& x:cupMarkWithId)
		if(x==0){
			x=unusedMarks.back();
			unusedMarks.pop_back();
		}

	// this is probably not possible but anyway
	if(not unusedMarks.empty()){
		std::cout<<"-1\n";
		return 0;
	}

	for(int& x:cupMarkWithId)
		std::cout<<x<<' ';
	std::cout<<'\n';
			

}