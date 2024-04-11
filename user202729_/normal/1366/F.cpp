#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
template<class F> struct Modular_ {
 static auto MOD(){ return
  (F::get()); }
 using T=typename std::decay<decltype((F::get()))>::type;
 T val;
 explicit operator T() const { return val; }
 Modular_():val(){}
 template<class U> static auto check_mod_mod()->decltype(std::declval<U>()%(F::get()), void());
 template<class U
  , class=decltype(check_mod_mod<U>())
  > Modular_(U v):val(T(v%(F::get()))){ if(val<0)val+=(F::get()); }
 template<class U> static Modular_ raw(U value){
  assert(0<=value); assert(value<(F::get()));
  Modular_ result; result.val=value; return result;
 }
 [[nodiscard]] bool operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] Modular_ operator+() const{ return *this; }
 [[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?(F::get())-x.val:0; return x; }
 Modular_& operator+=(Modular_ m) { if ((val += m.val) >= (F::get())) val -= (F::get()); return *this; }
 Modular_& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (F::get()); return *this; }
 Modular_& operator*=(Modular_ m) {
  if(__builtin_constant_p(m.val)){
   switch(m.val){
    case 1: return *this;
    case 2: return *this+=*this;
    case 3: return *this+=*this+*this;
    case 0: return *this=0;
    case -1: return *this=-*this;
   }
  }else if(__builtin_constant_p(val)){
   return *this=m**this;
  }
  if(std::is_same<T, int>::value){
   val = int((int64_t)val*m.val%(F::get()));
  }else if(std::is_same<T, int64_t>::value){
   uint64_t result=
    (uint64_t)val*(uint64_t)m.val-
    uint64_t((long double)val*m.val/(F::get()))*(uint64_t)(F::get());
   result+=(F::get());
   if(result>=(F::get())){
    result-=(F::get());
    if(result>=(F::get())) result-=(F::get());
   }
   val=result;
  }else{
   assert(false);
  }
  return *this;
 }
 template<class U>
 [[nodiscard]] Modular_ pow(U p) const {
  Modular_ a=*this;
  Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
  return ans;
 }
 [[nodiscard]] Modular_ inv() const {
  T a=val,b=(F::get()), ax=1,bx=0;
  while(b){
   T q=a/b, t=a%b;
   a=b; b=t;
   t=ax-bx*q; ax=bx; bx=t;
  }
  assert(a==1);
  if(ax<0)ax+=(F::get());
  return ax;
 }
 Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
 friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'M'; }
 [[nodiscard]] friend Modular_ operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>;
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>;


int main(){
	using modular=Modular<1000000007>;
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge, numQuery; std::cin>>numNode>>numEdge>>numQuery;
	struct Edge{int node, length;};
	std::vector<std::vector<Edge>> add(numNode);
	for(int _=0; _<numEdge; ++_){
		int u, v, w; std::cin>>u>>v>>w;
		--u;--v;
		add[u].push_back({v, w}); add[v].push_back({u, w});
	}

	std::vector<std::vector<int>> maxLength(numNode+1); // (maxWeight=1e6)*(numNode+1<=2e3+1) fits in an int
	maxLength[0].assign(numNode, INT_MIN);
	maxLength[0][0]=0;

	std::map<int, int> points; // base->slope, base increasing, slope decreasing

	modular result{};
	int consideredLength=0;
	for(int length=0; length<(int)maxLength.size()-1; ++length){
		maxLength[length+1].assign(numNode, INT_MIN);
		for(int node=0; node<numNode; ++node)
			if(auto const l=maxLength[length][node]; l!=INT_MIN){
				for(auto [other, edgeLength]: add[node]){
					maxLength[length+1][other]=std::max(maxLength[length+1][other],
							l+edgeLength);

					auto const slope=edgeLength;
					int const base=l-length*slope;
					// add point (base, slope)

					auto iterator=points.lower_bound(base);
					if(iterator!=points.end() and iterator->first==base){
						if(slope<=iterator->second) continue; // don't need to optimize
						iterator->second=slope;
					}else if(iterator!=points.end() and iterator!=points.begin() and
							[&]{
								auto const x0=base; auto const y0=slope;
								auto [x1, y1]=(std::pair<int, int>)*iterator;
								auto [x2, y2]=(std::pair<int, int>)*std::prev(iterator);
								x1-=x0; y1-=y0;
								x2-=x0; y2-=y0;
								auto const cross=(int64_t)x1*y2-(int64_t)x2*y1;
								return cross>=0;
							}()
							){
						continue; // below the current upper-hull
					}else{
						iterator=points.insert(iterator, {base, slope});
					}

					// optimize iterator
					auto const tryRemove=[&](auto iterator){
						assert(iterator!=points.end());
						if(iterator==points.begin() or std::next(iterator)==points.end())
							return false;
						auto [x0, y0]=(std::pair<int, int>)*iterator;
						auto [x1, y1]=(std::pair<int, int>)*std::next(iterator);
						auto [x2, y2]=(std::pair<int, int>)*std::prev(iterator);
						x1-=x0; y1-=y0;
						x2-=x0; y2-=y0;
						auto const cross=(int64_t)x1*y2-(int64_t)x2*y1;
						if(cross>=0){
							points.erase(iterator);
							return true;
						}else return false;
					};

					if(iterator!=points.begin())
						while(tryRemove(std::prev(iterator))){}
					if(std::next(iterator)!=points.end())
						while(tryRemove(std::next(iterator))){}

					// now the point set is negative-convex
					for(auto iterator=points.begin(); iterator!=points.end(); ++iterator)
						assert(not tryRemove(iterator));
				}
			}

		assert(consideredLength==length);
		while(points.size()>=2 and points.begin()->second<=(++points.begin())->second)
			points.erase(points.begin());
		while(points.size()>=2){
			auto const iter1=--points.end();
			auto const a=*std::prev(iter1), b=*iter1;
			assert(a.first<b.first); assert(a.second>b.second);
			if(a.first+length*int64_t(a.second-b.second)>=b.first)
				points.erase(iter1);
			else break;
		}

		// now the best is at points.rbegin()
		result+=points.rbegin()->first+points.rbegin()->second*(int64_t)length;
		++consideredLength;
		if(consideredLength==numQuery+1) break;
	}

	while(consideredLength!=numQuery+1){
		auto const iter1=--points.end();
		int64_t nextLength;

		if(points.size()>=2){
			auto const a=*std::prev(iter1), b=*iter1;
			assert(a.first<b.first); assert(a.second>b.second);

			auto const ceilDiv=[&](int a, int b){ return (a+b-1)/b; };
			nextLength=ceilDiv(b.first-a.first, a.second-b.second);
			assert(a.first+nextLength*int64_t(a.second-b.second)>=b.first);
			assert(not(a.first+(nextLength-1)*int64_t(a.second-b.second)>=b.first));
		}else{
			nextLength=numQuery+1;
		}

		assert(nextLength>=consideredLength);
		nextLength=std::min(nextLength, (int64_t)numQuery+1);
		assert(nextLength>=consideredLength);

		if(0){
			for(int length=consideredLength; length<nextLength; ++length)
				result+=points.rbegin()->first+points.rbegin()->second*(int64_t)length;
		}else{
			result+=modular(points.rbegin()->first)*(nextLength-consideredLength)+
				(modular(consideredLength)+nextLength-1)*(nextLength-consideredLength)/2*
				(points.rbegin()->second);
		}

		consideredLength=(int)nextLength;

		points.erase(iter1);
	}

	assert(consideredLength==numQuery+1);

	std::cout<<(int)result<<'\n';

}