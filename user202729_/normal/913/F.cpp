// more optimized...
// this is the last submission.





#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
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
 template<class U>
 [[nodiscard]] Modular_ constexpr pow(U p) const {
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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int maxNumber; std::cin>>maxNumber;

	modular const p=[&]{
		int a, b; std::cin>>a>>b;
		return modular(a)/b;
	}();
	std::vector<modular> f(maxNumber+1);
	f[1]=0;

	std::vector<modular> g(maxNumber+1);
	std::vector<modular> klast, kcur;
	klast.reserve(maxNumber+1);
	kcur.reserve(maxNumber+1);

	g[1]=1; // probability that the edge configuration forms a single strongly connected component
	klast.assign(2, 1); // middle probability of a particular split

	for(int number=2; number<=maxNumber; ++number){
		kcur.resize(number+1);
		kcur[0]=kcur[number]=1;

		auto const f0=[&](int number){return f[number]-(number-1)*number/2;};
		assert(f0(0)==0);
		modular tmp_f{};
		modular tmp_g=1;
		for(auto [s, pps, ip_, ip]=std::make_tuple(1, p, (1-p).pow(number-1), 1/(1-p));
				s<number; ++s, pps*=p, ip_*=ip){
			kcur[s]=
				klast[s]*pps+
				klast[s-1]*ip_;
			auto const v=kcur[s]*g[s];
			tmp_g-=v;
			tmp_f+=v*(f0(number-s)+f[s]);
		}
		tmp_f+=number*(number-1)/2;
		g[number]=tmp_g;
		f[number]=tmp_f/(1-g[number]);

		std::swap(klast, kcur);
	}

	std::cout<<(int)f[maxNumber]<<'\n';
}