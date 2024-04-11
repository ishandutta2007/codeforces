       
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
using modular=Modular<998244353>;
int main(){
 std::ios::sync_with_stdio(0);std::cin.tie(0);
 int numRow; std::cin>>numRow;
 int numCol; std::cin>>numCol;
 auto const comb=makeComb<modular>(numRow+numCol+1);
 modular result{};
 for(int row=1; row<numRow; ++row){
  modular value{};
  for(int col=1; col<numCol; ++col){
   value+=comb.walk(col-1, row)*comb.walk(numCol-col, row-1);
   result+=value*comb.walk(numRow-row-1, col)*comb.walk(numRow-row, numCol-col-1);
  }
 }
 for(int col=1; col<numCol; ++col){
  modular value{};
  for(int row=1; row<numRow; ++row){
   result+=value*comb.walk(numCol-col-1, row)*comb.walk(numCol-col, numRow-row-1);
   value+=comb.walk(row-1, col)*comb.walk(numRow-row, col-1);
  }
 }
 std::cout<<int(result*2)<<'\n';
}