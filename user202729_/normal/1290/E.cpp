/*
{}
*/


#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct SlowSegmentTree{
	std::vector<int> data;
	SlowSegmentTree(int number): data(number, -1){}
	void updateMaximum(int left, int right, int value){
		std::for_each(left+begin(data), right+begin(data),
				[&](auto& x){ if(x!=-1) x=std::max(x, value); }
				);
	}
	void add(int left, int right, int value){
		std::for_each(left+begin(data), right+begin(data),
				[&](auto& x){ if(x!=-1) x+=value; }
				);
	}
	void set(int index, int value){
		assert(data[index]==-1);
		data[index]=value;
	}
	int64_t getSum(int left, int right){
		return std::accumulate(left+begin(data), right+begin(data), (int64_t)0,
				[&](int64_t sum, int value){ return value!=-1 ? sum+value : sum; });
	}
};


#if LOCAL
#define SLOW(x...) x
#else
#define SLOW(x...)
#endif


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using set_t = __gnu_pbds::tree<
  int,
  __gnu_pbds::null_type,
  std::less<int>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update>;

set_t added;


struct SegmentTree{
	struct DataType{
		int minimum, count; 
		DataType():minimum(INT_MAX), count(0) {}
		DataType(int x):minimum(x), count(1) {}
		DataType(DataType first, DataType sec) :
			minimum(std::min(first.minimum, sec.minimum)),
			count(first.count+sec.count)
			{}

		void operator+=(int value){
			if(count){
				minimum+=value;
			}
		}
	};
	struct Node{
		DataType minimum, rest;
		int lazyAdd;
		int lazyUpdateMax;

		Node(): minimum{}, rest{}, lazyAdd{}, lazyUpdateMax{INT_MIN}{}
		Node(int value): minimum{value}, rest{}, lazyAdd{}, lazyUpdateMax{INT_MIN}{}

		void updateMaximum(int value){
			if(value<=minimum.minimum) return;
			assert(value<rest.minimum);
			minimum+=(value-minimum.minimum);
			lazyUpdateMax=std::max(lazyUpdateMax, value-lazyAdd);
		}

		void operator+=(int value){
			minimum+=value; rest+=value; lazyAdd+=value;
		}
	};
	std::vector<Node> data;
	int64_t sum=0;
	SLOW(SlowSegmentTree slow;)

	SegmentTree(int n)
		SLOW(: slow(n))
	{ reset(n); }
	void reset(int n){
		data.assign(n*2, {});
	}

	private:
	static bool evaluates_to_true(auto const& fn){ // fn is evaluated in any case
		if constexpr(std::is_same_v<decltype(fn()),void>){
			fn(); return false;
		}else{
			return fn();
		}
	}
#define IS_TRUE(expr...) evaluates_to_true([&]{ return (expr); })

	public:
	static void foreach_strict_ancestors_down(int x,auto const& fn){ // fn returns true to break loop
		for(int shift=31^__builtin_clz(x);shift;--shift)
			if(IS_TRUE(fn(x>>shift))) break;
	}

