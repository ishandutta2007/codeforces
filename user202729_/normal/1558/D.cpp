#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
       
       
template<class modular>
std::vector<modular> inverseF(int limit){
 std::vector<modular> inverse(limit);
 inverse[1]=1;
 for(unsigned i=2;i<inverse.size();++i)
  inverse[i]=inverse[modular::MOD()%i]*modular::raw(modular::MOD()-modular::MOD()/i);
 return inverse;
}
template<class modular>
std::vector<modular> inverseFactF(int limit, std::vector<modular> inverse={}){
 if(inverse.empty()) inverse=inverseF<modular>(limit);
 else assert((int)inverse.size()==limit);
 inverse[0]=1;
 for(int index=3; index<(int)inverse.size(); ++index)
  inverse[index]*=inverse[index-1];
 return inverse;
}
       
       
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
  using V=std::common_type_t<U, decltype((F::get()))>;
  assert(0<=value); assert((V)value<(V)(F::get()));
  Modular_ result; result.val=value; return result;
 }
 [[nodiscard]] bool operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] Modular_ operator+() const{ return *this; }
 [[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?(F::get())-x.val:0; return x; }
 Modular_& operator+=(Modular_ m) { if ((val += m.val) >= (F::get())) val -= (F::get()); return *this; }
 Modular_& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (F::get()); return *this; }
 Modular_& operator*=(Modular_ m) {
  if constexpr(std::is_same<T, int>::value){
   val = int((int64_t)val*m.val%(F::get()));
  }else if constexpr(std::is_same<T, int64_t>::value){
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
   val*=m.val;
   val%=(F::get());
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
  while(b!=0){
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
template<class modular>
std::vector<modular> factF(int limit){
 std::vector<modular> fact(limit);
 fact[0]=1;
 for(int i=1; i<(int)fact.size(); ++i)
  fact[i]=fact[i-1]*i;
 return fact;
}
template<class modular, bool tolerant> struct Comb_internalStructure{
 std::vector<modular> fact, inverseFact;
 modular operator()(int a, int b)const{
  if(tolerant and (b<0 or b>a)) return 0;
  return fact[a]*inverseFact[b]*inverseFact[a-b];
 }
 modular walk(int a, int b) const{
  return (*this)(a+b, b);
 }
};
template<class modular, bool tolerant=false>
Comb_internalStructure<modular, tolerant> makeComb(int limit){
 Comb_internalStructure<modular, tolerant> result;
 result.fact=factF<modular>(limit);
 result.inverseFact=inverseFactF<modular>(limit);
 return result;
}
template<class modular>
Comb_internalStructure<modular, true> makeTolerantComb(int limit){ return makeComb<modular, true>(limit); }


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using set_t = __gnu_pbds::tree<
  int,
  __gnu_pbds::null_type,
  std::less<int>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update>;




int const maxN=(int)
#if LOCAL
	5
#else
	2e5
#endif
	;

using modular=Modular<998244353>;
auto const comb=makeComb<modular>(maxN*2);


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);


	set_t s;
	for(int i=0; i<maxN; ++i) s.insert(i);

	
	int numTest; std::cin>>numTest;
	while(numTest--){
		int n; std::cin>>n;
		assert(n<=maxN);
		int m; std::cin>>m;

		std::vector<int> yValues(m); // in reverse time (chronological) order.
		for(int i=0; i<m; ++i){
			int x; std::cin>>x;
			int y; std::cin>>y; --y;
			yValues.rbegin()[i]=y;
		}
		
		std::vector<int> temporarily_removed; // need to do that to be fast...
		int f=0;
		for(auto y: yValues){
			assert(y<(int)s.size()-(maxN-n)-1);
			auto value_it=s.find_by_order(y);
			auto const value=*value_it;
			auto next_it=s.erase(value_it);
			assert(next_it!=s.end());
			if(*next_it==value+1)
				++f;
			temporarily_removed.push_back(value);
		}

		for(auto x: temporarily_removed){
			auto const [iterator, inserted]=s.insert(x);
			assert(inserted==true);
			assert(*iterator==x);
		}

		assert(s.size()==maxN);

		std::cout<<(int)comb(n*2-1-f, n-1-f)<<'\n';
	}
}