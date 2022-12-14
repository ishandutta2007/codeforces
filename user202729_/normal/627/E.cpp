// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int numRow, numCol, numViola, numExpected;
std::vector<std::vector<char>> have;

template<bool swapped>
int64_t work(int minX, int maxX, int minY, int maxY){ // return number of rectangles with number of viola inside >=numExpected
	assert(minX<maxX); assert(minY<maxY);
	if(maxX-minX>maxY-minY){
		return work<not swapped>(minY, maxY, minX, maxX);
	}
	auto const get=[&](auto x, auto y)->char{ // actually bool
		if(swapped) std::swap(x, y);
		return have[x][y];
	};

	if(maxY-minY==1) {
		assert(maxX-minX==1);
		return get(minX, minY) and numExpected==1;
	}

	auto const midY=(minY+maxY)>>1;
	struct Item{
		int x;
		std::array<std::vector<int>, 2> y; // {up (y>=midY), down (y<midY)}, store difference (smallest 0), each sorted by near to far
		// only take first (numExpected) elements
	};
	std::vector<Item> items; // sorted by x
	for(int x=minX; x<maxX; ++x){
		Item cur{x};
		for(int y=midY; y<maxY; ++y) if(get(x, y)) {
			cur.y[0].push_back(y-midY);
			if((int)cur.y[0].size()==numExpected) break;
		}
		for(int y=midY; y-->minY;) if(get(x, y)){
			cur.y[1].push_back(midY-y-1);
			if((int)cur.y[1].size()==numExpected) break;
		}
		if(not cur.y[0].empty() or not cur.y[1].empty())
			items.push_back(std::move(cur));
	}
	if(items.empty()) return 0;

	int64_t result{};
	for(int l=0; l<(int)items.size(); ++l){
		std::array<std::vector<int>, 2> data{{{0, maxY-midY}, {0, midY-minY}}}; // y coordinates difference merged
		std::vector<int> dataTemp;

		for(int r=l; r<(int)items.size(); ++r){
			for(int index=0; index<2; ++index) if(not items[r].y[index].empty()){
				dataTemp.clear();
				std::merge(begin(data[index]), end(data[index]),
						begin(items[r].y[index]), end(items[r].y[index]), std::back_inserter(dataTemp));
				if((int)dataTemp.size()>numExpected+2){
					dataTemp[numExpected+1]=dataTemp.back();
					dataTemp.resize(numExpected+2);
				}
				std::swap(data[index], dataTemp);
			}

			assert(data[0][0]==0);
			assert(data[0].back()==maxY-midY);
			assert(data[0].end()[-2]<maxY-midY);
			assert(data[1][0]==0);
			assert(data[1].back()==midY-minY);
			assert(data[1].end()[-2]<midY-minY);


			int64_t cur=0;
			for(int index=(int)data[0].size()-1; index--;){
				cur+=(data[0][index+1]-data[0][index])*
					(midY-minY-data[1][std::min((int)data[1].size()-1, numExpected-index)]);
			}
			if(int(data[0].size()+data[1].size())-4<numExpected) {
				assert(cur==0);
				continue;
			}
			assert(cur!=0);

			cur*=items[l].x-(l==0 ? minX-1: items[l-1].x);
			cur*=(r+1==(int)items.size() ? maxX: items[r+1].x)-items[r].x;
			result+=cur;
		}
	}

	return result+work<swapped>(minX, maxX, minY, midY)+work<swapped>(minX, maxX, midY, maxY);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	std::cin>>numRow>>numCol>>numViola>>numExpected;

	have.assign(numRow, std::vector<char>(numCol));
	for(int _=0; _<numViola; ++_){
		int x, y; std::cin>>x>>y;
		have[--x][--y]=true;
	}


	std::cout<<work<false>(0, numRow, 0, numCol)<<'\n';
}