	static void foreach_strict_ancestors_up(int x,auto const& fn){
		for(int y=x>>1;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}

	static void foreach_range(int l,int r,auto const& leftfn,auto const& rightfn){
		// leftfn is called from left to right on left nodes
		// rightfn is called from right to left on right nodes
		while(l<r){
			if(l&1) if(IS_TRUE(leftfn(l++))) break;
			if(r&1) if(IS_TRUE(rightfn(--r))) break;
			l>>=1;r>>=1;
		}
	}

	int offset()const{ return int(data.size()/2u); }

	void foreach_range(int l,int r,auto const& fn){
		foreach_range(l,r,fn,fn);
	}

	void pushLazy(int node){
		if(auto& lazy=data[node].lazyUpdateMax; lazy!=INT_MIN){
			for(auto child:{node*2, node*2+1})
				data[child].updateMaximum(lazy);
			lazy=INT_MIN;
		}
		if(auto& lazy=data[node].lazyAdd){
			assert(data[node].lazyUpdateMax==INT_MIN);
			for(auto child:{node*2, node*2+1})
				data[child]+=lazy;
			lazy=0;
		}
	}

	auto const mergeFromChild(int node){
		auto& cur=data[node];

		assert(cur.lazyAdd==0);
		assert(cur.lazyUpdateMax==INT_MIN);

		auto const* first=&data[node*2];
		auto const* sec=&data[node*2+1];
		if(first->minimum.minimum==sec->minimum.minimum){
			cur.minimum={first->minimum, sec->minimum};
			cur.rest={first->rest, sec->rest};
		}else{
			if(first->minimum.minimum>sec->minimum.minimum)
				std::swap(first, sec);
			cur.minimum=first->minimum;
			cur.rest={{first->rest, sec->minimum}, sec->rest};
		}
	}
	void updateMaximumRecursive(int node, int value){
		if(value<=data[node].minimum.minimum) return;
		if(value<data[node].rest.minimum){
			sum+=data[node].minimum.count*(value-data[node].minimum.minimum);
			data[node].updateMaximum(value);
			return;
		}
		pushLazy(node);
		updateMaximumRecursive(node<<1, value);
		updateMaximumRecursive(node<<1|1, value);
		mergeFromChild(node);
	}

	void pushLazyAll(int node){
		foreach_strict_ancestors_down(node, [&](int ancestor){ pushLazy(ancestor); } );
	}


	void updateAll(int node){
		pushLazyAll(node);
		foreach_strict_ancestors_up(node, [&](int ancestor){
			mergeFromChild(ancestor);
		});
	}



	void updateMaximum(int left, int right, int value){ // set range l...r to max (current value, val)
		SLOW(slow.updateMaximum(left, right, value));

		if(left==right) return;
		left+=offset(); right+=offset();
		pushLazyAll(left);
		pushLazyAll(right-1);
		foreach_range(left, right, [&](int node){
			updateMaximumRecursive(node, value);
		});
		updateAll(left);
		updateAll(right-1);

		SLOW(slowCheck();)
	}

	void add(int left, int right, int value){
		if(left==right) return;

		auto const pos=[&](int value){
			auto const iterator=added.lower_bound(value);
			auto const result=int(iterator!=end(added) ? added.order_of_key(*iterator) : added.size());
			assert(result==int(added.order_of_key(value)));
			return result;
		};

		int const numPresent=pos(right)-pos(left);
		if(numPresent==0) return;

		left+=offset(); right+=offset();
		for(auto node:{left, right-1}){
			foreach_strict_ancestors_down(node, [&](int ancestor){ pushLazy(ancestor); } );
		}

		SLOW(slowCheck();)

		sum+=value*(int64_t)numPresent;
		foreach_range(left, right, [&](int node){
			data[node]+=value;
		});
		updateAll(left);
		updateAll(right-1);

		SLOW(slow.add(left-offset(), right-offset(), value);)
		SLOW(slowCheck();)
	}

	void set(int index, int value){
		SLOW(slowCheck());
		SLOW(slow.set(index, value);)

		auto const node=index+offset();
		pushLazyAll(node);
		assert(data[node].minimum.count==0);
		data[node].minimum={value};
		updateAll(node);
		sum+=value;

		SLOW(slowCheck());
	}

#if SLOW(1)+0==1
	void slowCheck(){
		assert(sum==slow.getSum(0, offset()));
	}
#endif

};


int main(){
	if(0){
		added.insert(1);
		added.insert(3);
		for(int x=0;x<5;++x){

			auto const iterator=added.lower_bound(x);
			auto const result=int(iterator!=end(added) ? added.order_of_key(*iterator) : added.size());

			std::cout<<x<<' '<<
				added.order_of_key(x)<<' '
				<<result<<'\n';
		}


		return 0;
	}


	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> posOf(number),array(number);
	for(int index=0;index<number;++index) {
		int & value=array[index]; std::cin>>value;
		posOf[--value]=index;
	}

	SegmentTree leftUncovered(number), rightUncovered(number);
	for(int value=0;value<number;++value) {
		auto const pos=posOf[value];
		assert((int)added.size()==value);
		added.insert(pos);
		auto countLeft=(int)added.order_of_key(pos);
		auto countRight=value-countLeft;
		assert(countRight>=0);

		leftUncovered.set(pos, 0);
		rightUncovered.set(pos, 0);
		leftUncovered.updateMaximum(pos+1, number, countLeft);
		leftUncovered.add(pos+1, number, 1);
		rightUncovered.updateMaximum(0, pos, countRight);
		rightUncovered.add(0, pos, 1);

		auto const totalLeftUncovered=leftUncovered.sum;
		auto const totalRightUncovered=rightUncovered.sum;
		assert(totalLeftUncovered>=0);
		assert(totalRightUncovered>=0);
		std::cout<<
			value*int64_t(value+1) // total	number of ordered pairs (of 2 different elements)
			+value+1 // number of pairs with two elements equal
			-totalLeftUncovered-totalRightUncovered
			<<'\n';
	}
}