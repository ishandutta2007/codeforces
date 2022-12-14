#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int partSize, numEdge, numChange; std::cin>>partSize>>numEdge>>numChange;
	struct D{int x, y;};
	std::vector<D> data(partSize-1);
	for(auto& [x, y]: data) std::cin>>x>>y;
	//struct E{int x, y, z;}; std::vector<E> edges(numEdge);
	struct E_{int y, z;}; std::vector<std::vector<E_>> edges_(partSize);
	//for(auto& [x, y, z]: edges){
	for(int _=0, x, y, z; _<numEdge; ++_){
		std::cin>>x>>y>>z;
		--x;--y;
		edges_[x].push_back({y, z});
	}

	/*
	auto const compute [[maybe_unused]] =[&]{ // very naive algorithm (proven with MCMF theorem)
		auto minCut=INT64_MAX;
		for(int i=1; i<=partSize; ++i)
			for(int j=0; j<partSize; ++j){
				int64_t curCut=(i<partSize ? data[i-1].x: 0)+(0<j ? data[j-1].y: 0);
				for(auto& [x, y, z]: edges) if(x<i and j<=y) curCut+=z;
				minCut=std::min(minCut, curCut);
			}
		return minCut;
	};
	*/

	struct Tree{
		struct Node{
			int64_t lazyAdd;
			int64_t minimum_;
			int64_t minimum() const{return minimum_+lazyAdd;}
		};
		//std::vector<Node> data;
		int offset;
		std::unique_ptr<Node[]> data;
		Tree(int number): offset(number), data(new Node[number*2]{}){}
		void addRange(int left, int right, int64_t delta){
			left+=offset; right+=offset;
			std::array<int, 2> const old{{left, right-1}};
			for(; left<right; left>>=1, right>>=1){
				if(left&1) data[left++].lazyAdd+=delta;
				if(right&1) data[--right].lazyAdd+=delta;
			}
			for(auto it: old)
				for(it>>=1; it; it>>=1)
					data[it].minimum_=std::min(
							data[it*2].minimum(),
							data[it*2+1].minimum()
							);
		}
		int64_t minimum() const{
			return data[1].minimum();
		}
	};

	std::vector<int64_t> tmp(partSize);
	/*
	auto const tmp_=[&](int leftSideI){
		auto curMinimum=INT64_MAX;
		for(int j=0; j<partSize; ++j){
			int64_t tmp=0<j ? data[j-1].y: 0;
			for(auto& [x, y, z]: edges) if(x<leftSideI and j<=y) tmp+=z;
			curMinimum=std::min(curMinimum, tmp);
		}
		return curMinimum;
	};
	*/
	{
		Tree tree(partSize);
		for(int j=0; j<partSize; ++j)
			tree.addRange(j, j+1, 0<j ? data[j-1].y: 0);
		for(int i=1; i<=partSize; ++i){
			for(auto [y, z]: edges_[i-1]) tree.addRange(0, y+1, z);
			//tmp[i-1]=tmp_(i);
			tmp[i-1]=tree.minimum();
			//assert(tmp[i-1]==tmp_(i));
		}
	}

	auto const tmp2=[&](int i_){
		return tmp[i_]+(i_+1<partSize ? data[i_].x: 0);
	};

	std::multiset<int64_t> values;
	for(int i_=0; i_<partSize; ++i_) values.insert(tmp2(i_));

	std::cout<<*values.begin()<<'\n';
	for(int _=0; _<numChange; ++_){
		int v, w; std::cin>>v>>w;
		--v;
		values.erase(values.find(tmp2(v)));
		data[v].x=w;
		values.insert(tmp2(v));
		std::cout<<*values.begin()<<'\n';
	}
}