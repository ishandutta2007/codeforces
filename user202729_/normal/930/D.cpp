// :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct point{
	int x, y;

	template<int count=1> point rot() const{
		static_assert(count>=0, "");
		if constexpr(count!=0){
			return point{y,-x}.rot<count-1>();
		}
		return *this;
	}

	friend bool operator<(point first, point sec){
		return std::tie(first.x, first.y)<std::tie(sec.x, sec.y);
	}
};
template<int count=1> point rot(point p) { return p.rot<count>(); }

auto find_bound(auto first, auto last,
		auto const& inputTransform){
	// note that the range [first... last] may be reordered arbitrarily
	// (definitely bad API)
	assert(first!=last);

	std::sort(first, last,[&](auto first, auto sec){
		return inputTransform(first)<inputTransform(sec);
	});

	std::vector<point> out{*first};
	std::for_each(std::next(first), last,[&](auto p){
		assert(inputTransform(p).x>=inputTransform(out.back()).x);
		if(inputTransform(p).y<inputTransform(out.back()).y)
			out.push_back(p);
	});
	return out;
}


struct ST{
	using lazy_t=int; // added value
	struct data_t{ 
		int maximum, count; 
		data_t operator+(data_t other) const{
			return {
				std::max(maximum, other.maximum),
					maximum>other.maximum ? count:
						maximum==other.maximum ? count+other.count:
						other.count
			};
		}
	};

	struct node{
		lazy_t lazy;
		data_t data;
		data_t get()const{ return {data.maximum+lazy, data.count}; }
		// lazy does affect val of the same node
	};
	std::vector<node> d;

	ST(){}
	ST(int n){ reset(n); }
	void reset(int n){ // all zeroes state
		d.resize(n*2);
		for(int i=n;i--;)d[i+n]={0,{0, 1}};
		for(int i=n;--i;)d[i]={0, d[i<<1].data+d[i<<1|1].data};
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

	void add(int l,int r,int val){ // add (val) to range l...r
		assert(0<=l and l<=r and r<=offset());
		if(l==r) return;
		l+=offset(); r+=offset();
		foreach_range(l,r,[&](int node){
			d[node].lazy+=val;
		});
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_up(node,[&](int anc){
				d[anc].data=d[anc<<1].get()+d[anc<<1|1].get();
			});
		}
	}

	auto get_(){
		int l=0, r=offset();

		l+=offset();r+=offset();
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_down(node,[&](int anc){
				auto& lazy=d[anc].lazy;
				d[anc<<1].lazy+=lazy;
				d[anc<<1|1].lazy+=lazy;
				d[anc].data.maximum+=lazy;
				lazy=0;
			});
		}
		data_t out{INT_MIN, 0};
		foreach_range(l,r,[&](int node){
			out=out+d[node].get();
		});

		return out;
	}

	int get(){ // count number of 4's in the whole tree
		auto out=get_();
		assert(out.maximum<=4);
		return out.maximum==4 ? out.count: 0;
	}

	bool assertAllZeroes(){
		auto out=get_();
		assert(out.maximum==0);
		assert(out.count==offset());
		return true;
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<point> points(number);
	for(auto &[x, y]: points){
		std::cin>>x>>y;
	}
	auto iterator=std::partition(begin(points),end(points),[&](auto p){
		return (p.x+p.y)&1;
	});
	for(auto & p: points) p={(p.x+p.y)>>1, (p.x-p.y)>>1};

	int64_t result=0;
	auto const process=[&](auto first, auto last){
		if(last-first<4) return;

		int maxX=INT_MIN, maxY=INT_MIN;
		{
			int minX=INT_MAX, minY=INT_MAX;
			std::for_each(first, last,[&](auto p){
				minX=std::min(minX, p.x);
				minY=std::min(minY, p.y);
			});
			std::for_each(first, last,[&](auto& p){
				p={p.x-minX, p.y-minY};
				maxX=std::max(maxX, p.x);
				maxY=std::max(maxY, p.y);
			});
		}

		struct event{int y, left, right, change;};
		std::vector<event> events; // will be swept int increasing y value

		int lastCoordinate=maxY;
		for(auto [x, y]:find_bound(first, last, rot<0>)){
			events.push_back({lastCoordinate, x, maxX, -1});
			events.push_back({lastCoordinate=y, x, maxX, 1});
		}
		lastCoordinate=0;
		for(auto [x, y]:find_bound(first, last, rot<1>)){
			events.push_back({y, lastCoordinate, x, 1});
			events.push_back({maxY, lastCoordinate, x, -1});
			lastCoordinate=x;
		}
		lastCoordinate=0;
		for(auto [x, y]:find_bound(first, last, rot<2>)){
			events.push_back({lastCoordinate, 0, x, 1});
			events.push_back({lastCoordinate=y, 0, x, -1});
		}
		lastCoordinate=maxX;
		for(auto [x, y]:find_bound(first, last, rot<3>)){
			events.push_back({y, x, lastCoordinate, -1});
			events.push_back({0, x, lastCoordinate, 1});
			lastCoordinate=x;
		}

		assert(std::cerr<<"");

		std::sort(begin(events),end(events), [&](auto first, auto sec){
			return first.y<sec.y;
		});

		ST tree(maxX);
		int lastY=events[0].y;
		for(auto [y, left, right, change]: events){
			if(y!=lastY)
				result+=tree.get()*int64_t(y-lastY);
			tree.add(left, right, change);
			lastY=y;
		}

		assert(tree.assertAllZeroes());
	};

	process(begin(points), iterator);
	process(iterator, end(points));
	std::cout<<result<<'\n';
}