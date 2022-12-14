// [I didn't read the editorial or view/check/i-dont-know-what-verb-would-fit-here any failed test cases]
//
// But it took me too long to figure out the exact algorithm after think that it would involve sweep line
// + square root decomposition...
// (To be precise, the virtual participation was 10 days ago.)
//
// The O(n log^2 n) solution was not too hard to get after having the square root solution.
// It's not the standard segment tree 2D however.
//
// =============
// I didn't participate in Codeforces Round 614 (div. 1), not because
// the time is inconvenient or because I'm afraid of losing rating, but
// I think that the rating change would not be "impressive" enough.
// Given my performance on recent virtual contests, I'd get about +30
// to +40 on average, and that's still 20-30 units below my max rating.
// =============
//
// Implementation time: about 1 day (!?)

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

//It's required to explicitly instantiate the template.
//This may be a bug in older version of g++, it works fine locally.
template int const& std::min<int>(int const&,int const&);
template int const& std::max<int>(int const&,int const&);

constexpr auto maxf=(int const&(*)(int const&,int const&))std::max<int>;
constexpr auto minf=(int const&(*)(int const&,int const&))std::min<int>;

template<bool max> constexpr int f_id = max?INT_MIN:INT_MAX;
template<bool max> constexpr int f = max?maxf:minf;

template<class T,auto f>
struct RMQ{
	std::vector<std::vector<T>> d;
	RMQ():d(){}
	RMQ(std::vector<T> x):d(){
		assign(std::move(x));
	}
	void assign(std::vector<T> x){
		d.assign(1,std::move(x));
		for(int step=1;step<(int)d.back().size();step<<=1){
			std::vector<T> const& a=d.back();
			std::vector<T> b(begin(a),end(a)-step);
			std::transform(begin(b),end(b),begin(a)+step,begin(b),f);
			d.push_back(std::move(b));
		}
	}
	T operator[](auto i)const{ return d[0][i]; }
	T get(int l,int r)const{
		assert(l<r);
		int layer=std::__lg(r-l);
		return f(d[layer][l],d[layer][r-(1<<layer)]);
	}
	template<class U> T get(U lr)const{
		auto [l,r]=lr;
		return get(l,r);
	}
	T getrange(int l,int r)const{
		return get(std::minmax(l,r));
	}
};

struct undo_entry{
	int* source;
	int val;
};
std::vector<undo_entry> undost;
void undoto(std::size_t pos){
	assert(pos<=undost.size());
	for(auto z=undost.size()-pos;z--;){
		*undost.back().source = std::move(undost.back().val);
		undost.pop_back();
	}
}

#define SET(X,Y) ([&]{ \
	int& undoable_target=(X); \
	undost.push_back({&undoable_target,undoable_target}); \
	undoable_target=(Y); \
}())
// is it more efficient to only push when the old value is different from the new value?
	
struct ST{
	using lazy_t=int;
	using data_t=int;

	// lazy: pending "val = max(val, lazy)" op
	// val: min of range
	struct node{
		lazy_t lazy;
		data_t data;
		// lazy does **not** affect val of the same node
	};
	std::vector<node> d;

	ST(){}
	ST(int n){ reset(n); }
	void reset(int n){
		d.resize(n*2);
		for(int i=n*2;i--;)d[i]={INT_MIN,INT_MIN};
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

	void setmax(int l,int r,int val){ // set range l...r to max (current value, val)
		l+=offset(); r+=offset();
		foreach_range(l,r,[&](int node){
			SET(d[node].lazy, std::max(d[node].lazy,val));
			SET(d[node].data, std::max(d[node].data,val));
		});
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_up(node,[&](int anc){
				SET(d[anc].data, std::max(d[anc].lazy,std::min(d[anc<<1].data,d[anc<<1|1].data)));
			});
		}
	}

