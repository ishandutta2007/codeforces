// 8
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


int64_t mod;
using modular=Modular_<TPointerGetter<int64_t, mod>>;
bool modIsPrimeLarge(){
	assert(mod>13);
	auto q=mod-1;
	auto trailing=__builtin_ctzll(q); q>>=trailing;
	for(auto a: {2, 3, 5, 7, 11, 13}){
		auto y=modular(a).pow(q);
		if((int64_t)y==1) continue;
		for(int _=0; _<trailing; ++_){
			if((int64_t)y==mod-1) goto nexta;

			y=y*y;
			if((int64_t)y==1) return false;
		}
		assert((int64_t)y!=1);
		return false;
nexta:;
	}
	return true;
}
int64_t split(int64_t mod_){
	assert(mod_!=1);

	mod=mod_;
	for(auto a: {2, 3, 5, 7, 11, 13}){
		assert(mod>=a);
		if(mod==a) return 1;
		if(mod%a==0) return a;
	}
	if(modIsPrimeLarge()) return 1;

	assert(mod>13);
	for(int a=2;; ++a){
		modular hare=a, tortoise=a;
		while(true){
			modular product=1;

#define CHECK_PRODUCT \
			{ \
				assert(product!=0); \
				auto const g=std::gcd((int64_t)product, mod); \
				if(g!=1){ \
					assert(g!=0); return g; \
				} \
			}
			for(int _=0; _<25; ++_){
				hare=hare*hare+1;
				hare=hare*hare+1;
				tortoise=tortoise*tortoise+1;

				modular next=product*(hare-tortoise);
				if((int64_t)next==0){
					CHECK_PRODUCT;
					goto nexta;
				}
				product=next;
			}
			CHECK_PRODUCT;
		}
nexta:;
	}
}

std::map<int64_t, std::vector<int64_t>> factorsMemory; // insertion must not invalidate iterators and references
std::vector<int64_t> const& factors(int64_t value){
	// return unique prime factors sorted in increasing order
	auto [iterator, inserted]=factorsMemory.insert({value,{}});
	if(inserted and value!=1){
		assert(iterator->second.empty());
		auto factor=split(value);
		if(factor==1){
			iterator->second.push_back(value);
		}else{
			assert(value%factor==0);
			for(auto value:{factor, value/factor}){
				auto const& tmp=factors(value);
				iterator->second.insert(iterator->second.end(), begin(tmp), end(tmp));
			}
			std::sort(begin(iterator->second), end(iterator->second));
			iterator->second.erase(std::unique(begin(iterator->second), end(iterator->second)), end(iterator->second));
		}
	}
	return iterator->second;
}

std::map<int64_t, std::vector<int64_t>> valueMemory;
std::vector<int64_t> const& valueOf(int64_t k){
	auto [iterator, inserted]=valueMemory.insert({k,{}});
	if(inserted){
		auto const& v=factors(k);

		struct State{int pos; int64_t value; bool operator<(State other) const{return value>other.value;}};
		std::priority_queue<State> queue;

		auto const p=v[0];
		assert(p<INT_MAX);
		auto const first=v.begin()+1, last=v.end();

		std::vector value(p, INT64_MAX);
		queue.push({0, value[0]=0});
		while(not queue.empty()){
			auto [pos, value_]=queue.top(); queue.pop();
			if(value_>value[pos]) continue;
			assert(value_==value[pos]);
			std::for_each(first, last,[&](auto delta){
				auto tmp=value_*p+pos+delta;
				auto pos1=int(tmp%p); auto value1=tmp/p;
				if(value1<value[pos1]) queue.push({pos1, value[pos1]=value1});
			});
		}

		iterator->second=std::move(value);
	}
	return iterator->second;
}

void up(){
	int64_t n, k; std::cin>>n>>k;
	if(k==1){
		std::cout<<"NO\n"; return;
	}
	auto const& v=factors(k);

	if(v.size()==1){
		std::cout<<(n%v[0]==0 ? "YES\n": "NO\n"); return;
	}
	if(v.size()==2){
		mod=v[0];
		auto const b=int64_t(modular(n)/v[1]);
		std::cout<<(v[1]*b<=n ? "YES\n": "NO\n"); return;
	}

	auto const p=v[0];
	std::cout<<(n/p>=valueOf(k)[n%p] ? "YES\n": "NO\n");
}
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}