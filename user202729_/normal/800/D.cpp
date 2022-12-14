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

using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	std::vector<int> input(number);
	int block=1;
	{ // read input and compute block
		int maximum{};
		for(auto & it: input){std::cin>>it; maximum=std::max(maximum, it);}
		while(block<=maximum) block*=10;
	}

	struct Item{
		int count;
		modular sum, sum2;
#define op(op) \
		Item operator op(Item other) const{ return {\
			count op other.count, sum op other.sum, sum2 op other.sum2};\
		}\
		Item& operator op##=(Item other){ return *this=*this op other; }
		op(+) op(-)
#undef op
	};
	std::vector<Item> value(block);
	for(auto it: input){
		value[it].count+=1;
		value[it].sum+=it;
		value[it].sum2+=modular(it).pow(2);
	}

	// add to lower
	for(int dim=1; dim<block; dim*=10)
		for(int base=0; base<block; ++base) if((base/dim)%10==0){
			for(auto index=10; --index;)
				value[base+(index-1)*dim]+=value[base+index*dim];
		}

	for(auto& [count, sum, sum2]: value){
		// after this loop, sum is used to store the "result"
		if(count==0) continue;
		if(count==1){
			assert(sum2==sum.pow(2));
			sum=sum2;
			continue;
		}
		assert(count>=2);
		sum=modular(2).pow(count-2)*(sum.pow(2)+sum2);
	}

	// reverse of "add to lower"
	for(int dim=1; dim<block; dim*=10)
		for(int base=0; base<block; ++base) if((base/dim)%10==0){
			for(int index=1; index<10; ++index)
				value[base+(index-1)*dim]-=value[base+index*dim];
			// ^ (unnecessarily manipulate sum2)
		}

	int64_t result{};
	for(int index=0; index<(int)value.size(); ++index)
		result^=index*(int64_t)(int)value[index].sum;
	std::cout<<result<<'\n';
}