	int getmin(int l,int r){ // get min of range l...r
		int out=INT_MAX;
		l+=offset();r+=offset();
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_down(node,[&](int anc){
				auto& l=d[anc].lazy;
				if(l!=INT_MIN){
					SET(d[anc<<1].lazy  , std::max(d[anc<<1].lazy,l));
					SET(d[anc<<1|1].lazy, std::max(d[anc<<1|1].lazy,l));
					SET(d[anc<<1].data  , std::max(d[anc<<1].data,l));
					SET(d[anc<<1|1].data, std::max(d[anc<<1|1].data,l));
					SET(l               , INT_MIN);
				}
			});
		}
		foreach_range(l,r,[&](int node){
			out=std::min(out,d[node].data);
		});
		return out;
	}

	void dump(){
		for(int node=offset();node<2*offset();++node){
			int out=d[node].data;
			foreach_strict_ancestors_up(node,[&](int anc){ out=std::max(out,d[anc].lazy); });
			assert(std::cerr<<out<<' ');
		}
		assert(std::cerr<<'\n');
	}
};
ST st;

struct event{
	int x; // TODO is a bit field faster or slower?
	int id;
	bool open;
	bool operator<(event e)const{ return x<e.x; };
};

struct ranges{
	struct openpos{
		int x,val;
		bool operator<(openpos e)const{ return x<e.x; };
	};
	std::vector<openpos> d;

	template<class cmp_t> ranges min(ranges v,int maxx,cmp_t cmp={})const{
		if(d.empty()) return std::move(v);
		if(v.d.empty()) return *this;

		for(unsigned i=1;i<d.size();++i) assert(d[i-1].x<d[i].x);
		for(unsigned i=1;i<v.d.size();++i) assert(v.d[i-1].x<v.d[i].x);

		auto i1=begin(d); auto i2=begin(v.d);
		assert(i1->x==i2->x);
		assert(d.back().x==maxx and d.back().val==-1);
		assert(v.d.back().x==maxx and v.d.back().val==-1);
		ranges out;
		out.d.reserve(d.size()+v.d.size());
		auto lasti1val=i1->val;
		auto lasti2val=i2->val;
		auto lastval=std::min(lasti1val,lasti2val,cmp);
		out.d.push_back({i1->x,lastval});
		++i1; ++i2;

		while(true){
			int curx;
			if(i1->x<i2->x){
				curx=i1->x;
				lasti1val=i1->val;
				++i1;
			}else if(i1->x>i2->x){
				curx=i2->x;
				lasti2val=i2->val;
				++i2;
			}else{ // Unl)e typical merge sort, it's necessary to
				// specially han=e the == case. It took me a lot of time
				// to find out that (initially, for some reason, I
				// just assume that it would be automatically correct...)
				curx=i1->x;
				if(curx==maxx) break;
				lasti1val=i1->val;
				lasti2val=i2->val;
				++i1; ++i2;
			}
			auto newval=std::min(lasti1val,lasti2val,cmp);
			assert(curx<maxx);
			if(newval!=lastval){
				lastval=newval;
				assert(out.d.back().x<curx);
				out.d.push_back({curx,newval});
			}
		}
		out.d.push_back({maxx,-1});
		return out;
	}

	template<bool overlap_max>
	static ranges from_unsorted_events(std::vector<event> d){
		//assert(std::is_sorted(begin(d),end(d)));
		std::sort(begin(d),end(d));

		// for any overlapping part keep the segment with f<overlap_max> id.
		using comp=std::conditional_t<overlap_max,std::greater<int>,std::less<int>>;
		// TODO use static segment tree to be faster?
		std::multiset<int,comp> setid;
		// so f<overlap_max>(*setid) = *begin(setid)

		ranges out;out.d.reserve(d.size());

		for(auto [x,id,open]:d){
			if(open){
				if(setid.empty() or comp{}(id,*setid.begin())){
					// insertion of id changes *setid.begin()
					if(not out.d.empty() and out.d.back().x==x) out.d.pop_back();
					out.d.push_back({x,id});
				}
				setid.insert(id);
			}else{
				auto iter=setid.find(id);
				auto const old_max=*setid.begin();
				setid.erase(iter);
				if(setid.empty() or old_max!=*setid.begin()){
					if(not out.d.empty() and out.d.back().x==x) out.d.pop_back();
					if(setid.empty())
						out.d.push_back({x,-1}); // segment close (NOTE -1 is used)
					else
						out.d.push_back({x,*setid.begin()}); // old value override this
				}
			}
		}
		assert(std::is_sorted(begin(out.d),end(out.d)));
		return out;
	}
};

