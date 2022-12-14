// :((((
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int size, numCell; std::cin>>size>>numCell;
	struct cell{int height, pos;};
	std::vector<cell> cells(numCell);
	for(auto &x: cells){
		std::cin>>x.height>>x.pos;
		x.height=size-x.height;
		--x.pos;
		assert(x.pos<size and x.pos>=0);
	}
	auto const cost=[](auto height){
		return (int64_t(height+1)*(height+2)>>1)+2;
	};
	std::sort(begin(cells),end(cells),[](cell one, cell two){
		return one.height<two.height;
	});
	numCell=-1;

	//std::vector<cell> single;
	int numSingle=0;
	while(not cells.empty() and cost(cells.back().height)>=3*(int)cells.size()){
		//single.push_back(cells.back());
		++numSingle;
		cells.pop_back();
	}
	//std::sort(begin(single),end(single),[](cell one, cell two){
	//	return one.pos!=two.pos?one.pos<two.pos: one.height>two.height;
	//});

	//auto const cover=[](auto parent, auto child){
	//	assert(parent.pos<=child.pos);
	//	return child.pos-parent.pos<=parent.height-child.height;
	//};

	//auto out=begin(single);
	//for(auto item:single){
	//	if(out!=begin(single) and cover(out[-1], item))
	//		continue;
	//	*out++=item;
	//}
	//single.erase(out,end(single));

	//cells.erase(std::remove_if(begin(cells),end(cells),[&](auto item){
	//	auto upper=std::lower_bound(begin(single),end(single), item,[](cell one, cell two){
	//		return one.pos<two.pos;
	//	});
	//	return upper!=single.end() and cover(*upper, item);
	//}), end(cells));

	std::vector<std::vector<int>> heightByPos(size);
	for(auto [height, pos]:cells){
		heightByPos[pos].push_back(height);
	}

	int maxHeight=0;
	while(cost(maxHeight)<3*(int)cells.size())
		++maxHeight;

	std::vector<int> minCost(maxHeight+1);
	for(auto & x: heightByPos) std::sort(begin(x),end(x));

	for(int pos=(int)heightByPos.size(); pos--;){
		auto const oldMinCost=minCost;
		auto const& curHeights=heightByPos[pos];

		auto iter=end(curHeights);
		minCost[0]=oldMinCost[0]+(int)curHeights.size()*3;

		for(int height=(int)minCost.size();height--;) {
			while(iter!=begin(heightByPos[pos]) and iter[-1]>height)
				--iter;
			minCost[0]=std::min(minCost[0],
					int(end(curHeights)-iter)*3+
					(int)cost(height)+oldMinCost[height]
					);
		}

		iter=end(curHeights);
		for(int height=(int)minCost.size();--height;) {
			while(iter!=begin(heightByPos[pos]) and iter[-1]>=height)
				--iter;
			minCost[height]=std::min(minCost[0],
					int(end(curHeights)-iter)*3+
					oldMinCost[std::max(height-1, 0)]
					);
		}
	}

	std::cout<<minCost[0]+3*numSingle<<'\n';
}