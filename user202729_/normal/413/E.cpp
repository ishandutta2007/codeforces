// http://codeforces.com/problemset/problem/413/E

#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>

#ifdef _GLIBCXX_DEBUG
#define cin cin_
#include<sstream>
namespace std{std::stringstream cin(R"(
10 3
X...X..X..
..X...X..X
11 7
7 18
18 10


)");}
#endif

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	
	int width,nQuery;std::cin>>width>>nQuery;
	std::string l0,l1;
	l0.reserve(width);std::cin>>l0;
	l1.reserve(width);std::cin>>l1;

	std::vector<int> obstCols;
	for(int i=0;i<width;++i)if(l0[i]=='X'||l1[i]=='X')obstCols.push_back(i);

	// values of (i) such that it's not possible to reach col[i] from col[i-1]
	std::vector<int> impassableCols={0}; // of course col[-1] can't reach col[0]
	for(int i=1;i<width;++i){
		if(
			(l0[i-1]=='X'&&l1[i-1]=='X')||
			(l0[i  ]=='X'&&l1[i  ]=='X')||
			(l0[i-1]=='X'&&l1[i  ]=='X')||
			(l0[i  ]=='X'&&l1[i-1]=='X')
		)
			impassableCols.push_back(i);
	}
	impassableCols.push_back(width); // another dummy value

	std::vector<int> distLeftmostReachable(obstCols.size());
	int lastImpassableIndex=0,lastDist=0,lastCol=0,lastRow=l0[0]=='X';
	for(unsigned i=0;i<obstCols.size();++i){
		int const col=obstCols[i];
		int const row=l0[col]=='X' /* ?1:0 */;

		while(impassableCols[lastImpassableIndex+1]<=col){
			++lastImpassableIndex;
			lastDist=0;
			lastCol=impassableCols[lastImpassableIndex];
			lastRow=l0[lastCol]=='X';
		}

		assert(lastCol<=col);
		lastDist+=(col-lastCol)+(lastRow^row);
		lastCol=col;lastRow=row;
		distLeftmostReachable[i]=lastDist;
	}

	while(nQuery-->0){
		std::array<int,2> row,col;
		for(int i=0;i<2;++i){
			int index;std::cin>>index;--index;
			if((row[i]=index>=width))index-=width;
			col[i]=index;
		}

		if(col[0]>col[1]){
			std::swap(row[0],row[1]);
			std::swap(col[0],col[1]);
		}else if(col[0]==col[1]){
			std::cout<<(row[0]^row[1])<<'\n';
			continue;
		}

		if(*std::upper_bound(impassableCols.begin(),impassableCols.end(),col[0])<=col[1]){
			std::cout<<"-1\n";
			continue;
		}

		auto it=std::upper_bound(obstCols.begin(),obstCols.end(),col[0]);
		if(it==obstCols.end()||*it>=col[1]){ // no obstacles (strictly) between
			std::cout<<(col[1]-col[0])+(row[0]^row[1])<<'\n';
			continue;
		}

		// otherwise *it is the first column with an obstacle 
		auto i2=std::lower_bound(obstCols.begin(),obstCols.end(),col[1]);
		assert(i2!=obstCols.begin());--i2;
		std::cout<<
			(*it-col[0])+((l0[*it]=='X')^row[0]) +
			distLeftmostReachable[i2-obstCols.begin()]-distLeftmostReachable[it-obstCols.begin()] +
			(col[1]-*i2)+((l0[*i2]=='X')^row[1])
		<<'\n';
	}
}