std::vector<std::vector<event>> d_events;
std::vector<ranges> d;
std::vector<char> visible;

int nxval,nyval;

ranges proc(int node){
	auto cur=std::move(d[node]);
	if(not cur.d.empty())
		assert(cur.d[0].x==0 and cur.d.back().x==nxval);

	if(node*2<(int)d.size()){
		auto const moment=undost.size();

		for(unsigned i=1;i<cur.d.size();++i){
			st.setmax(cur.d[i-1].x,cur.d[i].x,cur.d[i-1].val);
		}
		auto p1=proc(node<<1);
		auto p2=proc(node<<1|1);
		undoto(moment);

		cur=cur.min<std::greater<int>>(
			p1.min<std::less<int>>(p2,nxval),
			nxval);
	}

	for(unsigned i=1;i<cur.d.size();++i){
		if(cur.d[i-1].val<0 or visible[cur.d[i-1].val]) continue;

		auto z=st.getmin(cur.d[i-1].x,cur.d[i].x);
		assert(z!=cur.d[i-1].val);
		if(cur.d[i-1].val>z)
			visible[cur.d[i-1].val]=true;
	}
	return cur;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	struct rect{ int x1,x2,y1,y2; };
	int nrect;std::cin>>nrect;
	std::vector<rect> rects(nrect);
	{ // Read input & compress coordinate
		std::vector<int> xs,ys;
		xs.reserve(2*nrect);ys.reserve(2*nrect);
		for(auto& [x1,x2,y1,y2]:rects){
			std::cin>>x1>>y1>>x2>>y2;
			xs.push_back(x1);xs.push_back(x2);
			ys.push_back(y1);ys.push_back(y2);
		}
		for(auto& ptr:{&xs,&ys}){
			auto& vals=*ptr;
			std::sort(begin(vals),end(vals));
			vals.erase(std::unique(begin(vals),end(vals)),end(vals));
		}
		nxval=(int)xs.size();
		nyval=(int)ys.size();

		auto const index=[](auto const& vec,int x){
			auto iter=std::lower_bound(begin(vec),end(vec),x);
			assert(*iter==x);
			return int(iter-begin(vec));
		};
		for(auto& [x1,x2,y1,y2]:rects){
			x1=index(xs,x1);
			x2=index(xs,x2);
			y1=index(ys,y1);
			y2=index(ys,y2);
		}
	}

	d_events.resize(nyval*2);
	for(int id=0;id<nrect;++id){
		auto [x1,x2,y1,y2]=rects[id];
		assert(y1<y2);
		auto const proc=[&](int node){
			d_events[node].push_back({x1,id,true});
			d_events[node].push_back({x2,id,false});
		};
		for(int l=nyval+y1,r=nyval+y2;l<r;l>>=1,r>>=1){
			if(l&1) proc(l++);
			if(r&1) proc(--r);
		}
	}

	d.resize(d_events.size());
	std::transform(
			std::move_iterator(begin(d_events)), // C++17 class template deduction :)
			std::move_iterator(end(d_events)),
			begin(d),
			[](std::vector<event> e){
				e.push_back({0,-1,true});
				e.push_back({nxval,-1,false});
				return ranges::from_unsorted_events<true>(std::move(e));
			});
	d_events.clear();

	assert(visible.empty());
	visible.resize(nrect);

	st.reset(nxval);
	assert(undost.empty());
	proc(1);
	assert(undost.empty());

	std::cout<<std::accumulate(begin(visible),end(visible),1)<<'\n';
}