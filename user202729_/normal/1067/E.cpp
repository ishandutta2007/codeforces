#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
 #include<type_traits>
template<class F>
struct Modular_ {
 using T=typename std::decay<decltype((F{}()))>::type;
 T val;
 explicit constexpr operator T() const { return val; }
 constexpr Modular_():val(){}
 constexpr Modular_(auto v):val(T(v%(F{}()))){ if(val<0)val+=(F{}()); }
 [[nodiscard]] bool constexpr operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool constexpr operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool constexpr operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool constexpr operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool constexpr operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool constexpr operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] friend Modular_ constexpr operator-(Modular_ x) { x.val=x.val?(F{}())-x.val:0; return x; }
 Modular_ constexpr& operator+=(Modular_ m) { if ((val += m.val) >= (F{}())) val -= (F{}()); return *this; }
 Modular_ constexpr& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (F{}()); return *this; }
 Modular_ constexpr& operator*=(Modular_ m) {
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
  bool constexpr is_int=std::is_same<T, int>::value;
  bool constexpr is_int64_t=std::is_same<T, int64_t>::value;
  static_assert(is_int or is_int64_t, "Mod type not supported");
  if(is_int){
   val = int((int64_t)val*m.val%(F{}()));
  }else{
   uint64_t result=
    (uint64_t)val*(uint64_t)m.val-
    uint64_t((long double)val*m.val/(F{}()))*(uint64_t)(F{}());
   result+=(F{}());
   if(result>=(F{}())){
    result-=(F{}());
    if(result>=(F{}())) result-=(F{}());
   }
   val=result;
  }
  return *this;
 }
 [[nodiscard]] Modular_ constexpr pow(int p) const {
  Modular_ a=*this;
  Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
  return ans;
 }
 [[nodiscard]] Modular_ constexpr inv() const {
  T a=val,b=(F{}()), ax=1,bx=0;
  while(b){
   T q=a/b, t=a%b;
   a=b; b=t;
   t=ax-bx*q; ax=bx; bx=t;
  }
  assert(a==1);
  if(ax<0)ax+=(F{}());
  return ax;
 }
 Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }
 [[nodiscard]] friend Modular_ constexpr operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ constexpr operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ constexpr operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ constexpr operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<int MOD> using Modular=Modular_<std::integral_constant<int, MOD>>;
template<class T, T const& x> struct TPointerGetter{ T operator()() const{ return x; } };
template<int const& x> using IntPointerGetter=TPointerGetter<int, x>;
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;

using modular=Modular<998244353>;

std::vector<std::vector<int>> add;
std::vector<int> par, postorder, subsize;

void work(int node){ // delete parent edge, fill par&postorder array
	subsize[node]=1;
	for(auto other: add[node]){
		std::swap(add[other].back(), *std::find(begin(add[other]), end(add[other]), node));
		add[other].pop_back();
		par[other]=node;
		work(other);
		subsize[node]+=subsize[other];
	}
	postorder.push_back(node);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	add.resize(number);

	//std::vector<std::array<int, 2>> edges;
	for(int _=0; _<number-1; ++_){
		int first, sec; std::cin>>first>>sec;--first;--sec;
		//edges.push_back({first, sec});
		add[first].push_back(sec); add[sec].push_back(first);
	}

	par.resize(number);
	subsize.resize(number);
	postorder.reserve(number);
	work(0);
	assert((int)postorder.size()==number);
	assert(postorder.back()==0);

	modular result=number*2;

	std::vector<modular> value(number);
	// [node] = expected value of f[node] over all 2^(number-1) subsets of the edges
	// (note that f[node] only depends on the kept-status of the edges inside the subtree)
	// f can be only 0 or 1.
	//
	// so value[node] is also the probability(f[node]==1), and 1-value[node]=P(f[node]==0).
	
	for(auto node: postorder){
		modular cur=1;
		for(auto x: add[node]){
			modular tmp=1;
			for(auto y: add[x]) tmp*=(1+(1-value[y]))/2;
			cur*=(1+(1-tmp))/2;
		}
		value[node]=cur;
	}

	result-=value[0];
	for(int node=1; node<number; ++node) result-=value[node];

	for(int node=0; node<number; ++node){
		modular tmp=1;
		for(auto x: add[node]) tmp*=1-value[x]/2;
		result-=tmp;
	}

	result*=modular(2).pow(number-1);
	std::cout<<(int)result<<'\n';
}