// time-limit: 1000
// problem-url: https://codeforces.com/contest/1566/problem/D1

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library BITSum.h ====

template<class T>
struct Tree{
	std::vector<T> data;
	Tree(int number=0): data(number){}
	void reset(int number){data.clear(); data.resize(number);}

	template<bool strict=true>
	T sumSuffix(int index)const{
		if(strict){
			assert(0<=index); assert(index<=(int)data.size());
		}
		T result{};
		while(index<(int)data.size()){
			result+=data[index];
			index|=index+1;
		}
		return result;
	}
	T sum(int left, int right) const{
		assert(0<=left); assert(left<=right); assert(right<=(int)data.size());
		return sumSuffix(left)-sumSuffix(right);
	}

	template<bool strict=true>
	void add(int index, T delta){
		if(strict){
			assert(0<=index); assert(index<(int)data.size());
		}
		++index;
		while(index>0){
			data[index-1]+=delta;
			index&=index-1;
		}
	}
};

// } ==== End library BITSum.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int numRow; std::cin>>numRow;
	int numCol; std::cin>>numCol;
	std::vector<int> a(numRow*numCol);
	for(auto& it: a) {
		std::cin>>it;
	}

	{// compress values in a, with special handling of equal values
		std::vector<int> values=a;
		std::sort(begin(values), end(values));

		std::vector<int> newIndex(a.size());
		for(int right=1, left=0; right<=(int)a.size(); ++right) 
			if(right==(int)a.size() or values[right]!=values[right-1]){
				[&]{ // process

					auto const fillReverse=[&](int left, int right){
						assert(left<=right);
						for(int index=left; index<right; ++index)
							newIndex[index]=left+right-1-index;
					};
					
					assert(left<right);
					if(left/numCol==(right-1)/numCol){
						fillReverse(left, right);
					}else{
						auto const tmp=(left/numCol+1)*numCol;
						fillReverse(left, tmp);
						auto const tmp2=right/numCol*numCol;
						fillReverse(tmp2, right);
						for(int index=tmp; index<tmp2; index+=numCol)
							fillReverse(index, index+numCol);
					}	
				}();
				left=right;
			}

		for(auto& item: a){
			auto const index=int(std::lower_bound(begin(values), end(values), item)-begin(values));
			assert(newIndex[index]!=-1);
			item=newIndex[index];
			assert((newIndex[index]=-1));
			values[index]--; // mark as used. By some complex arguments this works
		}
	}

	// emulate the process
	std::vector<Tree<int>> board(numRow);
	for(auto& row: board) row.reset(numCol);
	int64_t totalInconvenience=0;
	for(auto item: a){
		auto const row=item/numCol, col=item%numCol;
		totalInconvenience+=board[row].sum(0, col);
		board[row].add(col, 1);
	}

	std::cout<<totalInconvenience<<'\n';
	

	
	
}