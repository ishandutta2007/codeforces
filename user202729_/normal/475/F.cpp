// :(
// O(n log n)
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class Less> struct Tree{
	static int f(int first, int sec){return std::min(first, sec, Less{});} // tree operation

	std::vector<int> data;
	void reset(int number, int value){
		data.assign(number*2, value);
	}
	int offset() const{return int(data.size()/2);}
	void change(int index, int value){
		int node=index+offset();
		data[node]=value;
		for(node>>=1; node; node>>=1)
			data[node]=f(data[node*2], data[node*2+1]);
	}
	static void process(int left, int right, auto processLeft, auto processRight){
		for(; left<right; left>>=1, right>>=1){
			if(left&1) if(processLeft(left++)) break;
			if(right&1) if(processRight(--right)) break;
		}
	}
	static void process(int left, int right, auto process1){ process(left, right, process1, process1); }
	int get(int left, int right)const{
		left+=offset(); right+=offset();
		int result=data[left]; assert(left<right);
		process(left, right, [&](int node){result=f(result, node); return false;});
		return result;
	}
	int firstLess(int left, int right, int value)const{
		left+=offset(); right+=offset();
		std::vector<int> rightNodes;
		int found=-1;
		process(left, right,[&](int node){
			if(Less{}(data[node], value)){found=node; return true;}
			return false;
		},[&](int node){
			rightNodes.push_back(node);
			return false;
		});
		if(found<0){
			for(auto index=(int)rightNodes.size(); index--;)
				if(auto node=rightNodes[index]; Less{}(data[node], value)){
					found=node; break;
				}
			if(found<0) return -1;
		}

		while(found<offset()){
			found*=2; if(not Less{}(data[found], value)) ++found;
		}
		assert(Less{}(data[found], value));
		return found-offset();
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	using P=std::array<int, 2>;
	std::vector<P> data(number);
	for(auto& it: data)for(auto& it: it) std::cin>>it;
	std::array<int, 2> numValue;

	std::array<std::vector<std::vector<int>>, 2> list;
	// list[0][r] contains c in reverse-sorted order

	std::array<Tree<std::less<>>, 2> tree;
	std::array<Tree<std::greater<>>, 2> reverse;

	for(int dim=0; dim<2; ++dim){
		std::vector<int> values; values.reserve(number*2);
		for(auto it: data){
			values.push_back(it[dim]);
			values.push_back(it[dim]+1);
		}
		std::sort(begin(values), end(values));values.erase(std::unique(begin(values), end(values)), end(values));
		for(auto& it: data) it[dim]=int(std::lower_bound(begin(values), end(values), it[dim])-begin(values));
		numValue[dim]=(int)values.size();

		list[dim].resize(values.size());
		tree[dim].reset((int)values.size(), 0);
		reverse[dim].reset((int)values.size(), 0);
	}
	for(auto it: data)
		for(int dim=0; dim<2; ++dim){
			list[dim][it[dim]].push_back(it[not dim]);
		}

	for(auto& it: list)for(auto& it: it) std::sort(begin(it), end(it), std::greater<>());
	for(int dim=0; dim<2; ++dim)
		for(int pos=0; pos<numValue[dim]; ++pos){
			auto const value=list[dim][pos].empty() ? numValue[not dim]: list[dim][pos].back();
			tree[dim].change(pos, value);
			reverse[dim].change(pos, value);
		}

	int result{};
	auto const process=[&](auto process, std::array<int, 4> bounds){
		for(int dim=0; dim<2; ++dim){
			bounds[dim*2]=tree[dim].firstLess(bounds[dim*2], bounds[dim*2+1], bounds[(not dim)*2+1]);
			if(bounds[dim*2]<0) {
				assert(dim==0);
				return;
			}
			auto const mid=reverse[dim].firstLess(bounds[dim*2], bounds[dim*2+1], bounds[(not dim)*2+1]-1);
			if(mid>=0){
				auto const oldRight=bounds[dim*2+1];
				bounds[dim*2+1]=mid;
				process(process, bounds);
				bounds[dim*2]=mid+1; bounds[dim*2+1]=oldRight;
				process(process, bounds);
				return;
			}
		}

		++result;
		while(true){
			auto const mid=tree[0].firstLess(bounds[0], bounds[1], bounds[3]);
			if(mid<0) break;
			bounds[0]=mid;

			auto const x=bounds[0];
			auto& l1=list[0][x];
			auto const y=l1.back();
			assert(y<bounds[3]);
			assert(list[1][y].back()==x);

			list[1][y].pop_back(); l1.pop_back();
			auto const y1=l1.empty() ? INT_MAX: l1.back();
			auto const x1=list[1][y].empty() ? INT_MAX: list[1][y].back();
			tree[0].change(x, y1); tree[1].change(y, x1);
			reverse[0].change(x, y1); reverse[1].change(y, x1);
		}
	};
	process(process, {{0, numValue[0], 0, numValue[1]}});
	std::cout<<result<<'\n';
}