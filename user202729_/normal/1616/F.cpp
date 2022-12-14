// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/F
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// just resubmit

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}


int const N=256+1;
struct C{
	std::array<char, N+1> data;
	C operator+(C other) const{
		for(int index=0; index<(int)data.size(); ++index){
			other.data[index]+=data[index];
			if(other.data[index]>=3) other.data[index]-=3;
		}
		return other;
	}
};



void up(){
	int numNode; std::cin>>numNode;
	int numEdge; std::cin>>numEdge;

	std::vector<std::array<int, 3>> edges(numEdge);
	std::vector index(numNode, std::vector<int>(numNode, -1));

	std::vector<C> condition;
	for(int curIndex=0; curIndex<numEdge; ++curIndex){
		auto& [a, b, c]=edges[curIndex];
		std::cin>>a>>b>>c;
		--a; --b;
		index[a][b]=index[b][a]=curIndex;

		for(int d=0; d<numNode; ++d)
			if(index[a][d]>=0 and index[d][b]>=0){
				C c {};
				c.data[curIndex]=1;
				c.data[index[a][d]]=1;
				c.data[index[d][b]]=1;
				condition.push_back(c);
			}

		if(c>=0){
			--c;
			C item {};
			item.data[curIndex]=1;
			assert(0<=c and c<3);
			item.data[N-1]=(char)c;
			condition.push_back(item);
		}
	}

	std::vector<C> fixed;
	while(not condition.empty()){
		auto item=condition.back(); condition.pop_back();
		if(item.data==C{}.data) continue;

		auto pos=0; while(item.data[pos]==0) pos++;
		if(pos==N-1){
			std::cout<<"-1\n";
			return;
		}
		if(item.data[pos]==2) for(auto& x: item.data) x=(x==0 ? 0: 3-x);
		auto itemNegative=item; for(auto& x: itemNegative.data) x=(x==0 ? 0: 3-x);
		fixed.push_back(item);

		for(auto& other: condition){
			if(other.data[pos]==1) other=other+itemNegative;
			else if(other.data[pos]==2) other=other+item;

			assert(other.data[pos]==0);
		}
	}

	std::vector<int> result(numEdge);
	for(int pos=numEdge; pos--;){
		for(auto& item: fixed){
			if(item.data[pos] and std::all_of(item.data.begin(), item.data.begin()+pos, [&](auto const& it){
				return it==0;
			})){
				result[pos]=0;
				int value=item.data[N-1];
				for(int index=0; index<numEdge; ++index){
					if(item.data[index]==1) value+=result[index]*2;
					if(item.data[index]==2) value+=result[index];
				}
				value%=3; 
				result[pos]=value;
				break;
			}
		}
	}

	for(auto x: result) std::cout<<x+1<<' ';
	std::cout<<'\n';

}