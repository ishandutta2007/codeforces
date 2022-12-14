#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct Tree{
	struct Node{
		int sub, add;
		friend Node operator+(Node first, Node sec){
			auto it=std::min(first.add, sec.sub);
			first.add-=it;
			sec.sub-=it;
			return {first.sub+sec.sub, first.add+sec.add};
		}
	};
	std::vector<Node> data;

	Tree(int number): data(number*2){
	}

	int offset(int node) const{
		node+=1<<(31 xor __builtin_clz((int)data.size()));
		if(node>=(int)data.size()) node-=int(data.size()/2);
		return node;
	}

	void updateAll(int node){
		for(node>>=1; node; node>>=1)
			data[node]=data[node<<1]+data[node<<1|1];
	}

	void addBomb(int index){
		auto node=offset(index);
		data[node].sub=1;
		if(data[node].sub and data[node].add) data[node]={0, 0};
		updateAll(node);
	}

	void setValue(int index){
		auto node=offset(index);
		data[node].add=1;
		if(data[node].sub and data[node].add) data[node]={0, 0};
		updateAll(node);
	}

	bool compute()const{
		return data[1].add!=0;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> indexP(number);
	for(int index=0;index<number;++index) {
		int pAtIndex; std::cin>>pAtIndex;
		--pAtIndex;
		indexP[pAtIndex]=index;
	}

	//for(auto & index: q){std::cin>>index;--index;}

	Tree tree(number);
	int value=number;
	for(int _=0;_<number;++_) {
		while(tree.compute()==0)
			tree.setValue(indexP[--value]);

		std::cout<<value+1<<' ';
		int qCur; std::cin>>qCur;
		tree.addBomb(--qCur);
	}
	std::cout<<'\n';
}