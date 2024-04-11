#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int len; std::cin>>len;
	std::vector<int> pos(len);
	for(int posX=0;posX<len;++posX) {
		int x; std::cin>>x;
		pos[--x]=posX;
	}
	
	std::set<int> empty;
	std::set<std::pair<int, int>> countEmpty;
	for(int it=0;it<len;++it) {
		empty.insert(empty.end(), it);
		countEmpty.insert(countEmpty.end(), {0, it});
	}
	for(auto pos_: pos){
		auto iterator=empty.find(pos_); assert(iterator!=empty.end());
		int const countPos=iterator==empty.begin() ? pos_: pos_-*std::prev(iterator)-1;
		assert(countEmpty.count({countPos, pos_}));
		if(countPos!=countEmpty.rbegin()->first){
			std::cout<<"No\n"; return;
		}

		countEmpty.erase(countEmpty.find({countPos, pos_}));
		iterator=empty.erase(iterator);
		if(iterator!=empty.end()){
			auto const oldCountPos1=*iterator-pos_-1;
			auto const newCountPos1=countPos+oldCountPos1+1;
			assert(countEmpty.count({oldCountPos1, *iterator}));
			countEmpty.erase(countEmpty.find({oldCountPos1, *iterator}));
			countEmpty.insert({newCountPos1, *iterator});
		}
	}

	std::cout<<"Yes\n";
}