// :( I should have tried to solve the problem in O(dsu(n)) before reading the editorial...
// 10
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Dsu{
	std::vector<int> data;
	Dsu(int number): data(number, -1){}
	int root(int node){return data[node]<0 ? node: data[node]=root(data[node]);}
	void join(int first, int sec){
		first=root(first); sec=root(sec);
		if(first==sec) return;
		if(data[first]>data[sec]) std::swap(first, sec);
		if(data[first]==data[sec]) --data[first];
		data[sec]=first;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow, numCol, numQuery; std::cin>>numRow>>numCol>>numQuery;
	if(numCol==1){std::cout<<"0\n"; return 0;}

	int result{};
	Dsu dsu(numRow*numCol*2);
	auto const index=[&](int row, int col){return row+col*numRow;};
	std::vector<std::vector<char>> have(numRow, std::vector<char>(numCol));

	for(int _=0; _<numQuery; ++_){
		int row, col; std::cin>>row>>col; --row;--col;
		std::array<std::vector<int>, 2> roots;

		for(int row1=std::max(0, row-1); row1<std::min(numRow, row+2);++row1)
			for(int col1=col-1; col1<col+2;++col1)
				if(row1!=row or col1!=col){
					for(int index1=0; index1<2; ++index1){
						auto col2=col1+index1*numCol;
						if(col2<0) col2+=numCol*2;
						else if(col2>=numCol*2) col2-=numCol*2;

						auto const i=index(row1, col2);
						if(index1==0){
							if(not have[row1][col2-(col2>=numCol ? numCol: 0)]) break;
						}
						roots[index1].push_back(dsu.root(i));
					}
				}

		for(auto& it: roots){
			std::sort(begin(it), end(it));
			it.erase(std::unique(begin(it), end(it)), end(it));
		}
		for(auto a: roots[0])for(auto b: roots[1]) if(a==b) goto nextCell;

		if(false){nextCell: continue;}

		++result;
		for(auto a: roots[0]) dsu.join(a, index(row, col));
		for(auto b: roots[1]) dsu.join(b, index(row, col+numCol));
		have[row][col]=true;
	}
	std::cout<<result<<'\n';
}