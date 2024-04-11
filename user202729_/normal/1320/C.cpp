#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct ST{
	using lazy_t=int64_t; // int may be sufficient. But the limit for this problem is a bit too tight
	using data_t=int64_t;

	struct node{
		lazy_t add;
		data_t maximum_;
		auto maximum() const{return add+maximum_;}
		// lazy above data
	};
	std::vector<node> d;

	ST(){}
	ST(auto const& x){ // int this problem the tree is used to keep the profits
		auto const n=(int)x.size();
		d.resize(n*2);
		for(int i=n;i--;)d[i+n]={-x[i].coin, 0};
		for(int i=n;--i;)d[i]={0, std::max(d[i<<1].maximum(),d[i<<1|1].maximum())};
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

	int offset()const{ return int(d.size()/2u); }

	void foreach_range(int l,int r,auto const& fn){
		foreach_range(l,r,fn,fn);
	}

	void add(int l,int r,int val){
		l+=offset(); r+=offset();
		foreach_range(l,r,[&](int node){
			d[node].add+=val; // TODO replace "val" with "node" here does not trigger "unused parameter" warning?
		});
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_up(node,[&](int anc){
				d[anc].maximum_=std::max(d[anc<<1].maximum(),d[anc<<1|1].maximum());
			});
		}
	}

	auto get(){
		return d[1].maximum();
	}

	/*
	int get(int l,int r){ // get max of range l...r
		int out=-1;
		l+=offset();r+=offset();
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_down(node,[&](int anc){
				auto& l=d[anc].lazy;
				d[anc<<1].lazy=std::max(d[anc<<1].lazy,l);
				d[anc<<1|1].lazy=std::max(d[anc<<1|1].lazy,l);
				d[anc<<1].data=std::max(d[anc<<1].data,l);
				d[anc<<1|1].data=std::max(d[anc<<1|1].data,l);
				l=-1;
			});
		}
		foreach_range(l,r,[&](int node){
			out=std::max(out,d[node].data);
		});
		return out;
	}
	*/
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numWeapon, numArmor, numMonster;
	std::cin>>numWeapon>>numArmor>>numMonster;

	struct item{
		int value, coin;
	};
	auto const read=[&](int number){
		std::vector<item> result(number);
		for(auto &[value, coin]: result) std::cin>>value>>coin;
		std::sort(begin(result),end(result),[&](auto first, auto sec){
			return first.coin!=sec.coin ? first.coin<sec.coin : first.value>sec.value;
		});
		auto out=++begin(result);
		std::for_each(out, end(result),[&](item x){
			if(x.value>out[-1].value)
				*out++=x;
		});
		result.erase(out, end(result));
		return result;
	};
	auto weapons=read(numWeapon);
	auto armors=read(numArmor);
	numWeapon=numArmor=-1;

	struct monster{int x, y, coin;};
	std::vector<monster> monsters; monsters.reserve(numMonster);


	for(int _=0;_<numMonster;++_) {
		monster cur;
		auto &[x, y, coin]=cur;
		std::cin>>x>>y>>coin;
		++x;++y; // I accidentally implemented the program assuming that a monster can be defeated if weapon value is >= monster value

		if(x>weapons.back().value or y>armors.back().value) continue;

		auto iterator=std::lower_bound(begin(weapons),end(weapons),x,[&](item first, int sec){
			return first.value<sec;
		});
		assert(iterator!=end(weapons));
		x=int(iterator-begin(weapons));

		monsters.push_back(cur);
		//xValues.push_back(x);
	}
#if LOCAL
	for(auto & [value, coin]: weapons) value=-1;
#endif

	/*
	assert(xValues.size()==size_t(numMonster+numWeapon));

	std::sort(begin(xValues),end(xValues));
	xValues.erase(std::unique(begin(xValues),end(xValues)), end(xValues));

	*/
	ST tree(weapons);
	int64_t result=INT64_MIN;
	std::sort(begin(monsters),end(monsters),[&](monster first, monster sec){
		return first.y>sec.y;
	});
	for(auto [value, coin]: armors){
		while(not monsters.empty() and monsters.back().y<=value){
			tree.add(monsters.back().x, (int)weapons.size(), monsters.back().coin);
			monsters.pop_back();
		}
		result=std::max(result, tree.get()-coin);
	}
	assert(monsters.empty());
	std::cout<<result<<'\n';
}