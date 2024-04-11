// obviously.
// at least I didn't need to look at the editorial.
// in this case, throwing away the divide and conquer is the hint. Because divide and conquer will not make the solution easier.

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Tree{
	struct Node{
		int lazy; // add
		int minimum_;
		int minimum() const{
			assert(minimum_+lazy>=0);
			return minimum_+lazy;
		}

		int already; // sum of this node (a separate subtree)
	};
	std::vector<Node> data;
	Tree(int number): data(number*2){}

	int offset() const{return int(data.size()/2);}

	void addValue(int left, int right, int value){
		left+=offset(); right+=offset();
		assert(left<=right);
		if(left>=right) return;
		std::array<int, 2> tmp{{left, right-1}};
		for(; left<right; left>>=1, right>>=1){
			if(left&1) data[left++].lazy+=value;
			if(right&1) data[--right].lazy+=value;
		}
		for(auto it: tmp){
			for(;it>>=1;)
				data[it].minimum_=std::min(
						data[it<<1].minimum(),
						data[it<<1|1].minimum()
						);
		}
	}

	void addAlready(int index, int value){
		index+=offset();
		data[index].already+=value;
		for(; index>>=1;) data[index].already=data[index<<1].already+data[index<<1|1].already;
	}

	void pushAlready(int index){
		assert(minimum(index, index+1).value==0);
		addAlready(index, 1);
		addValue(index, index+1,
				(int)data.size()+1 // effectively infinity
				);

		if(index==offset()-1) return;
		addValue(index+1, offset(), -1);
		while(true){
			auto const tmp=minimum(index+1, offset());
			assert(tmp.value>=0);
			if(tmp.value!=0) break;
			pushAlready(tmp.index); // the recursion should not be necessary
		}
	}

	int sumAlready(int left, int right)const{
		left+=offset(); right+=offset();
		assert(left<=right);
		if(left>=right) return 0;
		int result{};
		for(; left<right; left>>=1, right>>=1){
			if(left&1) result+=data[left++].already;
			if(right&1) result+=data[--right].already;
		}
		return result;
	}

	void push(int node){
		if(auto& l=data[node].lazy){
			data[node].minimum_+=l;
			data[node<<1].lazy+=l;
			data[node<<1|1].lazy+=l;
			l=0;
		}
	}

	struct Result{int index, value;};
	Result minimum(int left, int right) { // rightmost if multiple | effectively const, but have push
		left+=offset(); right+=offset();
		assert(left<right);
		for(auto it: {left, right-1}){
			for(int shift=31^__builtin_clz(it); shift>0; shift--){
				push(it>>shift);
			}
		}
		static std::vector<int> a, b; // the slow way
		a.clear(); b.clear();
		for(; left<right; left>>=1, right>>=1){
			if(left&1) a.push_back(left++);
			if(right&1) b.push_back(--right);
		}
		b.insert(b.end(), a.rbegin(), a.rend());
		// now b is the list of nodes in right to left order
		int node=*std::min_element(begin(b), end(b),
				[&](auto const& first, auto const& sec){
					return data[first].minimum()<data[sec].minimum();
				}); // leftmost in b -> rightmost in tree
		while(node<offset()){
			push(node);
			node=node*2+(data[node*2+1].minimum()==data[node].minimum());
		}
		return {node-offset(), data[node].minimum()};
	}

};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int length, numQuery; std::cin>>length>>numQuery;
	std::vector<int> value(length);
	for(int i=0; i<length; ++i){
		std::cin>>value[i];
		value[i]=(i+1)-value[i];
		if(value[i]<0) value[i]=length+1; // effectively infinity
	}

	struct Query{int left, right, queryIndex;
		bool operator<(Query other) const{
			return left<other.left;
		}
	};
	std::vector<Query> queries(numQuery);
	std::vector<int> result(numQuery);
	for(int queryIndex=0; queryIndex<numQuery; ++queryIndex){
		int x, y; std::cin>>x>>y;
		queries[queryIndex]={x, length-y, queryIndex};
	}
	std::sort(begin(queries), end(queries));

	Tree tree(length);
	[&]{ for(int left=length;;){
		while(true){
			if(queries.empty()) return;
			if(queries.back().left!=left) break;
			auto const [_left, right, queryIndex]=queries.back(); queries.pop_back();
			result[queryIndex]=tree.sumAlready(left, right);
		}

		--left;
		assert(value[left]>=0);
		assert(tree.minimum(left, left+1).value==0);
		if(value[left]==0){
			tree.pushAlready(left);
		}else{
			tree.addValue(left, left+1, value[left]);
		}
	}
	}();
	for(auto it: result) std::cout<<it<<'\n';
}