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
template<class T, T x> struct TConstGetter{ T constexpr operator()() const{ return x; } };
template<int x> using IntConstGetter=TConstGetter<int, x>;
template<int MOD> using Modular=Modular_<IntConstGetter<MOD>>;
template<class T, T const& x> struct TPointerGetter{ T operator()() const{ return x; } };
template<int const& x> using IntPointerGetter=TPointerGetter<int, x>;
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;


using modular=Modular<1000000007>;

std::vector<std::vector<int>> add;
std::vector<char> visited;

int subsize; bool haveBack;
void work(int node, int par){
	++subsize;
	visited[node]=true;
	for(auto other: add[node]) if(other!=par){
		if(visited[other]) haveBack=true;
		else work(other, node);
	}
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	std::vector<std::array<int, 2>> points(number);
	for(auto & it: points)for(auto & it: it) std::cin>>it;

	auto const compress=[&](auto getter)->int{
		// getter: std::array<int, 2>& -> int&
		// return value: number of different values
		std::vector<int> values(points.size());
		std::transform(begin(points), end(points), values.begin(), getter);
		std::sort(begin(values), end(values));
		values.erase(std::unique(begin(values), end(values)), values.end());
		for(auto & it: points){
			auto& item=getter(it);
			item=int(std::lower_bound(begin(values), end(values), item)-values.begin());
		}
		return (int)values.size();
	};

	auto numx=compress([&](auto& it)->int&{ return it[0]; });
	auto numy=compress([&](auto& it)->int&{ return it[1]; });
	add.resize(numx+numy);
	for(auto [a, b]: points){
		b+=numx;
		add[a].push_back(b);
		add[b].push_back(a);
	}

	visited.resize(add.size());
	modular result=1;
	for(int node=0; node<(int)add.size(); ++node)
		if(not visited[node]){
			haveBack=false; subsize=0;
			work(node, -1);
			result*=modular(2).pow(subsize)-(not haveBack);
		}
	std::cout<<(int)result<<'\n';
}